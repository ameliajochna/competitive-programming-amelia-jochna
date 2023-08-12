#include <bits/stdc++.h>
using namespace std;
map<string, int> database;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string tmp_name;
    cin >> tmp_name;
    if (database[tmp_name] == 0) {
      cout << "OK" << '\n';
    } else
      cout << tmp_name << database[tmp_name] << "\n";
    database[tmp_name]++;
  }
  return 0;
}
