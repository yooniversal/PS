class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s == goal) return true;
        if (s.size() != goal.size()) return false;
        if (s.size() == 1 && s != goal) return false;
        string original = s;
        
        
        do {
            s = s.substr(1) + s[0];
            if (s == goal) return true;    
        } while (s != original);

        return false;
    }
};