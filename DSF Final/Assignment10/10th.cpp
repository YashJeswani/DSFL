//============================================================================
// Name        : 10th.cpp
// Author      : Yash Jeswani
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"prims.h"
using namespace std;

int main() 
{
	prims obj;
	
	obj.make_graph();
		cout<<endl;
	obj.prim_algo();
	return 0;
}
/*

Enter of vertices::6
Enter the adjacency matrix :

Enter the 0th row  Weight :: 0
3
1
6
0
0

Enter the 1th row  Weight :: 3
0
5
0
3
0

Enter the 2th row  Weight :: 1
5
0
5
6
4

Enter the 3th row  Weight :: 6
0
5
0
0
2

Enter the 4th row  Weight :: 0
3
6
0
0
6

Enter the 5th row  Weight :: 0
0
4
2
6
0

  |0  |3  |1  |6  |0  |0
  |3  |0  |5  |0  |3  |0
  |1  |5  |0  |5  |6  |4
  |6  |0  |5  |0  |0  |2
  |0  |3  |6  |0  |0  |6
  |0  |0  |4  |2  |6  |0
 COST Matrix ::

  |9999  |3  |1  |6  |9999  |9999
  |3  |9999  |5  |9999  |3  |9999
  |1  |5  |9999  |5  |6  |4
  |6  |9999  |5  |9999  |9999  |2
  |9999  |3  |6  |9999  |9999  |6
  |9999  |9999  |4  |2  |6  |9999
For 1 iteration :
9999 3 1 6 9999 9999
1 0 0 0 0 0
0 0 0 0 0 0

For 2 iteration :
9999 3 1 5 6 4
1 0 1 0 0 0
0 0 0 2 2 2

For 3 iteration :
9999 3 1 5 3 4
1 1 1 0 0 0
0 0 0 2 1 2

For 4 iteration :
9999 3 1 5 3 4
1 1 1 0 1 0
0 0 0 2 1 2

For 5 iteration :
9999 3 1 2 3 4
1 1 1 0 1 1
0 0 0 5 1 2

Adjacency matrix of minimum spanning tree::
0       3       1       0       0       0
3       0       0       0       3       0
1       0       0       0       0       4
0       0       0       0       0       2
0       3       0       0       0       0
0       0       4       2       0       0

Weight of mimnimum spanning tree is::13
*/
