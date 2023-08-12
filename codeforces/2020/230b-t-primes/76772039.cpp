#include <bits/stdc++.h>
using namespace std;
int const maxN = 1e6 + 10;
bool prime[maxN];
void sieve() {
  fill_n(prime, maxN, true);
  prime[1] = false;
  for (int i = 2; i < maxN; i++) {
    if (prime[i]) {
      for (int j = 2; i * j < maxN; j++) {
        prime[i * j] = false;
      }
    }
  }
}

void solution() {
  long long n;
  cin >> n;
  long long sqr = sqrt(n);
  if (sqr * sqr == n && prime[sqr])
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  sieve();
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
