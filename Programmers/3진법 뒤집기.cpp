#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int> st;
    while (n) {
        st.push(n % 3);
        n /= 3;
    }
    for (int i = 1; !st.empty(); i *= 3) {
        answer += st.top() * i;
        st.pop();
    }
    return answer;
}