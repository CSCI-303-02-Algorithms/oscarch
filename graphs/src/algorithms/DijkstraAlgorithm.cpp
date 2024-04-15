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

    // IMPLEMENT YOUR ALGORITHM HERE.
    // While you can implement the algorithm as you desire, we recommend
    // structuring your algorithm into multiple methods that perform
    // well-defined tasks. To facilitate this we provide the skeleton of
    // three methods: initialize, findMinDistVertex, and relaxOutGoingEdges.
    // These methods should be called from this method (findShortestPaths) and
    // possibly new ones that you create.
    // Also, while the algorithm covered in the lectures uses the "known" set of nodes,
    // we recommend using the "unknown" set of nodes for the main while loop of the algorithm.

    return new DijkstraOutput(graph, new unordered_map<int, double>(*dist), new unordered_map<int, int>(*prev));
}


//performs the initialization step of Dijkstra's algorithm
void DijkstraAlgorithm::initialize(Vertex *sourceVertex) {

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