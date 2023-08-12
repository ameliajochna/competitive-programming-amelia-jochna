#include <bits/stdc++.h>
using namespace std;

int formula(int x) {
  if (x % 2 == 0)
    return ((x + 1) * 3 * x / 2) - x;
  else
    return ((x + 1) / 2) * 3 * x - x;
}

void solution() {
  int a, houses = 0;
  cin >> a;
  int counter = ceil((sqrt(ceil(2 * a / 3))));
  while (formula(counter) > a) counter--;
  while (a >= formula(counter) && formula(counter) >= 2) {
    a -= formula(counter);
    counter = (ceil((sqrt(ceil(2 * a / 3)))));
    while (formula(counter) > a) counter--;
    houses++;
  }
  cout << houses << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
