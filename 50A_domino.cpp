#include <cstdio>

using namespace std;

int main()
{
    int n, m, result;
    scanf("%d %d", &n, &m);
    if (n == 1 || m == 1)
    {
        result = (n * m) / 2;
    }
    else if (n % 2 && m % 2)
    {
        result = (int)(n / 2) + (m - 1) * n / 2; // remove one row
    }
    else
    {
        result = m * n / 2;
    }
    printf("%d\n", result);
    return 0;
}