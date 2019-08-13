#include "kmeans.h"

using namespace ADJZAI001;

DataPoint::DataPoint() : x(0), y(0) {}

DataPoint::DataPoint(float x, float y) : x(x), y(y) {}

double DataPoint::operator-(const DataPoint & otherPoint) {
    return sqrt(pow(this->x - otherPoint.x, 2) + pow(this->y - otherPoint.y, 2));
}

DataPoint DataPoint::operator+(const DataPoint & otherPoint) {
    DataPoint point;
    point.x = this->x + otherPoint.x;
    point.y = this->y + otherPoint.y;
    return point;
}

DataPoint DataPoint::operator/(int denom) {
    DataPoint point;
    point.x = this->x / denom;
    point.y = this->y / denom;
    return point;
}

void Cluster::findCentroid() {
    DataPoint sum;
    for (DataPoint point : points) {
        sum = sum + point;
    }
    centroid = sum / points.size();
}