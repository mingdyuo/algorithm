#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (auto& n : arr) {
        answer += n;
    }
    return answer / arr.size();
}