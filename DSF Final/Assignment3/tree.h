#ifndef TREE_H
#define TREE_H
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;
class tree
{
	public:
		node* root;			//declearing root
		tree();
		~tree();
	node* maketree();		//declearing functions
    void insert();
    void display(node* , int );
    void preordertrav(node*);
    int depth(node*);
    int count(node*);
    node* copy(node*);
	protected:
};

#endif
