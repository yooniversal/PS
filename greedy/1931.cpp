//1931

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define max(a, b) (((a)>(b)) ? (a) : (b))

using namespace std;

pair<int, int> input[100005];

int main() {

	int n, cnt = 0;

	scanf("%d", &n);

	//종료 시각을 sort()로 정렬하기 위해 first에 넣어준다
	//따라서 시작 시각은 start에 넣어주자
	for (int i = 0; i < n; i++)
		scanf("%d %d", &input[i].second, &input[i].first);

	//종료 시각이 내림차순으로 정렬되고, 종료 시각이 같으면 시작 시각이 내림차순으로 정렬된다
	sort(input, input + n);

	int temp = 0; //직전 스케줄의 종료 시각을 저장
	for (int i = 0; i < n; i++) {
		//이번 스케줄 시작 시각은 직전 스케줄 종료 시각보다 같거나 늦는가?
		if (input[i].second >= temp) {
			temp = input[i].first;
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}