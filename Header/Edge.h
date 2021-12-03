//
// Created by timot on 11/30/2021.
// Edge must have a unique name and a source and destination vertex
//
//

#ifndef PROJECT4_EDGE_H
#define PROJECT4_EDGE_H


#include <string>

class Vertex;
class Edge {
private:
    std::string name;
    Vertex *source;
    Vertex *destination;

    uint32_t weight;

public:
    Edge(std::string name, Vertex *source, Vertex *destination);
    Edge(std::string name, Vertex *source, Vertex *destination, uint32_t weight);

    //allow an edge to be updated to a new source
    void ChangeSource(Vertex *newSource);
    //allow an edge to be updated to a new destination
    void ChangeDestination(Vertex *newDestination);

    //give access to source and destination
    Vertex& GetSource();
    Vertex& GetDestination();

    //give access to weight
    uint32_t GetWeight() const;
    void SetWeight(uint32_t);

    //give access to reading in name
    std::string GetName();

    //check if an edge has a Vertex
    bool hasVertex(Vertex*);

    //print edge mainly used for testing
    void printEdge();

    ~Edge();
};


#endif //PROJECT4_EDGE_H
