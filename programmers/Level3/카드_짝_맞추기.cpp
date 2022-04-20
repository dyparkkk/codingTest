#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int curY, curX;
struct st{
    int y,x,cnt;
};
int dy[]={0, 1, 0, -1};
int dx[]={1, 0, -1, 0};

int bfs(int dest, vector<vector<int>> &board){
    bool check[4][4] = {false, };
    queue<st> q;
    q.push({curY, curX, 0});
    check[curY][curX] = true;
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt; q.pop();
        if(board[y][x] == dest){
            board[y][x] = 0;
            curY = y;
            curX = x;
            return cnt+1;
        }
        // 1칸 이동
        for(int dir=0; dir<4; dir++){
            int ny = y+dy[dir];
            int nx = x+dx[dir];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if(check[ny][nx]) continue;
            q.push({ny, nx, cnt+1});
            check[ny][nx] = true;
        }
        // 컨트롤 이동
        for(int dir=0; dir<4; dir++){
            int ny = y;
            int nx = x;
            while(ny+dy[dir] >= 0 && ny+dy[dir] < 4 && nx+dx[dir] >= 0 && nx+dx[dir] < 4){
                ny += dy[dir];
                nx += dx[dir];
                if(board[ny][nx]) break;
            }

            if(check[ny][nx]) continue;
            q.push({ny, nx, cnt+1});
            check[ny][nx] = true;
        }
        
    }
}
/**
* 카드 고르기 완전탐색 ... -> 어떤 카드를 찾을지 고민할 필요가 없음 (순서 고정)
* 그러면 커서 이동에만 신경써서 구현하면 됨 (bfs)
* 이렇게 생각하면 풀만한 문제였음
*/
int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0x3fffffff;
    vector<int> v;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j])
                v.push_back(board[i][j]);
        }
    }
    // 중복제거
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    do{
        // 경우의 수 확인할 때마다 커서 초기화
        curY=r, curX=c;
        vector<vector<int>> tmpBoard = board;
        int tmp = 0;
        for(int i=0; i<v.size(); i++){
            tmp += bfs(v[i], tmpBoard);
            tmp += bfs(v[i], tmpBoard);
        }
        answer = min(answer, tmp);
    } while( next_permutation(v.begin(), v.end()));
    return answer;
}