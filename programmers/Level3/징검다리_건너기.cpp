// https://programmers.co.kr/learn/courses/30/lessons/64062
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
bool check(int pos, vector<int> &stones, int k){
    // 건널수 있으면 true, 없으면 false;
    int cnt=0;
    for(int i=0; i<stones.size(); i++){
        if(stones[i] < pos) cnt++;
        else cnt=0;
        
        if(cnt == k)
            return false;
    }
    answer = max(answer, pos);
    return true;
}

int solution(vector<int> stones, int k) {
    int st = 1, en = *max_element(stones.begin(), stones.end()); // !!
    while(st <= en){
        int mid = (en+st)/2;
        if(check(mid, stones, k)){
            st = mid+1;
        }
        else en = mid-1;
    }
    return answer;
}

/**
 * 회고 : 
 * 완탐으로 구현했는데 당연히 시간초과가 떴다. 
 * 이분탐색을 떠올리긴 했는데 적용에서 애를 먹었다. (범위를 보니 nlogn 알고리즘이었음)
 * 
 * 구현을 기억하자 !
 * while(st <= en) ... 매우 간단하게 구현해볼 수 있음 
 * 큰 범위를 이분탐색으로 (중복되더라도) 탐색할 수 있는지 고민해보자
 */