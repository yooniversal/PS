class Solution {
public:
    pair<int, int> alphabetIndices[26];

    void init() {
        for (int i=0; i<26; i++) {
            alphabetIndices[i].first = -1;
        }
    }

    int countPalindromicSubsequence(string s) {
        init();

        for (int i=0; i<s.size(); i++) {
            if (alphabetIndices[s[i] - 'a'].first == -1) alphabetIndices[s[i] - 'a'].first = i;
            alphabetIndices[s[i] - 'a'].second = i;
        }

        set<string> palindromes;

        for (int i=0; i<26; i++) {
            int start = alphabetIndices[i].first;
            int end = alphabetIndices[i].second;
            if (start == -1 || end - start <= 1) continue;

            char criteria = i + 'a';

            for (int j=start+1; j<end; j++) {
                string palindrome = string(1, criteria) + s[j] + criteria;
                palindromes.insert(palindrome);
            }
        }

        return palindromes.size();
    }
};