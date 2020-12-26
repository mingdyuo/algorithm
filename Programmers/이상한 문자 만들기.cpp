#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int index = 0;
    for (auto& ch : s) {
        if (ch == ' ') {
            index = 0;
            continue;
        }
        if (index % 2) 
            ch |= 32;
        else 
            ch &= ~(32);
        index++;
    }
    return s;
}