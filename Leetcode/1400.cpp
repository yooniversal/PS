class Solution {
public:

    int cnt[26];

    int getMin(int two, int one) {
        if (one == 0) return two > 0 ? 1 : 0;
        return one;
    }

    bool canConstruct(string s, int k) {
        for (int i=0; i<s.size(); i++) {
            cnt[s[i] - 'a']++;
        }

        int two = 0;
        int one = 0;

        for (int i=0; i<26; i++) {
            if (cnt[i] <= 0) continue;
            two += cnt[i] / 2;
            one += cnt[i] % 2 == 0 ? 0 : 1;
        }

        int minn = getMin(two, one);
        int maxx = two * 2 + one;

        return minn <= k && k <= maxx;
    }
};