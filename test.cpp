#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
  vector<int> a = {10, 20, 30, 40, 50};
  int n = a.size();
  int target = 25;

  auto it = lower_bound(a.begin(), a.end(), target);

  if(*it != target){
    cout << "NO\n";
  }
  else{
    cout << "YES\n";
  }

  // int l=0, r=n;
  // while(l<r){
  //   int mid = l+(r-l)/2;
  //   if(a[mid] < target){
  //     l = mid + 1;
  //   }
  //   else{
  //     r = mid;
  //   }
  // }

  // if(a[r] == target){
  //   cout << "YES\n";
  // }
  // else{
  //   cout << "NO\n";
  // }

  return 0;
}
