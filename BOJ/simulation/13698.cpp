//13698
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 2005
#define MOD 1000000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int ball[5];

void change(char x) {
	if (x == 'A') swap(ball[1], ball[2]);
	else if(x=='B') swap(ball[1], ball[3]);
	else if(x=='C') swap(ball[1], ball[4]);
	else if(x=='D') swap(ball[2], ball[3]);
	else if(x=='E') swap(ball[2], ball[4]);
	else swap(ball[3], ball[4]);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	ball[1] = 1, ball[4] = 2;
	for (int i = 0; i < s.size(); ++i)
		change(s[i]);

	int small = -1, big = -1;
	for (int i = 1; i <= 4; ++i)
		if (ball[i] == 1) small = i;
		else if(ball[i] == 2) big = i;

	cout << small << '\n' << big;

	return 0;
}