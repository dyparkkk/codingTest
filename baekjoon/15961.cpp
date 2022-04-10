// https://www.acmicpc.net/problem/15961
#include<bits/stdc++.h>
using namespace std;

int arr[3003005];
int n, d, k, c;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(NULL); 
  cin >> n >> d >> k >> c;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  // 회전 처리 -> n 뒤에 앞에 k개를 붙여보기 ??
  for(int i=0; i<k; i++){ // size == n+k
    arr[i+n] = arr[i];
  }
  
  
  unordered_map<int, int> m;
  // 다른 초밥 선택  -> map
  int st =0, en = 0, mx = 1, siz = 1;
  m[arr[0]]++;
  bool coupon = false; // 쿠폰 k 처리 
  if(arr[0] == c) 
    coupon = true;
  
  for(;st < n+k; st++){
    while(en < n+k && en-st+1 < k){
      en++;
      if(m[arr[en]] == 0) siz++;
      m[arr[en]]++;
      if(arr[en] == c) coupon = true;
    }
    if(en == n+k) break;
    // if(coupon == false ) // 쿠폰 초밥이 없으면 +1
    //   tmp++; 
    mx = max(mx, (coupon == false) ? siz+1: siz);
    m[arr[st]]--;
    if(m[arr[st]] == 0) {
      siz--;
      if(arr[st] == c) // coupon 삭제
        coupon = false;
    }
  }
  cout << mx;
  return 0;
}

/**
 * 회고 : 
 * 문제 자체를 설계하는 것은 금방했다. map을 쓰기 좋은 문제였다.
 * 문제는 시간초과가 계속 떴다. 
 * 확인해보니 map container 문제였는데
 * 
 * map은 레드 블랙 이진 트리로 구현되어 있어서 
 * 자동정렬이 되고 키값이 비슷해도 상관없다. 
 * 삽입 삭제 검색시 logN의 시간복잡도를 나타냈다.
 * 
 * 반면, unordered_map의 경우는 해시테이블로 구현되어 있어서
 * 키값을 해시한다
 * 삽입, 삭제, 검색시 O(1)의 복잡도를 나타냈다. 
 * 공간을 더 많이 잡아먹는다고 한다. (미리 배열 할당... Java의 HashMap과 비슷함)
 * 
 */