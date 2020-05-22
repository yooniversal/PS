//1436

//****** input 1부터 작동안됨

#include <stdio.h>

int position(int num) {
	int ans = 0;

	while (num != 0) {
		num /= 10;
		ans++;
	}

	return ans;
}

int iscontinuer(int num) {
	int* arr = malloc(sizeof(int) * position(num)+1);
	int i, cnt=0, position_count=0, conti666 = 0, temp=num;
	//insert num to arr
	for (i = 0; i < position(num); i++) {
		arr[i] = temp % 10;
		temp /= 10;
	}

	i = 0;

	//search mechanism
	while(1) {
		position_count++;

		if (position_count != position(num)) {
			if (arr[i] == 6)
				cnt++;
			else {
				if (cnt >= 3)
					conti666++;
				cnt = 0;
			}
		}
		else {
			if (arr[i] == 6)
				cnt++;

			if (cnt >= 3)
				conti666++;
		}
		//printf("position(temp)=%d\n", position(num));
		//printf("i=%d arr[i]=%d num=%d position(num)=%d cnt=%d conti666=%d\n", i, arr[i], num, position(num), cnt, conti666);

		if (position_count == position(num)) {
			if (conti666 >= 1) {
				free(arr);
				return 1;
			}
			else {
				free(arr);
				return 0;
			}
		}

		i++;
	}
}

int main() {

	int n, temp, cnt = 0, num = 666, T;
	//printf("%d", iscontinuer(666));
	
	
		scanf("%d", &n);
		cnt = 0;

		while (1) {
			if (iscontinuer(num))
				cnt++;

			if (cnt == n) {
				printf("%d", num);
				break;
			}

			num++;
		}
	

	return 0;
}