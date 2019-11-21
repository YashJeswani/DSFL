//============================================================================
// Name        : ass5.cpp
// Author      : 23125
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "bst.h"
#include "bst.cpp"
#define max 50
#include<string.h>

int main() {
	int data;
	int ch,key;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	    bst bt;
		do{
			cout<<"MENU \n1)Insert\n2)display\n3)Search\n4)delete\n5)Mirror Image\n6)LevelWise Display\nEnter Your Choice : ";
			cin>>ch;
			switch(ch)
			{
			case 1:
				cout << "Enter data: ";
				cin >>data;
				  bt.insert(bt.root,data);
				 cout<<endl;
				break;
			case 2:
				  bt.display(bt.root,0);
				  cout<<endl;
				  cout<<"preorder display is : ";
				  bt.preordertrav(bt.root);
				  cout<<endl;
				break;
			case 3:
				cout<<"Enter The Element You Want to Search : ";
				cin>>key;
				bt.searchbst(bt.root,key);
				break;
			case 4:
				cout<<"Enter The Element You Want to delete : ";
			    cin>>key;
				bt.removebst(bt.root,key);
				  break;
			case 5:
				cout<<"Mirror Image Of Tree Is : ";
				bt.mirrorimage(bt.root);
				bt.display(bt.root,0);
				cout<<endl;
				  break;
		    case 6:
				cout<<"Level Wise Display  Is : ";
				bt.levelwise(bt.root);
				cout<<endl;
				  break;
			}

		}while(ch!=0);
		return 0;
}
