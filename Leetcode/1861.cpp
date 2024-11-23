class Solution {
public:
    void gravity(vector<vector<char>>& a) {
        for (int col=0; col<a[0].size(); col++) {
            for (int row=a.size()-1; row>=0; row--) {
                if (a[row][col] != '#') continue;
                int target = row + 1;
                while (target < a.size()) {
                    if (a[target][col] == '#' || a[target][col] == '*') {
                        break;
                    }
                    target++;
                }

                swap(a[row][col], a[--target][col]);
            }
        }   
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> ret;

        // init
        for (int i=0; i<box[0].size(); i++) {
            vector<char> temp(box.size(), '.');
            ret.push_back(temp);
        }

        // set
        for (int i=0; i<box.size(); i++) {
            for (int j=0; j<box[i].size(); j++) {
                ret[j][i] = box[i][j];
            }
        }

        for (int i=0; i<ret.size(); i++) {
            reverse(ret[i].begin(), ret[i].end());
        }

        gravity(ret);

        return ret;
    }
};