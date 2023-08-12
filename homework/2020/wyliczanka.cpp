#include <bits/stdc++.h>
#define FOR(n) for (int i = 0; i < n; i++)
#define nd second
#define st first
using namespace std;
typedef pair<int, int> pii;
bool const isprime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0,
                        1, 0, 1, 0, 0, 0, 1, 0, 1, 0};
int n, cong[25];  // ita komorka: k=cong[i] mod i

int fastmodpow(int a, int power, int mod) {  //(a^power)%mod
  if (power <= 0) return 1;
  if (power % 2 == 0) {
    int ans = fastmodpow(a, power / 2, mod) % mod;
    return (ans * ans) % mod;
  }
  return (a * fastmodpow(a, power - 1, mod)) % mod;
}

int chinesereminder(vector<pii> congruence, int prod) {
  int solution = 0;
  FOR(congruence.size()) {
    int cur = prod / congruence[i].nd;
    solution += (cur)*fastmodpow(cur, congruence[i].nd - 2, congruence[i].nd) *
                congruence[i].st;
    solution = solution % prod;
  }
  return solution;
}

void to_modulo(vector<pii> seq) {
  sort(seq.begin(), seq.end());
  int next = 0;
  vector<bool> ingame(n);
  FOR(n) ingame[i] = true;
  FOR(n) {
    int reminder = 1;
    while (next != seq[i].nd) {
      if (ingame[next]) reminder++;
      next = (next + 1) % n;
    }
    reminder = reminder % (n - seq[i].st);
    ingame[next] = false;
    cong[n - i] = reminder;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  vector<pii> seq(n);
  for (int i = 0; i < n; i++) {
    int pos;
    cin >> pos;
    seq[i] = {pos - 1, i};
  }
  to_modulo(seq);
  vector<pii> correctcong;
  int primemult = 1;
  FOR(n + 1) {
    if (isprime[i]) correctcong.push_back({cong[i], i}), primemult *= i;
  }
  int solution = chinesereminder(correctcong, primemult);
  if (solution == 0) solution += primemult;
  for (int j = 1; j <= (232792560) / primemult; j++) {
    bool correct = true;
    for (int i = 1; i <= n; i++) {
      if (solution % i != cong[i]) {
        correct = false;
      }
    }
    if (correct) {
      cout << solution;
      return 0;
    }
    solution += primemult;
  }
  cout << "NIE\n";
  return 0;
}
