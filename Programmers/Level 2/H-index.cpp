#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] == citations.size() - i) {
            answer = citations[i]; break;
        }
        else if (citations[i] > citations.size() - i) {
            answer = max(citations[i - 1], (int)citations.size() - i);
            break;
        }
    }
    return answer;
}