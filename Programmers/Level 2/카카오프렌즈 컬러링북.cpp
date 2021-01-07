#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[102][102];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int M, N;

bool isValid(int x, int y) {
    if (x >= 0 && y >= 0 && x < M && y < N)
        return true;
    return false;
}

int bfs(int start_x, int start_y, vector<vector<int>>& picture) {
    queue<pair<int, int>> q;
    int color = picture[start_x][start_y];
    q.push({ start_x, start_y });
    visited[start_x][start_y] = true;
    int area = 1;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!isValid(nx, ny))
                continue;
            if (picture[nx][ny] == color && !visited[nx][ny]) {
                visited[nx][ny] = true;
                area++;
                q.push({ nx,ny });
            }
        }
    }
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for (int i = 0; i < m; i++) {
        memset(visited[i], 0, sizeof(int) * n);
    }
    M = m, N = n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int area = bfs(i, j, picture);
                if (picture[i][j] == 0)
                    continue;
                if (area > max_size_of_one_area)
                    max_size_of_one_area = area;
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
