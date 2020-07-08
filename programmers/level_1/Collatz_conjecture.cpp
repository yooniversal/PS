#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;
    int cnt = 0;

    long long n = (long long)num;

    while (n != 1) {
        if (cnt == 500) break;
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        //cout << n << " ";
        cnt++;
    }

    if (cnt == 500 && n != 1) answer = -1;
    else answer = cnt;

    return answer;
}