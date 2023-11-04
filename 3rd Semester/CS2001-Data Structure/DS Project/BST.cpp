#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;


/* Binary Search Tree Class Definition*/

class Binary_Search_Tree {

public:
	Binary_Search_Tree* left;
	Binary_Search_Tree* right;
	string country;
	string Confirmed;
	string Deaths;
	string Recovered;
	string Active;
	string New_cases;
	string New_deaths;
	string New_recover;
	string Confirmed_last_week;
	string one_week_change;
	string one_week_percent_increase;
	string WHO_region;

	/*Default Constructor*/
	Binary_Search_Tree() { }
	
	/*Parametrized Constructor prototype*/
	Binary_Search_Tree(string country, string Confirmed, string Deaths, string Recovered, string Active, string New_cases, string New_deaths,
		string New_recover, string Confirmed_last_week, string one_week_change, string one_week_percent_increase, string WHO_region);

	/*Inorder function  Binary search Tree prototype*/
	void Binary_Search_Tree_Inorder(Binary_Search_Tree *root);
	
	
	/* Seacrh_Data funtion prototype*/
	void Search_Data(Binary_Search_Tree *root, string);
	
	
	/*Delete_Data function prototype*/
	Binary_Search_Tree* Delete_Data(Binary_Search_Tree* root, string country);
	
};

/*Binary_Search_Tree_Inorder function definition*/ 
void Binary_Search_Tree::Binary_Search_Tree_Inorder(Binary_Search_Tree *root) {
	if(root) {
		Binary_Search_Tree_Inorder(root->left);
		cout << root->country << "\t  " << root->Confirmed << "\t  " << root->Deaths << "\t  " << root->Recovered << "\t  " << root->Active << "\t  " << root->New_cases << "\t  " <<
		root->New_deaths << "\t  " << root->New_recover << "\t  " << root->Confirmed_last_week << "\t  " << root->one_week_change << "\t  " << root->WHO_region << endl << endl;
//		sleep(1);
		Binary_Search_Tree_Inorder(root->right);
	}
}


/* Parametrized constructor definition */
Binary_Search_Tree::Binary_Search_Tree(string country, string Confirmed, string Deaths, string Recovered, string Active, string New_cases, string New_deaths,
	string New_recover, string Confirmed_last_week, string one_week_change, string one_week_percent_increase, string WHO_region) {
	
	left = NULL;
	right = NULL;
	this->country = country;
	this->Confirmed = Confirmed;
	this->Deaths = Deaths;
	this->Recovered = Recovered;
	this->Active = Active;
	this->New_cases = New_cases;
	this->New_deaths = New_deaths;
	this->New_recover = New_recover;
	this->Confirmed_last_week = Confirmed_last_week;
	this->one_week_change = one_week_change;
	this->one_week_percent_increase = one_week_percent_increase;
	this->WHO_region = WHO_region;

}



/* Create Node function definition */
Binary_Search_Tree* CreateNode(Binary_Search_Tree *root, string country, string confirmed, string deaths, string recovered,
	string active, string new_cases, string new_deaths, string new_recover, string confirmed_last_week, string one_week_change,
	string one_week_percent_increase, string who_region) {

	if (!root) {
		return new Binary_Search_Tree(country, confirmed, deaths, recovered, active, new_cases, new_deaths, new_recover,
			confirmed_last_week, one_week_change, one_week_percent_increase, who_region);
	}
	if (country > root->country)
		root->right = CreateNode(root->right, country, confirmed, deaths, recovered, active, new_cases, new_deaths, new_recover,
			confirmed_last_week, one_week_change, one_week_percent_increase, who_region);

	else if (country < root->country)
		root->left = CreateNode(root->left, country, confirmed, deaths, recovered, active, new_cases, new_deaths, new_recover,
			confirmed_last_week, one_week_change, one_week_percent_increase, who_region);
			
	return root;
}



/* Search_Data function definition*/

void Binary_Search_Tree::Search_Data(Binary_Search_Tree* root, string country) {
	
	
	if(root->country == country) {		
		cout << "Country  Confirmed Deaths Recoveres Active NCases NDeaths NRecover LastWeek Week   WHO Region" << endl; 
		cout << root->country << "  " << root->Confirmed << "  " << root->Deaths << "   " << root->Recovered << "\t   " << root->Active << "  " << root->New_cases << "\t" <<
		root->New_deaths << "\t " << root->New_recover << "     " << root->Confirmed_last_week << "  " << root->one_week_change << " " << root->WHO_region << endl << endl;
	}
	if(root->country > country)
		Search_Data(root->left, country);
	else if(root->country < country)
		Search_Data(root->right, country);
}



/* MinValue function definition*/
Binary_Search_Tree* MinValue(Binary_Search_Tree *temp) {
	Binary_Search_Tree* p = temp;
	
	while(p && p->left != NULL)
		p = p->left;
	
	return p;
}

/*Delete_Data function definition*/
Binary_Search_Tree* Binary_Search_Tree::Delete_Data(Binary_Search_Tree* root, string country) {
	if(root == NULL)
		return root;
		
	if(country < root->country)
		root->left = Delete_Data(root->left, country);
	
	else if(country > root->country)
		root->right = Delete_Data(root->right, country);
	
	else {
		if(root->left == NULL && root->right == NULL)
			return NULL;
		
		else if(root->left == NULL) {
			Binary_Search_Tree *temp = root->right;
			delete root;
			return temp;
		}
		
		
		else if(root->right == NULL) {
			Binary_Search_Tree *temp = root->left;
			delete root;
			return temp;
		}
		
		Binary_Search_Tree *temp = MinValue(root->right);
		root->country = temp->country;
		
		root->Confirmed = temp->Confirmed;
		root->Deaths = temp->Deaths;
		root->Recovered = temp->Recovered;
		root->Active = temp->Active;
		root->New_cases = temp->New_cases;
		root->New_deaths = temp->New_deaths;
		root->New_recover = temp->New_recover;
		root->Confirmed_last_week = temp->Confirmed_last_week;
		root->one_week_change = temp->one_week_change;
		root->one_week_percent_increase = temp->one_week_percent_increase;
		root->WHO_region = temp->WHO_region;
		
		
		
		root->right = Delete_Data(root->right, temp->country);
		
	}
	
	return root;
}







/* All_Country_final_data function definition */
void All_Country_final_data() {
	
	ifstream fout;
    
	// file openining
	fout.open("E:\\3rd Semester\\Data Structure\\Project\\archive\\country_wise_latest.csv");
    
    string country;
	string Confirmed;
	string Deaths;
	string Recovered;
	string Active;
	string New_cases;
	string New_deaths;
	string New_recover;
	string Confirmed_last_week;
	string one_week_change;
	string one_week_percent_increase;
	string WHO_region;

    Binary_Search_Tree *root = NULL;
	Binary_Search_Tree ob1;
    int i = 0;
	while(fout.good()) {
    	getline(fout, country, ',');
    	getline(fout, Confirmed, ',');
    	getline(fout, Deaths, ',');
    	getline(fout, Recovered, ',');
    	getline(fout, Active, ',');
    	getline(fout, New_cases, ',');
    	getline(fout, New_deaths, ',');
    	getline(fout, New_recover, ',');
    	getline(fout, Confirmed_last_week, ',');
    	getline(fout, one_week_change, ',');
    	getline(fout, one_week_percent_increase, ',');
    	getline(fout, WHO_region, '\n');
    	
		i++;
		if(i == 1) {
			cout << country << " " << Confirmed << " " << Deaths << " " << Recovered << " " << Active << " " << "NCases" << " " <<
		"NDeaths" << " " << "NRecover" << " " << "LastWeek" << " " << "Week" << " " << WHO_region << endl;
		}
		else if(root == NULL) {
    		root = CreateNode(root, country, Confirmed, Deaths, Recovered, Active, New_cases, New_deaths, New_recover, Confirmed_last_week, one_week_change, one_week_percent_increase, WHO_region);
		}
		else {
			root = CreateNode(root, country, Confirmed, Deaths, Recovered, Active, New_cases, New_deaths, New_recover, Confirmed_last_week, one_week_change, one_week_percent_increase, WHO_region);
		}
	}
	fout.close();
	
	// function calling
	ob1.Binary_Search_Tree_Inorder(root);
	
	system("Pause");
	system("cls");
	
	int num = 0;
	while(true) {
		cout << "1.Enter Country Name to Show Data " << endl << "2.Enter Country Name to delete the record "
			<< endl << "3 View Country wise Data \n 4.Exit \n Enteryour choice: ";
			cin >> num;
			switch(num) {
				case 1:
					cout << "Enter Country name: ";
					fflush(stdin);
					getline(cin, country);
					ob1.Search_Data(root, country);
					break;
				case 2:
					cout << "Enter Country name: ";
					fflush(stdin);
					getline(cin, country);
					root = ob1.Delete_Data(root, country);
					break;
				case 3:
					ob1.Binary_Search_Tree_Inorder(root);
					break;
				case 4:
					return;
			}
			system("pause");
			system("cls");
	}	
	
	
	system("pause");
	
	return; // return back
}
