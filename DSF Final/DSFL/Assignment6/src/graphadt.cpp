/*
 * graphadt.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: f9
 */
#include <iostream>
using namespace std;
#include "graphadt.h"
#include <iomanip>
#include <queue>
#include <stack>

user * getnode_user(int x)
{
	user *temp;
	string name;
	temp =new (user);
	cout<<"Enter the user name"<<endl;
	cin>>name;
	cout<<"Enter the DOB(dd mm yyyy)"<<endl;
	cin>>temp->date.day>>temp->date.month>>temp->date.year;
	temp->name=name;
	temp->id=x;
	temp->link=NULL;
	temp->dlink=NULL;
	return temp;
}
int max_find(int a[],int size){
	int i=0,j=0;
	int max=a[i];
	int first=a[i];
	int flag=1;
	for(int i=1;i<size;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			j=i;
		}
		if(first==a[i])
			flag++;
	}
	if(flag==size)
	return -1;
	else
	return j;
}
void graphadt::DFS()
{
	bool visited[fb_user]={0};
	user * temp=user_head;
	stack <user*> q1;
	frnd *f;
	visited[temp->id]=true;
	q1.push(temp);

	while(!q1.empty()){
		temp=q1.top();
		cout<<temp->name<<" - ";
		f=temp->link;
		q1.pop();
		while(f!=NULL)
		{
			if(visited[f->id_user_frnd->id]==0){
				q1.push(f->id_user_frnd);
				visited[f->id_user_frnd->id]=1;
			}
			f=f->next;	
		}
	}
	cout<<endl;
}

void graphadt::que(bool comments,bool friends,bool dob)
{
	bool visited[fb_user]={0};
	int maximum_com[fb_user]={0};
	int maximum_frnd[fb_user]={0};
	user* DOB_user[fb_user];
	user * temp=user_head;
	int month=0;
	int d_count=0;
	queue <user*> q1;
	frnd *f;

	if(dob){
		cout<<"\nEnter the month to check for Birthday::";
		cin>>month;
	}

	visited[temp->id]=true;
	q1.push(temp);

	while(!q1.empty()){
		temp=q1.front();
		f=temp->link;
		if(temp->date.month==month)
			DOB_user[d_count++]=temp;
		q1.pop();
		while(f!=NULL){
			maximum_com[temp->id]=maximum_com[temp->id]+f->com;
			maximum_frnd[temp->id]++;
			if(visited[f->id_user_frnd->id]==0){
				q1.push(f->id_user_frnd);
				visited[f->id_user_frnd->id]=1;
			}
			f=f->next;
		}
	}
	if(comments)
	{
		int c=max_find(maximum_com,fb_user);
		cout<<"1)User having maximun comments recieved : "<<endl;
		cout<<"Answer ==>"<<endl;
		for(int i=0;i<fb_user;i++)
			cout<<maximum_com[i]<<"-";
		cout<<endl;
		if(c!=-1)
		{
			int id=c;
			temp=user_head;
			while(temp->id!=id){
				temp=temp->dlink;
			}
			cout<<"'"<<temp->name<<"' have maximum comments received .\n\n";
		}
		else
			cout<<"All user have same number of comments received \n\n";
	}
	if(friends)
	{
		int c1=max_find(maximum_frnd,fb_user);
		cout<<"2)User having maximun number of friends  : "<<endl;
		cout<<"Answer ==>"<<endl;
		for(int i=0;i<fb_user;i++)
			cout<<maximum_frnd[i]<<"-";
		if(c1!=-1)
		{
			int id=c1;
			temp=user_head;
			while(temp->id!=id){
				temp=temp->dlink;
			}
			cout<<"'"<<temp->name<<"' have maximum number of friends\n\n";
		}
		else
			cout<<"All user have same number of friends \n\n";
	}
	if(dob)
	{
		cout<<"3)Birthday of user in particular months : "<<endl;
		cout<<"Answer ==>"<<endl;

		if(d_count==0)
			cout<<"There are nobody having Birthday in month "<<month<<endl;
		else{
			cout<<"There are "<<d_count<<" having Birthday in month "<<month<<endl;
			for(int i=0;i<d_count;i++)
				cout<<DOB_user[i]->name<<"-";
			cout<<endl;
		}
	}
}

void graphadt::BFS()
{
	bool visited[fb_user]={0};
	user * temp=user_head;
	queue <user*> q1;
	frnd *f;
	visited[temp->id]=true;
	q1.push(temp);

	while(!q1.empty()){
		temp=q1.front();
		cout<<temp->name<<" - ";
		f=temp->link;
		q1.pop();
		while(f!=NULL){

			if(visited[f->id_user_frnd->id]==0){
				q1.push(f->id_user_frnd);
				visited[f->id_user_frnd->id]=1;
			}
			f=f->next;
		}
	}
	cout<<endl;
}

void graphadt::createUser()
{
	int no_user;
	cout<<"Enter the number of user in network ::"<<endl;
	cin>>no_user;
	user *temp=NULL;
					//temp equal to head
	temp=user_head;
	for(int i=0;i<no_user;i++,fb_user++)
	{
		if(temp==NULL)
		{
			temp=getnode_user(fb_user);
			user_head=temp;
		}
		else
		{
			while(temp->dlink!=NULL)
				temp=temp->dlink;
			temp->dlink=getnode_user(fb_user);
		}
	}
}

graphadt::graphadt()
{
	// TODO Auto-generated constructor stub
	    user_head=NULL;
		fb_user=0;
}
void getfriend(user *search_frnd,user *temp_user)
{
	frnd *temp1,*temp2;
	int com1,com2;
	temp1 =new (frnd);
	temp2 =new (frnd);
	cout<<"Enter the number of comment by "<<search_frnd->name<<endl;
	cin>>com1;
	cout<<"Enter the number of comment by "<<temp_user->name<<endl;
	cin>>com2;
	temp1->com=com1;
	temp2->com=com2;

	temp1->frnd_name=search_frnd->name;
	temp2->frnd_name=temp_user->name;

	temp1->id_user_frnd=search_frnd;
	temp2->id_user_frnd=temp_user;

	temp1->next=NULL;
	temp2->next=NULL;

	if(temp_user->link==NULL)
		temp_user->link=temp1;
	else{
		frnd* x=temp_user->link;
		while(x->next!=NULL)
			x=x->next;
		x->next=temp1;
	}
	if(search_frnd->link==NULL)
		search_frnd->link=temp2;
	else{
		frnd* x=search_frnd->link;
		while(x->next!=NULL)
			x=x->next;
		x->next=temp2;
	}

}

user* graphadt::add_frnd()
{
	string uid,fid;
	user * temp_user=user_head;
	user * search_frnd=user_head;
	cout<<"Enter the user-name for which you add a friend \n";
	cin>>uid;
	cout<<"Enter the friend's name \n";
	cin>>fid;

								//Search for friend
								//Step1:Find friend
	while(search_frnd!=NULL && search_frnd->name!=fid  )
		search_frnd=search_frnd->dlink;
										//Return if friend does not find
	if(search_frnd==NULL)
			return NULL;
										//Step2:Find who's friend
										//find user which have frined
	while(temp_user->dlink!=NULL && temp_user->name!=uid )
		temp_user=temp_user->dlink;
	if(temp_user==NULL)
			return NULL;
									//self friend can't be possible
	if(temp_user->name==search_frnd->name)
		return NULL;
									//insert postion in temp_user
									//Step3:Insert the friend
	getfriend(search_frnd,temp_user);
	return search_frnd;
}
void graphadt::display()
{
	user *temp=user_head;
	frnd *frnd_temp=user_head->link;
	while(temp!=NULL)
	{
		cout<<setw(8)<<temp->name;
		frnd_temp=temp->link;
		while(frnd_temp!=NULL)
			{
				cout<<"----"<<setw(5)<<frnd_temp->frnd_name;
				frnd_temp=frnd_temp->next;
			}
		cout<<"\n";
		temp=temp->dlink;
	}
}
