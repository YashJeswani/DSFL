/*
 * prims.cpp
 *
 *  Created on: 19-Mar-2019
 *      Author: f9
 */

#include<iostream>
using namespace std;
#include "prims.h"

prims::prims() 
{		// TODO Auto-generated constructor stub

}
void prims::make_graph()
{
	cout<<"\nEnter of vertices::";
	 cin>>n;
	 cout<<"Enter the adjacency matrix : ";
	 cout<<endl;
	 for(int i=0;i<n;i++)
     {
     	cout<<"\n"<<"Enter the "<<i<<"th row  Weight :: ";
     	for(int j=0;j<n;j++)
     	{
     		cin>>G[i][j];
		 }
	 }									//taking input graph edges in adjacency matrix 
	for(int i=0;i<n;i++)
     {
     	cout<<endl;
     	for(int j=0;j<n;j++)
     	{
     		cout<<"  |"<<G[i][j];			//printing it!
		 }
	 }
	
}
void prims::prim_algo()
{
	int cost[max][max],result[max][max];						//cost matrix 
    int from[max];							//used for previous node
    int dist[max],visited[max];			//distance and visited array
    int mindist,count=1,nextnode;
	int i,j,u,v,weight=0;
	for(int i=0;i<n;i++)
     {
     	for(int j=0;j<n;j++)
     	{
     		if(G[i][j]==0)
     		  cost[i][j]=9999;
     		else
     		  cost[i][j]=G[i][j];
		   
		   result[i][j]=0;	    
		 }
	 }
	 cout<<" COST Matrix :: ";
	 cout<<endl;
     for(int i=0;i<n;i++)
     {
     	cout<<endl;
     	for(int j=0;j<n;j++)
     	{
     		cout<<"  |"<<cost[i][j];			//formation of cost atrix and displaying it !
		 }
	 }
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		dist[i]=cost[0][i];
		from[i]=0;	
	}
	visited[0]=1;
	int no_of_edges=n-1;
	while(no_of_edges>0)
	{
		cout<<"\n"<<"For "<<count<<" iteration : ";        //printing for every iteration distance array 
	 	cout<<endl;
	 	 for(int i=0;i<n;i++)
	     cout<<dist[i]<<" ";
	     
	      cout<<endl;
	      
	      for(int i=0;i<n;i++)								//visited array
	     cout<<visited[i]<<" ";
	     
	     cout<<endl;
	     
	     for(int i=0;i<n;i++)								//from array
	     cout<<from[i]<<" ";
	     cout<<endl;
	     
		int min=9999;
		for(i=0;i<n;i++)
		{
			if(visited[i]==0&&dist[i]<min)
			{
				v=i;
				min=dist[i];
			}
		}
		u=from[v];
		result[u][v]=dist[v];
		result[v][u]=dist[v];
		
		visited[v]=1;
		for(i=0;i<n;i++)
		{
			if(visited[i]==0&&cost[i][v]<dist[i])
			{
				dist[i]=cost[i][v];
				from[i]=v;
			}
		}
		no_of_edges--;
		count++;
		weight+=cost[u][v];
	}
	cout<<"\nAdjacency matrix of minimum spanning tree::\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<result[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\nWeight of mimnimum spanning tree is::"<<weight;
}
prims::~prims() 
{
	// TODO Auto-generated destructor stub
}

