// Bar Kirshenboim & Noa Dolev

#ifndef EX3_VALIDATION_CLIENT_H
#define EX3_VALIDATION_CLIENT_H

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;
bool isValidIP(string str);
/**
 * funcName: isValidPort
 * check if given port argument is valid
 * @param str - port given as string
 * @return true if valid, false otherwise
 */
bool isValidPort(string str);

/**
 * funcName: deleteAllocationCstr
 * deleting a dynamic array we alloc space to
 * @param str_array   - array we allocate space to
 * @param num_words - number of words to delete
 */
void deleteAllocationCstr(char **str_array, int num_words);

/**
 * funcName: checkInputClient
 * this function is getting the input we enter as users and check if it valid.
 * @param str - user input
 * @return if structure of input is "v0 v1 ... vn distance k" true, else - false
 */
bool checkInputClient(string str);

/**
 * funcName: strToUpper
 * @param word - string
 * @return the string after changing letters to big letters
 */
string strToUpper(string word);

/**
 * funcName: KIsValid
 * @param str - string that suppose to include k value
 * @return true if k is an un negative integer, else false
 */
bool KIsValid(string str);

/**
 * funcName: CurrStrIsDistance
 * @param str suppose to be distance type
 * @return true if it a distance type, false otherwise
 */
bool CurrStrIsDistance(string str);

/**
 * funcName: checkStrVector
 * @param str - vector given as string from user
 * @return true if valid and its ok to create vector, else false
 */
bool checkStrVector(string str);

/**
 * funcName: checkInput
 * This function check if a string is a number (int or double)
 * and return a boolean answer.
 * @param word - a string
 */
bool checkInput(string word);


#endif //EX3_VALIDATION_CLIENT_H