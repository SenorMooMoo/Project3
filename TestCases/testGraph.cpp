//
// Created by timot on 12/1/2021.
//

#include "../Header/Graph.h"

int main(){
    Graph g;
    g.AddVertex(new Vertex("v1"));
    g.AddVertex(new Vertex("v2"));
    g.AddVertex(new Vertex("v3"));
    g.AddVertex(new Vertex("v4"));
    g.AddVertex(new Vertex("v5"));
    g.AddVertex(new Vertex("v6"));
    g.AddVertex(new Vertex("v7"));


    g.AddEdge("v1", "v2", "e1", 10);
    g.AddEdge("v2", "v3", "e2", 5);
    g.AddEdge("v3", "v4", "e3", 2);
    g.AddEdge("v4", "v1", "e4", 1);
    g.AddEdge("v1", "v3", "e5", 20);
    g.AddEdge("v4", "v5", "e6", 10);
    g.AddEdge("v6", "v5", "e7", 10);
    g.AddEdge("v7", "v1", "e9", 10);
    g.AddEdge("v7", "v5", "e8", 10);



    g.DFS(g.GetVertexByName("v7"));
    g.DFSByDegree(g.GetVertexByName("v7"));
    g.BFS(g.GetVertexByName("v7"));

    g.printAdjList();

    g.FindShortestPath("v1","v3");

}