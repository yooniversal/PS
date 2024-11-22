class Solution {
public:
    bool isAllEqual(vector<int>& a, vector<int>& b) {
        for (int i=0; i<a.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool isAllNotEqual(vector<int>& a, vector<int>& b) {
        for (int i=0; i<a.size(); i++) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ret = 0;
        int n = matrix.size();
        
        for (int i=0; i<n; i++) {
            int cnt = 1;
            for (int j=i+1; j<n; j++) {
                if (isAllEqual(matrix[i], matrix[j]) || isAllNotEqual(matrix[i], matrix[j])) {
                    cnt++;
                }
            }
            ret = max(ret, cnt);
        }

        return ret;
    }
};