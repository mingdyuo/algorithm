#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

string line;
int answer = 0;
void input()
{
    cin>>line;
}
enum OPERATOR{
    PLUS=0, MINUS
};

pair<int, int> getInfo(int index){
    pair<int, int> val;
    string num;
    while(isdigit(line[index])){
        num += line[index++];
    }
    val.first = stoi(num);
    val.second = index;
    return val;
}

void calculate(int OP, int numIdx, int stack){
    pair<int, int> info = getInfo(numIdx);
    if(info.second==line.length()){
        if(OP==PLUS) answer+=info.first;
        else {
            stack += info.first;
            answer -= stack;
        }
        return;
    }

    int nextOP = line[info.second]=='+'?PLUS:MINUS;
    int currNum = info.first;
    
    if(OP == PLUS){
        answer += currNum;
        calculate(nextOP, info.second+1, 0);
    }
    else{
        stack+= currNum;
        if(nextOP == MINUS){
            answer -= stack;
            calculate(nextOP, info.second+1, 0);
        }
        else{
            calculate(OP, info.second+1, stack);
        }
    }
}

void solution()
{
    calculate(PLUS, 0, 0);
    cout<<answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solution();
    return 0;
}