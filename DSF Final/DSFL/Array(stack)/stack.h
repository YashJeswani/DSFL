#ifndef STACK_H
#define STACK_H
#define max 20

class stack
{
	int data[max];
	int top;
	public:
		stack();
		void push(int x);
		int pop();
		int peep();
		bool IsEmpty();
		void display();
		~stack();
};

#endif
