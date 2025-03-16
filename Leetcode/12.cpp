class Solution {
    public:
        const string symbols[4][10] = {
            {"", "I", "", "", "IV", "V", "", "", "", "IX"},
            {"", "X", "", "", "XL", "L", "", "", "", "XC"},
            {"", "C", "", "", "CD", "D", "", "", "", "CM"},
            {"", "M", "", "", "", "", "", "", "", ""}
        };
    
        string intToRoman(int num) {
            int power = 0;
            stack<string> st;
            while (num > 0) {
                if (num % 10 > 0) {
                    st.push(convertToRoman(num % 10, power));
                }
                
                num /= 10;
                power++;
            }
    
            string roman = "";
            while (!st.empty()) {
                string subRoman = st.top(); st.pop();
                roman += subRoman;
            }
    
            return roman;
        }
    
        int getMaxTarget(int v) {
            if (v >= 9) return 9;
            if (v >= 5) return 5;
            if (v >= 4) return 4;
            if (v >= 1) return 1;
            return 0;
        }
    
        string convertToRoman(int v, int power) {
            string ret = "";
            int target[4] = {9, 5, 4, 1};
            
            while (v > 0) {
                int target = getMaxTarget(v);
                ret += symbols[power][target];
                v -= target;
            }
            
            return ret;
        }
    };