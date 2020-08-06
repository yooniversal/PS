#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <algorithm>
#define MAXSIZE 500001

using namespace std;

bool chk[MAXSIZE];

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int fullsize = people.size();
    int high = people.size() - 1;
    for (int i = 0; i < people.size() / 2; i++) {
        if (!chk[i]) {
            for (int j = high; j > i; j--) {
                if (!chk[j]) {
                    chk[j] = true;
                    if (people[i] + people[j] <= limit) {
                        chk[i] = chk[j] = true;
                        fullsize -= 2;
                        answer++;
                        high = j - 1;
                        break;
                    }
                }
            }
        }
    }

    answer += fullsize;

    return answer;
}