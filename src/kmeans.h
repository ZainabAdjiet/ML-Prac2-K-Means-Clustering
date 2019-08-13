#ifndef KMEANS_H
#define KMEANS_H

/****************************************************************/
/* Includes														*/
/****************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

/****************************************************************/
/* Functions												    */
/****************************************************************/

namespace ADJZAI001 {

    class DataPoint {
        public:
            int number;
            float x;
            float y;
            DataPoint();
            DataPoint(float x, float y);
            double operator-(const DataPoint & otherPoint);
            DataPoint operator+(const DataPoint & otherPoint);
            DataPoint operator/(int denom);
    };

    class Cluster {
        public:
            int number;
            DataPoint centroid;
            std::vector<DataPoint> points;
            void findCentroid();
    };

    void assignClusters(std::vector<Cluster> & clusters, std::vector<DataPoint> & points);

}

#endif