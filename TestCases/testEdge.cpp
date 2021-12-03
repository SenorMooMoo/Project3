//
// Created by timot on 11/30/2021.
//

#include "../Header/Edge.h"
#include "../Header/Vertex.h"
#include "iostream"
void testBuilder(std::string, bool hasPassed);

int main(){
    Edge e = Edge("e1", new Vertex("v1"), new Vertex("v2"));
    e.printEdge();

    testBuilder("Test getName", e.GetName() == "e1");
    testBuilder("Test getSource", e.GetSource().GetName() == "v1");
    testBuilder("Test getDestination", e.GetDestination().GetName() == "v2");
    testBuilder("Test hasVertex", e.hasVertex(new Vertex("v1")));

    e.ChangeDestination(new Vertex("v5"));
    e.ChangeSource(new Vertex("v9"));

    testBuilder("Test getName after change", e.GetName() == "e1");
    testBuilder("Test changeSource", e.GetSource().GetName() == "v9");
    testBuilder("Test changeDestination", e.GetDestination().GetName() == "v5");

}

void testBuilder(std::string test, bool hasPassed){
    std::cout << test << " has " << (hasPassed ? "Passed" : "Failed") << std::endl;
}