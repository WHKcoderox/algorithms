#include <cstdio>

using namespace std;

int main()
{
    int n, k, i, a, current = 0, cutoff = 0;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == 0)
            break;
        if (i + 1 <= k)
        {
            current++;
            if (i + 1 == k)
                cutoff = a;
            continue;
        }
        else if (a < cutoff)
            break;
        current++;
    }
    printf("%d", current);
    return 0;
}