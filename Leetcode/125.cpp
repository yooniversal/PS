class Solution {
public:
    bool isAlphabetOrNumeric(char c) {
        if ('0' <= c && c <= '9') return true;
        if ('a' <= c && c <= 'z') return true;
        if ('A' <= c && c <= 'Z') return true;
        return false;
    }

    char toSmallAlphabetOrNumeric(char c) {
        if ('0' <= c && c <= '9') return c;
        if ('a' <= c && c <= 'z') return c;
        return 'a' + c - 'A';
    }

    bool isPalindrome(string s) {
        string input = "";
        
        for (int i=0; i<s.size(); i++) {
            if (isAlphabetOrNumeric(s[i])) {
                input += toSmallAlphabetOrNumeric(s[i]);
            }
        }

        for (int i=0, j=input.size()-1; i<input.size() && j >= 0; i++, j--) {
            if (input[i] != input[j]) return false;
        }

        return true;
    }
};