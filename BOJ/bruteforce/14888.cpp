//14888

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, num[11], oper[10], temp, line[10], idx;
vector<int> list, v;

//ver에 따라서 연산을 진행해주는 함수
int operat(int a, int b, int ver) {
	if (ver == 0)
		return a + b;
	else if (ver == 1)
		return a - b;
	else if (ver == 2)
		return a * b;
	else
		return a / b;
}

void process() {
	for (int i = 0; i < n - 1; i++)
		if (i == 0)											//처음엔 temp 초기화를 위해 i==0 별도 설정
			if (i == n - 2) {								//처음에 끝나는 경우
				temp = operat(num[i], num[i + 1], line[i]);	
				list.push_back(temp);						//마지막엔 list에 값을 추가
			}
			else
				temp = operat(num[i], num[i + 1], line[i]);
		else if (i == n - 2) {
			temp = operat(temp, num[i + 1], line[i]);
			list.push_back(temp);							//마지막엔 list에 값을 추가
		}
		else
			temp = operat(temp, num[i + 1], line[i]);
}

void listcase() {

	//permutation 함수를 통해 v 순열을 구해주고
	do {
		//구한 v 순열을 line에 저장해준다
		for (int i = 0; i < v.size(); i++)
			line[i] = v[i];

		//계산!
		process();

	} while (next_permutation(v.begin(), v.end()));
}

int getMax() {
	int max = list[0];
	for (int i = 0; i < list.size(); i++)
		if (max < list[i])
			max = list[i];

	return max;
}

int getMin() {
	int min = list[0];
	for (int i = 0; i < list.size(); i++)
		if (min > list[i])
			min = list[i];

	return min;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	// + - * /
	//입력받는 4개의 operator 값을 인덱스로 나열해 vector v에 저장
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
		while(oper[i] != 0) {
			v.push_back(i);
			oper[i]--;
		}
	}

	listcase();

	cout << getMax() << "\n";
	cout << getMin();

	return 0;
}