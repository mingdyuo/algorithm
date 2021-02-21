#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int R, C;
int answer;

int paper[51][51];
bool visited[51][51];

void input()
{
    cin >> R >> C;
    char ch;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> ch;
            if (ch == 'W')
                paper[i][j] = -1;
        }
    }
}

bool isValid(int x, int y)
{
    if (x >= 0 && y >= 0 && x < R && y < C)
        return true;
    return false;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    paper[si][sj] = 1;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (!isValid(nx, ny) || visited[nx][ny] || paper[nx][ny] == -1)
                continue;
            visited[nx][ny] = true;
            paper[nx][ny] = paper[x][y] + 1;
            q.push({nx, ny});
            answer = max(answer, paper[nx][ny]);
        }
    }
}

void solution()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (paper[i][j] >= 0)
            {
                bfs(i, j);
                memset(visited, false, sizeof(visited));
            }
        }
    }
    cout << answer - 1;
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