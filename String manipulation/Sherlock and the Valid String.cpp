#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    map<char, int> count;
    map<int, int> sortByCount;
    for(auto ch : s)
        count[ch]++;
    for(auto &elem : count)
        sortByCount[elem.second]++;
    
    if(sortByCount.size() == 1) 
        return string("YES");
    else if(sortByCount.size() == 2) {
        auto firstElem = sortByCount.begin();
        auto secondElem = firstElem; secondElem++;
        int firstKey = firstElem->first, secondKey = secondElem->first;
        int firstVal, secondVal;
        if(firstKey < secondKey){
            swap(firstKey, secondKey);
            firstVal = secondElem->second, secondVal = firstElem->second;
        }
        else {
            firstVal = firstElem->second, secondVal = secondElem->second;
        }
        if((firstKey - secondKey == 1 && firstVal == 1) 
            || (secondVal == 1 && secondKey == 1))
            return string("YES");
        
    }
    
    return string("NO");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
