//
// Created by timot on 11/30/2021.
//

#include <iostream>
#include "../Header/Graph.h"
#include <queue>
#include <stack>
#include <map>


# define INF 0x3f3f3f3f

Graph::~Graph() = default;

Graph::Graph() = default;

void Graph::AddVertex(Vertex *vertex) {
    vertexes.push_back(vertex);
}

Vertex* Graph::GetVertexByName(std::string vName) {
    for(auto v : vertexes){
        if(v->GetName() == vName)
            return v;
    }
}

void Graph::AddEdge(std::string source, std::string destination, std::string edge, uint32_t weight) {
    Graph::GetVertexByName(source)->addEdge(new Edge(edge,Graph::GetVertexByName(source),Graph::GetVertexByName(destination), weight));
}

void Graph::FindShortestPath(std::string source, std::string destination) {
    Vertex* vSource = GetVertexByName(source);
    Vertex* vDestination = GetVertexByName(destination);
    Vertex* vCurrent = vSource;
    std::vector<Vertex*> visitedVertexes;
    std::map<Vertex*, int> vertexDis;
    //map a vertex to the edge that should be used to reach it
    std::map<Vertex*, Edge*> path;

    for(auto v : vertexes){
        vertexDis[v] = INF;
    }
    vertexDis[vSource] = 0;
    visitedVertexes.push_back(vSource);
    for(auto e : vCurrent->GetAllEdges()){
        vertexDis[&e->GetDestination()] = e->GetWeight();
        path[&e->GetDestination()] = e;
    }


    while(vCurrent->GetName() != vDestination->GetName()){
        vCurrent = &vCurrent->GetSmallestEdgeDirected(visitedVertexes)->GetDestination();
        visitedVertexes.push_back(vCurrent);
        for(auto e : vCurrent->GetAllEdgesDirected(visitedVertexes)){
            int minDis = e->GetWeight() + vertexDis[vCurrent];
            if(vertexDis[&e->GetDestination()] > minDis) {
                vertexDis[&e->GetDestination()] = minDis;
                path[&e->GetDestination()] = e;
            }
        }
    }
    //backwards search through the edges starting from destination to start
    std::string current = destination;
    std::stack<std::string> tempStack;
    while(current != source){
        auto temp = path[GetVertexByName(current)];
        tempStack.push(temp->GetDestination().GetName());
        current = temp->GetSource().GetName();
    }
    tempStack.push(source);
    //reverse the order to print from start to destination
    while(!tempStack.empty()){
        std::cout << tempStack.top() << ((tempStack.size() == 1) ? " " : " -> ");
        tempStack.pop();
    }

    std::cout << std::endl;


    std::cout << vertexDis[vDestination] << std::endl;

}

void Graph::printAdjList() {
    for(auto v : vertexes){
        std::cout << v->GetName() << ": ";
        for(auto e : v->GetAllEdges()){
            std::cout << e->GetDestination().GetName() << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::BFS(Vertex * start) {
    std::vector<Vertex*> visited;
    visited.push_back(start);

    std::queue<Vertex*> nextVertex;
    nextVertex.push(start);

    while(!nextVertex.empty()){

        std::cout << nextVertex.front()->GetName() << " ";

        for(auto e : nextVertex.front()->GetAllEdges()){
            if(!hasVertex(visited,&e->GetDestination())){
                visited.push_back(&e->GetDestination());
                nextVertex.push(&e->GetDestination());
            }
        }
        nextVertex.pop();

    }
    std::cout << std::endl;
}

bool Graph::hasVertex(std::vector<Vertex *> v, Vertex * key) {
    return std::count(v.begin(), v.end(), key);
}

void Graph::DFS(Vertex * start) {
    std::vector<Vertex*> visited;

    std::stack<Vertex*> nextVertex;
    nextVertex.push(start);

    while(!nextVertex.empty()){
        Vertex* next = nextVertex.top();

        if(!hasVertex(visited,next)){
            std::cout << next->GetName() << " ";
            visited.push_back(next);
        }

        bool foundEdge = false;
        for(auto e : next->GetAllEdgesDirected(visited)){
                nextVertex.push(&e->GetDestination());
                foundEdge = true;
                break;
        }
        if(!foundEdge) nextVertex.pop();

    }
    std::cout << std::endl;
}


void Graph::DFSByDegree(Vertex * start) {
    std::vector<Vertex*> visited;

    std::stack<Vertex*> nextVertex;
    nextVertex.push(start);

    while(!nextVertex.empty()){
        Vertex* next = nextVertex.top();

        if(!hasVertex(visited,next)){
            std::cout << next->GetName() << " ";
            visited.push_back(next);
        }

        bool foundEdge = false;
        for(auto e : next->GetAllEdgesDirectedByDegree(visited)){
                nextVertex.push(&e->GetDestination());
                foundEdge = true;
                break;
        }
        if(!foundEdge) nextVertex.pop();

    }
    std::cout << std::endl;
}