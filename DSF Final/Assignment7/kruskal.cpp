/*
 * kruskal.cpp
 *
 *  Created on: 05-Mar-2019
 *      Author: f9
 */

#include "kruskal.h"
#include<iostream>
using namespace std;
kruskal::kruskal()
{
	// TODO Auto-generated constructor stub

}
void kruskal::input_edges()
{
	int n,u,v,w,k=1,i;
	cout<<"\nEnter of vertices::";
	cin>>n;
	elist1[0].start=elist1[0].end=n;
	cout<<"\n**Enter edges**";
	while(1)
	{
		cout<<"\nEnter start::";
		cin>>u;
		elist1[k].start=u;
		cout<<"\nEnter end::";
		cin>>v;
		elist1[k].end=v;
		cout<<"\nEnter weight::";
		cin>>w;
		if(w<0)
		{
			break;
		}
		elist1[k++].weight=w;
	}
	elist1[0].weight=k-1;

}
void kruskal::kruskalalgo()
{
	int component[10];
	int u,v,i,j,k,no_of_edges,cou,cov,cost=0;
	for(i=1;i<=elist1[0].start;i++)
	{
		component[i]=i;
	}
	for(i=1;i<=elist1[0].weight;i++)
	{
		for(j=i+1;j<=elist1[0].weight;j++)
		{
			if(elist1[j].weight<elist1[i].weight)
			{
				edge temp;
				temp=elist1[i];
				elist1[i]=elist1[j];
				elist1[j]=temp;
			}
		}
	}
	cout<<"\nsorted lists";
	for(i=0;i<=elist1[0].weight;i++)
	{
		cout<<"\n"<<elist1[i].start<<"\t"<<elist1[i].end<<"\t"<<elist1[i].weight;
	}
	no_of_edges=(elist1[0].start)-1;
	i=1;
	k=1;
	//cout<<no_of_edges;
	elist2[0].weight=no_of_edges;
	elist2[0].start=elist2[0].end=elist1[0].start;
	cout<<"\ncomponent array::";
	while(no_of_edges!=0)
	{
		u=elist1[i].start;
		v=elist1[i].end;
		cou=component[u];
		cov=component[v];
		if(cou!=cov)
		{
			elist2[k].start=u;
			elist2[k].end=v;
			elist2[k].weight=elist1[i].weight;
			k++;
			for(j=1;j<=elist1[0].start;j++)
			{
				if(component[j]==cov)
					component[j]=cou;
			}
			no_of_edges--;
		}
		i++;
		cout<<"\n";
		for(j=1;j<=elist1[0].start;j++)
		{
			cout<<component[j]<<"\t";
		}
	}
	cout<<"\nFinal mst list";
	for(i=0;i<=elist2[0].weight;i++)
	{
			cout<<"\n"<<elist2[i].start<<"\t"<<elist2[i].end<<"\t"<<elist2[i].weight;
			cost=cost+elist2[i+1].weight;
	}
	cout<<"\n cost of mst::"<<cost;

}
kruskal::~kruskal()
{
	// TODO Auto-generated destructor stub
}


