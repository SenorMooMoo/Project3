cmake_minimum_required(VERSION 3.20)
project(Project4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project3 main.cpp;
        Header/Edge.h;
        Header/Graph.h;
        Header/Vertex.h;
        Cpp/Edge.cpp;
        Cpp/Graph.cpp;
        Cpp/Vertex.cpp)
add_executable(TestEdge TestCases/testEdge.cpp;
        Header/Edge.h;
        Header/Vertex.h;
        Cpp/Edge.cpp;
        Cpp/Vertex.cpp)
add_executable(TestVertex TestCases/testVertex.cpp;
        Header/Edge.h;
        Header/Vertex.h;
        Cpp/Edge.cpp;
        Cpp/Vertex.cpp)
add_executable(TestGraph TestCases/testGraph.cpp;
        Header/Graph.h;
        Cpp/Graph.cpp;
        Header/Vertex.h;
        Cpp/Vertex.cpp;
        Header/Edge.h;
        Cpp/Edge.cpp)
