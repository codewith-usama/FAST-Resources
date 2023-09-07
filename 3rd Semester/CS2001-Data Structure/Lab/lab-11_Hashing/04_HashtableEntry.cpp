#include <iostream>
using namespace std;

const int tablesize = 10;

class HashTableEntry{
    public:
        int key;
        int value;

        HashTableEntry(){
            key=0;
            value=0;
        }
        HashTableEntry(int key, int value){
            this->key = key;
            this->value = value;
        }
};

class HashTable{

    HashTableEntry **table;

    public:
        HashTable(){
            table = new HashTableEntry *[tablesize];
            for(int i=0; i<tablesize; i++){
                table[i] = NULL;
            }
        }

        int hashFunction(int val)
		{
            int a=val;
			int b=0, c=0, d=0, sum;
			b = a% 10;
	
			c = a % 100;
			c = c/10;
	
			d = a /100;
	
			sum = d+b+c;
			return sum;
        }

        void insert(int key, int val){
            int hash = hashFunction(key);
            table[hash] = new HashTableEntry(key, val);
            cout << "Element inserted successfully!" << endl;
        }

        int search(int key){
            int hash = hashFunction(key);
            if(table[hash] != NULL){
                return table[hash]->value;
            }

            cout << "No element found at given key!" << endl;
            return -1;

        }

        void remove(int key){
            int hash = hashFunction(key);
            if(table[hash] == NULL){
                cout << "No data at key!" << endl;
                return;
            }
            delete table[hash];
            cout << "Element deleted successfully!";
        }

        void display(){
            cout << "Elements stored in hash table are as follows: ";
            for(int i=0; i<tablesize; i++){
                if(table[i] != NULL){
                    cout << table[i]->value << " ";
                }
                else{
                    cout << "__ ";
                }
            }
        }
};

int main()
{
    HashTable h;
    int key;
    int n=5;
    int arr[5] = {108,151,122,193,15};
    for(int i=0; i<n; i++){
        key = h.hashFunction(arr[i]);
        h.insert(key, arr[i]);
    }

    h.display();
    cout << endl;

    cout << "Enter a key to search in hash table: ";
    cin >> key;

    if(h.search(key) != -1){
        cout << "Data stored in the key = " << h.search(key) << endl;
    }
}
