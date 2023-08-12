#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define sz(a) a.size()
#define pb push_back
using namespace std;
typedef long long ll;
int const maxN = 1e5 + 10, MOD = 1e9 + 7;
int n, h[maxN], cnt[maxN];
vector<vector<int> > v;
bool taken[maxN];
ll ans = 1;

void end() {
  cout << "0\n";
  exit(0);
}

bool possible() {
  v.resize(n);
  for (int i = 0; i < n; i++) {
    int ind = i, val = h[i];
    v[val].push_back(ind);
  }
  for (int i = 0; i < n; i++) {
    if (v[i].size() > 2) return false;
    if (v[i].size() == 2 && v[i][0] != (v[i][1] - 2)) return false;
  }
  return true;
}

void reserve() {
  taken[1] = true;
  taken[n - 2] = true;
  if (n == 3 && h[0] != h[2]) end();
  for (int i = 0; i < n; i++)
    if (v[i].size() == 2) taken[v[i][0] + 1] = true;
  for (int i = 0; i < n; i++) {
    if (v[h[i]].size() == 2) continue;
    int ind1 = i - 1, ind2 = i + 1;
    if (ind1 >= 0 && ind2 < n) {
      if (taken[ind1] && taken[ind2])
        end();
      else if (taken[ind1])
        taken[ind2] = true;
      else if (taken[ind2])
        taken[ind1] = true;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (v[h[i]].size() == 2) continue;
    int ind1 = i - 1, ind2 = i + 1;
    if (ind1 >= 0 && ind2 < n) {
      if (taken[ind1]) taken[ind2] = true;
      if (taken[ind2])
        taken[ind1] = true;
      else {
        cnt[ind1]++;
        cnt[ind2]++;
      }
    }
  }
}

void calcans() {
  int curcnt = 0;
  bool started = false;
  for (int i = 0; i < n; i += 2) {
    if (cnt[i] == 0)
      continue;
    else if (cnt[i] == 1) {
      if (!started)
        curcnt++;
      else {
        ans *= (curcnt + 1);
        ans %= MOD;
        curcnt = 0;
      }
      started ^= 1;
    } else if (cnt[i] == 2)
      curcnt++;
  }
  curcnt = 0;
  started = false;
  for (int i = 1; i < n; i += 2) {
    if (cnt[i] == 0)
      continue;
    else if (cnt[i] == 1) {
      if (!started)
        curcnt++;
      else {
        ans *= (curcnt + 1);
        ans %= MOD;
        curcnt = 0;
      }
      started ^= 1;
    } else if (cnt[i] == 2)
      curcnt++;
  }
  int notused = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].size() == 0) {
      notused++;
      ans *= notused;
      ans %= MOD;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
    h[i]--;
  }
  if (!possible()) end();
  reserve();
  calcans();
  cout << ans << '\n';
}
