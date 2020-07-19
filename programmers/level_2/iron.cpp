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
            //�������� ��ȣ ���� ũ�Ⱑ 1
            if (i - ob.top() == 1) laser.push_back({ ob.top(), i });
            else iron.push_back({ ob.top(), i });
            ob.pop();
        }
    }

    int cnt[MAX_SIZE] = { 0, };
    for (int i = 0; i < iron.size(); i++) {
        for (int j = 0; j < laser.size(); j++) {
            //�������� �踷��� ���� �ȿ� ������
            if (iron[i].first < laser[j].first && laser[j].second < iron[i].second)
                cnt[i]++;
        }
    }

    //������ ���� Ƚ��+1 = �踷��� ����
    for (int i = 0; i < iron.size(); i++)
        answer += cnt[i] + 1;

    return answer;
}