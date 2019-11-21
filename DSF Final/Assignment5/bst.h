/*
 * bst.h
 *
 *  Created on: Feb 1, 2019
 *      Author: f9
 */

#ifndef BST_H_
#define BST_H_

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
class bst {
public:
	node* root;
	bst();
	node* maketree(int);
	void preordertrav(node* );
	void insert(node*,int);
	void display(node*,int);
	void searchbst(node*,int);
	void removebst(node*,int);
	void mirrorimage(node* );
	void levelwise(node*);
	virtual ~bst();
};

#endif /* BST_H_ */
