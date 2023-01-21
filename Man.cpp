// Bar Kirshenboim & Noa Dolev

# include "Distance.h"

double Man::calculateDistance(vector<double> v, vector<double> u) {
//   ....+|vi - ui|+....
    double sum = 0;
    double result;
    double sumMember;
    for (int i = 0; i < v.size(); i++) {
        sumMember = fabs(v[i] - u[i]);
        sum = sum + sumMember; // calculating sum by formula
    }
    result = (double) sum;

    return result;
}