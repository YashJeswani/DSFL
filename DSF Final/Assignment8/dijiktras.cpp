//============================================================================
// Name        : dijikstras.cpp
// Author      : 23125
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include"dijiktrass.h"
int main()
{
    int u;
	dijiktrass obj;					//making object of dijiktrass class and calling following functions
	
	obj.input_edges();				//calling input_edges function
	cout<<endl;
	
	cout<<"Enter The Starting Node :: ";			//accepting starting node from which you want distances to other nodes!
	cin>>u;
	
	obj.dijiktrasalgo(u);			//calling dijikstrasalgo function
	return 0;
}
/*

Enter of vertices::5
Enter the adjacency matrix :

Enter the 0th row  Weight :: 0 10 0 30 100

Enter the 1th row  Weight :: 10 0 50 0 0

Enter the 2th row  Weight :: 0 50 0 20 10

Enter the 3th row  Weight :: 30 0 20 0 60

Enter the 4th row  Weight :: 100 0 10 60 0
  
   |0   |10  |0   |30  |100
  |10  |0   |50  |0   |0
  |0   |50  |0   |20  |10
  |30  |0   |20  |0   |60
  |100 |0  |10   |60  |0
Enter The Starting Node :: 0
 COST Matrix ::

  |9999  |10     |9999  |30   |100
  |10    |9999  |50    |9999  |9999
  |9999  |50    |9999  |20    |10
  |30    |9999  |20    |9999  |60
  |100  |9999  |10     |60    |9999
  
For 1 iteration :
0 10 9999 30 100
1 0 0 0 0
0 0 0 0 0

For 2 iteration :
0 10 60 30 100
1 1 0 0 0
0 0 1 0 0

For 3 iteration :
0 10 50 30 90
1 1 0 1 0
0 0 3 0 3

For 4 iteration :
0 10 50 30 60
1 1 1 1 0
0 0 3 0 2

 Distance Of Node 1 = 10
 path :: 1 -> 0
 Distance Of Node 2 = 50
 path :: 2 -> 3 -> 0
 Distance Of Node 3 = 30
 path :: 3 -> 0
 Distance Of Node 4 = 60
 path :: 4 -> 2 -> 3 -> 0
--------------------------------
Process exited after 53.24 seconds with return value 0
Press any key to continue . . .*/
