#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n) {
    string answer = "";
    stack<int> st;
    int bottom = 0, top = 3, addition = 3, size = 1;
    while (true) {
        if (bottom < n && top >= n) {
            n -= bottom + 1;
            while (true) {
                st.push(n % 3);
                n /= 3;
                if (n == 0) break;
            }
            break;
        }
        else {
            bottom += addition;
            addition *= 3;
            top += addition;
            size++;
        }
    }

    for (int i = 0; i < size - st.size(); i++) {
        answer += '1';
    }
    while (!st.empty()) {
        switch (st.top())
        {
        case 0: answer += '1'; break;
        case 1: answer += '2'; break;
        case 2: answer += '4'; break;
        default: break;
        }
        st.pop();
    }
    return answer;
}