#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int>::iterator it = min_element(arr.begin(), arr.end());
    arr.erase(it);
    return arr.empty() ? vector<int>{-1} : arr;
}