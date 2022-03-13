#include<iostream>
#include<cmath>
using namespace std;

constexpr double gridpi(unsigned npoints){
    const long double rSquared = npoints * npoints; //evaluate total point amount (Area of square or r^2)
    double piEst = 0; //init pi estimation
    long double piOverFour = 0; //init area of circle / area of square ... it was very upset if i didn't split these
    long double circlePoints = 0; //Init circle points value
    for (int pointX = 0; pointX<npoints; ++pointX){ // for each value of x...
        for (int pointY = 0; pointY<npoints; ++pointY){ //and for each value of y...
            if ((pointX * pointX) + (pointY * pointY) <= rSquared){ //if the point is within the circle...
                ++circlePoints;}}} //add 1 to the area of the circle
    piOverFour = circlePoints / rSquared;
    piEst = piOverFour* 4;
    return piEst;
}


int main() {
    const int n = 1000;
    constexpr double maybePi = gridpi(n);
    cout << "Pi is estimated to be: " + to_string(maybePi) + " for " + to_string(n) + " points. \n";
    return 0;
}