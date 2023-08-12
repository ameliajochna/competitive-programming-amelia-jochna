#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  vector<int> even;
  vector<int> odd;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    if (e & 1)
      odd.push_back(i + 1);
    else
      even.push_back(i + 1);
  }
  if (!even.empty()) {
    cout << even.size() << '\n';
    for (int i = 0; i < even.size(); i++) cout << even[i] << " ";
    cout << '\n';
  } else if (odd.size() > 1) {
    cout << odd.size() - odd.size() % 2 << '\n';
    for (int i = 0; i < odd.size() - odd.size() % 2; i++) {
      cout << odd[i] << " ";
    }
    cout << '\n';
  } else
    cout << "-1" << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
