import 'package:flutter/material.dart';
import 'package:responsive_design/responsive_design.dart';

void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Responsive Design',
      home: ResponsiveDesign(),
    );
  }
}
