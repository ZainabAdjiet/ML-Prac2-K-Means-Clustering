#include "kmeans.h"

using namespace ADJZAI001_kmeans;
using namespace std;

int main(int argc, char const *argv[]) {

    if (argc > 1) {
        vector<data_point> data_points;
        load_data(data_points, argv[1]);

        vector<cluster> clusters = {
            cluster(1, data_points[0]), cluster(2, data_points[3]), cluster(3, data_points[6])
        };

        vector<cluster> prev_clusters;
        int iter = 1;
        do {
            prev_clusters = clusters;
            assign_clusters(clusters, data_points);
            cout << "Iteration " << iter << ":" << endl;
            for (cluster c : clusters) {
                cout << c << endl;
            }
            cout << endl;
            ++iter;
        } while (clusters != prev_clusters);

        return 0;
    }
    else {
        cout << "no file name specified" << endl;
        return 1;
    }
    
}
