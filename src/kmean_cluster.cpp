#include "kmeans.h"

using namespace ADJZAI001_kmeans;
using namespace std;

int main(int argc, char const *argv[]) {

    // check if input data file is specified
    if (argc > 1) {
        vector<data_point> data_points;
        load_data(data_points, argv[1]);    // load data points

        // set initial seeds: examples 1, 4, 7
        vector<cluster> clusters = {
            cluster(1, data_points[0]), cluster(2, data_points[3]), cluster(3, data_points[6])
        };

        ofstream out_file("output.txt");
        if (out_file.is_open()) {

            vector<cluster> prev_clusters;  // to test for convergence
            int iter = 0;   // iteration number
            do {
                ++iter;
                prev_clusters = clusters;
                assign_clusters(clusters, data_points); // assigns data points to nearest cluster

                // output clusters for current iteration
                out_file << "Iteration " << iter << ":" << endl;
                for (cluster c : clusters) {
                    out_file << c << endl;
                }
                out_file << endl;
            } while (clusters != prev_clusters);

            out_file << "Iterations to converge: " << --iter << endl;

            out_file.close();
        }
        else {
            cout << "could not write to output.txt" << endl;
            return 1;
        }

        return 0;
    }
    else {
        cout << "no file name specified" << endl;
        return 1;
    }
    
}
