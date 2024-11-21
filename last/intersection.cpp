#include <iostream>
using namespace std;
struct Point {
int x, y;
};

int orientation(Point p, Point q, Point r) {
int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
if (val == 0) return 0;
return (val > 0) ? 1 : 2;
}

bool onSegment(Point p, Point q, Point r) {
if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))

return true;
return false;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
int o1 = orientation(p1, q1, p2);
int o2 = orientation(p1, q1, q2);
int o3 = orientation(p2, q2, p1);
int o4 = orientation(p2, q2, q1);

if (o1 != o2 && o3 != o4)
return true;

if (o1 == 0 && onSegment(p1, p2, q1)) return true;
if (o2 == 0 && onSegment(p1, q2, q1)) return true;
if (o3 == 0 && onSegment(p2, p1, q2)) return true;
if (o4 == 0 && onSegment(p2, q1, q2)) return true;

return false; // Doesn't fall in any of the above cases
}

int main() {
Point p1 = {1, 1}, q1 = {10, 1};
Point p2 = {1, 2}, q2 = {10, 2};

doIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";

Point p3 = {10, 0}, q3 = {0, 10};
Point p4 = {0, 0}, q4 = {10, 10};

doIntersect(p3, q3, p4, q4) ? cout << "Yes\n" : cout << "No\n";

return 0;
}