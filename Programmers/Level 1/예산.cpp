#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0, size = d.size();
    sort(d.begin(), d.end());
    for (int i = 0; i < size; i++) {
        if (budget - d[i] >= 0) {
            budget -= d[i];
            answer++;
        }
        else break;
    }
    return answer;
}