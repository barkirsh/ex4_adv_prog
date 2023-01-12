// Bar Kirshenboim & Noa Dolev
#include "DataSetsHandler.h"
#include <sstream>
#include <fstream>


map <vector<double>, string> DataSetsHandler::createFileDataSet(ifstream &file) {
    // Create an empty map
    map <vector<double>, string> m;
    int lineCounter = 0;
    int lineLength = 0;

    // Read the file line by line
    string line;
    while (getline(file, line)) {//each time reading next line
        lineCounter++;
        // Parse the line to extract the vector and the string
        stringstream ss(line);
        vector <string> temp; // temp string vector from the line we read
        vector<double> vec; // vector that we get from line that v(0) = dist, this vector will be inserted into map.
        string value; // type of object.
        string field; // part of the line that we divide

        // reading a line(words seperated by ',') into vector
        while (getline(ss, field, ',')) {
            temp.push_back(field);
        }
        for (int j = 0; j < temp.size() - 1; j++) {
            try {
                // Convert the field to a double value and add it to the vector
                if (checkInput(temp.at(j))) {
                    vec.push_back(stod(temp.at(j)));
                }
            }
            catch (const invalid_argument &ia) {
                throw invalid_argument("Wrong Input");
            }
        }
        if (lineCounter == 1) {
            lineLength = vec.size();
        } else {
            if (vec.size() != lineLength) {
                throw invalid_argument("Wrong Input");
            }
        }
        // the string type
        value = temp.back();
        temp.clear();
        // Insert the vector and the string into the map
        m.emplace(vec, value);
    }

    return m;
}

vector<double> DataSetsHandler::createVector(string str) {
    vector<double> v;
    stringstream ss(str);
    string word;
    // split the string into words seperated by spaces.
    while (ss >> word) {
        try {
            if (checkInput(word)) {
                //trying entering the numbers to vector
                v.push_back(stod(word));
            }
        }
            // the word is not number
        catch (const invalid_argument &ia) {
            perror("worng input");
        }
    }
    return v;
}

vector<double> DataSetsHandler::createVectorFromVectorString(vector <string> vec_str) {
    vector<double> v;
    for (int i = 0; i < vec_str.size(); i++) {
        try {
            if (checkInput(vec_str.at(i))) {
                v.push_back(stod(vec_str.at(i)));
            }
        } catch (const invalid_argument &ia) {
            throw invalid_argument("Wrong input");
        }
    }
    return v;
}