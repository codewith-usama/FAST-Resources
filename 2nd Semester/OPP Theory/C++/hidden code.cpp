#include <iostream>

using namespace std;

int main()
{
    string name;
    int n, num;
    int len;
    cout << endl
         << "Enter your name:";
    cin >> name;

    cout << endl;
    len = name.length();

    if (len % 2 == 0)
    {
        for (int i = 0; i < len / 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << "*";
            }
        }
    }
    else
    {
        for (int i = 0; i < len / 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << "*";
            }
        }
        cout << "*";
    }

    return 0;
}
