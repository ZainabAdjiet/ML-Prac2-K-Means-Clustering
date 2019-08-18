/****************************************************************/
/* Includes
/****************************************************************/

#include "kmeans.h"

using namespace ADJZAI001_kmeans;

/****************************************************************/
/* General K-Means Clustering program functions
/****************************************************************/

// loads data points from text file
void ADJZAI001_kmeans::load_data(std::vector<data_point> & points, std::string filename) {
    std::ifstream data(filename);
    std::string line;

    if (data.is_open()) {
        getline(data, line); // discard header line

        while (getline(data, line)) {
            int number;
            float x, y;

            std::istringstream temp(line);
            temp >> number;
            temp >> x;
            temp >> y;
            
            points.push_back(data_point(number, x, y));
        }

        data.close();
    }
    else {
        std::cout << "could not load data from " << filename << std::endl;
    }
}

// assigns data points to nearest cluster based on distance from their centroids
void ADJZAI001_kmeans::assign_clusters(std::vector<cluster> & clusters, const std::vector<data_point> & points) {
    for (int c = 0; c < clusters.size(); ++c) {
        clusters[c].points.clear();
    }

    for (data_point p : points) {
        double smallest_distance = std::numeric_limits<double>::max();
        int nearest_cluster = -1;

        for (int i = 0; i < clusters.size(); ++i) {
            double distance = p - clusters[i].centroid;
            if (distance < smallest_distance) {
                smallest_distance = distance;
                nearest_cluster = i;
            }
        }
        clusters[nearest_cluster].points.push_back(p);
    }

    // recalculates centroid for new set of points
    for (int c = 0; c < clusters.size(); ++c) {
        clusters[c].find_centroid();
    }
}

/****************************************************************/
/* Stream operators
/****************************************************************/

// prints out point in format "(x, y)"
std::ostream & ADJZAI001_kmeans::operator<<(std::ostream & os, const data_point & point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

// prints out cluster points and centroid
std::ostream & ADJZAI001_kmeans::operator<<(std::ostream & os, const cluster & cluster) {
    os << "Cluster " << cluster.number << ": ";

    int i = 0;
    for (; i<cluster.points.size()-1; ++i) {
        os << cluster.points[i].number << ", ";
    }
    os << cluster.points[i].number << std::endl;

    os << "Centroid: " << cluster.centroid;
    return os;
}