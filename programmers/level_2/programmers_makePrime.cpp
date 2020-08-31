#include <vector>
#include <iostream>
#include <cmath>
#define MAX 3001
using namespace std;

int prime[MAX];

void PRIME() {
    for (int i = 1; i < MAX; i++)
        prime[i] = i;

    for (int i = 2; i <= sqrt(MAX); i++) {
        if (prime[i] == 0) continue;
        for (int j = i + i; j <= MAX; j += i) {
            prime[j] = 0;
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;

    PRIME();

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (prime[nums[i] + nums[j] + nums[k]]) answer++;
            }
        }
    }

    return answer;
}