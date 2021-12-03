//
// Created by timot on 11/30/2021.
//

#include "../Header/Vertex.h"
#include "../Header/Edge.h"
#include "iostream"

void testBuilder(std::string, bool hasPassed);

int main(){
    auto* v = new Vertex("v1");
    auto* a = new Vertex("v2");
    auto* b = new Vertex("v3");
    auto* c = new Vertex("v4");
    v->addEdge(new Edge("e1",v,a,10));
    v->addEdge(new Edge("e1",v,a,5));
    v->addEdge(new Edge("e2",v,b,2));
    v->addEdge(new Edge("e3",v,c,20));

    std::vector<Vertex*> ignoreThis;
    ignoreThis.push_back(b);
    ignoreThis.push_back(a);

    testBuilder("Test Vertex Name", v->GetName() == "v1");
    testBuilder("Test Vertex Edge", v->GetEdgeByName("e1")->GetName() == "e1");
    testBuilder("Test Different Edge", v->GetEdgeByName("e2")->GetName() == "e2");
    v->deleteEdgeByName("e1");
    testBuilder("Test Edge Deletion", v->GetEdgeByName("e1") == nullptr);
    testBuilder("Test Find Smallest Edge", v->GetSmallestEdge()->GetName() == "e2");
    testBuilder("Test Find Smallest Edge Ignoring Visited Vertexes", v->GetSmallestEdgeDirected(ignoreThis)->GetName() == "e3");
    testBuilder("Test Find All Edges Ignoring Visited Vertexes", v->GetAllEdgesDirected(ignoreThis)[0]->GetName() == "e3");

    v->deleteEdgeByName("e1");
}

void testBuilder(std::string test, bool hasPassed){
    std::cout << test << " has " << (hasPassed ? "Passed" : "Failed") << std::endl;
}