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

namespace ADJZAI001_kmeans {

    struct data_point {
        int number;
        float x;
        float y;
        data_point();
        data_point(int number, float x, float y);
        double operator-(const data_point & other);
        data_point operator+(const data_point & other);
        data_point operator/(int denom);
        bool operator==(const data_point & other) const;
    };

    struct cluster {
        int number;
        data_point centroid;
        std::vector<data_point> points;
        cluster();
        cluster(int number, data_point centroid);
        void find_centroid();
        bool operator==(const cluster & other) const;
    };

    std::ostream & operator<<(std::ostream & os, const data_point & point);
    std::ostream & operator<<(std::ostream & os, const cluster & cluster);
    void load_data(std::vector<data_point> & points, std::string filename);
    void assign_clusters(std::vector<cluster> & clusters, const std::vector<data_point> & points);
}

#endif