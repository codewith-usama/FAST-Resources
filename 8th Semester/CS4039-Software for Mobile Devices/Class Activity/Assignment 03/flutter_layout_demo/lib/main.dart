import 'package:flutter/material.dart';
import 'package:flutter_layout_demo/button_section.dart';
import 'package:flutter_layout_demo/image_section.dart';
import 'package:flutter_layout_demo/text_section.dart';
import 'package:flutter_layout_demo/title_section.dart';

void main() {
  runApp(const MainApp());
}

class MainApp extends StatelessWidget {
  const MainApp({super.key});

  @override
  Widget build(BuildContext context) {
    const String appTitle = 'Flutter layout demo';
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: appTitle,
      home: Scaffold(
        appBar: AppBar(
          centerTitle: true,
          title: const Text(appTitle),
        ),
        body: const Column(
          children: [
            ImageSection(
                image:
                    'https://folder.pk/wp-content/uploads/2018/04/Banjosa-Lake.jpg'),
            TitleSection(
              name: 'Banjosa Lake',
              location: 'Kashmir, Pakistan',
            ),
            ButtonSection(),
            TextSection(
              description:
                  'Banjosa Lake (Urdu: بنجوسہ جھیل ) is an artificial lake and a tourist resort 18 kilometers (11 mi) from the city of Rawalakot in Poonch District of Azad Kashmir, Pakistan.'
                  'It is located at an altitude of 1,981 meters (6,499 ft).This lake is 160 kilometers away from Rawalpindi'
                  'The lake is surrounded by dense pine forest and mountains. The Lake is accessible by a metalled road from Rawalakot.',
            )
          ],
        ),
      ),
    );
  }
}