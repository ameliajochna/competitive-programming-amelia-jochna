#include <bits/stdc++.h>
using namespace std;
int const maxN = 2e5 + 2;
int trie[maxN * 30][2], nextv = 1, cnt[maxN * 30][2];
typedef long long ll;

void add(int n) {
  int s = 0;
  for (int i = 30; i >= 0; i--) {
    int b = (n >> i) & 1;
    cnt[s][b]++;
    if (!trie[s][b]) trie[s][b] = nextv++;
    s = trie[s][b];
  }
}

int ans(int n) {
  int s = 0;
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int b = (n >> i) & 1;
    if (trie[s][!b] && cnt[s][!b] > 0) {
      s = trie[s][!b];
      ans *= 2, ans |= 1;
    } else if (trie[s][b]) {
      s = trie[s][b];
      ans *= 2;
    }
  }
  return ans;
}

void erase(int n) {
  int s = 0;
  for (int i = 30; i >= 0; i--) {
    int b = (n >> i) & 1;
    cnt[s][b]--;
    s = trie[s][b];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  add(0);
  int n;
  cin >> n;
  while (n--) {
    char type;
    int a;
    cin >> type >> a;
    if (type == '+')
      add(a);
    else if (type == '-')
      erase(a);
    else if (type == '?')
      cout << ans(a) << '\n';
  }
}
