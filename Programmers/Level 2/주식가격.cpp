#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();
    for (int i = 0; i < size; i++) {
        answer.push_back(0);
        for (int j = i + 1; j < size; j++) {
            answer[i]++;
            if (prices[i] > prices[j]) {
                break;
            }
        }
    }
    return answer;
}