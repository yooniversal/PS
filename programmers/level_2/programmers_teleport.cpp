#include <iostream>
using namespace std;

int solution(int n)
{
    int ret = 0;
    while (n != 0) {
        if (n % 2) {
            ++ret;
            --n;
        }
        else n /= 2;
    }
    return ret;
}