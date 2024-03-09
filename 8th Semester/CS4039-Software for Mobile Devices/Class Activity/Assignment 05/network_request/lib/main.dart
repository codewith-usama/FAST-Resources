import 'package:flutter/material.dart';
import 'package:network_request/network_req.dart';
import 'package:network_request/post_model.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  late Future<PostModel> futurePost;
  late NetworkReq networkReq;

  @override
  void initState() {
    super.initState();
    networkReq = NetworkReq();
    futurePost = networkReq.fetchPost();
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Network Request',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.lightBlue,
          centerTitle: true,
          title: const Text(
            'Network Request',
            style: TextStyle(
              fontWeight: FontWeight.w400,
              color: Colors.white,
            ),
          ),
        ),
        body: Center(
          child: FutureBuilder<PostModel>(
            future: futurePost,
            builder: (context, snapshot) {
              if (snapshot.hasData) {
                return Padding(
                  padding: const EdgeInsets.all(12.0),
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text('Post ID: ${snapshot.data!.postId}'),
                      Text('ID: ${snapshot.data!.id}'),
                      Text('Name: ${snapshot.data!.name}'),
                      Text('Email: ${snapshot.data!.email}'),
                      Text('Body: ${snapshot.data!.body}'),
                    ],
                  ),
                );
              } else if (snapshot.hasError) {
                return Text('${snapshot.error}');
              }
              return const CircularProgressIndicator();
            },
          ),
        ),
      ),
    );
  }
}
