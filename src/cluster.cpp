/****************************************************************/
/* Includes
/****************************************************************/

#include "kmeans.h"

using namespace ADJZAI001_kmeans;

/****************************************************************/
/* cluster attributes
/****************************************************************/

cluster::cluster() : number(0), centroid() {}

cluster::cluster(int n, data_point c) : number(n), centroid(c) {}

// recalculates centroid for cluster after points are assigned
void cluster::find_centroid() {
    data_point sum;
    for (data_point point : points) {
        sum = sum + point;
    }
    this->centroid = sum / points.size();
}

bool cluster::operator==(const cluster & other) const {
    return this->points == other.points &&
           this->centroid == other.centroid;
}