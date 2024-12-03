class Solution {
public:
    bool space[300005];

    string addSpaces(string s, vector<int>& spaces) {
        string ret = "";
        for (int i=0; i<spaces.size(); i++) {
            space[spaces[i]] = true;
        }

        for (int i=0; i<s.size(); i++) {
            if (space[i]) ret += " ";
            ret += s[i];
        }

        return ret;
    }
};