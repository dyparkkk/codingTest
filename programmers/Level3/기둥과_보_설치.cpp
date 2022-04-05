// https://programmers.co.kr/learn/courses/30/lessons/60061
#include <string>
#include <vector>
using namespace std;
// x, y, a, b == {좌표, 기둥(보), 삭제(설치)}
// 교차점 좌표를 기준으로 보는 오른쪽, 기둥은 위쪽 방향으로 설치 또는 삭제
int gidung[105][105], bo[105][105];

bool check(int n){
    for(int y=2; y<=n+2; y++){
        for(int x=2; x<=n+2; x++){
            if(gidung[y][x]){ // 기둥
                if( y==2 || gidung[y-1][x] ||
                   bo[y][x-1] || bo[y][x] ){}
                else return false;

            }
            if(bo[y][x]){
                if(gidung[y-1][x] || gidung[y-1][x+1] ||
                  (bo[y][x-1] && bo[y][x+1])){}
                else return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    // build_frame에서 하나씩 체크
    for(auto frame : build_frame){
        int x = frame[0] + 2;
        int y = frame[1] + 2;
        // 4가지 경우 ...
        // 기둥과 보 검증 후에 설치
        // 기둥 = 밑이 바닥,밑에 기둥, 왼쪽 보 x & 본인 보 O, 왼쪽 보 O & 본인 보 x,
        if(frame[2]==0 && frame[3]==1){ // 기둥 설치
            if(y==2 || gidung[y-1][x]) gidung[y][x] = 1;
            else if(bo[y][x-1] || bo[y][x]) gidung[y][x] = 1;
        }
        // 보 = 본인 밑 기둥 ,  왼쪽 보 & 오른쪽 보
        else if(frame[2]==1 && frame[3]==1){ // 보 설치
            if(gidung[y-1][x] || gidung[y-1][x+1]) bo[y][x]=1;
            else if( bo[y][x-1] && bo[y][x+1] ) bo[y][x]=1;
        }
        // 삭제시 일단 삭제하고 모든 구조물에 대해서 조건을 만족하는지 확인
        // 만족하지 않을시 다시 설치
        else if(frame[2]==0 && frame[3]==0){ // 기둥 삭제
            gidung[y][x] = 0;
            if(check(n) == false) gidung[y][x] = 1;
        }       
        else if(frame[2]==1 && frame[3]==0){ // 보 삭제
            bo[y][x] =0;
            if(check(n) == false) bo[y][x] =1;
        }
        
    }
    // 배열에서 벡터에 전부 담아서 정렬(순서대로 담아도 됨)
    // x  = x+2 , y = x+2
    for(int j=2; j<=n+2; j++){ 
        for(int i=2; i<=n+2; i++){
            if(gidung[i][j]) answer.push_back({j-2, i-2, 0});
            if(bo[i][j]) answer.push_back({j-2, i-2, 1});
        }
    }
    return answer;
}

/**
 * 회고 : 
 *  구현 자체는 쉬웠다. 처음에 주석으로 단계를 정해서 차근차근 풀어갔다. 
 *  문제는 삭제때 부터 였는데 예외가 많고 어려웠다... 
 * 
 * 접근법 : 
 *  설치는 쉽고 삭제는 어려우니 
 *  일단 삭제하고 다른 모든 구조물에 대해서 설치 조건을 검사한다. 
 *  -> 어려운 부분보다는 쉬운 부분을 모든 원소에 적용... 
 *  
 * 기타 : 
 *  경계 검사가 귀찮아서 x, y 에 +2 를 해서 검사를 피했다. 만족스럽다. 
 */