//============================================================================
// Name        : Assignment4.cpp
// Author      : yash
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "btree.h"
#include "btree.cpp"

int main() {

	btree b;

	int ch;

	do{
		cout<<"\nMenu\n1:Create tree from post\n2:Display Recursive\n3:Display NonRecursive\n4:exit\n";
		cout<<"Enter choice\n";
		cin>>ch;
	switch(ch)
	{

		case 1: b.create_exptree_post();
				break;

		case 2: cout<<"\nInorder Display : ";
					b.dispinorder(b.root);
				cout<<"\nPreorder Display : ";
				    b.disppreorder(b.root);
				cout<<"\nPostorder Display : ";
					b.disppostorder(b.root);
				break;

		case 3: cout<<"\nInorder Non-Recursive Display : ";
					b.dispInorderNonRec();
				cout<<"\nPreorder Non-Recursive Display : ";
					b.dispPreorderNonRec();
				cout<<"\nPostorder Non-Recursive Display : ";
					b.disppostorderNonRec();
				break;

	}
	}while(ch!=0);
	return 0;
}

