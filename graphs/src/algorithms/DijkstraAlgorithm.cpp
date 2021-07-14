//
// Created by ojcch on 4/19/2020.
//

#include "algorithms/DijkstraAlgorithm.h"

//constructor
DijkstraAlgorithm::DijkstraAlgorithm(Graph *pGraph) {
    graph = pGraph;
    this->dist = new unordered_map<int, double>();
    this->prev = new unordered_map<int, int>();
    this->unknown = new unordered_set<int>();
}

//destructor
DijkstraAlgorithm::~DijkstraAlgorithm() {
    delete (dist);
    delete (prev);
    delete unknown;
}

//runs the algorithm on source vertex (data) v
DijkstraOutput *DijkstraAlgorithm::findShortestPaths(Object *v) {
    Vertex *source = graph->getVertex(v, true);

    //...

    return new DijkstraOutput(graph, new unordered_map<int, double>(*dist), new unordered_map<int, int>(*prev));
}


//performs the initialization step of the algorithm
void DijkstraAlgorithm::initialize(Vertex *pVertex) {

    //every time there is an initialization, start over
    delete dist;
    delete prev;
    delete unknown;
    this->dist = new unordered_map<int, double>();
    this->prev = new unordered_map<int, int>();
    this->unknown = new unordered_set<int>();

    //...

}

//finds the vertex with the minimum dist from the unknown vertices
Vertex *DijkstraAlgorithm::findMinDistVertex() {

    //...

    return nullptr;
}

//relaxes the outgoing edges of v
void DijkstraAlgorithm::relaxOutGoingEdges(Vertex *v) {

    //...
}