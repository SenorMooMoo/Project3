//
// Created by timot on 11/30/2021.
// Handles storing the graph and graphing algorithms
//


#ifndef PROJECT4_GRAPH_H
#define PROJECT4_GRAPH_H

#include "Vertex.h"
#include "Edge.h"

class Graph {
private:
    std::vector<Vertex*> vertexes;

public:
    Graph();
    ~Graph();
    //add a vertex
    void AddVertex(Vertex* vertex);
    //get a vertex by name
    Vertex* GetVertexByName(std::string);

    //add an edge, first vertex would be the source and will be added to that vertex
    void AddEdge(std::string v1, std::string v2, std::string e1, uint32_t weight);

    //Find shortest path using Dijkstra’s algorithm if no destination is found the program crashes
    void FindShortestPath(std::string source, std::string destination);

    //print the graph in adjacency list format
    void printAdjList();

    //breadth first search
    void BFS(Vertex*);

    //Depth first search
    void DFS(Vertex*);

    //Depth first search by degree
    void DFSByDegree(Vertex*);

    //check if a vertex is in a given vertex
    static bool hasVertex(std::vector<Vertex*>,Vertex*);
};


#endif //PROJECT4_GRAPH_H
