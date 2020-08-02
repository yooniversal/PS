#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> sidx; //�� ����

//ù��° ���� ��
//���ڰ� ���ٸ� ���� ��
bool compare(string a, string b) {
    if (a[0] == b[0]) return a.size() < b.size();
    return a[0] < b[0];
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), compare);
    int first = phone_book[0][0];
    sidx.push_back(0);
    for (int i = 1; i < phone_book.size(); i++) {
        //ù��° ���ڰ� �ٸ���
        if (first != phone_book[i][0]) {
            sidx.push_back(i);
            first = phone_book[i][0];
        }
    }

    if (sidx.size() != 1) {
        for (int i = 0; i < sidx.size() - 1; i++) {
            for (int s = sidx[i]; s < sidx[i + 1]; s++) {
                //�� ����
                string cmp = phone_book[s];
                for (int j = s + 1; j < sidx[i + 1]; j++) {
                    //�� ���ھ� ��
                    bool same = true;
                    for (int k = 0; k < cmp.size(); k++) {
                        if (cmp[k] != phone_book[j][k]) {
                            same = false;
                            break;
                        }
                    }
                    //���λ簡 ���� ���
                    if (same) return false;
                }
            }
        }
    }
    else {
        for (int s = 0; s < phone_book.size() - 1; s++) {
            //�� ����
            string cmp = phone_book[s];
            for (int j = s + 1; j < phone_book.size(); j++) {
                //�� ���ھ� ��
                bool same = true;
                for (int k = 0; k < cmp.size(); k++) {
                    if (cmp[k] != phone_book[j][k]) {
                        same = false;
                        break;
                    }
                }
                //���λ簡 ���� ���
                if (same) return false;
            }
        }
    }

    return true;
}