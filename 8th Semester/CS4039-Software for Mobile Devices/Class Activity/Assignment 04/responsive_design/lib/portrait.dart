import 'package:flutter/material.dart';
import 'package:responsive_design/drawer.dart';

class Portrait extends StatelessWidget {
  const Portrait({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Responsive Design'),
        centerTitle: true,
        leading: Builder(
          builder: (context) => IconButton(
            onPressed: () {
              Scaffold.of(context).openDrawer();
            },
            icon: const Icon(Icons.menu),
          ),
        ),
      ),
      drawer: const CustomDrawer(),
      body: SafeArea(
        child: Padding(
          padding: const EdgeInsets.all(8.0),
          child: ListView(
            children: List.generate(
              20,
              (index) => Container(
                padding: const EdgeInsets.all(12),
                margin: const EdgeInsets.all(4),
                color: Colors.amber,
                child: Text('Item no ${index + 1}'),
              ),
            ),
          ),
        ),
      ),
    );
  }
}
