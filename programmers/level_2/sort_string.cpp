#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    string right = a + b, reverse = b + a;
    if (right > reverse) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> ans;

    for (auto& num : numbers) {
        ans.push_back(to_string(num));
    }

    sort(ans.begin(), ans.end(), compare);

    for (auto& a : ans) {
        if (answer == "0") {
            if (a == "0") continue;
            else answer = a;
        }
        else answer += a;
    }

    return answer;
}