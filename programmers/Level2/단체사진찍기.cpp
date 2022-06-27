#include <bits/stdc++.h> // 22.06.07
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string order = "ACFJMNRT";
    do{
        bool ok = true;
        for(string s:data){
            int a, b;
            for(int i=0; i<order.size(); i++){
                if(order[i] == s[0]) a=i;
                if(order[i] == s[2]) b=i;
            }
            
            if(s[3] == '='){
                if( !(abs(a-b)-1 == s[4]-'0')){
                    ok = false; break; 
                }
            }
            else if(s[3] == '<'){
                if( !(abs(a-b)-1 < s[4]-'0')){
                    ok = false; break; 
                }
            }
            else if(s[3] == '>'){
                if( !(abs(a-b)-1 > s[4]-'0')){
                    ok = false; break; 
                }
            }
        }
        if(ok) answer++;
    } while( next_permutation(order.begin(), order.end()));
    return answer;
}

/**
 * 원소가 8개에 조건이 100개인 문제였다. 
 * 답 : 원소의 순서의 경우의 수 -> 8! * 100 정도의 O(n)이어서 완탐으로 풀었다.
 * 
 * nextPermutation에 String도 가능하며, 제시된 조건이 String으로 주어져서 
 * String으로 순열을 구했다.  
 * 
 */