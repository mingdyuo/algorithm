#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> heights, basket;
    int size = board.size();
    for (int i = 0; i < size; i++)  {
        int height = 0;
        for (int j = size - 1; j >= 0; j--) {
            if (board[j][i])
                height++;
            else
                break;
        }
        heights.push_back(height);
    }

    for (int& pop : moves) {
        if (heights[pop - 1]) {
            int top = board[size - heights[pop - 1]][pop - 1];
            heights[pop - 1]--;
            if (basket.empty() || basket.back() != top) {
                basket.push_back(top);
            }
            else {
                basket.pop_back();
                answer += 2;
            }
        }
    }
    return answer;
}