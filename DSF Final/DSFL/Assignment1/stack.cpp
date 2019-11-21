/*
 * stack.cpp
 *
 *  Created on: Dec 28, 2018
 *      Author: f9
 */

#include "stack.h"
#include<iostream>
using namespace std;
#include "lld.h"
#include "lld.cpp"

template<class T>
stack<T>::stack() {
	// TODO Auto-generated constructor
}
template<class T>
T stack<T>::peep()
{
	return obj.head_data();				//returning TOP element by calling Function by  obj of lld
}
template<class T>
void stack<T>::push(T a)
{
	obj.insertfront(a);
}
template<class T>
T stack<T>::pop()
{
	T x=obj.removefirst();				//since return type of removefirst is Ttype the store it in Ttype
	return x;
}
template<class T>
int stack<T>::isEmpty()
{
	if(obj.isempty())					//calling isempty function of lld by calling function by obj of lld
	{
		return 1;
	}
	return 0;
}
template<class T>
void stack<T>::displaystack()
{
	obj.display();
}
template<class T>
stack<T>::~stack() {
	// TODO Auto-generated destructor
}

