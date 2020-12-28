#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int size = completion.size();

    bool needToCheckRemainder = true;
    while (!completion.empty()) {
        string par = participant.back(), com = completion.back();
        if (par != com) {
            answer += par;
            needToCheckRemainder = false;
            break;
        }
        participant.pop_back(); completion.pop_back();
    }
    if (needToCheckRemainder)
        answer += participant.back();
        
    return answer;
}

