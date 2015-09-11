/*
 * graph.cpp
 *
 *  Created on: 11 sept. 2015
 *      Author: tnguyen
 */
#include "config.h"
#include "util.h"


#include <iostream>

#include "graph.h"

using std::cout;
using std::endl;
using std::map;
using std::set;

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
	Marking * p;
	p=&m;
	Mset_.insert(p);
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

void Graph::addSuccessors(const Marking * m)
{
		Marking * succ;

		std::set<Transition *> at= m->getActivateTransitions();
		if (at.empty())	return;

		PNAPI_FOREACH(it,at)
		{
			Marking & a=m->getSuccessor(**it);
			for (std::set<Marking *>::iterator i=Mset_.begin();i!=Mset_.end();++i)
			{
				if (succ==*i)

					return;
				else
					Mset_.insert(succ);
			}
			addSuccessors(succ);
		}
}


} //end of pnapi

