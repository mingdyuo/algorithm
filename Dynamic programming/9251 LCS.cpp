#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2][1000];
string sa, sb;
void input()
{
    cin >> sa >> sb;
}

void solution()
{
    for (int i = 0; i <= sb.size(); i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= sa.size(); i++)
    {
        for (int j = 1; j <= sb.size(); j++)
        {
            if (sa[i - 1] == sb[j - 1])
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            else
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
        }
    }
    cout << dp[sa.size() % 2][sb.size()];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solution();
    return 0;
}