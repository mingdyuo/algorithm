#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long number = num;
    while (true) {
        if (number == 1)
            return answer;
        else if (answer > 500)
            return -1;

        if (number & 1) 
            number = number * 3 + 1; 
        else 
            number >>= 1;
        
        answer++;
    }
}