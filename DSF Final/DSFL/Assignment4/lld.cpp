/*
 * lld.cpp
 *
 *  Created on: Dec 21, 2018
 *      Author: f9
 */

#include "lld.h"
#include<iostream>
using namespace std;

template<class T>
int lld<T>::isempty()
{
	if(head==NULL) 
	{
		return 1;				//ie. stack is empty
	}
	return 0;
}
template <class T>
lld<T>::lld() {
	// TODO Auto-generated constructor stub
	  head=NULL;
	  temp=NULL;
}
template<class T>
T lld<T>::head_data()      //printing topside data ie.peep
{
	return head->data;
}

template <class T>
void lld<T>::insertfront(T x)		//making as Template passing Ttype data
{
	sll_node<T>* temp=NULL;
	temp=new sll_node<T>;			//Allocating dynamically memory as Template
	temp->data=x;
	temp->next=head;
	head=temp;
}


template <class T>
T  lld<T>::removefirst()
{
	    T x;							//since data is Ttype so store data in Ttype only
	    sll_node<T>* temp=head;         //temp pointing to head
	    x=head->data;					//storing top element to x;
		head=temp->next;
		delete temp;
		return x;
}


template <class T>
void lld<T>::display()
{
	sll_node<T>* temp=head;
		cout<<"the list is : ";
		do{
			cout<<temp->data<<"-->>";
			temp=temp->next;
		}while(temp!=NULL);

}
template <class T>
lld<T>::~lld() {
	// TODO Auto-generated destructor stub
}

