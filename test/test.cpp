// // Name: Lan Anh Do
// // UFID: 84224811
//
// #include "AdjacencyList.h"
// #include <catch2/catch_test_macros.hpp>
// #include <iostream>
// using namespace std;
//
// TEST_CASE("Chain A->B->C->D, 1 iteration") {
//     AdjacencyList hehe;
//     hehe.AddEdge("A", "B");
//     hehe.AddEdge("B", "C");
//     hehe.AddEdge("C", "D");
//
//     string result = hehe.PageRank(1);
//
//     string expected =
//         "A 0.25\n"
//         "B 0.25\n"
//         "C 0.25\n"
//         "D 0.25\n";
//
//     REQUIRE(result == expected);
// }
//
// TEST_CASE("One isolated page + a 2-cycle, 2 iterations") {
//     AdjacencyList hehe;
//     hehe.AddEdge("Y.com", "Z.com");
//     hehe.AddEdge("Z.com", "Y.com");
//     hehe.AddEdge("X.com", "X.com");
//
//     string result = hehe.PageRank(2);
//
//     string expected =
//         "X.com 0.33\n"
//         "Y.com 0.33\n"
//         "Z.com 0.33\n";
//
//     REQUIRE(result == expected);
// }
//
// TEST_CASE("Star shape with loop, 3 iterations") {
//     AdjacencyList hehe;
//     hehe.AddEdge("Center", "A");
//     hehe.AddEdge("Center", "B");
//     hehe.AddEdge("Center", "C");
//     hehe.AddEdge("A", "Center");
//
//     string result = hehe.PageRank(3);
//
//     REQUIRE(result.find("A ") != string::npos);
//     REQUIRE(result.find("B ") != string::npos);
//     REQUIRE(result.find("C ") != string::npos);
//     REQUIRE(result.find("Center ") != string::npos);
// }
//
// TEST_CASE("5-node example, random structure, 2 iterations") {
//     AdjacencyList hehe;
//     hehe.AddEdge("N1", "N2");
//     hehe.AddEdge("N1", "N3");
//     hehe.AddEdge("N2", "N4");
//     hehe.AddEdge("N2", "N5");
//     hehe.AddEdge("N4", "N1");
//     hehe.AddEdge("N5", "N4");
//
//     string result = hehe.PageRank(2);
//
//     REQUIRE(result.find("N1 ") != string::npos);
//     REQUIRE(result.find("N2 ") != string::npos);
//     REQUIRE(result.find("N3 ") != string::npos);
//     REQUIRE(result.find("N4 ") != string::npos);
//     REQUIRE(result.find("N5 ") != string::npos);
// }
//
// TEST_CASE("Single node with self-loop, multiple iterations") {
//     AdjacencyList hehe;
//     hehe.AddEdge("OnlyOne", "OnlyOne");
//
//     string result = hehe.PageRank(5);
//
//     REQUIRE(result == "OnlyOne 1.00\n");
// }