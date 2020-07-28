#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <iostream>
#define MAXSIZE 10000001

using namespace std;

bool num[MAXSIZE];
bool chk[8];
int ans;

//소수 판별
bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;

    return true;
}

void dfs(string numbers, string key, int size) {
    //길이가 맞으면
    if (size == 0) {
        int value = stoi(key);
        if (num[value]) return;
        num[value] = true;
        if (isPrime(value)) ans++;
        return;
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (chk[i]) continue;
        chk[i] = true;
        key += numbers[i];
        dfs(numbers, key, size - 1);
        chk[i] = false;
        key.erase(--key.end());
    }
}
int solution(string numbers) {
    int answer = 0;

    //i : size
    for (int i = 1; i <= numbers.size(); i++) {
        memset(chk, false, sizeof(chk));
        dfs(numbers, "", i);
    }

    return answer = ans;
}
