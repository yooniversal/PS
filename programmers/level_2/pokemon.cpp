#include <vector>
using namespace std;

bool chk[200001];

int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (!chk[nums[i]]) {
            chk[nums[i]] = true;
            cnt++;
        }
    }

    if (cnt > nums.size() / 2) answer = nums.size() / 2;
    else answer = cnt;

    return answer;
}