#include <string>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

/***********************************/
class AdjacencyList {

private:
    int V; //the number of vertices
    map<string, map<string, double>> adList; // container for the vertices and their rank
    set<string> websitesSet; // main purpose is to count the number of vertices
    vector<string> toVector; // stores websites with incoming links
    vector<string> fromVector; // stores websites with outgoing links
    map<string, int> outDegree; // stores the outDegree of all the vertices
    map<string, double> rankMap; // stores the rank of the websites

public:
    AdjacencyList(int V);
    void PageRank(int p);
    void setOutDegree(vector<string> fromVector);
    map<string, int> getOutDegree();
    void setAdList(map<string, int> outDegree, vector<string> toVector, vector<string> fromVector);

    void setToVector(vector<string> toVector);
    void setFromVector(vector<string> fromVector);

    void setWebsitesSet(set<string> websitesSet);
    void initRankMap(); // initializes the map with websites and their rank
};

/***********************************/
void AdjacencyList::PageRank(int p){
    // prints the PageRank of all pages after p powerIterations in
    // ascending alphabetical order of webpages and rounding rank to two
    // decimal places

    // initialize the rankMap
    this->initRankMap();

    //implementing the multiplication
    double newNumber;
    map<string, double> newRankMap;

    for (int i = 0; i < p-1; i++) {
        for (auto it = this->adList.cbegin(); it != this->adList.cend(); ++it){
            newNumber = 0;
            for (auto jt = (*it).second.cbegin(); jt != (*it).second.cend(); ++jt){
                newNumber = newNumber + ((*jt).second)*(this->rankMap[(*jt).first]);
            }
            newRankMap[(*it).first] = newNumber;
        }
        this->rankMap = newRankMap;
    }

    for (auto itr = this->rankMap.cbegin(); itr != this->rankMap.cend(); ++itr){
        cout << (*itr).first << " ";
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << (*itr).second;
        cout << endl;
    }
}

// creates an adjacencyList with V number of vertices
AdjacencyList::AdjacencyList(int V) {
    this->V = V;
}

// yields the outdegree of the websites
void AdjacencyList::setOutDegree(vector<string> fromVector) {
    for (auto &i: fromVector){
        this->outDegree[i]++;
    }
}

// sets the toVector of the adList
void AdjacencyList::setToVector(vector<string> toVector) {
    this->toVector = toVector;
}

// sets the fromVector of the adList
void AdjacencyList::setFromVector(vector<string> fromVector) {
    this->fromVector = fromVector;
}

// returns the map with the websites and their outdegrees
map<string, int> AdjacencyList::getOutDegree() {
    return this->outDegree;
}

// sets the adjacency list with the appropriate values
void AdjacencyList::setAdList(map<string, int> outDegree, vector<string> toVector, vector<string> fromVector) {

    for (int i = 0; i < fromVector.size(); i++){
        this->adList[toVector.at(i)].insert({fromVector.at(i), (double) 1/outDegree[fromVector.at(i)]});
    }
}

// sets the websitesSet
void AdjacencyList::setWebsitesSet(set<string> websites) {
    this->websitesSet = websites;
}

// initializes the rank map
void AdjacencyList::initRankMap() {
    set<string>::iterator itr;
    for (itr = this->websitesSet.begin(); itr != this->websitesSet.end(); ++itr){
        this->rankMap[*itr] = (double) 1 / this->V;
    }
}


/****************************************/
int main()
{
    string no_of_lines, power_iterations;
    string from, to;

    string input;
    getline(cin, input);
    istringstream in(input);

    in >> no_of_lines;
    in >> power_iterations;
    int n = stoi(no_of_lines);
    int p = stoi(power_iterations);

    // taking input for the number of lines
    // cin >> no_of_lines;
    // taking input for the number of power iterations
    // cin >> power_iterations;

    set<string> websiteSet; // set to hold unique values of website
    vector<string> fromVector; // vector that holds websites that send link out
    vector<string> toVector; // vector that holds websites with incoming links

    //take entries
    for(int i = 0;i < n; i++)
    {
        string line;
        getline(cin, line);
        istringstream in(line);

        string from;
        in >> from;

        string to;
        in >> to;


        //cin >> from;
        //cin >> to;
        // inserting into the set to get count
        websiteSet.insert(from);
        websiteSet.insert(to);
        // inserting into the
        fromVector.push_back(from);
        toVector.push_back(to);
    }

    // Create a graph object
    int V = websiteSet.size();

    AdjacencyList Created_Graph = *new AdjacencyList(V);
    Created_Graph.setFromVector(fromVector);
    Created_Graph.setToVector(toVector);

    // set the websitesSet in the adjacency list
    Created_Graph.setWebsitesSet(websiteSet);
    // set the outDegrees of the website
    Created_Graph.setOutDegree(fromVector);
    // set the adj list for the graph
    Created_Graph.setAdList(Created_Graph.getOutDegree(), toVector, fromVector);
    // running the pagerank algorithm
    Created_Graph.PageRank(p);
}
