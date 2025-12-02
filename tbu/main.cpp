// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ranges>

using namespace std;
#define int long long

// __builtin_popcountll() -> number of one's (set bit's) in a long long
// __builtin_clzll() -> number of leading zeros
// 64 - __builtin_clzll(n) -> size of n in binary

bool check(int num){
  return (num*num>=100);
}

signed main(){
  auto possible_answers = views::iota(0ll, 1001ll);
  auto it = ranges::partition_point(possible_answers, check);

  cout << *it << "\n";

	return 0;
}
