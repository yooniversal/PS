//2503
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000001, INF = 1000000001, MOD = 1234567;

struct P {
	int v, s, b; //��, ��Ʈ����ũ, ��
};

int n;
vector<P> Case;

//���� �ٸ� ������ üũ
bool diff(int cur) {
	int h = cur / 100, t = (cur / 10) % 10, o = cur % 10; //��, ��, �����ڸ�
	if (h == t || h == o || t == o) return false;
	return true;
}

//��� ���̽��� ����ϸ� true ��ȯ
bool solve(int cur) {
	int cur_digit[3] = { cur / 100, (cur / 10) % 10, cur % 10 }; //��, ��, �����ڸ�
	for (int i = 0; i < n; ++i) {
		P next = Case[i];
		int next_digit[3] = { next.v / 100, (next.v / 10) % 10, next.v % 10 }; //���� ��, ��, �����ڸ�
		int cur_s = 0, cur_b = 0; //���� �Ǵ� ��
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (cur_digit[j] == next_digit[k]) {
					if (j == k) ++cur_s;
					else ++cur_b;
				}
			}
		}

		//���� ������
		if (!(cur_s == next.s && cur_b == next.b)) return false;
	}

	//��� ���̽� ���
	return true;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int v, s, b; cin >> v >> s >> b;
		Case.push_back({ v,s,b });
	}

	int ret = 0;
	for (int i = 111; i <= 999; ++i) {
		//���� 0�� ���� ���̽� & �ڸ����� ���� ��� -> ����
		if ((i / 10) % 10 == 0 || i % 10 == 0 || !diff(i)) continue;
		if (solve(i)) ++ret;
	}

	cout << ret << '\n';

	return 0;
}