// Name: Lan Anh Do
// UFID: 84224811

#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class AdjacencyList {
private:
    unordered_map<string, vector<string>> adjList;
    unordered_map<string, int> outdegree;
    set<string> allWebpages;

public:
    void AddEdge(const string& src, const string& dest);
    string PageRank(int p);
};
