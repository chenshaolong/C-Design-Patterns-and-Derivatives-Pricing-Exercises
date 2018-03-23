// C++ Design Patterns and Derivatives Pricing---Exercise 4.1, page 83
// std::auto_ptr<> deprecated since C++11. std::unique_ptr<> should be preferred instead.

/*
Exercise 4.2 Find out about an auto ptr. 
Observe that it cannot be copied in the usual sense of copying. 
Show that a class with an auto ptr data member will need a copy constructor but not a destructor.
*/


//use of pointer
#include<iostream>
#include<memory>
using namespace std;

int main() {
	cout << "use of pointer: \n";
	int n1 = 6, n2 = 8;
	int * p1 = &n1;
	int * p2 = &n2;
	cout << "n1 = " << n1 << ", *p1 = " << *p1 << ", p1 = " << p1 << endl;
	cout << "n2 = " << n2 << ", *p2 = " << *p2 << ", p2 = " << p2 << endl;
	cout << endl;
    
	*p1 = 10;
	*p2 = *p1; 
	cout << "*p1 = " << *p1 << ", p1 = " << p1 << endl;
	cout << "*p2 = " << *p2 << ", p2 = " << p2 << endl;
	cout << endl;

	*p2 = 20;
	p1 = p2;
	cout << "*p1 = " << *p1 << ", p1 = " << p1 << endl;
	cout << "*p2 = " << *p2 << ", p2 = " << p2 << endl;
	cout << endl;

	*p1 = 88;
	cout << "*p1 = " << *p1 << ", p1 = " << p1 << endl;
	cout << "*p2 = " << *p2 << ", p2 = " << p2 << endl;
	cout << endl;


	cout << "use of auto_ptr: \n";
	std::auto_ptr<int> ap1(new int);
	*ap1.get() = 10;
    cout << "*ap1 = " << *ap1 << endl;
	std::auto_ptr<int> ap2(ap1); // (ap1 is now null-pointer auto_ptr)
	cout << "*ap2 = " << *ap2 << endl;
	cout << endl;
	
	cout << "Done.\n";
	return 0;
}