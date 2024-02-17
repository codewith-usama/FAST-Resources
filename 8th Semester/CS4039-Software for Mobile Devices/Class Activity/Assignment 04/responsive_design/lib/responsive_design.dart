import 'package:flutter/material.dart';
import 'package:responsive_design/landscape.dart';
import 'package:responsive_design/portrait.dart';

class ResponsiveDesign extends StatelessWidget {
  const ResponsiveDesign({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: OrientationBuilder(
        builder: (BuildContext context, Orientation orientation) =>
            orientation == Orientation.landscape
                ? const LandScape()
                : const Portrait(),
      ),
    );
  }
}
