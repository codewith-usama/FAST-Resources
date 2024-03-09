import 'dart:convert';
import 'package:http/http.dart' as http;
import 'package:network_request/post_model.dart';

class NetworkReq {
  Future<PostModel> fetchPost() async {
    final response = await http
        .get(Uri.parse('https://jsonplaceholder.typicode.com/comments/1'));

    if (response.statusCode == 200) {
      return PostModel.fromJson(jsonDecode(response.body));
    } else {
      throw Exception('Failed to load post');
    }
  }
}
