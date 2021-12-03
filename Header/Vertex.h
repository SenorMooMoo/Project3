//
// Created by timot on 11/30/2021.
// Vertex contains a unique name and a list of edges
//

#ifndef PROJECT4_VERTEX_H
#define PROJECT4_VERTEX_H


#include <string>
#include <vector>

class Edge;
class Vertex {
private:
    std::string name;
    std::vector<Edge*> edges;
public:
    Vertex(std::string name);
    //allow access to name
    std::string GetName();
    //add edge to list
    void addEdge(Edge*);
    //delete edge from list using name
    void deleteEdgeByName(const std::string&);

    //Get an edge from the list by name
    Edge* GetEdgeByName(const std::string&);
    //Get the smallest edge in weight from list
    Edge* GetSmallestEdge();
    //Get the smallest edge in weight from list excluding edges that go to the list of vertexes
    Edge* GetSmallestEdgeDirected(std::vector<Vertex*>);

    //Get all the edges from list
    std::vector<Edge*>& GetAllEdges();
    //Get all the edges from list excluding edges that go to the list of vertexes
    std::vector<Edge*> GetAllEdgesDirected(std::vector<Vertex*>);
    //Get all the edges from list in order of degree excluding edges that go to the list of vertexes
    std::vector<Edge*> GetAllEdgesDirectedByDegree(std::vector<Vertex*>);

    //get the degree which is the number of connected edges
    int GetDegree();

    //print vertex mainly for testing
    void printVertex();

    ~Vertex();
};


#endif //PROJECT4_VERTEX_H
