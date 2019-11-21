/*
 * dijiktrass.cpp
 *
 *  Created on: Mar 19, 2019
 *      Author: f9
 */

#include <iostream>
using namespace std;
#include "dijiktrass.h"

dijiktrass::dijiktrass() {
												// TODO Auto-generated constructor stub
     n=0;
}

void dijiktrass::input_edges()
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
void dijiktrass::dijiktrasalgo(int startnode)
{
  int cost[max][max];						//cost matrix 
  int pred[max];							//used for previous node
  int distance[max],visited[max];			//distance and visited array
  int mindist,count,nextnode;
  for(int i=0;i<n;i++)
     {
     	for(int j=0;j<n;j++)
     	{
     		if(G[i][j]==0)
     		  cost[i][j]=9999;
     		else
     		  cost[i][j]=G[i][j]; 
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
	 for(int i=0;i<n;i++)						//initialising distance and visited and pred as given below
	 {
	 	distance[i]=cost[startnode][i];
	 	visited[i]=0;
	 	pred[i]=startnode;
	 }
	 distance[startnode]=0;						//making as distance of startnode as 0 and visited of startnode as 1
	 visited[startnode]=1;
	 count=1;
	 while(count<n)
	 {
	 	cout<<"\n"<<"For "<<count<<" iteration : ";        //printing for every iteration distance array 
	 	cout<<endl;
	 	 for(int i=0;i<n;i++)
	     cout<<distance[i]<<" ";
	     
	      cout<<endl;
	      
	      for(int i=0;i<n;i++)								//visited array
	     cout<<visited[i]<<" ";
	     
	     cout<<endl;
	     
	     for(int i=0;i<n;i++)								//pred array
	     cout<<pred[i]<<" ";
	     
	 	mindist=9999;
	 	for(int i=0;i<n;i++)								//loop for finding minimum distance from distance array
	 	{
	 		if(distance[i]<mindist && !visited[i])
	 		    {
	 		    	mindist=distance[i];
	 		    	nextnode=i;
				 }
		 }
		 visited[nextnode]=1;
		 for(int i=0;i<n;i++)								//this loop for better path exist from next node
		 {
		 	if(!visited[i])
		 		if(mindist+cost[nextnode][i]<distance[i])
		 		{		 		   
				 distance[i]=mindist+cost[nextnode][i];
				  pred[i]=nextnode;
			    }    
	     }
	     count++;											//checking for next count
	 }
	 for(int i=0;i<n;i++)
	 {
	 	 if(i!=startnode)
	 	 {
	 	 	cout<<"\n Distance Of Node "<<i<<" = "<<distance[i];		//printing shortest distance from start node to other 
	 	 	cout<<"\n path :: "<<i;										//printing path using pred array resp
	 	 	int j=i;
	 	 	do{
	 	 		j=pred[j];
	 	 		cout<<" -> "<<j;
			  }while(j!=startnode);
		  }
     }	 
}

dijiktrass::~dijiktrass() {
	// TODO Auto-generated destructor stub
}
