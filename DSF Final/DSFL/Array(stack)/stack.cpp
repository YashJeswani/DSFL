#include <iostream>
#include "stack.h"
using namespace std;
stack::stack()
{
	top=-1;
}

void stack::push(int x)
{
	top=top+1;
	data[top]=x;
	cout<<"push"<<"  "<<top<<endl;
}

int stack::pop()
{
	int x=data[top];
	top=top-1;
	return x;
}

int stack::peep()
{
	return data[top];
}

bool stack::IsEmpty()
{
	if(top<0)
	return true;
	return false;
}

void stack::display()
{
	int i=0;
	while(i<=top)
		cout<<data[i++]<<endl;
}

stack::~stack()
{
}
