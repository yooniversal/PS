#include <string>
#include <vector>

using namespace std;

bool chk[7];

int Rank(int cnt) {
    if (cnt < 2) return 6;
    if (cnt == 2) return 5;
    if (cnt == 3) return 4;
    if (cnt == 4) return 3;
    if (cnt == 5) return 2;
    return 1;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int cnt = 0;
    for (int& cur : lottos) {
        for (int i = 0; i < win_nums.size(); ++i) {
            if (chk[i]) continue;
            int target = win_nums[i];
            if (target == cur) {
                chk[i] = true;
                ++cnt;
                break;
            }
        }
    }

    int zero = 0;
    for (int& cur : lottos) {
        if (cur == 0) ++zero;
    }

    int best = zero + cnt;

    answer.push_back(Rank(best));
    answer.push_back(Rank(cnt));

    return answer;
}