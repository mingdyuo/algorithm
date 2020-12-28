#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string weekDay[] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int days[] =
    {
        31, 29, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31,
        30, 31, 30, 31
    };
    for (int i = 0; i < a - 1; i++) {
        b += days[i];
    }
    
    return weekDay[(b - 1) % 7];
}