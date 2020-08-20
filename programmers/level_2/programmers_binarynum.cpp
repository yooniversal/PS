#include <string>
#include <vector>

using namespace std;

int bi(int n) {
    int ret = 0;

    while (n != 0) {
        ret += n % 2;
        n /= 2;
    }

    return ret;
}

int solution(int n) {
    int answer = 0;

    int key = bi(n);
    for (int i = n + 1; ; i++) {
        if (key == bi(i)) return i;
    }

    return answer;
}