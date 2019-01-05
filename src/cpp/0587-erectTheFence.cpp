/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        vector<Point> res;
        Point first = points[0];
        int firstIdx = 0, n = points.size();
        for (int i = 1; i < n; ++i) {
            if (points[i].x < first.x) {
                first = points[i];
                firstIdx = i;
            }
        }
        res.push_back(first);
        Point cur = first;
        int curIdx = firstIdx;
        while (true) {
            Point next = points[0];
            int nextIdx = 0;
            for (int i = 1; i < n; ++i) {
                if (i == curIdx) continue;
                int cross = crossProduct(cur, points[i], next);
                if (nextIdx == curIdx || cross > 0 || (cross == 0 && dist(points[i], cur) > dist(next, cur))) {
                    next = points[i];
                    nextIdx = i;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i == curIdx) continue;
                int cross = crossProduct(cur, points[i], next);
                if (cross == 0) {
                    if (check(res, points[i])) res.push_back(points[i]);
                }
            }
            cur = next;
            curIdx = nextIdx;
            if (curIdx == firstIdx) break;
        }
        return res;
    }
    int crossProduct(Point A, Point B, Point C) {
        int BAx = A.x - B.x;
        int BAy = A.y - B.y;
        int BCx = C.x - B.x;
        int BCy = C.y - B.y;
        return BAx * BCy - BAy * BCx;
    }
    int dist(Point A, Point B) {
        return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
    }
    bool check(vector<Point>& res, Point p) {
        for (Point r : res) {
            if (r.x == p.x && r.y == p.y) return false;
        }
        return true;
    }
};
