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
#include <limits>

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
            DataPoint(int number, float x, float y);
            double operator-(const DataPoint & otherPoint);
            DataPoint operator+(const DataPoint & otherPoint);
            DataPoint operator/(int denom);
    };

    class Cluster {
        public:
            int number;
            DataPoint centroid;
            std::vector<DataPoint> points;
            Cluster(int number, DataPoint centroid);
            void findCentroid();
    };

    std::ostream & operator<<(std::ostream & os, const DataPoint & point);
    std::ostream & operator<<(std::ostream & os, const Cluster & cluster);
    void assignClusters(std::vector<Cluster> & clusters, std::vector<DataPoint> & points);

}

#endif