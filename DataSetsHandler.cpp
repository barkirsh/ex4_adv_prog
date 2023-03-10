// Bar Kirshenboim & Noa Dolev
#include "DataSetsHandler.h"
#include <sstream>

// the function gets a vector that contains the lines from the file and return a map
map<vector<double>, string> DataSetsHandler::createFileDataSet(vector<string> dataVec) {
    // Create an empty map
    map<vector<double>, string> m;
    int lineCounter = 0;
    int lineLength = 0;
    vector<string> temp; // temp string vector from the line we read
    string value; // type of object.
    string field; // part of the line that we divide

    // Read the vector line by line
    for (string line: dataVec) {
        vector<double> vec; // vector that we get from line that v(0) = dist, this vector will be inserted into map.

        lineCounter++;
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

vector<double> DataSetsHandler::createVectorFromVectorString(vector<string> vec_str) {
    vector<double> v;
    for (const auto & i : vec_str) {
        try {
            if (checkInput(i)) {
                v.push_back(stod(i));
            }
        } catch (const invalid_argument &ia) {
            throw invalid_argument("Wrong input");
        }
    }
    return v;
}

bool DataSetsHandler::hasEnding(string fullString, string ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

bool DataSetsHandler::checkInput(string word) {
    // too long number will be overflow
    if (word.length() >= 300) {
        return false;
    }

    bool isPoint = false;

    string newWord;

    // last word in every line contains \r
    if (hasEnding(word, "\r")) {
        for (int i = 0; i < word.length() - 1; i++) {
            newWord += word[i];
        }
    } else {
        newWord = word;
    }

    // the word must start with a digit or - to be a number
    if (!isdigit(newWord[0])) { // if starts without a number

        if (newWord[0] == '.') {
            isPoint = true;
        } else if (newWord[0] != '-' && newWord[0] != '+') {
            return false;
        } else if (!isdigit(newWord[1])) { // if - and then another sign that is not a number
            return false;
        }
    }

    for (int j = 1; j < newWord.length(); j++) {
        if (newWord[j] == '-' || newWord[j] == '+') { // having +/- at curr char
            if (j == newWord.length() - 1) { // last char is a sigh
                return false;
            } else if ((newWord[j - 1] == 'e' || newWord[j - 1] == 'E') &&
                       (isdigit(newWord[j + 1]))) { // +/- between e to digit
                continue;
            }
            return false;

        }
        if (newWord[j] == 'e' || newWord[j] == 'E') { // curr char is e
            if (j == newWord.length() - 1) { // last char
                return false;
            } else if (newWord[j + 1] == '-' || newWord[j + 1] == '+') { // after e there is +/- sign
                if (j == newWord.length() - 2) { // the sign is last char
                    return false;
                }
                isPoint = true;
                continue;
            }
        }
        if (newWord[j] == '.') { // checking if its double
            if (isPoint) {
                return false;
            }
            isPoint = true;
            if (j == newWord.length() - 1 || (newWord[j + 1] == 'e' || newWord[j + 1] == 'E')) {
                return true;
            } else if (!isdigit(newWord[j + 1])) { // after point there is not a number
                return false;
            }
        } else if (!isdigit(newWord[j])) { // any other char beside numbers/ .
            return false;
        }
    }

    return true;
}
