/*
 *      PathFinder.cpp
 *      CS15 Lab 11: Graph Traversals
 *
 *      Implementation of PathFinder.h.
 * 
 *      2025-03-31 Modified by Lindsay Ulrey
 *                 Edited to follow CS15 style guide.
 *                 Added comments for clarity.
 *                 Added file header and function contracts.
 *                 Edited parameters of run_bfs() for consistency. Revised
 *                     neighbor traversal in run_bfs() to avoid range-based
 *                     for loop.
 *                 Revised run() to remove switch statment.
 */

#include <vector>
#include <queue>
#include <random>

#include "PathFinder.h"

using namespace std;

/* constructor
 *    Purpose: Initialize PathFinder.
 * Parameters: None
 *    Returns: 
 *       Note: Nothing to do for Graph class, it self initializes
 */
PathFinder::PathFinder()
{
    /* Initialize random seed */
    srand(time(NULL));
}


/* destructor
 *    Purpose: None
 * Parameters: None
 *    Returns: None
 */
PathFinder::~PathFinder()
{
    /* nothing to do, Graph and PathFinder class self destruct */
}


/* run_bfs()
 *    Purpose: Run breadth-first traversal from cities c1 to c2.
 * Parameters: City c1   - starting city node
 *             City c2   - ending city node
 *    Returns: bool      - true if there exists a path between c1 and c2,
 *                         false otherwise
 */
bool PathFinder::run_bfs(City c1, City c2)
{
    // cout << "BFS would run... TODO: needs implementing!" << endl;
    queue <City> cityQueue;
    cityQueue.push(c1);
    while(!cityQueue.empty()){
        graph.get_to_vertices(cityQueue.front(), cityQueue);
        graph.mark_vertex(cityQueue.front());
        for(int i = 0; i < cityQueue.front().get_num_neighbors(); i++){
            if(!graph.is_marked(cityQueue.front().get_neighbors().at(i))){
                graph.update_predecessor(cityQueue.front(), cityQueue.front().get_neighbors().at(i));
                cityQueue.push(cityQueue.front().get_neighbors().at(i));
            }
        }
        if(cityQueue.front().get_name() == c2.get_name()) {
            return true;
        }
        cityQueue.pop();
    }
    return false;
}


/* run_dfs()
 *    Purpose: Run recursive depth-first traversal from cities c1 to c2.
 * Parameters: City c1   - starting city node
 *             City c2   - ending city node
 *    Returns: bool      - true if there exists a path between c1 and c2,
 *                         false otherwise
 */
bool PathFinder::run_dfs(City c1, City c2)
{
    // stack <City> cityQueue;
    // cityQueue.push(c1);
    // while(!cityQueue.empty()){
    //     graph.get_to_vertices(cityQueue.front(), cityQueue);
    //     graph.mark_vertex(cityQueue.front());
    //     for(int i = 0; i < cityQueue.front().get_num_neighbors(); i++){
    //         if(!graph.is_marked(cityQueue.front().get_neighbors().at(i))){
    //             graph.update_predecessor(cityQueue.front(), cityQueue.front().get_neighbors().at(i));
    //             cityQueue.push(cityQueue.front().get_neighbors().at(i));
    //         }
    //     }
    //     if(cityQueue.front().get_name() == c2.get_name()) {
    //         return true;
    //     }
    //     cityQueue.pop();
    // }
    // return false;
}


/* The functions below are mostly for setup, so no need to look at them! */

/* get_cities()
 *    Purpose: Get city names from user input.
 * Parameters: None
 *    Returns: pair<string, string> - city names in pair
 */
pair<string, string> PathFinder::get_cities()
{
    string city1, city2;

    cout << "City 1? ";
    cin >> city1;
    cout << "City 2? ";
    cin >> city2;

    return make_pair(city1, city2);
}


/* bfs()
 *    Purpose: Run breadth-first traversal.
 * Parameters: None
 *    Returns: None
 *       Note: Calls run_bfs(), which must be completed before bfs() can work
 */
void PathFinder::bfs()
{
    pair<string, string> cities = get_cities();
    City city1 = graph.get_vertex(cities.first);
    City city2 = graph.get_vertex(cities.second);

    if (run_bfs(city1, city2)) {
        graph.report_path(cout, city1, city2);
    } else {
        cout << "No flight from " << city1.get_name() << " to " 
            << city2.get_name() << ".\n";
    }

    /* resets graph, allows it to be traversed again */
    graph.clear_marks();
}


/* dfs()
 *    Purpose: Run depth-first traversal.
 * Parameters: None
 *    Returns: None
 *       Note: Calls run_dfs(), which must be completed before dfs() can work
 */
void PathFinder::dfs()
{
    pair<string, string> cities = get_cities();
    City city1 = graph.get_vertex(cities.first);
    City city2 = graph.get_vertex(cities.second);

    if (run_dfs(city1, city2)) {
        graph.report_path(cout, city1, city2);
    } else {
        cout << "No flight from " << city1.get_name() << " to " 
            << city2.get_name() << ".\n";
    }

    /* resets graph, allows it to be traversed again */
    graph.clear_marks();
}


/* run()
 *    Purpose: Read and process user commands to traverse graph.
 * Parameters: None
 *    Returns: None
 */
void PathFinder::run()
{
    string cmnd = "";
    bool running = true;
    
    try {
        while (running) {
            cout << "Command? ";
            cin >> cmnd;
                /* process command from input */
                if (cmnd == "print" or cmnd == "p") {
                    graph.print_matrix(cout);
                } else if (cmnd == "bfs") {
                    bfs();
                } else if (cmnd == "dfs") {
                    dfs();
                } else if (cmnd == "quit" or cmnd == "q") {
                    running = false;
                } else {
                    cout << "Command not recognized! Try again." << endl;
                }
        }
        clean_up();
    }
    catch (const runtime_error& e) {
        cerr << e.what() << '\n';
        run();
    }
}


/* clean_up()
 *    Purpose: Print ending message for program.
 * Parameters: None
 *    Returns: None
 */
void PathFinder::clean_up()
{
    cout << "Thanks for finding paths and such" << endl;
}


/* get_airline()
 *    Purpose: Get random airline name from array.
 * Parameters: None
 *    Returns: None
 */
string PathFinder::get_airline()
{
    string airlines[] = {"Delta", "American Airlines", "Spirit", "Virgin",
                            "Jet Blue", "Southwest", "United"};
    int random = rand() % 7;
    return airlines[random];
}


/* populate_graph()
 *    Purpose: Set up graph of cities using data from a filestream.
 * Parameters: ifstream &data - contents of file dictating cities and their
 *                              connections
 *    Returns: None
 */
void PathFinder::populate_graph(std::ifstream &data)
{
    string vertex = "";
    vector<City> cities;

    while (data >> vertex) {
        City c(vertex);
        while (data >> vertex) {
            if (vertex == "###") {
                cities.push_back(c);
                break;
            } else {
                c.add_neighbor(vertex);
            }
        }
    }

    graph.initialize_graph(cities.size());

    /* dont worry too much about the for loop syntax here!
     * essentially 'auto' tells the complier to deduce the type
     * and the colon (:) is used to iterate through each element
     * in cities
     */
    for (auto &city : cities) {
        graph.add_vertex(city);
    }
    for (auto &city : cities) {
        for (auto &edge: city.get_neighbors()) {
            graph.add_edge(city, edge, get_airline());
        }
    }
}
