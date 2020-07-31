#include <string>
#include <vector>
#include <queue>
#include <iostream>
typedef long long ll;
using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;

    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    while (pq.top() < K) {
        if (pq.size() == 1 && pq.top() < K) {
            return -1;
        }
        ll m1 = pq.top(); pq.pop();
        ll m2 = pq.top(); pq.pop();

        m2 = m1 + m2 * 2;
        pq.push(m2);

        answer++;
    }

    return answer;
}