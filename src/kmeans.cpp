#include "kmeans.h"

using namespace ADJZAI001_kmeans;

data_point::data_point() : x(0), y(0) {}

data_point::data_point(int n, float x, float y) : number(n), x(x), y(y) {}

double data_point::operator-(const data_point & other) {
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}

data_point data_point::operator+(const data_point & other) {
    data_point point;
    point.x = this->x + other.x;
    point.y = this->y + other.y;
    return point;
}

data_point data_point::operator/(int denom) {
    data_point point;
    point.x = this->x / denom;
    point.y = this->y / denom;
    return point;
}

bool data_point::operator==(const data_point & other) const {
    return this->x == other.x && this->y == other.y;
}

cluster::cluster() : number(0), centroid() {}

cluster::cluster(int n, data_point c) : number(n), centroid(c) {}

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

std::ostream & ADJZAI001_kmeans::operator<<(std::ostream & os, const data_point & point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

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
}

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

    for (int c = 0; c < clusters.size(); ++c) {
        clusters[c].find_centroid();
    }
}