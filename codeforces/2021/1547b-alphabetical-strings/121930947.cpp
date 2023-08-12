#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  string s;
  cin >> s;
  int ptl = -10, ptr;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') {
      ptl = i - 1, ptr = i + 1;
      break;
    }
  }
  bool ok = true;
  if (ptl == -10) ok = false;
  for (int i = 1; i <= min(26, int(s.size()) - 1); i++) {
    char cur = 'a' + i;
    if (ptl >= 0 && s[ptl] == cur) {
      ptl--;
    } else if (ptr < s.size() && s[ptr] == cur) {
      ptr++;
    } else {
      ok = false;
      break;
    }
  }
  if (!ok) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  while (t--) solution();
}
