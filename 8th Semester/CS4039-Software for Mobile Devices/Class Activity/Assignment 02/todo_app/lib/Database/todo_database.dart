import 'package:hive_flutter/hive_flutter.dart';

class ToDoDatabase {
  List toDoList = [];

  final _myBox = Hive.box('mybox');

  void createInitialList() {
    toDoList = [
      ["Make tutorial", false],
      ["Do exercise", false],
    ];
  }

  // load Data
  void loadData() {
    toDoList = _myBox.get("TODOLIST");
  }

  // update Database
  void updateDatabase() {
    _myBox.put("TODOLIST", toDoList);
  }
}
