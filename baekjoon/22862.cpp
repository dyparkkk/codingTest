// https://www.acmicpc.net/problem/22862
#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[1000005];
int main(){
  ios_base::sync_with_stdio(0); cin.tie(NULL);  
  cin >> n >> k;

  for(int i=0; i<n; i++)
    cin >> arr[i];

  int st = 0, en = 0, ans = 0;
  int cnt = arr[0]%2;
  for(; st < n; st++){
    while(en < n && cnt <= k){
      en++;
      if(arr[en]%2) cnt++;
    }
    if(en==n) break;
    ans = max(ans, en-st-cnt+1); // en을 포함하는 길이
    if(arr[st]%2) cnt--;
  }
  ans = max(ans, en-st-cnt); // en을 포함하지 않는 길이 
  cout << ans;
  return 0;
}

/**
 * 회고 : 
 * 투포인터를 구현할 때 en을 포함할 것인지, 포함하지 않을 것인지 잘 구분을 해야겠다. 
 * 
 * 
 */