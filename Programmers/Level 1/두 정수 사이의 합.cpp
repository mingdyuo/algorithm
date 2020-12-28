#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution1(int a, int b) {
    long long answer = 0;
    if (a > b) swap(a, b);
    for (long long i = a; i <= b; i++) {
        answer += i;
    }
    return answer;
}

long long solution2(int a, int b) {
    long long answer = 0;
    if (a > b) swap(a, b);
    answer = (long long)(b - a + 1) * (a + b) / 2;
    return answer;
}