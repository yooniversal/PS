#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int t = x;
    int tmp = 0;
    while (t != 0) {
        tmp += t % 10;
        t /= 10;
    }
    if (x % tmp != 0) answer = false;
    return answer;
}