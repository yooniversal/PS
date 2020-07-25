#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;

    for (int i = 0; i < heights.size(); i++) {
        bool chk = false;
        for (int j = i - 1; j >= 0; j--) {
            if (heights[i] < heights[j]) {
                answer.push_back(j + 1);
                j = -1;
                chk = true;
            }
        }
        if (!chk) answer.push_back(0);
    }

    return answer;
}
