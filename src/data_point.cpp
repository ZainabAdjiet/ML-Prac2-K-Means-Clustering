/****************************************************************/
/* Includes
/****************************************************************/

#include "kmeans.h"

using namespace ADJZAI001_kmeans;

/****************************************************************/
/* data_point attributes
/****************************************************************/

data_point::data_point() : x(0), y(0) {}

data_point::data_point(int n, float x, float y) : number(n), x(x), y(y) {}

//calculates Euclidean distance between x,y points
double data_point::operator-(const data_point & other) {
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}

// sums 2 x,y points
data_point data_point::operator+(const data_point & other) {
    data_point point;
    point.x = this->x + other.x;
    point.y = this->y + other.y;
    return point;
}

// used to calculate mean of cluster
data_point data_point::operator/(int denom) {
    data_point point;
    point.x = this->x / denom;
    point.y = this->y / denom;
    return point;
}

bool data_point::operator==(const data_point & other) const {
    return this->x == other.x && this->y == other.y;
}
