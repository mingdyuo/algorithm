#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        int number1 = arr1[i], number2 = arr2[i];
        string line = "";
        for (int j = 0; j < n; j++) {
            bool bit1 = number1 & 1, bit2 = number2 & 1;
            number1 >>= 1; number2 >>= 1;
            if (bit1 || bit2)
                line = '#' + line;
            else
                line = ' ' + line;
        }
        answer.push_back(line);
    }

    return answer;
}