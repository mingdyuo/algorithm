#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    string token;
    string delimiter = string(" ");

    int pos = s.find(delimiter);
    token = s.substr(0, pos);
    int min = stoi(token), max = stoi(token);
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        if (max < stoi(token)) max = stoi(token);
        else if (min > stoi(token)) min = stoi(token);
        s.erase(0, pos + delimiter.length());
    }
    if (max < stoi(s)) max = stoi(s);
    else if (min > stoi(s)) min = stoi(s);
    
    answer += to_string(min) + ' ' + to_string(max);
    return answer;
}