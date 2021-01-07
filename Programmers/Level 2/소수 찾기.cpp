#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0 || n == 1) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0, size = numbers.length();
    vector<int> number, ans;
    for (int i = 0; i < numbers.size(); i++) {
        number.push_back(numbers[i] - '0');
    }

    sort(number.begin(), number.end());
    do {
        for (int i = 0; i <= size; i++) {
            int total = 0;
            for (int j = 0; j < i; j++) {
                total = (total * 10) + number[j];
                ans.push_back(total);
            }
        }
    } while (next_permutation(number.begin(), number.end()));
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        if (isPrime(ans[i]))
            answer++;
    }
    return answer;
}
