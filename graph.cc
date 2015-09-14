/*
 * graph.cpp
 *
 *  Created on: 11 sept. 2015
 *      Author: tnguyen
 */
#include "config.h"
#include "util.h"


#include <iostream>
#include  <vector>

#include "graph.h"
#include "component.h"


using std::cout;
using std::endl;
using std::map;
using std::vector;


namespace pnapi
{

Graph::Graph() {
	// TODO Auto-generated constructor stub
	init_=NULL;
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
	init_=NULL;
}

Graph::Graph(Marking m)
{
	init_=&m;
//	std::vector<Marking>::iterator it=Mset_.begin();
	Mset_.push_back(m);
}

/*Marking * Graph::getInitialMarking()
{
	return init_;
}

void Graph::setInitialMarking(const Marking & m)
{
	*init_= m;
}
*/

//----get the number of markings in the graph
int Graph::getNumMarking()
{
	return Mset_.size();
}

//---Initialize the graph with initial marking m


//----add all successors of marking m to the graph

void Graph::addMarking(Marking & m)
{
	std::set<Transition *> at=m.getActivateTransitions();
	std::cout<<"Number of activate transitions: "<< at.size()<<std::endl;
	if (at.empty())	return;

	std::set<Transition *>::iterator it;
	for (it=at.begin();it!=at.end();++it)
	{
		Mset_.push_back(m.getSuccessor(**it));
		//m.addSuccessor(m.getSuccessor(**it));
	}

	std::cout<<"Quantity of Marking in the graph:  "<<Mset_.size()<<std::endl;
	return ;
}


} //end of pnapi

