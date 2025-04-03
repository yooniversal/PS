class Solution {
    public:
        string getAnswer(int n) {
            if (n % 3 == 0 && n % 5 == 0) return "FizzBuzz";
            if (n % 3 == 0) return "Fizz";
            if (n % 5 == 0) return "Buzz";
            return to_string(n);
        }
    
        vector<string> fizzBuzz(int n) {
            vector<string> ret;
            
            for (int i=1; i<=n; i++) ret.push_back(getAnswer(i));
    
            return ret;
        }
    };