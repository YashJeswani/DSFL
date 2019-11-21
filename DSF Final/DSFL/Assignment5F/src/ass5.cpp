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
#define max 50
#include<string.h>

int main() {
	int data;
	int ch,key;
	cout << "!!!Hello World!!!" << endl;
	    bst bt;
		do{
			cout<<"MENU \n1)Insert\n2)display\n3)Search\n4)delete\n5)Mirror Image\n6)LevelWise Display\nEnter Your Choice : ";
			cin>>ch;
			switch(ch)
			{
			case 1:
				cout << "Enter data: ";
				cin >>data;
				  bt.insert(bt.root,data);		//calling insert function
				 cout<<endl;
				break;
			case 2:
				  bt.display(bt.root,0);
				  cout<<endl;
				  cout<<"preorder display is : ";   //calling display function
				  bt.preordertrav(bt.root);
				  cout<<endl;
				break;
			case 3:
				cout<<"Enter The Element You Want to Search : ";
				cin>>key;
				bt.searchbst(bt.root,key);			//calling search function
				break;
			case 4:
				cout<<"Enter The Element You Want to delete : ";
			    cin>>key;
				bt.removebst(bt.root,key);          //calling remove function
				  break;
			case 5:
				cout<<"Mirror Image Of Tree Is : ";
				bt.mirrorimage(bt.root);			//calling mirror imgage function
				bt.display(bt.root,0);
				cout<<endl;
				  break;
		    case 6:
				cout<<"Level Wise Display  Is : ";
				bt.levelwise(bt.root);				//calling levelwise function
				cout<<endl;
				  break;
			}

		}while(ch!=0);
		return 0;
}
/*
yash_2420@yash-Inspiron-15-3567:~/Assignment5F/src$ g++ ass5.cpp bst.cpp
yash_2420@yash-Inspiron-15-3567:~/Assignment5F/src$ ./a.out
!!!Hello World!!!
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 10

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 5

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 15

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 3

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 7

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 12

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 18

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 1

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 4

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 6

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 9

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 11

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 14

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 16

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 19

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 2


                    19

               18

                    16

          15

                    14

               12

                    11

     10

                    9

               7

                    6

          5

                    4

               3

                    1
preorder display is : 10 5 3 1 4 7 6 9 15 12 11 14 18 16 19 
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 2

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 2


                    19

               18

                    16

          15

                    14

               12

                    11

     10

                    9

               7

                    6

          5

                    4

               3

                         2

                    1
preorder display is : 10 5 3 1 2 4 7 6 9 15 12 11 14 18 16 19 
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 1
Enter data: 13

MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 2


                    19

               18

                    16

          15

                    14

                         13

               12

                    11

     10

                    9

               7

                    6

          5

                    4

               3

                         2

                    1
preorder display is : 10 5 3 1 2 4 7 6 9 15 12 11 14 13 18 16 19 
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 3
Enter The Element You Want to Search : 1
Data Is Found ! 
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 3
Enter The Element You Want to Search : 8
Data NOT Found !  
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 4
Enter The Element You Want to delete : 2
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 2


                    19

               18

                    16

          15

                    14

                         13

               12

                    11

     10

                    9

               7

                    6

          5

                    4

               3

                    1
preorder display is : 10 5 3 1 4 7 6 9 15 12 11 14 13 18 16 19 
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 4
Enter The Element You Want to delete : 3
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 2


                    19

               18

                    16

          15

                    14

                         13

               12

                    11

     10

                    9

               7

                    6

          5

               4

                    1
preorder display is : 10 5 4 1 7 6 9 15 12 11 14 13 18 16 19 
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 4
Enter The Element You Want to delete : 6
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 2


                    19

               18

                    16

          15

                    14

                         13

               12

                    11

     10

                    9

               7

          5

               4

                    1
preorder display is : 10 5 4 1 7 9 15 12 11 14 13 18 16 19 
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 6
Level Wise Display  Is : 10 5 15 4 7 12 18 1 9 11 14 16 19 13 
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : 5
Mirror Image Of Tree Is : 

                    1

               4

          5

               7

                    9

     10

                    11

               12

                         13

                    14

          15

                    16

               18

                    19
MENU 
1)Insert
2)display
3)Search
4)delete
5)Mirror Image
6)LevelWise Display
Enter Your Choice : */                                                                                           

