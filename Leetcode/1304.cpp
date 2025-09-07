class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        if (n % 2 == 1) ret.push_back(0);

        int cnt = 1;
        for (int i=0; i<n/2; i++) {
            ret.push_back(cnt);
            ret.push_back(-cnt);
            cnt++;
        }

        return ret;
    }
};