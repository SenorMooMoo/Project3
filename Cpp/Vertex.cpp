//
// Created by timot on 11/30/2021.
//

#include <iostream>
#include "../Header/Vertex.h"
#include "../Header/Edge.h"

Vertex::Vertex(std::string name) {
    Vertex::name = name;
    Vertex::edges;
}

std::string Vertex::GetName() {
    return Vertex::name;
}

void Vertex::addEdge(Edge* e) {
    for(auto temp : edges)
        if(temp->GetName() == e->GetName()) return;
    edges.push_back(e);
    //code below would make the graph undirected
    //e->GetDestination().addEdge(new Edge(e->GetName(),&e->GetDestination(),&e->GetSource(),e->GetWeight()));
}

void Vertex::deleteEdgeByName(const std::string& edgeName) {
    int i = 0;
    for(auto e : edges){
        if(e->GetName() == edgeName)
            edges.erase(edges.cbegin() + i);
        i++;
    }
}

void Vertex::printVertex() {
    std::cout << "Vertex: " << Vertex::name << std::endl;
    for(auto e :edges){
        std::cout << "Edge: " << e->GetName() << " Source: "<< e->GetSource().GetName() << " Destination: " << e->GetDestination().GetName() << std::endl;
    }
}

Edge *Vertex::GetEdgeByName(const std::string& edgeName) {
    for(auto e: edges){
        if(e->GetName() == edgeName) return e;
    }
    return nullptr;
}

Edge *Vertex::GetSmallestEdge() {
    uint32_t smallest = 100000;
    Edge* smallEdge;
    for(auto e : edges){
        if(e->GetWeight() < smallest){
            smallest = e->GetWeight();
            smallEdge = e;
        }
    }
    return smallEdge;
}

std::vector<Edge *>& Vertex::GetAllEdges() {
    return edges;
}

std::vector<Edge *> Vertex::GetAllEdgesDirected(std::vector<Vertex*> visited) {
    std::vector<Edge *> tempEdge;
    //filter edges that contain a vertex in the vertex list
    for(auto e : GetAllEdges()){
        bool isSkip = false;
        for(auto v : visited){
            if(e->GetDestination().GetName() == v->GetName()){
                isSkip = true;
                break;
            }
        }
        if(isSkip) continue;
        tempEdge.push_back(e);
    }
    return tempEdge;
}

std::vector<Edge *> Vertex::GetAllEdgesDirectedByDegree(std::vector<Vertex*> visited) {
    std::vector<Edge *> tempEdge;
    //filter edges that contain a vertex in the vertex list
    for(auto e : GetAllEdges()){
        bool isSkip = false;
        for(auto v : visited){
            if(e->GetDestination().GetName() == v->GetName()){
                isSkip = true;
                break;
            }
        }
        if(isSkip) continue;
        bool isInserted = false;
        //order the edge list by degree
        for(auto i = tempEdge.cbegin(); i < tempEdge.cend(); ++i){
            if((*i)->GetDestination().GetDegree() > e->GetDestination().GetDegree()){
                tempEdge.insert(i, e);
                isInserted = true;
                break;
            }
        }
        if(!isInserted) tempEdge.push_back(e);

    }
    return tempEdge;
}

Edge *Vertex::GetSmallestEdgeDirected(std::vector<Vertex*> visited) {
    uint32_t smallest = 100000;
    Edge* smallEdge;
    //filter edges that contain a vertex in the vertex list
    for(auto e : GetAllEdges()){
        bool isSkip = false;
        for(auto v : visited){
            if(e->GetDestination().GetName() == v->GetName()){
                isSkip = true;
                break;
            }
        }
        if(isSkip) continue;
        if(e->GetWeight() < smallest){
            smallest = e->GetWeight();
            smallEdge = e;
        }
    }
    return smallEdge;
}

int Vertex::GetDegree() {
    return edges.size();
}

Vertex::~Vertex() = default;
