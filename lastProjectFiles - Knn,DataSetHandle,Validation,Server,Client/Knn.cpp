// Bar Kirshenboim & Noa Dolev
// CPP program for implementation of our KNN algorithm

#include "Knn.h"


Distance &Knn::calcWayOfDist(string keyword) {
    if (keyword == "AUC") {
        static Euc euc;
        return euc;
    } else if (keyword == "MAN") {
        static Man man;
        return man;
    } else if (keyword == "CHB") {
        static Cheb chb;
        return chb;
    } else if (keyword == "CAN") {
        static Can can;
        return can;
    } else if (keyword == "MIN") {
        static Minikovski min;
        return min;
    } else {
        throw "Wrong input";
    }
}

bool Knn::inTypesList(string curType, map<string, int> kTypes) {
    for (std::map<string, int>::iterator it = kTypes.begin(); it != kTypes.end(); ++it) {
        if (curType.compare(it->first) == 0) { //if there is a key that is equal to given string.
            return true;
        }
    }
    return false;
}

map<string, int> Knn::countTypesAppear(map <vector<double>, string> m, int k) {
    string curType;
    int count;
    map<string, int> kTypes;

    // going through given map and
    // creating a new map with the K the nearest types with the number of their occurrence as values.
    for (std::map < vector < double > , string > ::iterator it = m.begin(); it != m.end() && k > 0;
    ++it) {
        curType = it->second; // get the node's type(string part of node)
        if (!inTypesList(curType, kTypes)) { //if we haven't already entered this exact string to new map
            kTypes.emplace(curType, 1);
        } else {
            count = kTypes.at(curType) + 1;
            kTypes.erase(curType);
            kTypes.emplace(curType, count);
        }
        k--;
    }
    return kTypes; // returning map <string=types,int= OccurrenceNum>
}


string Knn::mostOccurType(map<string, int> countTypes) {
    int max = 0;
    string mostOccur;
    for (std::map<string, int>::iterator it = countTypes.begin(); it != countTypes.end(); ++it) {
        if (it->second > max) {
            max = it->second; // cur max occur num
            mostOccur = it->first; // string part of node that has the cur max value of occur
        }
    }

    return mostOccur; // returning the type with the most occurrence from the nearest K vectors.
}

map <vector<double>, string>
Knn::dataSetForAlg(vector<double> inputVec, map <vector<double>, string> m, string calcWay, int k) {
    map <vector<double>, string> mapForAlg;
    vector<double> curVec;
    for (std::map < vector < double > , string > ::iterator it = m.begin(); it != m.end(); ++it) {
        curVec = it->first;

        // the vector is not at the same size as the input vector - cant calculate distance
        if (inputVec.size() != curVec.size()) {
            throw invalid_argument("Wrong Input");
        }
        //calculating distance between curVec and inputVec
        double distance = (Knn::calcWayOfDist(calcWay)).calculateDistance(inputVec, curVec);
        // inserting distance as first element of vector
        curVec.insert(curVec.begin(), distance);
        // inserting the new vector to sorted place of new map
        mapForAlg.emplace(curVec, it->second);
    }
    return mapForAlg;
}


