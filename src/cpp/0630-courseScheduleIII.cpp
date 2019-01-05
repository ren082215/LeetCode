class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int curTime = 0;
        priority_queue<int> q;
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        for (auto course : courses) {
            curTime += course[0];
            q.push(course[0]);
            if (curTime > course[1]) {
                curTime -= q.top(); q.pop();
            }
        }
        return q.size();
    }
};
