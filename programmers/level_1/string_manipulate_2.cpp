#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (!(s.size() == 4 || s.size() == 6)) answer = false;
    else {
        for (int i = 0; i < s.size(); i++)
            if (!('0' <= s[i] && s[i] <= '9')) answer = false;
    }
    return answer;
}