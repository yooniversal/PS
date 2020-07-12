#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            for (int j = 0; j < n; j++) {
                if (s[i] == 'Z') s[i] = 'A';
                else s[i]++;
            }
        }
        else if ('a' <= s[i] && s[i] <= 'z') {
            for (int j = 0; j < n; j++) {
                if (s[i] == 'z') s[i] = 'a';
                else s[i]++;
            }
        }
        answer += s[i];
    }
    return answer;
}