#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "�輭���� ";
    int strSize = seoul.size();
    for (int i = 0; i < strSize; i++) {
        if (seoul[i] == "Kim") {
            answer += to_string(i);
            answer += "�� �ִ�";
            break;
        }
    }
    return answer;
}