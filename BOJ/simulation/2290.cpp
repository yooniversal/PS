//2290
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int s;
//n: 0~9 h: 0~4
void print(int n, int h) {
	if (h == 0 || h==2 || h==4) {
		if ((n == 0 && h == 2) || (n == 7 && (h == 2 || h == 4))) {
			for (int i = 0; i < s + 3; ++i) cout << ' ';
		}
		else if (n == 4 && h == 2) {
			cout << ' ';
			for (int i = 0; i < s; ++i) cout << '-';
			cout << "  ";
		}
		else if (n == 0 || n == 2 || n == 3 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9) {
			cout << ' ';
			for (int i = 0; i < s; ++i) cout << '-';
			cout << "  ";
		}
		else {
			for (int i = 0; i < s + 3; ++i) cout << ' ';
		}
	}
	else if (h == 1) {
		if (n == 1 || n == 2 || n == 3 || n == 7) {
			for (int i = 0; i < s + 1; ++i) cout << ' ';
			cout << "| ";
		}
		else if (n == 5 || n == 6) {
			cout << "|";
			for (int i = 0; i < s + 2; ++i) cout << ' ';
		}
		else {
			cout << '|';
			for (int i = 0; i < s; ++i) cout << ' ';
			cout << "| ";
		}
	}
	else{
		if(n==1||n==3||n==4||n==5||n==7||n==9) {
			for (int i = 0; i < s + 1; ++i) cout << ' ';
			cout << "| ";
		}
		else if (n == 2) {
			cout << "|";
			for (int i = 0; i < s + 2; ++i) cout << ' ';
		}
		else {
			cout << '|';
			for (int i = 0; i < s; ++i) cout << ' ';
			cout << "| ";
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string n; cin >> s >> n;
	for (int turn = 0; turn < 5; ++turn) {
		if(turn%2)
			for (int iter = 0; iter < s; ++iter) {
				for (int i = 0; i < n.size(); ++i) {
					print(n[i] - '0', turn);
				}
				cout << '\n';
			}
		else {
			for (int i = 0; i < n.size(); ++i) {
				print(n[i] - '0', turn);
			}
			cout << '\n';
		}
		
	}

	return 0;
}