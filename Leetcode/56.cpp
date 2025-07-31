class Solution {
public:
    bool isOverlapped(vector<int>& a, vector<int>& b) {
        if (a[1] < b[0]) return false;
        return true;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;

        vector<int> startInterval = intervals[0];
        for (int i=1; i<intervals.size(); i++) {
            if (isOverlapped(startInterval, intervals[i])) {
                startInterval[0] = min(startInterval[0], intervals[i][0]);
                startInterval[1] = max(startInterval[1], intervals[i][1]);
            } else {
                ret.push_back(startInterval);
                startInterval = intervals[i];
            }
        }
        ret.push_back(startInterval);

        return ret;
    }
};