import 'package:flutter/material.dart';
import 'package:responsive_design/drawer.dart';

class LandScape extends StatelessWidget {
  const LandScape({super.key});

  @override
  Widget build(BuildContext context) {
    Scaffold.of(context).openDrawer();

    return Scaffold(
      appBar: AppBar(centerTitle: true, title: const Text('Responsive Design')),
      body: SafeArea(
        child: Padding(
          padding: const EdgeInsets.all(8.0),
          child: Row(
            children: [
              const Expanded(child: CustomDrawer()),
              Expanded(
                flex: 3,
                child: GridView(
                  gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                    crossAxisCount: 2,
                    childAspectRatio: 5,
                  ),
                  shrinkWrap: true,
                  children: List.generate(
                    20,
                    (index) => Container(
                      margin: const EdgeInsets.all(4),
                      color: Colors.amber,
                      child: Center(child: Text('Item no ${index + 1}')),
                    ),
                  ),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
