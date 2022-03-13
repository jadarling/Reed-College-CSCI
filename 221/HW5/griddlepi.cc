#include<iostream>
#include<cmath>
using namespace std;

double gridpi(unsigned npoints){ 
    long double rSquared = pow(npoints,2); //evaluate total point amount (Area of square or r^2)
    double piEst = 0.0; //init pi estimation
    long double piOverFour = 0; //init area of circle / area of square ... it was very upset if i didn't split these (especially non-constant)
    long double circlePoints = 0; //init circle points value
    for (int pointX = 0; pointX<npoints; ++pointX){ //for each value of x...
        for (int pointY = 0; pointY<npoints; ++pointY){ //and for each value of y...
            if (pow(pointX,2) + pow(pointY,2) <= rSquared){ //If the x,y pair is in the circle...
                ++circlePoints;}}} //add to area of the circle
    piOverFour = circlePoints / rSquared;
    piEst = piOverFour* 4;
    return piEst;
}


int main() {
    const int n = 1000;
    double maybePi = gridpi(n);
    cout << "Pi is estimated to be: " + to_string(maybePi) + " for " + to_string(n) + " points. \n";
    return 0;
}