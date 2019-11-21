/*
 * graphadt.h
 *
 *  Created on: Feb 12, 2019
 *      Author: f9
 */

#ifndef GRAPHADT_H_
#define GRAPHADT_H_
#include<string.h>
#include <iostream>
using namespace std;

struct user;
struct DOB{
	int day;
	int month;
	int year;
};
struct frnd{
	int com;
	string frnd_name;
	user *id_user_frnd;
	frnd *next;
};

struct user{
	string name;
	DOB date;
	int id;
	frnd *link;
	user *dlink;
};

class graphadt {
private:
	user *user_head;
    int fb_user;
public:
	    graphadt();
	    void createUser();
		void display();
		void BFS();
		void DFS();
		void que(bool,bool,bool);
		user* add_frnd();
		user* getuser();
};

#endif /* GRAPHADT_H_ */
