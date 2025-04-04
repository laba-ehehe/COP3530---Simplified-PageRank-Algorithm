// Name: Lan Anh Do
// UFID: 84224811

#include "AdjacencyList.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

void AdjacencyList::AddEdge(const string& src, const string& dest) {
    // add dest to adjacency list for src
    adjList[src].push_back(dest);
    outdegree[src]++;

    // insert src and dest into set of webpages
    allWebpages.insert(src);
    allWebpages.insert(dest);

    if (adjList.find(dest) == adjList.end()) {
        adjList[dest] = vector<string>();
    }
}

string AdjacencyList::PageRank(int p) {
    // no webpages -> empty output
    if (allWebpages.empty()) {
        return "";
    }

    int n = static_cast<int>(allWebpages.size());

    // initialize each webpage's rank to 1/n
    unordered_map<string, double> rank;
    double i = 1.0 / n;
    for (auto &page : allWebpages) {
        rank[page] = i;
    }

    for (int i = 0; i < p - 1; i++) {
        unordered_map<string, double> newRank;

        for (auto &page : allWebpages) {
            newRank[page] = 0.0;
        }

        // distribute from each page to its out-links
        for (auto &entry : adjList) {
            const string &src = entry.first;
            double currentRank = rank[src];
            int od = outdegree[src];
            if (od > 0) {
                double share = currentRank / od;
                for (auto &dest : entry.second) {
                    newRank[dest] += share;
                }
            }
        }
        rank = newRank;
    }

    // sort pages alphabetically
    vector<string> sortedPages(allWebpages.begin(), allWebpages.end());
    sort(sortedPages.begin(), sortedPages.end());

    // build output string with two decimals
    ostringstream oss;
    oss << fixed << setprecision(2);
    for (auto &page : sortedPages) {
        oss << page << " " << rank[page] << "\n";
    }

    return oss.str();
}
