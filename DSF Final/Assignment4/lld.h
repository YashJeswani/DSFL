/*
 * lld.h
 *
 *  Created on: Dec 21, 2018
 *      Author: f9
 */

#ifndef LLD_H_
#define LLD_H_

template <class T>						//Only declerations
struct sll_node{
	T data;
  struct sll_node<T>* next;
};

template <class T>
class lld {
	sll_node<T> *head,*temp;			//Head and temp are of Ttype node*
public:
	lld();
	void display();
	int isempty();
	void insertfront(T);
	T removefirst();					//since data is poped ie. Ttype data
	T head_data();						//Since data is peeped(top element) ie.Ttype data
	virtual ~lld();
};

#endif /* LLD_H_ */
