import 'package:flutter/material.dart';
import 'db_helper.dart';
import 'todo.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter To-Do App',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        brightness: Brightness.light,
        scaffoldBackgroundColor: Colors.white,
        appBarTheme: const AppBarTheme(
          backgroundColor: Colors.white,
          foregroundColor: Colors.black,
          elevation: 1,
        ),
        floatingActionButtonTheme: const FloatingActionButtonThemeData(
          backgroundColor: Colors.blue,
          foregroundColor: Colors.white,
        ),
        dialogTheme: DialogTheme(
          shape: RoundedRectangleBorder(
            borderRadius: BorderRadius.circular(12),
          ),
        ),
      ),
      home: const TodoListScreen(),
    );
  }
}

class TodoListScreen extends StatefulWidget {
  const TodoListScreen({super.key});

  @override
  _TodoListScreenState createState() => _TodoListScreenState();
}

class _TodoListScreenState extends State<TodoListScreen> {
  List<Todo> _todos = [];
  final DBHelper _dbHelper = DBHelper();
  final GlobalKey<AnimatedListState> _listKey = GlobalKey<AnimatedListState>();

  @override
  void initState() {
    super.initState();
    _refreshTodoList();
  }

  void _refreshTodoList() async {
    final data = await _dbHelper.queryAll();
    setState(() {
      _todos = data.map((item) => Todo.fromMap(item)).toList();
    });
  }

  void _showTodoDialog({Todo? todo}) {
    final _textController = TextEditingController(text: todo?.title ?? '');

    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: Text(todo == null ? 'Add To-Do' : 'Edit To-Do'),
          content: TextField(
            controller: _textController,
            decoration: const InputDecoration(
              hintText: 'Enter To-Do',
              border: OutlineInputBorder(),
              focusedBorder: OutlineInputBorder(
                borderSide: BorderSide(color: Colors.blue),
              ),
            ),
          ),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: const Text('Cancel'),
            ),
            ElevatedButton(
              onPressed: () {
                if (_textController.text.isNotEmpty) {
                  final newTodo = Todo(
                    id: todo?.id,
                    title: _textController.text,
                  );
                  if (todo == null) {
                    _addTodo(newTodo);
                  } else {
                    _updateTodo(newTodo);
                  }
                  Navigator.of(context).pop();
                }
              },
              child: const Text('Submit'),
            ),
          ],
        );
      },
    );
  }

  void _addTodo(Todo todo) async {
    final id = await _dbHelper.insert(todo.toMap());
    final newTodo = Todo(
      id: id,
      title: todo.title,
    );

    setState(() {
      _todos.insert(0, newTodo);
      _listKey.currentState?.insertItem(0);
    });
  }

  void _updateTodo(Todo todo) async {
    await _dbHelper.update(todo.toMap());
    _refreshTodoList();
  }

  void _deleteTodo(int index) async {
    await _dbHelper.delete(_todos[index].id!);

    setState(() {
      _listKey.currentState?.removeItem(
        index,
        (context, animation) => _buildItem(_todos[index], index, animation),
        duration: const Duration(milliseconds: 300),
      );
      _todos.removeAt(index);
    });
  }

  Widget _buildItem(Todo todo, int index, Animation<double> animation) {
    return SizeTransition(
      sizeFactor: animation,
      child: Card(
        margin: const EdgeInsets.symmetric(vertical: 4, horizontal: 12),
        child: ListTile(
          contentPadding:
              const EdgeInsets.symmetric(vertical: 8, horizontal: 16),
          title: Text(todo.title),
          trailing: IconButton(
            icon: const Icon(Icons.delete, color: Colors.red),
            onPressed: () => _deleteTodo(index),
          ),
          onTap: () => _showTodoDialog(todo: todo),
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('To-Do List'),
      ),
      body: AnimatedList(
        key: _listKey,
        initialItemCount: _todos.length,
        itemBuilder: (context, index, animation) {
          return _buildItem(_todos[index], index, animation);
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () => _showTodoDialog(),
        child: const Icon(Icons.add),
      ),
    );
  }
}
