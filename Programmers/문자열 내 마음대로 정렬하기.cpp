#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
    int n;
    bool operator() (const string& a, const string& b) {
        if (a[n] == b[n]) return a < b ? true : false;
        else return a[n] < b[n] ? true : false;
    }
    compare(int N) { n = N; }
};

vector<string> solution(vector<string> strings, int n) {
    compare comp = compare(n);
    sort(strings.begin(), strings.end(), comp);
    return strings;
}