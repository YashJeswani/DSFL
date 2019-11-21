/*
 * prims.h
 *
 *  Created on: 19-Mar-2019
 *      Author: f9
 */

#ifndef PRIMS_H_
#define PRIMS_H_
#define max 10

class prims 
{
	int G[max][max];	
	int n;
public:
	void make_graph();				//calling functions respectively
	void prim_algo();
	prims();
	virtual ~prims();
	
};

#endif /* PRIMS_H_ */
