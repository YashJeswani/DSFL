//============================================================================
// Name        : hashing.cpp
// Author      : 23270
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//hashing with chaining without replacement


#include <iostream>
using namespace std;
#include<ctype.h>
#include<string.h>
#define hash(x) x%10


 struct node
{
   long int mob;
   int chain;
   char name[10];
};
class hash
{
  public:
    node data[10];
    int i;

void initialise()
{
	for(i=0;i<10;i++)
	{
		data[i].mob=-1;
		data[i].chain=-1;
		strcpy(data[i].name,"-1");
	}
}

void disp()
{
	cout<<"\nloc\tmobile\tname\tchain";
  for(i=0;i<10;i++)
  {
    cout<<"\n"<<i<<"\t"<<data[i].mob<<"\t"<<data[i].name<<"\t"<<data[i].chain;
  }
}

int isfull()
{
	for(i=0;i<10;i++)
	{
		if((data[i].mob)==-1)
			return 0;
	}
	return 1;
}

void insert()
{
	node s;
	int loc,previous;
	if(isfull())
	{
			cout<<"\nHash table is full";

	}
	cout<<"\nEnter the mobile no and the name:";
	cin>>s.mob>>s.name;
	s.chain=-1;

	loc=hash(s.mob);

	if(data[loc].mob==-1)
	{
			data[loc]=s;
	}
	else if(loc==hash(data[loc].mob))
	{
		while(data[loc].chain!=-1)
			loc=data[loc].chain;

			previous=loc;
		while(data[loc].mob!=-1)
				loc=(loc+1)%10;

			data[loc]=s;
			data[previous].chain=loc;
	}
	else
	{
		int j=loc;
		while(data[loc].mob!=-1)
			loc=(loc+1)%10;
		data[loc]=s;
	}
}
};
int main()
{
	hash h;
	h.initialise();
	h.disp();
	while(1)
	{

		h.insert();
		h.disp();
	}
	return 0;
}
