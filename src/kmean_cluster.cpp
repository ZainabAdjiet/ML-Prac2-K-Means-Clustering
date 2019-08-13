#include "kmeans.h"

using namespace ADJZAI001;
using namespace std;

int main(int argc, char const *argv[])
{
    vector<DataPoint> dataPoints = {
        DataPoint(2,10), DataPoint(2,5), DataPoint(8,4), DataPoint(5,8),
        DataPoint(7,5), DataPoint(6,4), DataPoint(1,2), DataPoint(4,9)
    };

    float diff = dataPoints[0] - dataPoints[1];

    DataPoint sum = dataPoints[0] + dataPoints[2];

    DataPoint ave = sum / 2;

    Cluster cluster;
    cluster.points = { dataPoints[0], dataPoints[1] };
    cluster.findCentroid();

    cout << "Diff: " << diff << endl;
    cout << "Sum: " << sum.x << ", " << sum.y << endl;
    cout << "Average: " << ave.x << ", " << ave.y << endl;
    cout << "Cluster centroid: " << cluster.centroid.x << ", " << cluster.centroid.y << endl;

    return 0;
}
