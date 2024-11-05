class Solution {
public:
    bool is_vowel(char c) {
        if (c == 'a' || c == 'A') return true;
        if (c == 'e' || c == 'E') return true;
        if (c == 'i' || c == 'I') return true;
        if (c == 'o' || c == 'O') return true;
        if (c == 'u' || c == 'U') return true;
        return false;
    }

    string reverseVowels(string s) {
        string vowels = "";
        string ret = "";

        for (int i=0; i<s.size(); i++) {
            if (is_vowel(s[i])) vowels += s[i];
        }

        for (int i=0, j=vowels.size()-1; i<s.size(); i++) {
            if (is_vowel(s[i])) {
                ret += vowels[j--];
                continue;
            }

            ret += s[i];
        }

        return ret;
    }
};