#include "stack.h"
#include <iostream>
using namespace std;

template<class T>
node<T> * getnode(T x)
{
	node<T> *temp;
	temp=new(node<T>);
	temp->data=x;
	temp->next=NULL;	
	return temp;
}

template<class T>
void stack<T>::push(T x)				//Insert At beg in linked list having head(Top)
{
	node<T> *temp=getnode(x);
	temp->next=top;
	top=temp;
	cout<<"Pushed\t"<<x<<endl;
}

template<class T>
int stack<T>::pop()
{
	node<T> *temp=top;
	int x=temp->data;
	top=top->next;
	delete temp;
	return x;	
}

template<class T>
int stack<T>::peep()
{
	node<T> *temp=top;
	return temp->data;
}

template<class T>
bool stack<T>::IsEmpty()
{
	node<T> *temp=top;
	if(top==NULL)
	return true;
	return false;
}

template<class T>
void stack<T>::display()
{
	node<T> *temp=top;
	while(temp!=NULL)
	{
		cout<<"\n"<<temp->data;
		temp=temp->next;
	}
	cout<<"\n";
}

template<class T>
stack<T>::stack()
{
	top=NULL;
}

template<class T>
stack<T>::~stack()
{
}
