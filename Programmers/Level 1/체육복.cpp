#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> total(n+2, 0);
    for (auto studentRsv : reserve) {
        total[studentRsv]++;
    }
    for (auto studentLost : lost) {
        total[studentLost]--;
    }
    for (int i = 1; i <= n; i++) {
        if (total[i] < 0) {
            if (total[i - 1] > 0) {
                total[i - 1]--;
            }
            else if(total[i + 1] > 0){
                total[i + 1]--;
            }
            else {
                total[i]++;
                answer++;
            }
            
        }
    }

    return n - answer;
}