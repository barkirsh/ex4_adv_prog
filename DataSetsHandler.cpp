// Bar Kirshenboim & Noa Dolev
#include "DataSetsHandler.h"
#include <sstream>

// the function gets a vector that contains the lines from the file and return a map
map <vector<double>, string> DataSetsHandler::createFileDataSet(vector<string> dataVec) {
    // Create an empty map
    map <vector<double>, string> m;
    int lineCounter = 0;
    int lineLength = 0;
    vector <string> temp; // temp string vector from the line we read
    string value; // type of object.
    string field; // part of the line that we divide

    // Read the vector line by line
    for (string line: dataVec) {
        vector<double> vec; // vector that we get from line that v(0) = dist, this vector will be inserted into map.

        lineCounter ++;
        // Parse the line to extract the vector and the string
        stringstream ss(line);

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
    while (getline(ss, word, ',')) {
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

bool DataSetsHandler::checkInput(string word) {
    // too long number will be overflow
    if (word.length() >= 300) {
        return false;
    }

    bool isPoint = false;

    // the word must start with a digit or - to be a number
    if (!isdigit(word[0])) { // if starts without a number

        if (word[0] == '.') {
            isPoint = true;
        } else if (word[0] != '-' && word[0] != '+') {
            return false;
        } else if (!isdigit(word[1])) { // if - and then another sign that is not a number
            return false;
        }
    }

    for (int j = 1; j < word.length(); j++) {
        if (word[j] == '-' || word[j] == '+') { // having +/- at curr char
            if (j == word.length() - 1) { // last char is a sigh
                return false;
            } else if ((word[j - 1] == 'e' || word[j - 1] == 'E') && (isdigit(word[j + 1]))) { // +/- between e to digit
                continue;
            }
            return false;

        }
        if (word[j] == 'e' || word[j] == 'E') { // curr char is e
            if (j == word.length() - 1) { // last char
                return false;
            } else if (word[j + 1] == '-' || word[j + 1] == '+') { // after e there is +/- sign
                if (j == word.length() - 2) { // the sign is last char
                    return false;
                }
                isPoint = true;
                continue;
            }
        }
        if (word[j] == '.') { // checking if its double
            if (isPoint) {
                return false;
            }
            isPoint = true;
            if (j == word.length() - 1 || (word[j + 1] == 'e' || word[j + 1] == 'E')) {
                return true;
            } else if (!isdigit(word[j + 1])) { // after point there is not a number
                return false;
            }
        } else if (!isdigit(word[j])) { // any other char beside numbers/ .
            return false;
        }
    }

    return true;
}
