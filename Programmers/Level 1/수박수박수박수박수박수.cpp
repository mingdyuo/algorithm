#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    int limit = n / 2;
    for (int i = 0; i < limit; i++) {
        answer += "¼ö¹Ú";
    }
    if (n & 1) answer += "¼ö";
    return answer;
}