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

	//���� �ð��� sort()�� �����ϱ� ���� first�� �־��ش�
	//���� ���� �ð��� start�� �־�����
	for (int i = 0; i < n; i++)
		scanf("%d %d", &input[i].second, &input[i].first);

	//���� �ð��� ������������ ���ĵǰ�, ���� �ð��� ������ ���� �ð��� ������������ ���ĵȴ�
	sort(input, input + n);

	int temp = 0; //���� �������� ���� �ð��� ����
	for (int i = 0; i < n; i++) {
		//�̹� ������ ���� �ð��� ���� ������ ���� �ð����� ���ų� �ʴ°�?
		if (input[i].second >= temp) {
			temp = input[i].first;
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}