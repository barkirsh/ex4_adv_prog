// Bar Kirshenboim & Noa Dolev

#include "Distance.h"


double Cheb::calculateDistance(vector<double> v, vector<double> u) {
//max(.... (|vi-ui|)... ) 
    double max = 0;
    for (int i = 0; i < v.size(); i++) {
        if (max <= fabs(v[i] - u[i])) {
            max = fabs(v[i] - u[i]); //calculating by formula, finding max 
        }
    }
    return max;
}
