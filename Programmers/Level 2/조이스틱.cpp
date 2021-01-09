#include <string>
#include <vector>
using namespace std;

int solution(string name) {
    int answer = 0;
    string solution = string('A', name.length());
    for (char a : name) answer += a - 'A' < 'Z' + 1 - a ? a - 'A' : 'Z' + 1 - a;
    
    int aCount = 0, aMaxCount = 0;
    char prev = name[0];
    int maxA[2];
    vector<int> Aindex;
    if (prev == 'A') {
        aCount++;
        Aindex.push_back(0);
    }
    for (int i = 1; i < name.size(); i++) {
        if (prev == 'A') {
            if (name[i] == 'A') {
                aCount++;
                Aindex.push_back(i);
            }
            else {
                if (aMaxCount < aCount) {
                    aMaxCount = aCount;
                    maxA[0] = Aindex.front();
                    maxA[1] = Aindex.back();
                }
                aCount = 0;
                Aindex.clear();
            }
        }
        else {
            if (name[i] == 'A') {
                aCount = 1;
                Aindex.push_back(i);
            }
        }
        prev = name[i];
    }
    if (prev == 'A' && aMaxCount < aCount) {
        aMaxCount = aCount;
        maxA[0] = Aindex.front();
        maxA[1] = Aindex.back();
    }

    if (aMaxCount == 0) {
        answer += name.size() - 1;
    }
    else {
        int backwards = name.size() - maxA[1] + 2 * maxA[0] - 3,
            forwards = name.size() - 1;
        answer += forwards < backwards ? forwards : backwards;
    }
    return answer;
}