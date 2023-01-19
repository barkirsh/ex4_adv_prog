// Bar Kirshenboim & Noa Dolev

#include "Distance.h"

double Can::calculateDistance(vector<double> v, vector<double> u) {
    // ....+(|vi - ui|)/(|vi|+|ui|) +...
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0 && u[i] == 0) {
            return -1;
        }
        sum = sum + fabs(v[i] - u[i]) / (fabs(v[i]) + fabs(u[i])); //calculating by formula
    }
    return sum;
}