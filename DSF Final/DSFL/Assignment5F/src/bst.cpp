/*
 * bst.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: f9
 */

#include <iostream>
using namespace std;
#include "bst.h"
#include "queue.cpp"

bst::bst() {
	root=NULL;
	// TODO Auto-generated constructor stub

}

bst::~bst() {
	// TODO Auto-generated destructor stub
}


node* bst::maketree(int data)
{
	node* p;
	p=new(node);				//allocating memory dynamically
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void bst::insert(node* temp,int data)
{
	 node* p;
	if (root == NULL) {
	       root=maketree(data);		//if root is not made make root
	       return ;
	    }
	else
	{
		p=temp;
		if (data < p->data)			//if data to be insert is less
									//insert in left
		{
			if(p->left!=NULL)
				 insert(p->left,data);
			else
				p->left=maketree(data);
		}

		else						//if data to be insert is greater
									//insert in right
		{

			if(p->right!=NULL)
				  insert(p->right,data);
			else
				  p->right=maketree(data);
		}

	}
}
void bst::searchbst(node* root,int key)
{
	node* p;
	if(root==NULL)
		cout<<"Data NOT Found !  "<<endl;	//for tree not created
	else
	{
		p=root;

		if(key<p->data)
			searchbst(p->left,key);			//recurssive if data is less than root

		else if(key>p->data)				//recurssive if data is greater than root
			searchbst(p->right,key);

		else if(key==p->data){				//print it data found
			cout<<"Data Is Found ! "<<endl;
		    return;
		}
		else
			cout<<"Data NOT Found !  "<<endl;
	}
}
node* bst::findminvalue(node* T)
{
	node* current=T;					//T is keys right subtree
	while(current->left!=NULL)			//going to left upto min value is not found
		current=current->left;
	return current;
}
node* bst::removebst(node* root,int key)
{
	      if(root==NULL)
			cout<<"Data NOT Found !  "<<endl;
		 if(root->data>key)
			  root->left=removebst(root->left,key);
		 else if(root->data<key)
			 root->right=removebst(root->right,key);
		 else
		 {
			  if(root->left== NULL && root->right==NULL)  			//for leaf node
			  {
			        delete root;
			        root=NULL;
			  }

			  else if(root->left==NULL)					//for lchild ie. 1 child
			  {
				  node* p;
				  p=root;
				  root=root->right;
				  delete p;
			  }
			  else if(root->right==NULL)				//for rchild ie. 1 child
			  {
			  	 node* p;
			  	 p=root;
			  	 root=root->left;
			  	 delete p;
			  }
			  else										//for 2 child
			  {
				  node* p;
				  p=findminvalue(root->right);			//finding min and then substituting it
				  root->data=p->data;
				  root->right=removebst(root->right,p->data);  //for deleting that node call
			  }
		}
		 return root;								//return statement for making NULL
}
void bst::mirrorimage(node* root)
{
	node* temp;
	node* p=root;
	if(root==NULL)
		return;
	else{

		temp=p->right;						//storin right in temp
		p->right=p->left;					//making right as left
		p->left=temp;						//making left as right
		mirrorimage(p->left);				//calling recurssively
		mirrorimage(p->right);
	}
}
void bst::preordertrav(node* root)
 {

     if (root == NULL) {
         return;
     }
     else if (root != NULL) {		//root left right (pre)
    	 cout <<root->data<< " ";
    	 preordertrav(root->left);
    	 preordertrav(root->right);
     }
 }
 void bst::levelwise(node* root)
 {
 	queue<node*>q;
 	if(root==NULL)
 	    cout<<"Tree is Empty ! ";
 	else
 	{
 		q.enqueue(root);			//enqueuing root
 		while(!q.IsEmpty())				//upto queue is not empty
 		{
 			node* T=q.dequeue();		//dequeuing and printing it
 			cout <<T->data<< " ";
 			if(T->left!=NULL)
 			    q.enqueue(T->left);		//first enqueuing left because it wl be printed frst
 			if(T->right!=NULL)
 			     q.enqueue(T->right);
		 }

	 }
 }
 void bst::display(node *root, int space)
  {
  	if(root==NULL)
  		return;

  	else
  	{
  		space+=5;
  		display(root->right,space);

  		cout<<"\n\n";
  		for(int i=0;i<space;i++)
  		 			cout<<" ";
  		cout<<root->data;
  		display(root->left,space);
  	}
  }
