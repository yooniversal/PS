class Solution {
public:
    int ransomNoteAlphabetCnt[26];
    int magazineAlphabetCnt[26];

    void initAlphabetCnt(string& ransomNote, string& magazine) {
        for (int i=0; i<ransomNote.size(); i++) {
            ransomNoteAlphabetCnt[ransomNote[i] - 'a']++;
        }
        for (int i=0; i<magazine.size(); i++) {
            magazineAlphabetCnt[magazine[i] - 'a']++;
        }
    }

    bool canConstruct(string ransomNote, string magazine) {
        initAlphabetCnt(ransomNote, magazine);

        for (int i=0; i<26; i++) {
            if (ransomNoteAlphabetCnt[i] > magazineAlphabetCnt[i])
                return false;
        }
        
        return true;
    }
};