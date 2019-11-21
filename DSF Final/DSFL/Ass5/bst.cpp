/*
 * bst.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: f9
 */

#include <iostream>
using namespace std;
#include "bst.h"
#include "queue.h"
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
	p=new(node);
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void bst::insert(node* temp,int data)
{
	 int ch1;
	 node* p;
	if (root == NULL) {
	       root=maketree(data);
	       return ;
	    }
	else
	{
		p=temp;
		if (data < p->data)
		{
			if(p->left!=NULL)
				 insert(p->left,data);
			else
				p->left=maketree(data);
		}

		else
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
		cout<<"Data NOT Found !  "<<endl;
	else
	{
		p=root;

		if(key<p->data)
			searchbst(p->left,key);

		else if(key>p->data)
			searchbst(p->right,key);

		else if(key==p->data){
			cout<<"Data Is Found ! "<<endl;
		    return;
		}
	}
}
void bst::removebst(node* root,int key)
{
	node* p;
		if(root==NULL)
			cout<<"Data NOT Found !  "<<endl;
		else{
			p=root;
			/*if(p->left== NULL && p->right==NULL)
			{
			     if(root==p)
			    	 root = NULL;
			     else if(p==pre->right)
			    	 p->right=NULL;
			     else
			    	 p->left=NULL;
			}*/



		}
}
void bst::mirrorimage(node* root)
{
	node* temp;
	node* p=root;
	if(root==NULL)
		return;
	else{

		temp=p->right;
		p->right=p->left;
		p->left=temp;
		mirrorimage(p->left);
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
 		q.enqueue(root);
 		while(!q.IsEmpty())
 		{
 			node* T=q.dequeue();			//suppose tree                        10
 			cout <<T->data<< " ";								//5                                   15
 			if(T->left!=NULL)						//3                  8                  12                17
 			    q.enqueue(T->left);			//1             4        6       9         11        13       16      18
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
