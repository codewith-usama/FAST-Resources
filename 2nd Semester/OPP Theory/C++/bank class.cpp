//All the banks operating in India are controlled by RBI. RBI has set a well defined guideline (e.g. minimum interest rate, minimum balance allowed, 
//maximum withdrawal limit etc) which all banks must follow. For example, suppose RBI has set minimum interest rate applicable to a saving bank account 
//to be 4% annually; however, banks are free to use 4% interest rate or to set any rates above it. Write a program to implement bank functionality in the 
//above scenario. Note: Create few classes namely Customer, Account, RBI (Base Class) and few derived classes (SBI, ICICI, PNB etc). Assume and implement 
//required member variables and functions in each class.

Hint:
Class Customer
{
//Personal Details ...
// Few functions ...
}
Class Account
{
// Account Detail ...
// Few functions ...
} 
Class RBI
{
Customer c; //hasA relationship
Account a;	//hasA relationship
..
Public double GetInterestRate() {	}
Public double GetWithdrawalLimit() {	}
}
Class SBI: public RBI
{
//Use RBI functionality or define own functionality.
} 
Class ICICI: public RBI
{
//Use RBI functionality or define own functionality.
}
