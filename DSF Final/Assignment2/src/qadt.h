/*
 * qadt.h
 *
 *  Created on: Jan 15, 2019
 *      Author: f9
 */

#ifndef QADT_H_
#define QADT_H_
#include<string.h>
#include<iostream>
using namespace std;			//all function declerations 

struct node{
    string str;
    int age;
	int priority;
	struct node *next;
};
class qadt {
	struct node *front;
	struct node *rear;
public:
	qadt();
	node get_info();
	void enqueue(node T);
	node dequeue();
	void display();
	bool IsEmpty();
	virtual ~qadt();
};

#endif
