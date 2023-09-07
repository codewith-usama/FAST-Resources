#include <iostream>
#include <cmath>
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
	int Sorted_Insert(HashTableEntry **H, int);
	int Insert_Division_Method(HashTableEntry *H[], int);
	
	int Multiplication_Hash(HashTableEntry *H[], int, int);
	
	int Mid_Square_Hash(HashTableEntry *H[], int);
	int Middle_Value(int);
	
	int Folding_Hash(HashTableEntry *H[], int);
	
	HashTableEntry* Search(HashTableEntry *p, int);
	void Delete_Value(int);
	~HashMapTable() { }
};

// Getting index for inserting values in Hash Table
int HashMapTable::HashFun(int k) {
	return (k % 10);
}

// For insertion in Sorted Order
int HashMapTable::Sorted_Insert(HashTableEntry **H, int k) {
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
int HashMapTable::Insert_Division_Method(HashTableEntry *H[], int k) {
	int index = HashFun(k);
	Sorted_Insert(&H[index], k);
}


// Inserting Values in Hash Table using Multiplication Method
int HashMapTable::Multiplication_Hash(HashTableEntry *H[], int k, int size) {
	int index = HashFun(size*k);
	Sorted_Insert(&H[index], k);
}

// Inserting Values in Hash tabel using Mid Square Hash Method
int HashMapTable::Mid_Square_Hash(HashTableEntry *H[], int k) {
	int index = Middle_Value(k);
	Sorted_Insert(&H[index], k);
}

// Calculating Middle digit of the value
int HashMapTable::Middle_Value(int k) {
	int dig = (int)log10(k) + 1;
	
	k = (int)(k / pow(10, dig / 2)) % 10;
	
	return k;
}


// Inserting Values in Hash tabel using Folding Hash Method
int HashMapTable::Folding_Hash(HashTableEntry *H[], int) {
	
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
	int check;
	cout << "Press respective key for Different Insertion Method\n"
			<< "1. Dividion Mehtod\n2.Multiplication Method\n"
			<< "3.Mid Square Method\n4.Folding Hash\n5.Radix Hash\nEnter you Choice: ";
			cin >> check;
			
			
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
		switch(check) {
			case 1:
				ob1.Insert_Division_Method(table, value);
				break;
			case 2:
				ob1.Multiplication_Hash(table, value, num);
				break;
			case 3:
				ob1.Mid_Square_Hash(table, value);
				break;
//			case 4:
					
		}
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
