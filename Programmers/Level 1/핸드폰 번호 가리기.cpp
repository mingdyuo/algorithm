#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int strSize = phone_number.length();
    for (int i = 0; i < strSize - 4; i++) {
        answer += '*';
    }
    for (int i = strSize - 4; i < strSize; i++) {
        answer += phone_number[i];
    }
    return answer;
}