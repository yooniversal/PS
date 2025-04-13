class Solution {
    public:
        int hIndex(vector<int>& citations) {
            sort(citations.begin(), citations.end());
            
            for (int i=0, j=citations.size(); i<citations.size(); i++, j--) {
                if (citations[i] >= j) return j;
            }
    
            return 0;
        }
    };