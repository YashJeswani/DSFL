#include<iostream>
using namespace std;
#include<stdlib.h>
#include "queue.h"

template<class T>
queue<T>::queue()
{
	front=NULL;
	rear=NULL;
}
template<class T>
queue<T>::~queue()
{
}
template<class T>
bool queue<T>::IsEmpty()
{
		if(rear==NULL)
		return true;
		return false;
}
template<class T>
void queue<T>::enqueue(T a)
{
	QNode<T> *ptr=new QNode<T>;			//making ptr node
	ptr->data=a;					//saving all information in that node
	ptr->next=NULL;
	if(front == NULL)
    {
        front = rear = ptr;
        rear->next = NULL;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = NULL;
    }
}
template<class T>
T queue<T>::dequeue()
{
    T a;						//taking node to store information about deleted node
	QNode<T>* ptr=front;
	 a=ptr->data;						//node T=*ptr means whole information of front node is now in T node
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
	return a;					//returning that node
}

