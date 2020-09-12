#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct File {
    string head;
    int number, order;
    File(string a, int b, int c) : head(a), number(b), order(c) {}
    bool operator<(const File& F) const {
        if (head != F.head) return head < F.head;
        if (number != F.number) return number < F.number;
        return order < F.order;
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> f;

    for (int i = 0; i < files.size(); i++) {
        string s = ""; int n = 0, order = i;
        bool head = false;
        for (int j = 0; j < files[i].size(); j++) {
            //NUMBER
            if ('0' <= files[i][j] && files[i][j] <= '9') {
                head = true;
                n = n * 10 + (files[i][j] - '0');
            }
            else if (!head) {
                //HEAD
                if ('A' <= files[i][j] && files[i][j] <= 'Z') {
                    s += files[i][j] - 'A' + 'a';;
                }
                else {
                    s += files[i][j];
                }
            }
            else break;
        }
        f.push_back(File(s, n, order));
    }
    sort(f.begin(), f.end());

    for (int i = 0; i < f.size(); i++)
        answer.push_back(files[f[i].order]);

    return answer;
}