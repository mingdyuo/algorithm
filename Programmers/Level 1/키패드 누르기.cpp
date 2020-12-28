#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline int distance(int curr, int next) {
    return abs((curr - 1) / 3 - (next - 1) / 3)
        + abs((curr - 1) % 3 - (next - 1) % 3);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int right = 12, left = 10;
    for (int button : numbers) {
        if (button == 0) button = 11;
        if (button == 1 || button == 4 || button == 7) {
            answer += "L";
            left = button;
        }
        else if (button == 3 || button == 6 || button == 9) {
            answer += "R";
            right = button;
        }
        else {
            int rightDist = distance(right, button);
            int leftDist = distance(left, button);
            if (rightDist == leftDist) {
                if (hand == "right") {
                    answer += "R";
                    right = button;
                }
                else {
                    answer += "L";
                    left = button;
                }
            }
            else if (rightDist > leftDist) {
                answer += "L";
                left = button;
            }
            else {
                answer += "R";
                right = button;
            }
            
        }
    }
    return answer;
}