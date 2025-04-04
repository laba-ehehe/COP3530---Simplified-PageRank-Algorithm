// Name: Lan Anh Do
// UFID: 84224811

#include "AdjacencyList.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int no_of_lines, power_iterations;
    cin >> no_of_lines;
    cin >> power_iterations;
    AdjacencyList graph;

    // read the input edges
    for (int i = 0; i < no_of_lines; i++) {
        string from, to;
        cin >> from >> to;
        graph.AddEdge(from, to);
    }

    // compute PageRank and print the result
    string result = graph.PageRank(power_iterations);
    cout << result;

    return 0;
}
