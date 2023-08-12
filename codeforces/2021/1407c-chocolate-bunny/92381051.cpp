#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> value(n + 1);
  vector<bool> taken(n + 1);
  set<int> s;
  for (int i = 1; i <= n; i++) s.insert(i);
  while (s.size() != 1) {
    auto it = s.begin();
    int a1 = *(it++), a2 = *(it), rest1, rest2;
    cout << "? " << a1 << " " << a2 << '\n';
    cin >> rest1;
    cout << "? " << a2 << " " << a1 << '\n';
    cin >> rest2;
    if (rest1 < rest2)
      value[a2] = rest2, s.erase(a2), taken[rest2] = true;
    else
      value[a1] = rest1, s.erase(a1), taken[rest1] = true;
  }
  cout << "! ";
  int left;
  for (int i = 1; i <= n; i++)
    if (!taken[i]) {
      left = i;
      break;
    }
  for (int i = 1; i <= n; i++) {
    if (value[i] == 0) value[i] = left;
    cout << value[i] << " ";
  }
  cout.flush();
}
