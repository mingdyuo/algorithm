#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for (int i = 1, num = x; i <= n; i++, num += x) {
        answer.push_back(num);
    }
    return answer;
}