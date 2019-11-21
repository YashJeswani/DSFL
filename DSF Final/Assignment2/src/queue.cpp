//============================================================================
// Name        : queue.cpp
// Author      : 23125
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <iomanip>
using namespace std;
#include "qadt.cpp"

class Queue
{
	qadt Q;						//makinng class qadt object Q
public:
	Queue();					//constructor and functions 
	node input();
	bool isEmpty();
	void insert(node);
	node remove();
	void display();
};

Queue::Queue()
{
	//constructor
}

node Queue::input()					//function for inputing data
{
	return Q.get_info();			//calling  get_info function
}

bool Queue::isEmpty()
{
	return Q.IsEmpty();
}

void Queue::insert(node T)
{
	Q.enqueue(T);
}

node Queue::remove()
{
	return Q.dequeue();
}

void Queue::display()
{
	Q.display();
}

void display1(node T)
{
	cout<<setw(15)<<T.str<<setw(8)<<T.age<<setw(5)<<T.priority<<endl;
}


int main() {
	Queue q;						//making object of class Queue
		int ch;
		node T;
		do
		{
			cout<<"\nMenu\n";
			cout<<"1.Insert Patient data In List\n2.Give Treatment First To : \n3.Display\n4.Exit\n";
			cout<<"Enter your choice  :\t";
			cin>>ch;
			switch(ch)
			{
			case 1:
                       T=q.input();				//calling input function and taking information and storing it in T node
					   q.insert(T);				//inserting ie. enqueue that node
				   break;
			case 2:
			         if(!q.isEmpty())
			       {
						cout<<"\nDeleted data : \n";
						T=q.remove();				//calling dequeue function by remove funstion and deleted node infor store in T
						display1(T);				//that deleted node data is displayed
			       }
				   else
					   cout<<"\nQueue is Empty\n";
			       break;
			case 3:
			       cout<<"\nQueue is :\n";
				   q.display();
			       break;
			case 4:break;
			 
		        	default:cout<<"\nInvalid choice\n";

			}
		}while(ch!=4);
	return 0;
}

