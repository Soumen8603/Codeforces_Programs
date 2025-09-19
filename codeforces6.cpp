#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    long t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vector<double>dist(n);
        for (int i = 0; i < n; i++)
        {
            cin >> dist[i];
        }
        double d = sqrt(((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)));
        double total_dist = d;
        double max_len = d;
        for (int i = 0; i < n; i++)
        {
            total_dist += dist[i];
            max_len = max(max_len, dist[i]);
        }
        total_dist -= max_len;
        if (max_len > total_dist)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}