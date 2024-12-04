class Solution {
public:
    char nextChar(char c) {
        if (c == 'z') return 'a';
        return c + 1;
    }

    bool check(string str1, string str2) {
        int i=0, j=0;
        while (i<str1.size() && j<str2.size()) {
            if (str1[i] == str2[j] || nextChar(str1[i]) == str2[j]) {
                i++; j++;
                continue;
            }
            i++;
        }

        return j == str2.size();
    }

    bool canMakeSubsequence(string str1, string str2) {
        return check(str1, str2);
    }
};