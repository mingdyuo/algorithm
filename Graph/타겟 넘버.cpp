#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

int t;
int answer;

void dfs(vector<int> numbers, int curr, int sum, int rest) {
    if (curr == numbers.size()) {
        if(sum == t) answer++;
        return;
    }
    int k = numbers[curr];
    if (sum - rest + 2 * k <= t)
        dfs(numbers, curr + 1, sum + k, rest - k);
    if (sum + rest - 2 * k >= t)
        dfs(numbers, curr + 1, sum - k, rest - k);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    t = target;
    dfs(numbers, 0, 0, accumulate(numbers.begin(), numbers.end(), 0));
    return answer;
}

int main() {
    cout<<solution({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 10);
}