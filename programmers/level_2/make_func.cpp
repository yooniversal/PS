#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> process;

    for (int i = 0; i < progresses.size(); i++) {
        int tmp = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i]) tmp++;
        process.push_back(tmp);
    }

    int submax = process[0];
    for (int i = 0; i < process.size(); i++) {
        if (submax < process[i]) submax = process[i];
        else process[i] = submax;
    }

    int ans = 0, cmp = process[0];
    for (int i = 0; i < process.size(); i++) {
        if (process[i] == cmp) {
            ans++;
            if (i == process.size() - 1) answer.push_back(ans);
        }
        else {
            answer.push_back(ans);
            cmp = process[i];
            ans = 1;
            if (i == process.size() - 1) answer.push_back(ans);
        }
    }

    return answer;
}