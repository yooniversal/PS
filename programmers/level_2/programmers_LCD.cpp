#include <string>
#include <vector>
#include <iostream>

using namespace std;

void swap(int* a, int* b) { int tmp = *a; *a = *b; *b = tmp; }
int GCD(int a, int b) {
    if (a < b) swap(&a, &b);
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int solution(vector<int> arr) {

    for (int i = 0; i < arr.size() - 1; i++) {
        int g = GCD(arr[i], arr[i + 1]);
        arr[i + 1] = arr[i] / g * arr[i + 1] / g * g;
    }

    return arr[arr.size() - 1];
}