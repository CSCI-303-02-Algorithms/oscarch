#include <iostream>
#include "graph/Vertex.h"
#include "graph/Graph.h"
#include "entity/City.h"
#include "entity/StringElement.h"
#include "algorithms/DijkstraAlgorithm.h"

void buildGraphOfCities();

void buildGraphOfStringElements();

void runDijkstraAlgorithm(Graph *graph, Object *sourceObj, Object *targetObj);

int main() {
    buildGraphOfStringElements();
    cout << "-------------------------------------" << endl;
    buildGraphOfCities();
    return 0;
}

void buildGraphOfStringElements() {

    //----------------
    //objects to be stored in the graph

    Object *A = new StringElement("A");
    Object *D = new StringElement("D");
    Object *C = new StringElement("C");

    //------------------
    //building the graph

    auto *undirectedGraph = new Graph(true);
    undirectedGraph->addEdge(A, D, 9);
    undirectedGraph->addEdge(A, C, 12);
    undirectedGraph->addEdge(C, D, 3);

    //----------------
    //printing the graph

    cout << endl << "* Graph of strings: " << endl;
    undirectedGraph->print();

    //----------------
    //running Dijkstra's algorithm

    runDijkstraAlgorithm(undirectedGraph, A, D);

    delete (undirectedGraph);
}

void buildGraphOfCities() {

    //----------------
    //cities to be stored in the graph

    City *sanFrancisco = new City("San Francisco");
    City *losAngeles = new City("Los Angeles");
    City *riverside = new City("Riverside");

    //------------------
    //building the graph

    auto *undirectedGraph = new Graph(true);
    undirectedGraph->addEdge(sanFrancisco, riverside, 386);
    undirectedGraph->addEdge(sanFrancisco, losAngeles, 348);
    undirectedGraph->addEdge(losAngeles, riverside, 50);

    //----------------
    //printing the graph

    cout << endl << "* Graph of cities: " << endl;
    undirectedGraph->print();

    //----------------
    //running Dijkstra's algorithm

    runDijkstraAlgorithm(undirectedGraph, sanFrancisco, riverside);

    delete (undirectedGraph);
}

/*
 * Runs Dijkstra's algorithm on the provided graph using source object.
 * It prints the result of the algorithm and also the shortest path from the source object to the target object.
 */
void runDijkstraAlgorithm(Graph *graph, Object *sourceObj, Object *targetObj) {
    auto *algorithm = new DijkstraAlgorithm(graph);
    DijkstraOutput *output = algorithm->findShortestPaths(sourceObj);

    cout << endl << "* Dijkstra's result: " << endl;
    if (output != nullptr) {
        output->print();
        cout << endl;
        output->printShortestPath(targetObj);
    } else {
        cout << "No output" << endl;
    }

    delete (output);
    delete (algorithm);
}
