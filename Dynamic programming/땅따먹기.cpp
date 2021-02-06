#include <iostream>
#include <vector>
using namespace std;
int dp[100002][4];
int solution(vector<vector<int>> land)
{
    for (int i = 0; i < 4; i++) dp[0][i] = land[0][i];
    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int max = 0;
            for (int k = 0; k < 4; k++) {
                if (k == j) continue;
                max = max < dp[i - 1][k] ? dp[i - 1][k] : max;
            }
            dp[i][j] = land[i][j] + max;
        }
    }
    int answer = dp[land.size()-1][0];
    for (int i = 1; i < 4; i++)
        if (answer < dp[land.size() - 1][i])
            answer = dp[land.size() - 1][i];

    return answer;
}