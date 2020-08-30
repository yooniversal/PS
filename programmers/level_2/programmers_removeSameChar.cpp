#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int chk[26];

int solution(string s)
{
    stack<char> S;

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        //체크된 적 없다면
        if (chk[s[i] - 'a'] == 0) {
            S.push(s[i]);
            chk[s[i] - 'a']++;
            cnt++;
        }
        //체크된 적 있다면
        else {
            //최근에 담은 것과 같을 때
            if (S.top() == s[i]) {
                chk[s[i] - 'a']--;
                S.pop();
                cnt--;
                //cout << "i:"<<i<<'\n';
            }
            //최근에 담은 것과 다를 때
            else {
                //cout << "S.top:"<<S.top()<<" s["<<i<<"]"<<s[i]<<'\n';
                chk[s[i] - 'a']++;
                S.push(s[i]);
                cnt++;
            }
        }
    }
    if (!cnt) return 1;
    return 0;
}