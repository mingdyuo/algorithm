#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long answer = 0;
    vector<pair<char, int>> arr;
    char prev = s[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        if(prev != s[i]){
            arr.push_back({prev, count});
            prev = s[i];
            count = 1;
        }
        else 
            count++;
    }
    arr.push_back({prev, count});
    for(auto elem : arr){
        answer += (elem.second) * (elem.second + 1) / 2;
    }
    if(arr.size()<3) return answer;
    for(int i=1;i<=arr.size()-2;i++){
        if(arr[i-1].first == arr[i+1].first && arr[i].second == 1){
            answer += min(arr[i-1].second, arr[i+1].second);
        }
    }
    
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
