/*
 * kruskal.h
 *
 *  Created on: 05-Mar-2019
 *      Author: f9
 */

#ifndef KRUSKAL_H_
#define KRUSKAL_H_
struct edge
{
	int start, end, weight;
};
class kruskal
{
	edge elist1[20],elist2[20];
public:
	kruskal();
	void input_edges();
	void kruskalalgo();
	void show_mst();
	virtual ~kruskal();
};

#endif /* KRUSKAL_H_ */

