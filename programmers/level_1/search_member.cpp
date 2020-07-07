#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int key;
    for (int i = 0; i < participant.size(); i++) {
        if (participant[i] != completion[i]) {
            key = i;
            break;
        }
    }

    answer = participant[key];
    return answer;
}