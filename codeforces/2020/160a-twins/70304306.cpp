#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int prefix[101], coins_value[101], coins_sum, n, sum;

bool compare(int x, int y) { return (x > y); }

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> coins_value[i];

  sort(coins_value, coins_value + n, compare);
}

void prefix_sum() {
  for (int i = 0; i < n; i++) {
    sum += coins_value[i];
    prefix[i] = sum;
  }
}

int answer() {
  int i = 0;
  while (prefix[i] <= sum / 2 && i <= n) i++;
  return i + 1;
}

int main() {
  input();
  prefix_sum();
  cout << answer();
  return 0;
}
