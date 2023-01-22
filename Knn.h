// Bar Kirshenboim & Noa Dolev
// this is header of KNN algorithm file

#include <math.h>
#include <iostream>
#include <vector>

#include <map>

#include "Distance.h"
#include "DataSetsHandler.h"

using namespace std;

class Knn {
public:
/**
* funcName: calcWayOfDist
* this function finding and returning the way to calculate distance,
* based on which formula.
* 
* in case entered an un valid distance type, then returning default == minikowski
* 
* @param keyword - the name of distance type
* @return Distance&, the type of distance for calculating.
*/
    static Distance &calcWayOfDist(string keyword);

/**
 * funcName: inTypesList
 * this func is responsible for determine if a given string is in a given map<str,int> already.
 * @param curType - string we want to know if contained in kTypes
 * @param kTypes - map of str,int 
 * @return true if exist, false otherwise
 * 
*/
    bool inTypesList(string curType, map<string, int> kTypes);

/**
 * funcName: coutTypesAppear
 * this func is responsible for creating a map of the k 
 * nearest types with their number of occur out of the map with vectors and types.
 * @param m - the data base with distances, vectors values, types
 * @param k - the number of how many neighbours we need to look at.
 * @return map with counted knn types
 * 
*/
    map<string, int> countTypesAppear(map<vector<double>, string> m, int k);


/**
 * funcName: mostOccurType
 * this func is responsible for finding the node with maximal value
 * @param countTypes - map: strings->keys, int->values
 * @return string of the string with highest int value 
*/
    string mostOccurType(map<string, int> countTypes);

/**
* funcName: dataSetWithDistance
* this function creates a map<vector<double>, string>,
* so first element in vector is distance from a given vector calculated by given distance type
* @param inputVec - vector for distance calculating
* @param m - our data base, map with vectors and types.
* @param k - the number of how many neighbours we need to look at.
* @param calcWay - the string of the way to calculate distance
* @return map, new data base with first element in vector of distance from the input vector
*/
    map<vector<double>, string>
    dataSetForAlg(vector<double> inputVec, map<vector<double>, string> m, string calcWay, int k);
};
