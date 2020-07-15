#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    bool chk_lost[31];
    bool chk_reserve[31];

    //초기화
    for (int i = 1; i <= 30; i++) {
        chk_lost[i] = false;
        chk_reserve[i] = false;
    }
    for (int i = 0; i < lost.size(); i++)
        chk_lost[lost[i]] = true;
    for (int j = 0; j < reserve.size(); j++)
        chk_reserve[reserve[j]] = true;

    //여벌옷이 있었으나 도난당한 학생은 제외
    //도난당한 학생 체크
    for (int j = 0; j < reserve.size(); j++) {
        for (int i = 0; i < lost.size(); i++) {
            if (reserve[j] == lost[i]) {
                chk_lost[lost[i]] = false;
                chk_reserve[reserve[j]] = false;
            }
        }
    }

    //process
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == lost[i] - 1) {
                if (chk_lost[lost[i]] && chk_reserve[reserve[j]]) {
                    chk_lost[lost[i]] = false;
                    chk_reserve[reserve[j]] = false;
                }
            }
            else if (reserve[j] == lost[i] + 1) {
                if (chk_lost[lost[i]] && chk_reserve[reserve[j]]) {
                    chk_lost[lost[i]] = false;
                    chk_reserve[reserve[j]] = false;
                }
            }
        }
    }

    //answer
    for (int i = 1; i <= n; i++)
        if (!chk_lost[i])
            answer++;

    return answer;
}
