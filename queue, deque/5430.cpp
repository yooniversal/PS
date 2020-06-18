//5430

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	deque<int> dq;
	string str, numstr;
	int T, n, ttp=0, temp[3], cnt=0, rcnt=0, dcnt=0, ccnt=1;

	cin >> T;
	while (T--) {
		cin >> str;
		cin >> n;
		cin >> numstr;

		//입력하고 덱에 숫자 입력하기
		for (int i = 1; i < numstr.size(); i++) {
			if (numstr.at(i) == ',' || numstr.at(i) == ']') {
				ccnt = 1;
				for (int j = cnt - 1; j >= 0; j--) {
					ttp += temp[j] * ccnt;
					ccnt *= 10;
				}
				dq.push_back(ttp);
				cnt = ttp = 0;
				if (n == 0) dq.pop_back();
			}
			else {
				temp[cnt] = numstr.at(i) - '0';
				cnt++;
			}
		}

		for (int i = 0; i < str.size(); i++)
			if (str.at(i) == 'D') dcnt++;

		for (int i = 0; i < str.size(); i++) {
			if (str.at(i) == 'R') rcnt++;
			else if (str.at(i) == 'D') {
				if (dq.size() != 0) {
					if (rcnt % 2 == 0)
						dq.pop_front();
					else if (rcnt % 2 == 1)
						dq.pop_back();
				}
				else {
					//D가 덱 사이즈보다 많으면 error 표시하고 for loop에서 나오기
					printf("error\n");
					rcnt = -1;
					break;
				}
			}
		}

		//error 처리
		if (rcnt == -1) {
			rcnt = dcnt = 0;
			str.clear();
			dq.clear();
			continue;
		}

		//print
		//r 짝수
		if (rcnt % 2 == 0) {
			if (dq.size() == 0)
				printf("[]\n");
			else if (dq.size() == 1)
				printf("[%d]\n", dq.front());
			else if (dq.size() == 2)
				printf("[%d,%d]\n", dq.front(), dq.at(dq.size() - 1));
			else {
				for (int i = 0; i < dq.size(); i++)
					if (i == 0)
						printf("[%d", dq.at(i));
					else if (i == dq.size() - 1)
						printf(",%d]\n", dq.at(i));
					else
						printf(",%d", dq.at(i));
			}
		}
		//r 홀수
		else{
			if (dq.size() == 0)
				printf("[]\n");
			else if (dq.size() == 1)
				printf("[%d]\n", dq.front());
			else if (dq.size() == 2)
				printf("[%d,%d]\n", dq.at(dq.size() - 1), dq.front());
			else {
				for (int i = dq.size()-1; i >= 0; i--)
					if (i == dq.size()-1)
						printf("[%d", dq.at(i));
					else if (i == 0)
						printf(",%d]\n", dq.at(i));
					else
						printf(",%d", dq.at(i));
			}
		}

		rcnt = dcnt = 0;
		str.clear();
		dq.clear();
	}

	
}