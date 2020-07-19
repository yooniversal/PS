#include <string>
#include <vector>
#include <stack>
#include <iostream>
#define MAX_SIZE 100000

using namespace std;

int solution(string arrangement) {
    int answer = 0;

    stack<int> ob;
    vector<pair<int, int>> iron, laser;
    for (int i = 0; i < arrangement.size(); i++) {
        if (arrangement[i] == '(') ob.push(i);
        else {
            //레이저는 괄호 범위 크기가 1
            if (i - ob.top() == 1) laser.push_back({ ob.top(), i });
            else iron.push_back({ ob.top(), i });
            ob.pop();
        }
    }

    int cnt[MAX_SIZE] = { 0, };
    for (int i = 0; i < iron.size(); i++) {
        for (int j = 0; j < laser.size(); j++) {
            //레이저가 쇠막대기 범위 안에 있으면
            if (iron[i].first < laser[j].first && laser[j].second < iron[i].second)
                cnt[i]++;
        }
    }

    //레이저 맞은 횟수+1 = 쇠막대기 개수
    for (int i = 0; i < iron.size(); i++)
        answer += cnt[i] + 1;

    return answer;
}