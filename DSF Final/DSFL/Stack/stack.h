#ifndef STACK_H
#define STACK_H

template<class T>
struct node{
	T data;
	struct node<T> *next;
};

template<class T>
class stack
{
	node<T> * top;
	public:
		void push(T x);
		int  pop();
		int peep();
		bool IsEmpty();
		void display();
		stack();
		~stack();
	protected:
};

#endif
