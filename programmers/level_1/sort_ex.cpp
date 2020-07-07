#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    deque<int> q;

    while (n != 0) {
        q.push_front(n % 10);
        n /= 10;
    }

    sort(q.begin(), q.end());

    while (!q.empty()) {
        answer = answer * 10 + q.back();
        q.pop_back();
    }

    return answer;
}