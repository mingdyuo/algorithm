#include <string>
#include <vector>

using namespace std;

char shift(char ch, int n) {
    if (ch == ' ')
        return ' ';
    while (n--) {
        ch++;
        if (!isalpha(ch))
            ch -= 26;
    }

}


string solution(string s, int n) {
    string answer = "";
    s = string("ZzZzZ Z Z Zzz ZZ ZZ zz dkj pkj JDkj JDlfksj d");
    n = 25;
    int strSize = s.size();
    for (int i = 0; i < strSize; i++) {
        answer += shift(s[i], n);
    }
    return answer;
}