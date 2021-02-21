#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


int N;
int visited[16];
int answer = 0;


void dfs(int curr){
    if(curr==N){
        answer++;
        return;
    }
    for(int i=0;i<N;i++){
        bool flag = true;
        for(int j= 0;j<curr;j++){
            if( visited[j] == i || abs(i - visited[j]) == abs(curr - j)){
                flag = false;
                break;
            }
        }
        if(flag){
            visited[curr] = i;
            dfs(curr+1);
        }   
    }
}

void solution(){
    cin>>N;
    dfs(0);
    cout<<answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solution();
    return 0;

}