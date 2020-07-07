#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i]) {
            if (cnt % 2 == 0) {
                if (s[i]) {
                    s[i] = s[i] - 'a' + 'A';
                    cnt++;
                }
            }
        }
        else if (s[i] == ' ') {
            cnt = 0;
        }
    }
    return answer;
}