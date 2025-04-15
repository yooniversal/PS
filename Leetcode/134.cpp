class Solution {
    public:
        int origin[100005];
    
        bool process(vector<int>& gas, vector<int>& cost, int start) {
            int hasGas = gas[start];
            
            for (int i=start, cnt=0; cnt<gas.size(); cnt++) {
                if (hasGas < cost[i]) return false;
                hasGas -= cost[i];
    
                i = (i+1) % gas.size();
                hasGas += gas[i];
            }
    
            return true;
        }
    
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            vector<int> newGas, newCost;
            
            int newIndex = 0;
            for (int i=0; i<gas.size(); i++) {
                if (gas[i] == cost[i]) continue;
                newGas.push_back(gas[i]);
                newCost.push_back(cost[i]);
                origin[newIndex++] = i;
            }
    
            if (newIndex == 0) return 0;
    
            for (int i=0; i<newGas.size(); i++) {
                if (newCost[i] > newGas[i]) continue;
                if (process(newGas, newCost, i)) return origin[i];
            }
    
            return -1;
        }
    };