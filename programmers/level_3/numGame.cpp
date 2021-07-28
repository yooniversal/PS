#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool chk[100001];

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int cnt = 1;
    for (int i = 0; i < A.size(); ++i) {
        int num = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        if (num == 0) continue;
        if (chk[num]) continue;
        chk[cnt++] = true;
        ++answer;
    }

    return answer;
}