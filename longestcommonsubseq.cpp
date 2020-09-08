#include <string>
#include <algorithm>

using namespace std;

string memo[61][61] = {{""}};

string lcs(const string &x, const string &y, bool startup = true, int xll = -1, int yll = -1)
{
    if (startup)
    { // reset global memo table
        for (int i = 0; i < 61; i++)
            for (int j = 0; j < 61; j++)
                memo[i][j].clear();
    }
    int xl = (xll > -1) ? xll : x.length(), yl = (yll > -1) ? yll : y.length();
    string x1 = x.substr(0, xl - 1), y1 = y.substr(0, yl - 1), a, b;

    if (xl == 0 || yl == 0)
        return "";

    if (!memo[xl - 1][yl - 1].empty())
        return memo[xl - 1][yl - 1];

    if (x[xl - 1] == y[yl - 1])
    {
        memo[xl - 1][yl - 1] = lcs(x1, y1, false, xl - 1, yl - 1) + x[xl - 1];
    }
    else
    {
        if (xl > 1)
        {
            a = lcs(x1, y, false, xl - 2, yl - 1);
        }
        if (yl > 1)
        {
            b = lcs(x, y1, false, xl - 1, yl - 2);
        }
        if (a.length() > b.length())
            memo[xl - 1][yl - 1] = a;
        else
            memo[xl - 1][yl - 1] = b;
    }
    return memo[xl - 1][yl - 1];
}