//============================================================================
// Name        : cpp.cpp
// Author      : 23125
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define c 5

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
class Binary_tree {
public:
	node* root;

    Binary_tree();
   node* maketree();
    void insert();
    void preordertrav(node*);
    void display(node* ,int);
    int depth(node*);
    int count(node*);
    node* copy(node*);
};
Binary_tree::Binary_tree()
{
    root= NULL;
}
node* Binary_tree::maketree()
{
	node* p;
	p=new(node);
	cout << "Enter item: ";
     cin >>p->data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
 void Binary_tree::insert()
{
	 int ch1;
	 int flag=0;
	if (root == NULL) {
	       root=maketree();
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
					    p->left=maketree();
					    flag=1;
					}
					else
						p=p->left;
					break;
				case 2:
					if(p->right==NULL)
					{
						p->right=maketree();
				      	flag=1;
					}
					else
						p=p->right;
					break;
				}

			}while(flag!=1);
	}

}
 void Binary_tree::preordertrav(node* root)
 {

     if (root == NULL) {
         return;
     }
     else if (root != NULL) {
    	 cout <<root->data<< " ";
    	 preordertrav(root->left);
    	 preordertrav(root->right);
     }
 }
  int Binary_tree::count(node* root)
  {
  	int i;
  	if(root==NULL)
  	  return 0;
  	if(root->left==NULL && root->right==NULL)
  	{
  		cout<<"   "<<root->data;
  		return 1;
	}

  	i=count(root->left)+count(root->right);
  	return i;
  }

   node* Binary_tree::copy(node* root)
   {

   	node* cpyroot=NULL;
   	if(root!=NULL)
   	{
   	   	cpyroot=new node;
   		cpyroot->left=NULL;
   		cpyroot->right=NULL;
	   cpyroot->data=root->data;
	   cpyroot->left=copy(root->left);
	   cpyroot->right=copy(root->right);
	}
     	return cpyroot;

   }
 int Binary_tree::depth(node* root)
 {
	 int lheight;
	 int rheight;
	 if(root==NULL)
		 return 0;
	 if(root->left==NULL && root->right==NULL)
         return 0;
       lheight=depth(root->left);
       rheight=depth(root->right);
	 if(lheight>rheight) {
		   lheight=lheight+1;
	       return lheight;
		 }
	 else{
		 rheight=rheight+1;
		 return rheight;
        }
	 }


 void Binary_tree::display(node *root, int space)
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
int main() {
	Binary_tree bt;
	int ch;
	int height;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	do{
		cout<<"MENU \n1)Insert\n2)display\n3)Depht\n4)LEAF NODES\n5)Copy Of Tree\nEnter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			bt.insert();
			 bt.preordertrav(bt.root);
			 cout<<endl;
			break;
		case 2:
			  bt.display(bt.root,0);
			  //bt.preordertrav(bt.root);
			  cout<<endl;
			break;
		case 3:
			height=bt.depth(bt.root);
			cout<<"the Depth is : "<<height<<endl;
			break;
		case 4:
			cout<<"Leaf Nodes Are : ";
			int l;
			l=bt.count(bt.root);
			cout<<endl;
			cout<<"The Total Leaf Nodes Are : "<<l<<endl;
			  break;
		case 5:
			cout<<"Copy of Tree is : ";
			node* p;
			p=bt.copy(bt.root);
			bt.display(p,0);
			//bt.preordertrav(p);
			cout<<endl;
			  break;
		}

	}while(ch!=0);
}
