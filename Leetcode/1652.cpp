class Solution {
public:
    int decrypt(vector<int>& code, int k, int target) {
        if (k == 0) return 0;

        int ret = 0;

        if (k > 0) {
            for (int i=target+1, cnt=0; cnt<k; i++, cnt++) {
                i %= code.size();
                ret += code[i];
            }
        } else {
            for (int i=target-1, cnt=0; cnt<abs(k); i--, cnt++) {
                if (i < 0) i = code.size() - 1;
                ret += code[i];
            }
        }

        return ret;
    }

    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ret;
        for (int i=0; i<code.size(); i++) ret.push_back(decrypt(code, k, i));
        return ret;
    }
};