//10699

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	time_t curr_time;

	struct tm* curr_tm;

	curr_time = time(NULL);

	curr_tm = localtime(&curr_time);

	printf("%04d-%02d-%02d", curr_tm->tm_year + 1900, curr_tm->tm_mon + 1, curr_tm->tm_mday);

	return 0;
}