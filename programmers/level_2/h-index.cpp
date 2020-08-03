#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAXSIZE 1001

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

bool compare(int a, int b) { return a > b; }

int u[MAXSIZE], d[MAXSIZE];

int solution(vector<int> citations) {
    int answer = 0;

    //descending order
    sort(citations.begin(), citations.end(), compare);

    for (int i = 0; i < citations.size(); i++) {
        answer = max(answer, min(citations[i], i + 1));
    }

    return answer;
}