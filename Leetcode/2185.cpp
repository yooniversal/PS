class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;

        for (int i=0; i<words.size(); i++) {
            string word = words[i];
            if (word.size() < pref.size()) continue;
            
            bool flag = true;
            for (int j=0; j<pref.size(); j++) {
                if (word[j] != pref[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) ret++;
        }

        return ret;
    }
};