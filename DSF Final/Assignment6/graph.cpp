//============================================================================
// Name        : graph.cpp
// Author      : 23125
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
#include "graphadt.h"

int main() {
	graphadt g1;
	user * temp;
	int ch;
	do{
			cout<<"\n----------Menu----------\n 1)Insert Facebook User\n 2)Add Friends\n 3)Display Networks\n 4)BFS\n 5)DFS\n 6)Concept\n 7)Exits \n Enter Your Choice ::";
			cin>>ch;
			switch(ch)
			{
				case 1:
					g1.createUser();
					break;
				case 2:
					temp=g1.add_frnd();
					if(temp==NULL)
						cout<<"User OR Friend not exits"<<endl;
					else
						cout<<"Now,"<<temp->name<<" and our user are friends"<<endl;
					break;
				case 3:
					g1.display();
					break;
				case 4:
					g1.BFS();
					break;
				case 5:
					g1.DFS();
					break;
				case 6:
					g1.que(1,1,1);
					break;
				case 7:
					return 0;
				default:
					cout<<"Enter valid choice\n";

			}
		}while(1);;
	return 0;
}
