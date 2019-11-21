//============================================================================
// Name        : hashing.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//hashing with chaining without replacement


#include <iostream>
using namespace std;
#include<ctype.h>
#include<string.h>

#define hash(x) x%10		//macro function of hash

 struct node				//structure decleration
{
   long int mob;
   int chain;
   int flag;
   char name[10];
};

class hash
{
  public:
    node data[10];				//class decleration and members decleration
    int i;
    int check=1;
void initialise()				//function defination initialise
{
	for(i=0;i<10;i++)
	{
		data[i].mob=-1;
		data[i].flag=0;
		data[i].chain=-1;
		strcpy(data[i].name,"-1");
	}
}

void disp()						//function defination disp
{
	cout<<"\nloc\tmobile\tname\tchain\tflag";
  for(i=0;i<10;i++)
  {
    cout<<"\n"<<i<<"\t"<<data[i].mob<<"\t"<<data[i].name<<"\t"<<data[i].chain<<"\t"<<data[i].flag;
  }
}

int isfull()					//function defination isfull
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
	int count;
	int loc,previous;
	if(isfull())					//first check is hash table full
	{
			cout<<"\nHash table is full";
			check=0;

	}
	cout<<"\nEnter the mobile no and the name:";
	cin>>s.mob>>s.name;
	s.chain=-1;						//taking input

	loc=hash(s.mob);				//finding hash

	if(data[loc].flag==0)			//if flag bit is 0 ie. on that loc no number is present
	{
			data[loc]=s;
			data[loc].flag=1;
	}
	else if(loc==hash(data[loc].mob))		//if loc is equal to hash of that loc number
	{
		count=0;
		int j=loc;
		while(data[j].flag==1 && count<10)		//finding empty location
			j=(j+1)%10; count++;

        if(count==10)
        	cout<<"Hash Table Is Full ! "<<endl;

		while(data[loc].chain!=-1)
				loc=data[loc].chain;

			data[j]=s;							//copying whole structure taken inputed
			data[j].flag=1;						//at empty loc and flag bit set

			data[loc].chain=j;					//changing chain block
	}
	else
	{
		count=0;
		int j=loc;
		while(data[j].flag==1 && count<10)		//finding empty location
			j=(j+1)%10; count++;

		 if(count==10)
		     cout<<"Hash Table Is Full ! "<<endl;

		 i=hash(data[loc].mob);					//i pointing to hashed loc mob no

		 while(data[i].chain!=loc)
			 i=data[i].chain;					//changing until chain equal to loc

		 data[i].chain=data[loc].chain;

		 while(data[i].chain!=-1)
		 	i=data[i].chain;

		 data[j]=data[loc];					//on empty location copying whole structure which points on loc
		 data[j].chain=-1;
		 data[j].flag=1;					//setting flag bit

		 data[i].chain=j;					//chainging original ith position chain equal to empty location


		 data[loc]=s;
		 data[loc].flag=1;					//writing whole structre inputted
		 	 	 	 	      //at location because its with replacement and setting flag bit
	}
}
};
int main()
{
	hash h;
	h.initialise();
	h.disp();							//iuntialising call and display function
	while(h.check)
	{

		h.insert();						//calling insert function and display function
		h.disp();
	}
	return 0;
}
