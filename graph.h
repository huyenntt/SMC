/*
 * graph.h
 *
 *  Created on: 11 sept. 2015
 *      Author: tnguyen
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include  "marking.h"



namespace pnapi
{
class Place;
class Marking;
class Transition;

class Graph {
private:
		std::vector<Marking> Mset_; // set of reachable markings
		Marking * init_; // initial marking
public:
	Graph();
	virtual ~Graph();
	Graph(Marking m);
	//Marking * getInitialMarking();
	//void setInitialMarking(const Marking & m);
	void addMarking(Marking & m);
	void printing();
	bool check_reachable_place(Place * p);
	int getNumMarking();
}; // end of class

} //end of namespace
#endif /* GRAPH_H_ */
