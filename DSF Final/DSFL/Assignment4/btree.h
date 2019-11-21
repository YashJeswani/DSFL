
/*
 * btree.h
 *
 *  Created on: 16-Jan-2019
 *      Author: f9
 */

#ifndef BTREE_H_
#define BTREE_H_

struct bTreenode
{
	char data;
	bTreenode*left;
	bTreenode *right;
};

class btree {						//marking as function declerations

public:

	bTreenode* root;					//root of treee
	
	btree();
	virtual ~btree();
	
	bTreenode* maketree(char);
	
	bool isOperand(char);
	bool isOperator(char);

	void create_exptree_post();

	void dispinorder(bTreenode* root);
	void disppreorder(bTreenode* root);
	void disppostorder(bTreenode* root);

	void dispInorderNonRec();
	void dispPreorderNonRec();
    void disppostorderNonRec();



};

#endif /* BTREE_H_ */

