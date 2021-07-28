#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int p = 0;
    for (int i = 0; i < stations.size(); ++i) {
        int tmp = stations[i] - w - 1 - p;
        answer += tmp / (w * 2 + 1);
        if (tmp % (w * 2 + 1) > 0) ++answer;
        p = stations[i] + w;
    }
    if (p < n) {
        n -= p;
        answer += n / (w * 2 + 1);
        if (n % (w * 2 + 1) > 0) ++answer;
    }

    return answer;
}