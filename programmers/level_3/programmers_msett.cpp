#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n <= s) {
        int m = s / n;
        answer.resize(n);
        for (int i = 0; i < n; ++i) {
            answer[i] = m;
            s -= m;
        }
        if (s > 0) {
            for (int i = 0; i < answer.size() && s--; ++i)
                answer[i] += 1;
        }
    }
    else
        answer.push_back(-1);

    sort(answer.begin(), answer.end());

    return answer;
}