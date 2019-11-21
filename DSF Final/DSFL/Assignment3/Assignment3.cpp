#include <iostream>
using namespace std;
#include "tree.h"
#include "tree.cpp"

int main() {
	tree bt;
	int ch;
	int height;
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
		      cout<<endl;
		      cout<<"preorder display is : ";
			  bt.preordertrav(bt.root);
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
		    cout<<endl;
		    cout<<"preorder display is : ";
			bt.preordertrav(p);
			cout<<endl;			
			  break;
		}

	}while(ch!=0);
}
/*

                  10
         9                 8
    7        6        5          4
3      2 

MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 1
Enter item: 10
10
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
Enter item: 9
10 9
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 2
Enter item: 8
10 9 8
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
Enter item: 7
10 9 7 8
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 2
Enter item: 6
10 9 7 6 8
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 2
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
Enter item: 5
10 9 7 6 8 5
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 2
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 2
Enter item: 4
10 9 7 6 8 5 4
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
Enter item: 3
10 9 7 3 6 8 5 4
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 1
MENU
1)Insert At Left
2)Insert At Right
Enter Your Choice : 2
Enter item: 2
10 9 7 3 2 6 8 5 4
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 2


               4

          8

               5

     10

               6

          9

                    2

               7

                    3
preorder display is : 10 9 7 3 2 6 8 5 4
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 3
the Depth is : 3
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 4
Leaf Nodes Are :    3   2   6   5   4
The Total Leaf Nodes Are : 5
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice : 5
Copy of Tree is :

               4

          8

               5

     10

               6

          9

                    2

               7

                    3
preorder display is : 10 9 7 3 2 6 8 5 4
MENU
1)Insert
2)display
3)Depht
4)LEAF NODES
5)Copy Of Tree
Enter Your Choice :                         
 */
