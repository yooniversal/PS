class Solution {
public:
    int N;
    int originIndex[100005];
    bool chk[100005];

    bool OOB(int cur) {
        return cur < 0 || cur >= N;
    }

    long long findScore(vector<int>& nums) {
        long long ret = 0L;
        vector<pair<int, int>> a;

        N = nums.size();
        
        for (int i=0; i<N; i++) {
            a.push_back({nums[i], i});
        }
        sort(a.begin(), a.end());

        for (int i=0; i<a.size(); i++) {
            int currentIndex = a[i].second;
            if (chk[currentIndex]) continue;

            ret += a[i].first;
            
            chk[currentIndex] = true;
            if (!OOB(currentIndex - 1)) chk[currentIndex - 1] = true;
            if (!OOB(currentIndex + 1)) chk[currentIndex + 1] = true;
        }

        return ret;
    }
};