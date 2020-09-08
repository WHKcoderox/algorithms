#include <cstdio>

using namespace std;

int main()
{
    int n, k, i, ci, threshold = 0;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ci);
        if (i + 1 == k)
        {
            threshold = ci;
        }
        if (ci < threshold || ci == 0)
        {
            break;
        }
    }
    printf("%d\n", i);
    return 0;
}