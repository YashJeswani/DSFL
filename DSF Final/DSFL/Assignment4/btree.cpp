
/*
 * btree.cpp
 *
 *  Created on: 16-Jan-2019
 *      Author: f9
 */
#include<iostream>
#include "btree.h"
#include "stack.h"
#include "stack.cpp"

using namespace std;


btree::btree() {
	// TODO Auto-generated constructor stub
	root=NULL;

}


btree::~btree() {
	// TODO Auto-generated destructor stub
}


bTreenode* btree::maketree(char x)
{
  bTreenode* p=NULL;
  p=new bTreenode;						//allocating memory
  p->data=x;
  p->left=NULL;
  p->right=NULL;
  return p;

}


void btree::create_exptree_post()
{
	string post;
	stack<bTreenode*>s;							//taking stack of nodeptr
	cout<<"Enter postfix expression : ";		//accepting postfix expresssion
	cin>>post;

	int i=0;
	while(post[i]!='\0')
	{
		char x=post[i];

		if(isOperand(x))
		{
			bTreenode* temp=maketree(x);			//if its operand the push it into stack
			s.push(temp);
		}

		if(isOperator(x))							//if its operator as + - * / then make 
														//top 2 elements as left and right of that operator
		{
			bTreenode* temp=maketree(x);
			temp->right=s.pop();
			temp->left=s.pop();
			s.push(temp);
		}

		i++;
	}

   root=s.pop();										//return root for traversals 
}




void btree::dispinorder(bTreenode* p)					//recurssive inorder left visit right
{
	if(p!=NULL)
	{
		dispinorder(p->left);
	    cout<<p->data<<" ";
		dispinorder(p->right);
	}
}

void btree::disppreorder(bTreenode* p)					//recurssive inorder  visit left right
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		disppreorder(p->left);
		disppreorder(p->right);
	}
}


void btree::disppostorder(bTreenode* p)						//recurssive inorder left  right  visit
 {
	if(p!=NULL)
	{
		disppostorder(p->left);
		disppostorder(p->right);
		cout<<p->data<<" ";
	}
}


void btree::dispInorderNonRec()			//left visit right 
{
	bTreenode* p=root;
	stack<bTreenode*>s;
	if(p==NULL)
	{
		cout<<"Empty";
		return;
	}
	do
	{
		while(p!=NULL)					//pushing all nodeptr including root and left all
		{
			s.push(p);
			p=p->left;
		}
		if(!s.isEmpty())				
		{
			p=s.pop();
			cout<<p->data<<" ";				//displaying leftmost element in tree then root display and push right

				p=p->right;
		}

	}while(p!=NULL || (!s.isEmpty()));
}


void btree::dispPreorderNonRec()			//visit left right
{
	stack<bTreenode*>s;
	bTreenode* p=root;
	if(p==NULL)
	{
		cout<<"Empty";
		return;
	}

	s.push(p);									//pushing root element

	while(!s.isEmpty())
	{
		p=s.pop();
		cout<<p->data<<" ";						//visiting first root then pushing right first and then left


		if(p->right!=NULL)						//first right will be pushed so check first right
			s.push(p->right);
		if(p->left!=NULL)
			s.push(p->left);

	}
}

void btree::disppostorderNonRec()					//Imp
{
	stack<bTreenode*>s;
	bTreenode* p=root;
	bTreenode* prev=NULL;							//for storing prev so to visit right after left

	if(p==NULL)
	  {
		 cout<<"Empty";
		 return;
	  }

	s.push(p);

	while((!s.isEmpty()))
	{

			p=s.pop();									//popping root which is pushed before only

			if(p->right==NULL && p->left==NULL)			//if its leaf node then print it
			{
				prev=p;									//make prev as it before printing it
				cout<<p->data<<" ";
			}
			else
			{
				if(p->right==prev || p->left==prev)		// after printing checking as prev to print left then right then root
				{
					prev=p;
					cout<<p->data<<" ";
				}
				else
				{
					s.push(p);							//pushing elements in stack to come first at leftmost
					if(p->right!=NULL)					// and printing right using pre and then root 
						s.push(p->right);				//first moving right to stack then left because we frst print leftmost
					if(p->left!=NULL)
						s.push(p->left);
				}
			}

	}

}

bool btree::isOperand(char x)
{
	if((x>='0' && x<='9')|| (x>='a' && x<='z')||(x>='A' && x<='Z'))
			return true;
	else
		return false;
}


bool btree::isOperator(char x)
{
	if(x=='^' || x=='*' || x=='/' || x=='+' || x=='-' || x=='%' )
		return true;
	else
		return false;
}


