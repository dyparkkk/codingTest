// https://www.acmicpc.net/problem/20366
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++)
    cin >> v[i];

  // 1. 원소 두 개를 고른다 nC2
  vector<tuple<int,int,int>> tuplev;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      tuplev.push_back({v[i]+v[j], i, j});
    }
  }
  // 2. 쌍들의 크기를 비교한다. 
  // ( 정렬 후에 앞뒤로 비교하면 됨, 차이만 출력하는 것이기 때문에 가능)
  int ans = 2e9;
  sort(tuplev.begin(), tuplev.end());
  for(int i=0; i<tuplev.size()-1; i++){
    if (get<1>(tuplev[i]) == get<1>(tuplev[i+1]) || get<1>(tuplev[i]) == get<2>(tuplev[i+1])) continue;
    if (get<2>(tuplev[i]) == get<1>(tuplev[i+1]) || get<2>(tuplev[i]) == get<2>(tuplev[i+1])) continue;
    ans = min(ans, abs(get<0>(tuplev[i]) - get<0>(tuplev[i+1])));
  }
  cout << ans;
  return 0;
}

/**
 * 회고 : 
 * 처음 봤을때 정말 막막한 문제였다. 변수가 4개라서 고려해야 할 것이 많은게 문제였다.
 * 투포인터로 변수 3개까지는 처리해 봤는데 4개는 또 다른 느낌이었다. 
 * 
 * 풀이 : 
 * 두 가지 풀이가 있다. 
 * 위 방식은 조합을 이용해서 푸는 방식인데 답이 눈덩이 쌍의 차이를 구하라! 였기 때문에 
 * 눈덩이 쌍을 구하고 그 합의 차이를 정렬해서 크기를 비교하는 방식이다. 
 * 다른 방식으로는 먼저 정렬을 하고 두 눈덩이를 정한다. 그리고 그 중간에 눈덩이들을 
 * left, right를 사용해서 투포인터로 푸는 방식이다. 
 * https://ansohxxn.github.io/boj/20366/ 참고...
 * 
 * ps : 
 * 답의 출력 방식이 힌트였다!
 * 
 */