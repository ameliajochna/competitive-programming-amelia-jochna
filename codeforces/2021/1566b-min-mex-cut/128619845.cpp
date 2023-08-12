#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

void solution() {
  string s;
  cin >> s;
  bool zero = false;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '0') zero = true;
  if (!zero) {
    cout << "0\n";
  } else {
    int stzero = -1, lastzero = -1;
    for (int i = 0; i < s.size(); i++) {
      if (stzero == -1 && s[i] == '0') stzero = i;
    }
    for (int i = s.size() - 1; i >= 0; i--) {
      if (lastzero == -1 && s[i] == '0') lastzero = i;
    }
    for (int i = stzero; i <= lastzero; i++) {
      if (s[i] == '1') {
        cout << "2\n";
        return;
      }
    }
    cout << "1\n";
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
