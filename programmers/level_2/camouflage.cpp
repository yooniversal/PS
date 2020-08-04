#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> m;

    //종류 얻기
    vector<string> kinds, unique;
    for (int i = 0; i < clothes.size(); i++) {
        kinds.push_back(clothes[i][1]);
        if (m[clothes[i][1]] == NULL) unique.push_back(clothes[i][1]);
        m[clothes[i][1]] = 1;
    }


    for (int i = 0; i < kinds.size(); i++) {
        m[kinds[i]]++;
    }


    for (int i = 0; i < unique.size(); i++) {
        answer *= m[unique[i]];
    }

    answer--;

    return answer;
}