//============================================================================
// Name        : kruskal.cpp
// Author      : 23125
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct sparse{					//creating structure
	int start,end;
	int cost;
};

int main() {
	sparse obj[50];				//creating two structure objects
	sparse mst[50];

	int component[50];			//and one component array for cycle detection

	int n,e;

	cout<<"Enter THE No Of Nodes(Vertices) : ";
	cin>>n;

	cout<<"Enter THE No Of Edges : ";
	cin>>e;

	obj[0].start=n;				//taking as total no of vertices and edge+1 at oth ind
	obj[0].end=n;
	obj[0].cost=e+1;

	for(int i=1;i<=e;i++)		//taking input as edge between vertices and cost
	{
	  cout<<"Enter Which Two Vertices Have Edges : ";
	  cin>>obj[i].start>>obj[i].end;
	  cout<<"Weight Of That Edge : ";
	  cin>>obj[i].cost;
	}

	cout<<"Display : "<<endl;		//displaying that sparse matrix
	cout<<"--------------------------------"<<endl;
	cout<<"|start"<<"    "<<"|end"<<"   "<<"|Cost"<<"|   "<<endl;

	cout<<"--------------------------------"<<endl;
	for(int i=0;i<e+1;i++)
	{
		cout<<"|   "<<obj[i].start<<"      | "<<obj[i].end<<"    |"<<obj[i].cost<<"|   "<<endl;
	    if(i==0)
	    cout<<"--------------------------------"<<endl;
	}
	cout<<"--------------------------------"<<endl;
	cout<<"sorting :::"<<endl;			//sort using bubble sort

	for(int i=0;i<e-1;i++)
				{
					for(int j=1;j<=e-i-1;j++)
					{
						if(obj[j].cost > obj[j+1].cost)
						 {
							sparse temp;
							temp=obj[j];
							obj[j]=obj[j+1];
							obj[j+1]=temp;
						 }
					}
				}
	cout<<"Display : "<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"|start"<<"    "<<"|end"<<"   "<<"|Cost"<<"|   "<<endl;	//displaying sorted sparse
	cout<<"---------------------------------"<<endl;
	for(int i=0;i<e+1;i++)
		{
		cout<<"|   "<<obj[i].start<<"      | "<<obj[i].end<<"    |"<<obj[i].cost<<"|   "<<endl;
			if(i==0)
				    cout<<"------------------------------"<<endl;
		}
	cout<<"--------------------------------"<<endl;
    for(int i=1;i<=n;i++)			//taking component array of size n
    	component[i]=i;				//initialising every array element with that vertix

    cout<<"Displaying Passwise Output : "<<endl;

    for(int i=1;i<=n;i++)
    	cout<<i<<"       ";
     cout<<endl;

    mst[0].start=obj[0].start;
    mst[0].end=obj[0].end;
    mst[0].cost=obj[0].cost;

    int i=1;
    int k=1;
    int no_of_edges=n-1;  			//taking while loop of no_of_edges!=0

    while(no_of_edges!=0)
    {
    	int u=obj[i].start;			//taking vertex in u and v
    	int v=obj[i].end;

    	int cou=component[u];		//finding component of both
    	int cov=component[v];

    	if(cou!=cov)				//if its not equal
    	{
    		mst[k].start=u;			//then in mst put whole sparse ith index
    		mst[k].end=v;
    		mst[k].cost=obj[i].cost;
    		k++;

    		for(int j=1;j<=n;j++)		//**puting cou in component of that no
    		{
    			 cout<<component[j]<<"       ";      //**simply for cycle detection
    			if(component[j]==cov)
    				component[j]=cou;

    		}
    		cout<<endl;
    		no_of_edges--;
    	}
        i++;
    }
    cout<<"Display MST : "<<endl;			//we got final mst sparse
        cout<<"--------------------------------"<<endl;
        cout<<"|start"<<"    "<<"|end"<<"   "<<"|Cost"<<"|   "<<endl;
    	cout<<"--------------------------------"<<endl;
    	for(int i=0;i<k;i++)
    		{
    		cout<<"|   "<<mst[i].start<<"      | "<<mst[i].end<<"    |"<<mst[i].cost<<"|   "<<endl;
    			if(i==0)
    				    cout<<"-----------------------------"<<endl;
    		}
    	cout<<"--------------------------------"<<endl;
    	int d;						//after displaying final mst sparse
    								//finding cost
    	for(int i=1;i<k;i++)
    	{

    		d+=mst[i].cost;
    	}
    	cout<<" Total Minimum Cost Is : "<<d;		//displaying minimal cost

	return 0;
}

