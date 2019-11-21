/*
 * stack.h
 *
 *  Created on: Dec 28, 2018
 *      Author: f9
 */

#ifndef STACK_H_
#define STACK_H_
#include"lld.h"

template<class T>
class stack {
	lld<T> obj;					//making object of lld
public:
	stack();
	void push(T );				//passing Ttype data
	T pop();					//since returning data ie. Ttype data
	T peep();
	int isEmpty();
	void displaystack();
	virtual ~stack();
};

#endif /* STACK_H_ */
