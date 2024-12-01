class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> chk;
        int zeroCnt = 0;

        for (auto& v : arr) {
            if (v == 0) zeroCnt++;
            chk.insert(v*2);
        }

        if (zeroCnt >= 2) return true;

        for (auto& v : arr) {
            if (v == 0) continue;
            if (chk.find(v) != chk.end()) {
                return true;
            }
        }

        return false;
    }
};