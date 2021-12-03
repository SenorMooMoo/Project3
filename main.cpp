#include <iostream>
#include <fstream>
#include <sstream>
#include "Header/Graph.h"


void checkValidInput();

void generateMenu(){
    std::cout << "\t Welcome to Graphing System" << std::endl;
    std::cout << "\t ----------------------------------------------" << std::endl;
    std::cout << "Please select one of the following:" << std::endl;
    std::cout << "  [1] Find shortest path between two nodes" << std::endl;
    std::cout << "  [2] Print adjacency list" << std::endl;
    std::cout << "  [3] Breadth-first search" << std::endl;
    std::cout << "  [4] Depth-first search" << std::endl;
    std::cout << "  [5] Depth-first search ordered by degree" << std::endl;
    std::cout << "  Please select 1-5 of the options or exit with 6" << std::endl;

}

void loadCourseCSV(Graph* graph){

    // File pointer
    std::fstream fin;

    // Open an existing file
    fin.open("../Graph.txt", std::ios::in);

    if(fin.is_open()){
        std::cout << "File opened" << std::endl;
    }else{
        std::cout << "File failed to open" << std::endl;
        return;
    }

    std::string line, word, temp;
    // Skip header line
    getline(fin,line);
    auto numofVertex = stoi(line);
    for(int i = 0; i < numofVertex; i++) {
        getline(fin, line);
        std::string vertex = line;
        graph->AddVertex(new Vertex(vertex));
    }
    int i = 1;
    while(getline(fin,line)){
        std::stringstream s(line);
        std::getline(s,word,',');
        std::string edge = "e";
        edge += std::to_string(i);
        std::string v1 = word;
        getline(s,word,',');
        std::string v2 = word;
        getline(s,word,',');
        uint32_t weight = std::stoi(word);
        graph->AddEdge(v1, v2, edge, weight);
        i++;
    }

}

int main() {
    auto a = new Graph;
    //fill graph a with the graph.txt file
    loadCourseCSV(a);

    int input = 0;
    do{
        generateMenu();
        std::cin >> input;
        //check if bad input and clean cin
        checkValidInput();

        switch(input){
            case 1: {
                std::string source;
                std::string destination;
                std::cout << "Enter start vertex" << std::endl;
                std::cin >> source;
                //check if bad input and clean cin
                checkValidInput();

                std::cout << "Enter destination vertex" << std::endl;
                std::cin >> destination;
                //check if bad input and clean cin
                checkValidInput();
                a->FindShortestPath(source,destination);
                //pause for user to look at records
                system("pause");
                break;
            }
            case 2:
                a->printAdjList();
                system("pause");
                break;
            case 3: {
                std::string start;
                std::cout << "Enter start vertex" << std::endl;
                std::cin >> start;
                checkValidInput();
                a->BFS(a->GetVertexByName(start));
                system("pause");
                break;
            }
            case 4: {
                std::string start;
                std::cout << "Enter start vertex" << std::endl;
                std::cin >> start;
                checkValidInput();
                a->DFS(a->GetVertexByName(start));
                system("pause");
                break;
            }
            case 5: {
                std::string start;
                std::cout << "Enter start vertex" << std::endl;
                std::cin >> start;
                checkValidInput();
                a->DFSByDegree(a->GetVertexByName(start));
                system("pause");
                break;
            }
        }

    }while(input != 6);


}

void checkValidInput() {
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "INVALID INPUT" << std::endl;
        system("pause");
    }
}
