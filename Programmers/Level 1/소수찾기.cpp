#include <string>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i+=2) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    vector<bool> primes(n + 1, true);
    answer = 1;
    for (int i = 3; i <= n; i+=2) {
        if (primes[i] == false) continue;
        if (isPrime(i)) {
            answer++;
            for (int j = 2; j * i <= n; j++) {
                primes[j * i] = false;
            }
        }
    }
    return answer;
}