#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> check;
    int size = numbers.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int sum = numbers[i] + numbers[j];
            if (check.find(sum) == check.end()) {
                answer.push_back(sum);
                check.insert(sum);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}