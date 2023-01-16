// Bar Kirshenboim & Noa Dolev

#include "ValidationClient.h"
#include <sstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <stdexcept> // std::invalid_argument

bool isValidIP(string str) {
    // Split the string by the '.' delimiter
    std::stringstream ss(str);
    std::string token;
    int count = 0;
    while (std::getline(ss, token, '.')) {
        ++count;
        // If there are more or less than 4 tokens, it is not a valid IP address
        if (count > 4) {
            return false;
        }
        try {
            // Check that each token is a number between 0 and 255
            int num = std::stoi(token);
            if (num < 0 || num > 255) {
                return false;
            }
        }
        catch (...) {
            return false;
        }
    }
    // Return true if there are exactly 4 tokens
    return count == 4;
}

bool isValidPort(string str) {
    int portNum;
    try {
        portNum = stoi(str);
        if (portNum < 1024 || portNum > 65535) {
            return false;
        }
    }
    catch (const invalid_argument &ia) {
        return false;
    }
    return true;
}

void deleteAllocationCstr(char **str_array, int num_words) {
    for (int i = 0; i < num_words; i++) {
        delete[] str_array[i];
    }
    delete[] str_array;
}

bool checkInputClient(string str) { //"1 2 2 3 man 3"=> ["1 2 2 3" , "man" , "3"]

    bool result = true;
    str = strToUpper(str);
    // reference the given str as array of strings
    stringstream ss(str);
    string word;
    vector <string> words;
    while (ss >> word) {
        words.push_back(word);
    }

// Convert the vector of strings to an array of strings
    int num_words = words.size();
    if (num_words < 3) {
        return false;
    }
    char **str_array = new char *[num_words];
    for (int i = 0; i < num_words; i++) {
        int word_length = words[i].size();
        str_array[i] = new char[word_length + 1];
        strcpy(str_array[i], words[i].c_str());
    }


    // start checking the string input we got
    if (!KIsValid(str_array[num_words - 1])) { // k is supposed to be the last element
        result = false;
        deleteAllocationCstr(str_array, num_words);  // Don't forget to deallocate the memory!
        return result;
    } else if (!CurrStrIsDistance(str_array[num_words - 2])) { // distance supposed to be one before last element
        result = false;
        deleteAllocationCstr(str_array, num_words);  // Don't forget to deallocate the memory!
        return result;
    }
    if (num_words < 3) {
        deleteAllocationCstr(str_array, num_words);  // Don't forget to deallocate the memory!
        return result;
    }
    // create the vector from cstr(array of  strings) to a string : "v0 v1 v2 ... vn"
    // initializing vector string, each element cant be more than 300 chars & for each element we save space for SPACE
    char *vector = new char[4096];
    //    ^  600 * (num_words - 2) the actual max needed space, but we were told max input len = 4096
    strcpy(vector, str_array[0]);   // first element doesnt have SPACE char before
    for (int i = 1; i < num_words - 2; i++) { // creating the string for vector : "v0 v1 v2 ... vn"
        strcat(vector, " ");
        strcat(vector, str_array[i]);
    }
    // after creating the string of vector. we will check if it is valid
    if (!checkStrVector(vector)) {
        result = false;
        deleteAllocationCstr(str_array, num_words);  // Don't forget to deallocate the memory!
        delete[] vector;
        return result;

    }
    delete[] vector;
    deleteAllocationCstr(str_array, num_words);  // Don't forget to deallocate the memory!
    return result; // if input string is build as: "vector dist k"
}

bool KIsValid(string str) {
    int k; //  k param value
    try {
        k = stoi(str);
    } catch (const invalid_argument &ia) {
        return false;
    }
    if (k <= 0) {
        return false;
    }
    return true;
}

string strToUpper(string word) {
    for (char &c: word) {
        c = std::toupper(c);
    }
    return word;
}


bool CurrStrIsDistance(string str) {
    str = strToUpper(str);
    // if given str is a number based on our checks
    if (checkInput(str)) {
        return false;
    } else if (str == "AUC") {
        return true;
    } else if (str == "MAN") {
        return true;
    } else if (str == "CHB") {
        return true;
    } else if (str == "CAN") {
        return true;
    } else if (str == "MIN") {
        return true;
    } else {        // the given string that suppose to be a distance type isn't a distance
        return false;
    }

}

bool checkStrVector(string str) {
    stringstream ss(str);
    string word;
    // split the string into words seperated by spaces.
    while (ss >> word) {
        try {
            // if element of str vector is correct - continuing, otherwise
            if (checkInput(word)) {
                continue;
            } else {
                return false;
            }
        }
            // the word is not number
        catch (const invalid_argument &ia) {
            return false;
        }
    }
    return true;
}

bool checkInput(string word) {
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

