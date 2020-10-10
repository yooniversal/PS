#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
const int INF = 987654321;

map<int, int> notPush;
priority_queue<int> pq;

int solution(vector<int> stones, int k) {
    int answer = INF;

    for (int i = 0; i < k; ++i)
        pq.push(stones[i]);
    answer = min(answer, pq.top());

    for (int i = 1; i < stones.size() - k + 1; ++i) {
        if (stones[i - 1] != pq.top()) ++notPush[stones[i - 1]];
        else {
            pq.pop();
            while (notPush[pq.top()] > 0) {
                --notPush[pq.top()];
                pq.pop();
            }
        }
        pq.push(stones[i + k - 1]);
        answer = min(answer, pq.top());
    }

    return answer;
}