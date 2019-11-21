
#include <iostream>
using namespace std;
#include "tree.h"
#define c 5

tree::tree()
{
	root=NULL;
}

tree::~tree()
{
	
}

 void tree::display(node *root, int space)
 {
 	if(root==NULL)
 		return;

 	else
 	{
 		space+=c;
 		display(root->right,space);

 		cout<<"\n\n";
 		for(int i=0;i<space;i++)
 		 			cout<<" ";
 		cout<<root->data;
 		display(root->left,space);
 	}
 }
node* tree::maketree()
{
	node* p;
	p=new(node);				//dynamically allocating memory
	cout << "Enter item: ";
     cin >>p->data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
 void tree::insert()
{
	 int ch1;
	 int flag=0;
	if (root == NULL) {
	       root=maketree();				//creating root if not created
	    }
	else{
		node*p=root;
		do{
				cout<<"MENU \n1)Insert At Left\n2)Insert At Right\nEnter Your Choice : ";
				cin>>ch1;
				switch(ch1)
				{
				case 1:
					if(p->left==NULL)
					{
					    p->left=maketree();				//left tree
					    flag=1;
					}
					else
						p=p->left;
					break;
				case 2:
					if(p->right==NULL)
					{
						p->right=maketree();			//right tree
				      	flag=1;
					}
					else
						p=p->right;
					break;
				}

			}while(flag!=1);
	}

}
 void tree::preordertrav(node* root)
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
  int tree::count(node* root)
  {
  	int i;
  	if(root==NULL)
  	  return 0;
  	if(root->left==NULL && root->right==NULL)		//leaf nodes
  	{
  		cout<<"   "<<root->data;
  		return 1;
	}

  	i=count(root->left)+count(root->right);
  	return i;										//total leaf nodes
  }
   node* tree::copy(node* root)
   {
   	
   	node* cpyroot=NULL;							//cpyroot is root of copied tree
   	if(root!=NULL)
   	{
   	   	cpyroot=new node;						//allocating memory and making root 
   		cpyroot->left=NULL;
   		cpyroot->right=NULL;
	   cpyroot->data=root->data;
	   cpyroot->left=copy(root->left);			//calling left and right tree ie. copying left and ight tree
	   cpyroot->right=copy(root->right);		
	}
     	return cpyroot;
   	
   }
 int tree::depth(node* root)
 {
	 int lheight;
	 int rheight;
	 if(root==NULL)
		 return 0;
	 if(root->left==NULL && root->right==NULL)
         return 0;
       lheight=depth(root->left);
       rheight=depth(root->right);
	 if(lheight>rheight) {				//finding maximum height from left or right tree
		   lheight=lheight+1;
	       return lheight;
		 }
	 else{
		 rheight=rheight+1;
		 return rheight;
        }
	 }


