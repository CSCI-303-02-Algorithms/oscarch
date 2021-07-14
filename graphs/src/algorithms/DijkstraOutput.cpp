//
// Created by ojcch on 4/24/2020.
//

#include "algorithms/DijkstraOutput.h"

//constructor
DijkstraOutput::DijkstraOutput(Graph *graph, unordered_map<int, double> *dist, unordered_map<int, int> *prev) {
    this->graph = graph;
    this->dist = dist;
    this->prev = prev;
}

//prints this output
void DijkstraOutput::print() {
    //....
}

//prints the shortest path from the source vertex to targetObj
void DijkstraOutput::printShortestPath(Object *targetObj) {
   //....
}

//destructor
DijkstraOutput::~DijkstraOutput() {
    delete (dist);
    delete (prev);
}
