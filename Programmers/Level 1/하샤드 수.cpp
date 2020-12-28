#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string number = to_string(x);
    int sumOfPos = 0;
    for (auto& ch : number) {
        sumOfPos += ch - '0';
    }
    return x % sumOfPos == 0 ? true : false;
}