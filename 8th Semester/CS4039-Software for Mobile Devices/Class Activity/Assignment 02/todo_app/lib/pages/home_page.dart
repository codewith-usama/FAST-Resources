import 'package:flutter/material.dart';
import 'package:todo_app/Database/todo_database.dart';
import 'package:todo_app/util/todo_tile.dart';
import 'package:hive_flutter/hive_flutter.dart';
import 'package:todo_app/util/dialog_button.dart';

class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  // reference the hive box
  final Box _myBox = Hive.box('mybox');
  ToDoDatabase db = ToDoDatabase();

  @override
  void initState() {
    // dummy todos
    if (_myBox.get("TODOLIST") == null) {
      db.createInitialList();
    } else {
      db.loadData();
    }
    super.initState();
  }

  @override
  void dispose() {
    Hive.close();
    super.dispose();
  }

  // delete task
  void deleteTask(int index) {
    setState(() {
      db.toDoList.removeAt(index);
    });
    db.updateDatabase();
  }

  // Changing Check Box
  void checkBoxChanged(bool? value, int index) {
    setState(() {
      db.toDoList[index][1] = !db.toDoList[index][1];
    });
    db.updateDatabase();
  }

  // Text controller
  final TextEditingController taskController = TextEditingController();

  // create new Task
  void createNewTask() {
    showDialog(
      barrierDismissible: false,
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          title: const Text("Enter Todo"),
          content: SingleChildScrollView(
            child: ListBody(
              children: [
                TextField(
                  controller: taskController,
                  decoration: const InputDecoration(
                    border: OutlineInputBorder(),
                    hintText: "Enter Task",
                  ),
                ),
                const SizedBox(
                  height: 20.0,
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceAround,
                  children: [
                    MyButton(
                        text: "Save",
                        onPressed: () {
                          setState(() {
                            db.toDoList.add([taskController.text, false]);
                            taskController.clear();
                          });
                          Navigator.of(context).pop();
                          db.updateDatabase();
                        }),
                    const SizedBox(
                      width: 10.0,
                    ),
                    MyButton(
                      text: "Cancel",
                      onPressed: () {
                        Navigator.of(context).pop();
                      },
                    )
                  ],
                )
              ],
            ),
          ),
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: const Color(0XFFFFF7F1),
      appBar: AppBar(
        title: const Text("TO DO"),
        elevation: 0,
        backgroundColor: const Color(0XFFFFF7F1),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: createNewTask,
        backgroundColor: Theme.of(context).colorScheme.secondary,
        child: Icon(
          Icons.add,
          color: Theme.of(context).colorScheme.onSecondary,
        ),
      ),
      body: ListView.builder(
        itemCount: db.toDoList.length,
        itemBuilder: (context, index) {
          return ToDoTile(
            taskName: db.toDoList[index][0],
            taskCompleted: db.toDoList[index][1],
            onChanged: (value) => checkBoxChanged(value, index),
            onPressed: (context) => deleteTask(index),
          );
        },
      ),
    );
  }
}
