#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<double, int>a, pair<double, int>b) {
    if (a.first > b.first) return true;
    else if (a.first == b.first) {
        if (a.second < b.second) return true;
    }

    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int>> a;
    double members = (double)stages.size();

    int cl[501] = { 0, };
    for (int i = 0; i < stages.size(); i++) {
        cl[stages[i]]++;
    }


    for (int i = 1; i <= N; i++) {
        if (cl[i] != 0) {
            a.push_back({ cl[i] / members, i });
            members -= cl[i];
        }
        else a.push_back({ 0.0, i });
    }

    sort(a.begin(), a.end(), compare);

    vector<int> answer;

    for (int i = 0; i < a.size(); i++) {
        answer.push_back(a[i].second);
    }

    return answer;
}