#include <iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;

int main() {
	stack s1;
	
	s1.push(10);
	s1.push(90);
	cout<<"display"<<endl;
	s1.display();
	cout<<endl<<"poped "<<s1.pop()<<endl;
	cout<<"display"<<endl;
	s1.display();
	s1.push(14);
	s1.push(97);
	s1.push(14);
	s1.push(96);
	cout<<"display"<<endl;
	s1.display();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
	if(s1.IsEmpty())
	cout<<"Array is Empty"<<endl;
	else
	cout<<"Not Empty"<<endl;
	return 0;
}
