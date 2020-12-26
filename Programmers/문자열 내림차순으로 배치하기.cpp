#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const char& a, const char& b) {
    if (islower(a) && isupper(b)) {
        return true;
    }
    else if (isupper(a) && islower(b)) {
        return false;
    }
    return a > b ? true : false;
}

string solution(string s) {
    sort(s.begin(), s.end(), compare);
    return s;
}