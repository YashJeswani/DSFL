/*
 * qadt.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: f9
 */
#include<iostream>
#include <iomanip>
using namespace std;
#include "qadt.h"
#include<stdlib.h>
#include<string.h>


qadt::qadt() {
	// TODO Auto-generated constructor stub
   front=NULL;
   rear=NULL;
}
node qadt::get_info()			//calling get info and taking all information about data
{
	node T;
	    cout<<"\nEnter data   :\n";
		cout<<"\nEnter name         :  ";
	    cin>>T.str;
	    cout<<"\nEnter age          :  ";
	    cin>>T.age;
		cout<<"Enter priority  \n1.General\n2.Medium\n3.Emergency\n";
		cin>>T.priority;
	    T.next=NULL;
	return T;					//returning that node
}


bool qadt::IsEmpty()
{
		if(rear==NULL)
		return true;
		return false;
}
void qadt::enqueue(node T)
{
	node *ptr=new node();			//making ptr node
	ptr->str=T.str;
	ptr->priority=T.priority;		//saving all information in that node
	ptr->age=T.age;
	ptr->next=NULL;
	if(front==NULL)
	{
		front=ptr;
		rear=ptr;
	}
	else
	{
		node *temp=front;

		 if (temp->priority < ptr->priority) {

		       							 // Insert New Node before head
		        ptr->next =temp;
		        front = ptr;
		    }
		    else {

		       								 // Traverse the list and find a
		       								 // position to insert new node
		        while (temp->next != NULL &&
		               temp->next->priority > ptr->priority ) {
		            temp= temp->next;
		        }

		       							 // Either at the ends of the list
		        						// or at required position
		        ptr->next = temp->next;
		        temp->next = ptr;

		    }
     }
}
node qadt::dequeue()
{
	node T;						//taking node to store information about deleted node
	node* ptr=front;
	T=*ptr;						//node T=*ptr means whole information of front node is now in T node
	if(front==NULL && rear==NULL)
		cout<<"Queue is Empty";
	else if(front==rear)
	{
		   delete front ;
		   front=rear=NULL;
	}
	else
	{
		front=front->next;
		delete ptr;

	}
	return T;					//returning that node
}
void qadt::display()
{
	node *temp=front;
	while(temp!=NULL)
	{
		cout<<setw(15)<<temp->str<<setw(8)<<temp->age<<setw(5)<<temp->priority<<endl;
		temp=temp->next;
	}
	cout<<"\n\n";
}
qadt::~qadt() {
	// TODO Auto-generated destructor stub
}
