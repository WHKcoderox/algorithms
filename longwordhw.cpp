#include <cstdio>

using namespace std;

int main()
{
    int n, i, j;
    char inp[101], last;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", inp);
        for (j = 0; j < 101; j++)
        {
            if (inp[j])
                last = inp[j];
            else
                break;
        }
        if (--j > 9)
        {
            j--;
            printf("%c%d%c\n", inp[0], j, last);
        }
        else
        {
            printf("%s\n", inp);
        }
    }
    return 0;
}