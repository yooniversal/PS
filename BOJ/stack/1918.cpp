//1918
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

string s, ret;
int START[105]; //괄호 쌍의 시작 인덱스
bool chk[105];

//피연산자 처리
//cur : 시작 인덱스
//ver : 대상 ~ -1: 전체, 0: 알파벳, 1: 괄호
string f(int cur, int ver) {
	string ret = "";
	stack<char> st; //+, - 담는 용도

	for (int i = cur; i < s.size(); ++i) {
		if (chk[i]) continue;
		chk[i] = true;

		if (s[i] == ')') {
			if (START[i] == cur - 1) break;
			continue;
		}

		//연산자
		if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
			if (s[i] == '*' || s[i] == '/') {
				if (s[i + 1] == '(') ret += f(i + 2, 1), chk[i+1] = true;
				else ret += f(i + 1, 0);
				ret += s[i];
			}
			else {
				if (st.empty()) st.push(s[i]);
				else {
					ret += st.top(); st.pop();
					st.push(s[i]);
				}
			}

			continue;
		}
		

		//피연산자
		//괄호
		if (s[i] == '(') ret += f(i + 1, 1);
		//알파벳
		else ret += s[i];

		if (ver == 0) break; //알파벳 피연산자 탐색시 처리만 하기
	}

	while (!st.empty()) {
		ret += st.top(); st.pop();
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(START, -1, sizeof(START));

	cin >> s;
	stack<int> S; //괄호 시작 인덱스 담는용
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') S.push(i);
		else if(s[i] == ')') {
			START[i] = S.top();
			S.pop();
		}
	}
	
	cout << f(0, -1) << '\n';;

	return 0;
}