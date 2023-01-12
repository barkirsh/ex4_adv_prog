// Bar Kirshenboim & Noa Dolev

#include "Distance.h"

double Minikovski::calculateDistance(vector<double> v, vector<double> u) {
    // (.... + (|vi-ui|^p)... + )^(1/p)  p is int const we choose
    double sum = 0;
    double result;
    double sumMember;
    for (int i = 0; i < v.size(); i++) {
        sumMember = fabs(v[i] - u[i]);
        sum = sum + pow(sumMember, 2); // calculating sum by formula
    }
    result = (double) pow(sum, 1.0 / 2);

    return result;
}
