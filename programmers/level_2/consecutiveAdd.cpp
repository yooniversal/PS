#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool add(int idx, int n) {
    int ret = 0;
    while (ret < n) {
        ret += idx++;
    }
    if (ret == n) return true;
    return false;
}

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n / 2; i++) {
        if (add(i, n)) {
            answer++;
        }
    }

    return ++answer;
}