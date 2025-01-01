class Solution {
public:
    int maxScore(string s) {
        int ret = 0;

        int leftZeros[505], rightOnes[505];

        int cnt = 0;
        for (int i=0; i<s.size()-1; i++) {
            if (s[i] == '0') cnt++;
            leftZeros[i] = cnt;
        }
        leftZeros[s.size()-1] = cnt;

        cnt = 0;
        for (int i=s.size()-1; i>=1; i--) {
            if (s[i] == '1') cnt++;
            rightOnes[i] = cnt;
        }
        rightOnes[0] = cnt;

        for (int i=0; i<s.size(); i++) {
            ret = max(ret, leftZeros[i] + rightOnes[i]);
        }

        return ret;
    }
};