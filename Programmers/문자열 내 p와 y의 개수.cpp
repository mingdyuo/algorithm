#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int strSize = s.size();
    int pCount = 0, yCount = 0;
    for (int i = 0; i < strSize; i++) {
        if (s[i] == 'p' || s[i] == 'P') pCount++;
        else if (s[i] == 'y' || s[i] == 'Y') yCount++;
    }
    return pCount == yCount ? true : false;
}