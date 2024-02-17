import 'package:flutter/material.dart';

class CustomDrawer extends StatelessWidget {
  const CustomDrawer({super.key});

  @override
  Widget build(BuildContext context) {
    return Drawer(
      child: Container(
        color: Colors.purpleAccent[50],
        child: ListView(
          children: const [
            DrawerHeader(
              child: Center(
                  child: Text(
                'L O G O',
                style: TextStyle(
                  fontSize: 30,
                  fontWeight: FontWeight.w500,
                ),
              )),
            ),
            ListTile(
              leading: Icon(Icons.person),
              title: Text('Mohammad Usama'),
            ),
            ListTile(
              leading: Icon(Icons.person),
              title: Text('Hameez Ahmed'),
            ),
            ListTile(
              leading: Icon(Icons.person),
              title: Text('Sameer Raza'),
            ),
          ],
        ),
      ),
    );
  }
}
