#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <float.h>
using namespace std;
struct Point {
int x, y;
};
float distance(Point p1, Point p2) {
return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(vector<Point>& points, int left, int right) {
float minDist = FLT_MAX;
for (int i = left; i < right; ++i) {
for (int j = i + 1; j < right; ++j) {
minDist = min(minDist, distance(points[i], points[j]));
}

}
return minDist;
}

float stripClosest(vector<Point>& strip, float d) {
float minDist = d;
sort(strip.begin(), strip.end(), [](Point p1, Point p2) { return p1.y <
p2.y; });

for (size_t i = 0; i < strip.size(); ++i) {
for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist;
++j) {
minDist = min(minDist, distance(strip[i], strip[j]));
}
}
return minDist;
}

float closestUtil(vector<Point>& points, int left, int right) {
if (right - left <= 3) { // Use brute force if the subset is small

return bruteForce(points, left, right);
}
int mid = left + (right - left) / 2;
Point midPoint = points[mid];
float dl = closestUtil(points, left, mid);
float dr = closestUtil(points, mid, right);
float d = min(dl, dr);
vector<Point> strip;
for (int i = left; i < right; ++i) {
if (abs(points[i].x - midPoint.x) < d) {
strip.push_back(points[i]);
}
}

return min(d, stripClosest(strip, d));
}

float closestPairOfPoints(vector<Point>& points) {
sort(points.begin(), points.end(), [](Point p1, Point p2) { return p1.x <
p2.x; });

return closestUtil(points, 0, points.size());
}

int main() {
vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3,
4}};
cout << "The smallest distance is " << closestPairOfPoints(points) <<
endl;
return 0;
}