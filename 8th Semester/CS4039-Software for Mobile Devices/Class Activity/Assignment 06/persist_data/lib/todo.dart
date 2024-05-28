class Todo {
  int? id;
  String title;

  Todo({
    this.id,
    required this.title,
  });

  Map<String, dynamic> toMap() {
    var map = <String, dynamic>{
      'title': title,
    };
    if (id != null) {
      map['id'] = id;
    }
    return map;
  }

  Todo.fromMap(Map<String, dynamic> map)
      : id = map['id'],
        title = map['title'];
}
