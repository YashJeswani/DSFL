/*
 * dijiktrass.h
 *
 *  Created on: Mar 19, 2019
 *      Author: f9
 */

#ifndef DIJIKTRASS_H_
#define DIJIKTRASS_H_
#define max 10

class dijiktrass {
	int n;
	int G[max][max];			//taking as n vertices element and G matrix adjacency matrix!
public:
	dijiktrass();				//calling functions respectively
	void input_edges();
	void dijiktrasalgo(int );
	virtual ~dijiktrass();
};

#endif /* DIJIKTRASS_H_ */
