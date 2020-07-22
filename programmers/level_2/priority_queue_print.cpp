#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool desc(int a, int b) {
    return a > b;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int key = priorities[location];
    vector<int> sorted = priorities;
    sort(sorted.begin(), sorted.end(), desc);

    queue<pair<int, bool>> q;
    for (int i = 0; i < priorities.size(); i++) {
        if (i == location) q.push({ priorities[i], true });
        else q.push({ priorities[i], false });
    }

    int ans = 0, idx = 0;
    while (!q.empty()) {
        pair<int, bool> val = q.front();
        q.pop();

        if (val.first == sorted[idx]) {
            ans++;
            if (val.second) {
                answer = ans;
                break;
            }
            idx++;
        }
        else {
            q.push(val);
        }
    }

    return answer;
}