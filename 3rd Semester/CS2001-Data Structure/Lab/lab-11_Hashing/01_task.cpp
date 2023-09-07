#include<iostream>

using namespace std;
class HashTableEntry {
public:
	int k;
	int v;
	HashTableEntry *next;
	HashTableEntry(int key): k(key) { }
	HashTableEntry(): next(NULL) { }
	HashTableEntry(int k, int v) {
		this->k = k;
		this->v = v;
	} 	
};

class HashMapTable {
private:
	HashTableEntry *head;
	HashTableEntry *tail;
public:
	HashTableEntry* Get_Head() { return head; }
	HashMapTable(): head(NULL), tail(NULL) { }
	int HashFun(int);
	void Sorted_Insert(HashTableEntry **H, int);
	void Insert(HashTableEntry *H[], int);
	HashTableEntry* Search(HashTableEntry *p, int);
	void Delete_Value(int);
	~HashMapTable() { }
};

// Getting index for inserting values in Hash Table
int HashMapTable::HashFun(int k) {
	return (k % 10);
}

// For insertion in Sorted Order
void HashMapTable::Sorted_Insert(HashTableEntry **H, int k) {
	HashTableEntry *temp = new HashTableEntry(k);
	HashTableEntry *p = *H;
	HashTableEntry *q = NULL;
	temp->next = NULL;
	if(*H == NULL)
		*H = temp;
	else {
		while(p && p->k < k) {
			q = p;
			p = p->next;
		}
		if(p == *H) {
			temp->next = head;
			head = temp;
		}
		else {
			temp->next = *H;
			*H = temp;
		}
	}
}

// For Getting index from Hash Function and passing value to Sorted_Insert Function
void HashMapTable::Insert(HashTableEntry *H[], int k) {
	int index = HashFun(k);
	Sorted_Insert(&H[index], k);
}


// For searching specific Value
HashTableEntry* HashMapTable::Search(HashTableEntry *p, int k) {
	while(p) {
		if(k == p->k) return p;
		
		p = p->next;
	}
	return NULL;
}

// For deleting/removing value
void HashMapTable::Delete_Value(int k) {
	HashTableEntry *p = head, *q = NULL;
	while(p) {
		if(k == p->k) {
			q->next = p->next;
			delete p;
		}
		q = p;
		p = p->next;
	}
}


// Driver Program
int main() {
	
	int num;
	int value = 0;
	cout << "Enter number of values you want to enter in Hash table: ";  cin >> num;
	
	HashTableEntry *table[num];
	HashTableEntry *temp;
	for(int i = 0;i < num; i++)
		table[i] = NULL;
		
	HashMapTable ob1;
	
	for(int i = 0; i < num; i++) {
		fflush(stdin);
		cout << "Enter Values: ";
		cin >> value;
		ob1.Insert(table, value);
		value = 0;
	}
	
	
	cout << "Enter value you want to search: "; cin >> num;
	temp = ob1.Search(table[ob1.HashFun(num)], num);
	if(temp == NULL) {
		cout << "Key is not present in Hash Table\n";
	}
	else {
		cout << "Key is found\n";
	}
	
	
	return 0;
}
