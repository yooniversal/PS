#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    ll sum1 = 0, sum2 = 0;
    queue<ll> q1, q2;
    for (auto& v : queue1) {
        q1.push(v);
        sum1 += v;
    }
    for (auto& v : queue2) {
        q2.push(v);
        sum2 += v;
    }
    
    bool flag = false;
    int cnt = 0;
    while (cnt < queue1.size() * 4) {
        if (sum1 == sum2) {
            flag = true;
            break;
        }
        
        if (sum1 > sum2) {
            ll v = q1.front(); q1.pop();
            q2.push(v);
            sum1 -= v;
            sum2 += v;
        } else {
            ll v = q2.front(); q2.pop();
            q1.push(v);
            sum1 += v;
            sum2 -= v;
        }
        
        cnt++;
    }
    
    return flag ? cnt : -1;
}