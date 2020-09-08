#include <cstdio>

using namespace std;

int main()
{
    int n, i, j, p, t, result = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        t = 0;
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &p);
            t += p;
        }
        if (t > 1)
            result++;
    }
    printf("%d\n", result);
}