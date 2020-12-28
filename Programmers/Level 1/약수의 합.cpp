#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    if (n == 0) return 0;
    int limit = (int)sqrt(n);
    for (int i = 1; i < limit; i++) {
        if (n % i == 0)
            answer += i + (n / i);
    }
    if (n % limit == 0) {
        if (limit * limit == n)
            answer += limit;
        else
            answer += limit + (n / limit);
    }
    return answer;
}