//5635

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, year, month, day;
	int oyear=-1, omonth, oday, yyear, ymonth, yday;
	string old, young, name;

	cin >> n;

	while (n--) {
		cin >> name >> day >> month >> year;
		if (oyear == -1) {
			oyear = yyear = year;
			omonth = ymonth = month;
			oday = yday = day;
			old = young = name;
		}
		else {
			if (year < oyear) {
				oyear = year;
				omonth = month;
				oday = day;
				old = name;
			}
			else if(year == oyear)
				if (month < omonth) {
					oyear = year;
					omonth = month;
					oday = day;
					old = name;
				}
				else if(month == omonth)
					if (day < oday) {
						oyear = year;
						omonth = month;
						oday = day;
						old = name;
					}
			if (year > yyear) {
				yyear = year;
				ymonth = month;
				yday = day;
				young = name;
			}
			else if(year == yyear)
				if (month > ymonth) {
					yyear = year;
					ymonth = month;
					yday = day;
					young = name;
				}
				else if(month == ymonth)
					if (day > yday) {
						yyear = year;
						ymonth = month;
						yday = day;
						young = name;
					}
		}
	}

	cout << young << "\n" << old;

	return 0;
}