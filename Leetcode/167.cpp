class Solution {
public:
    void init(map<int, vector<int>>& num_map, vector<int>& numbers) {
        for (int i=0; i<numbers.size(); i++) {
            vector<int> v = num_map[numbers[i]];
            if (v.size() >= 2) continue;

            v.push_back(i + 1);
            num_map[numbers[i]] = v;
        }
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        map<int, vector<int>> num_map;
        init(num_map, numbers);
        
        for (int i=0; i<numbers.size(); i++) {
            vector<int> v = num_map[target - numbers[i]];
            if (v.size() == 0) continue;
            if (v.size() == 1 && target - numbers[i] == numbers[i]) continue;
            
            // target - numbers[i] == numbers[i]
            if (v.size() == 2) {
                sort(v.begin(), v.end());
                return v;
            }

            // target - numbers[i] != numbers[i]
            ret.push_back(i + 1);
            ret.push_back(v[0]);
            sort(ret.begin(), ret.end());
            return ret;
        }

        return ret;
    }
};