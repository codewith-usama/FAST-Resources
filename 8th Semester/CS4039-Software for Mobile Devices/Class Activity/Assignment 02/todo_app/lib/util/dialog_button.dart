// ignore_for_file: must_be_immutable

import 'package:flutter/material.dart';

class MyButton extends StatelessWidget {
  MyButton({
    super.key,
    required this.text,
    required this.onPressed,
  });
  final String text;
  VoidCallback onPressed;

  @override
  Widget build(BuildContext context) {
    return ElevatedButton(
      style:
          ElevatedButton.styleFrom(textStyle: const TextStyle(fontSize: 15.0)),
      onPressed: onPressed,
      child: Container(
        padding: const EdgeInsets.all(10.0),
        child: Center(
          child: Text(text),
        ),
      ),
    );
  }
}
