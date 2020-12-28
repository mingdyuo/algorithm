#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
    int strLen = s.length();
    if (strLen != 4 && strLen != 6)
        return false;
    for (int i = 0; i < strLen; i++) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}