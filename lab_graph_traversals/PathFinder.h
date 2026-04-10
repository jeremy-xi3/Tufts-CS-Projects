/*
 *      PathFinder.h
 *      CS15 Lab 11: Graph Traversals
 *
 *      A class that builds and traverses a graph of cities.
 * 
 *      2025-03-31 Modified by Lindsay Ulrey
 *                 Added file header and updated function contracts.
 */

#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;

class PathFinder
{
    public:
        PathFinder();
        ~PathFinder();
        
        void populate_graph(ifstream &data);

        void run();
        void bfs();
        void dfs();
        
    private:
        Graph graph;
        
        pair<string, string> get_cities();
        string get_airline();

        bool run_bfs(City city1, City city2);
        bool run_dfs(City city1, City city2);
        
        void clean_up();
};

#endif
