#include <iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;

int main()
{
	stack s1;
	s1.push(10.27);
	s1.push(20.1);
	s1.push(89.4);
	s1.display();
	cout<<endl;
	cout<<s1.pop()<<" is poped from stack\n";
	cout<<s1.pop()<<" is poped from stack\n";
	s1.display();
	cout<<endl;
	s1.push(88.5);
	s1.push(90.8);
	s1.display();
	cout<<endl;
	cout<<"top elements is"<<s1.peep()<<endl;
	cout<<s1.pop()<<" is poped from stack\n";
	cout<<"top elements is"<<s1.peep()<<endl;
	s1.display();
	cout<<endl;
	cout<<s1.pop()<<" is poped from stack\n";
	if(s1.IsEmpty())
	cout<<"stack is underflow 1"<<endl;
	cout<<s1.pop()<<" is poped from stack\n";
	if(s1.IsEmpty())
	cout<<"stack is underflow 2"<<endl;
	return 0;
}
