using namespace std;

long long solution(int price, int money, int count)
{
    long long need = (1LL) * price * count * (count + 1) / 2;
    if (need - money >= 0) return need - money;
    return 0;
}