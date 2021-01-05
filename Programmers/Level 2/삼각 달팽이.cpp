#include <string>
#include <vector>

using namespace std;
int dx[] = { 1, 0, -1 };
int dy[] = { 0, 1, -1 };
int table[1001][1001];
vector<int> solution(int n) {
    vector<int> answer;
    int dir = 0;
    int number = 1;
     int x = 0, y = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            x += dx[dir]; y += dy[dir];
            table[x][y] = number++;
        }
        dir = (dir + 1) % 3;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            answer.push_back(table[i][j]);
        }
    }
    return answer;
}
