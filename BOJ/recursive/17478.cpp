// 17478
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int n;

void under(int a)
{
    for ( int i = 0; i < a; ++i )
    {
        cout << "____";
    }
}

void f(int cnt)
{
    if ( cnt == n )
    {
        under(cnt); cout << "\"����Լ��� ������?\"\n";
        under(cnt); cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        under(cnt); cout << "��� �亯�Ͽ���.\n";
        return;
    }

    under(cnt); cout << "\"����Լ��� ������?\"\n";
    under(cnt); cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    under(cnt); cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    under(cnt); cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

    f(cnt + 1);

    under(cnt); cout << "��� �亯�Ͽ���.\n";
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    f(0);

    return 0;
}
