#include "kmeans.h"

using namespace ADJZAI001;

DataPoint::DataPoint() : x(0), y(0) {}

DataPoint::DataPoint(int n, float x, float y) : number(n), x(x), y(y) {}

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

bool DataPoint::operator==(const DataPoint & otherPoint) const {
    return this->x == otherPoint.x && this->y == otherPoint.y;
}

Cluster::Cluster() : number(0), centroid() {}

Cluster::Cluster(int n, DataPoint c) : number(n), centroid(c) {}

void Cluster::findCentroid() {
    DataPoint sum;
    for (DataPoint point : points) {
        sum = sum + point;
    }
    centroid = sum / points.size();
}

bool Cluster::operator==(const Cluster & otherCluster) const {
    return this->points == otherCluster.points &&
           this->centroid == otherCluster.centroid;
}

std::ostream & ADJZAI001::operator<<(std::ostream & os, const DataPoint & point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

std::ostream & ADJZAI001::operator<<(std::ostream & os, const Cluster & cluster) {
    os << "Cluster " << cluster.number << ": ";

    int i = 0;
    for (; i<cluster.points.size()-1; ++i) {
        os << cluster.points[i].number << ", ";
    }
    os << cluster.points[i].number << std::endl;

    os << "Centroid: " << cluster.centroid;
    return os;
}

void ADJZAI001::assignClusters(std::vector<Cluster> & clusters, std::vector<DataPoint> & points) {
    for (int c = 0; c < clusters.size(); ++c) {
        clusters[c].points.clear();
    }

    for (DataPoint p : points) {
        double smallestDistance = std::numeric_limits<double>::max();
        int nearestCluster = -1;

        for (int i = 0; i < clusters.size(); ++i) {
            double distance = p - clusters[i].centroid;
            if (distance < smallestDistance) {
                smallestDistance = distance;
                nearestCluster = i;
            }
        }
        clusters[nearestCluster].points.push_back(p);
    }

    for (int c = 0; c < clusters.size(); ++c) {
        clusters[c].findCentroid();
    }
}