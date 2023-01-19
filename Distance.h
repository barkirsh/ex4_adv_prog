// Bar Kirshenboim & Noa Dolev

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

class Distance {

private:

protected:

public:

    /**
    * funcName: calculateDistance
    * this func calculates the distance between to given vectors<double>
    * by a certain formula and returns it.
    * @param v - vector<double>
    * @param u - vector<double>
    * @return distance value
    */
    virtual double calculateDistance(vector<double> v, vector<double> u) = 0;

    /**
    * funcName: isInteger
    * @param num - value that need to be checked
    * returns if is int
    */
    bool isInteger(double num);

};

class Cheb : public Distance {
public:
    /**
    * funcName: calculateDistance
    * this func calculates the distance between to given vectors<double>
    * by a certain formula and returns it.
    * formula: max(.... (|vi-ui|)... ) 
    * @param v - vector<double>
    * @param u - vector<double>
    * @return distance value
    */
    double calculateDistance(vector<double> v, vector<double> u);
};

class Minikovski : public Distance {
public:
    /**
    * funcName: calculateDistance
    * this func calculates the distance between to given vectors<double>
    * by a certain formula and returns it.
    * formula: (.... + (|vi-ui|^p)... + )^(1/p)  p is int const we choose 
    * - for this ex we chose p=2
    * @param v - vector<double>
    * @param u - vector<double>
    * @return distance value
    */
    double calculateDistance(vector<double> v, vector<double> u);
};

class Euc : public Minikovski {
public:
    /**
    * funcName: calculateDistance
    * this func calculates the distance between to given vectors<double>
    * by a certain formula and returns it.
    * formula : sqrt(....+|vi - ui|^2+....) , private case of minikowski
    * @param v - vector<double>
    * @param u - vector<double>
    * @return distance value
    */
    double calculateDistance(vector<double> v, vector<double> u);
};

class Man : public Distance {
public:
    /**
    * funcName: calculateDistance
    * this func calculates the distance between to given vectors<double>
    * by a certain formula and returns it.
    * formula : ....+|vi - ui|+.... 
    * @param v - vector<double>
    * @param u - vector<double>
    * @return distance value
    */
    double calculateDistance(vector<double> v, vector<double> u);
};

class Can : public Distance {
public:
    /**
    * funcName: calculateDistance
    * this func calculates the distance between to given vectors<double>
    * by a certain formula and returns it.
    * formula :  ....+(|vi - ui|)/(|vi|+|ui|) +... 
    * @param v - vector<double>
    * @param u - vector<double>
    * @return distance value
    */
    double calculateDistance(vector<double> v, vector<double> u);
};
