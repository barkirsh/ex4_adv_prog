
#include <map>

#include <math.h>
#include <iostream>
#include <vector>
#include "ValidationClient.h"

using namespace std;

class DataSetsHandler {
public:

    /**
    * funcName: createDataset
    * this function creates a map<vector<double>, string> based on data from a given file
    * @param file - the file we create from our data base
    * @return map, the data base
    */
    map<vector<double>, string> createFileDataSet(vector<string> vec);

    /**
    * server creating vector based on a given string that we know is correct to be convert to vector
    * @param str - a string
    * @return a vector of double
    */
    vector<double> createVector(string str);

    /**
   * server creating vector of double based on a given vector of strings that can be converted to double.
   * @param vec_str - vector of strings
   * @return a vector of double
   */
    vector<double> createVectorFromVectorString(vector<string> vec_str);

    /**
     * check if a string ends with a string
     * @param fullString
     * @param ending
     * @return
     */
    static bool hasEnding(string fullString, string ending);

    /**
 * funcName: checkInput
 * This function check if a string is a number (int or double)
 * and return a boolean answer.
 * @param word - a string
 */
    bool checkInput(string word);
};