#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int cnt = 1;
    while (cnt != n + 1) {
        if (cnt % 2) answer += "��";
        else answer += "��";
        cnt++;
    }
    return answer;
}