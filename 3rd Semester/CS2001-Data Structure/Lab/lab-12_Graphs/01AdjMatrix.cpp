#include <iostream>

using namespace std;

class Graph {
    private:
        int G[5][5];
        int size = 5;


    public:

        Graph() {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    G[i][j] = 0;
                }
                
            }
            
        }

        void addEdge(int v1, int v2) {
            G[v1-1][v2-1] = 1;  // weighted
            G[v2-1][v1-1] = 1;  // weighted
        }


        void Display() {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    cout<<G[i][j]<<" ";
                }
                cout<<endl;
                
            }
            
        }
};

int main() {

    Graph g1;
    g1.addEdge(1,5);
    g1.addEdge(1,2);
    // g1.addEdge(2,1);
    g1.addEdge(2,3);
    g1.addEdge(2,5);
    g1.addEdge(3,4);
    g1.Display();
    return 0;
}