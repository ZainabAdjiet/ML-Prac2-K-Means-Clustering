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

/****************************************************************/
/* Functions												    */
/****************************************************************/

namespace ADJZAI001 {

    class DataPoint {
        public:
            int number;
            float x;
            float y;
            float operator-(const DataPoint & otherPoint);
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