#include "kmeans.h"

using namespace ADJZAI001;
using namespace std;

int main(int argc, char const *argv[])
{
    vector<DataPoint> dataPoints = {
        DataPoint(1,2,10), DataPoint(2,2,5), DataPoint(3,8,4), DataPoint(4,5,8),
        DataPoint(5,7,5), DataPoint(6,6,4), DataPoint(7,1,2), DataPoint(8,4,9)
    };

    vector<Cluster> clusters = {
        Cluster(1, dataPoints[0]), Cluster(2, dataPoints[3]), Cluster(3, dataPoints[6])
    };

    assignClusters(clusters, dataPoints);

    for (Cluster c : clusters) {
        cout << c << endl;
    }

    return 0;
}
