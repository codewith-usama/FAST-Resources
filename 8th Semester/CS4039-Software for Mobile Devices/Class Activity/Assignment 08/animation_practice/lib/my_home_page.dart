import 'package:flutter/material.dart';
import 'package:rive/rive.dart';

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  Artboard? _artboard;

  bool get isPlaying => _artboard?.isPlaying ?? true;
  void _togglePlay() {
    if (isPlaying) {
      _artboard?.pause();
    } else {
      _artboard?.play();
    }

    setState(() {});
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color.fromARGB(255, 140, 201, 229),
        title: const Text(
          'Animation Example',
          style: TextStyle(color: Colors.white),
        ),
      ),
      body: SafeArea(
        child: Center(
          child: SizedBox(
            height: 200,
            width: 200,
            child: RiveAnimation.asset(
              'animations/off_road_car.riv',
              animations: const ["idle"],
              fit: BoxFit.cover,
              onInit: (artboard) {
                _artboard = artboard;
              },
            ),
          ),
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _togglePlay,
        tooltip: isPlaying ? 'Pause' : 'Play',
        child: Icon(
          isPlaying ? Icons.pause : Icons.play_arrow,
        ),
      ),
    );
  }
}
