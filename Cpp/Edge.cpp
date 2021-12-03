//
// Created by timot on 11/30/2021.
//

#include "../Header/Edge.h"
#include "../Header/Vertex.h"
#include <utility>
#include "iostream"

Edge::Edge(std::string name, Vertex *source, Vertex* destination) {
    Edge::name = std::move(name);
    Edge::source = source;
    Edge::destination = destination;
    Edge::weight = 0;
}

Edge::Edge(std::string name, Vertex *source, Vertex *destination, uint32_t weight) {
    Edge::name = std::move(name);
    Edge::source = source;
    Edge::destination = destination;
    Edge::weight = weight;
}

void Edge::ChangeSource(Vertex *newSource) {
    Edge::source = newSource;
}

void Edge::ChangeDestination(Vertex *newDestination) {
    Edge::destination = newDestination;
}

Vertex& Edge::GetSource() {
    return *Edge::source;
}

Vertex& Edge::GetDestination() {
    return *Edge::destination;
}

uint32_t Edge::GetWeight() const {
    return Edge::weight;
}

void Edge::SetWeight(uint32_t newWeight) {
    Edge::weight = newWeight;
}

void Edge::printEdge() {
    std::cout << "Edge: " << Edge::name << std::endl;
    std::cout << "Weight: "<< Edge::weight << std::endl;
    std::cout << "Source: "<< Edge::source->GetName() << std::endl;
    std::cout << "Destination: "<< Edge::destination->GetName() << std::endl;
}

std::string Edge::GetName() {
    return Edge::name;
}

bool Edge::hasVertex(Vertex *vertex) {
    return vertex->GetName() == Edge::GetSource().GetName() || vertex->GetName() == Edge::GetDestination().GetName();
}

Edge::~Edge() = default;
