#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxlen = 4;
vector<string> wzor;

bool cmp(string s1, string s2) {
  if (s1.size() < s2.size())
    return true;
  else if (s1.size() == s2.size())
    return s1 < s2;
  else
    return false;
}

void solution() {
  vector<string> v;
  int n;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 0; i < n; i++) {
    string cur;
    cur = a[i];
    // cout<<cur<<'\n';
    v.push_back(cur);
  }
  for (int i = 1; i < n; i++) {
    string cur;
    cur = a[i - 1];
    cur.push_back(a[i]);
    // cout<<cur<<'\n';
    v.push_back(cur);
  }
  for (int i = 2; i < n; i++) {
    string cur;
    cur = a[i - 2];
    cur.push_back(a[i - 1]);
    cur.push_back(a[i]);
    // cout<<cur<<'\n';
    v.push_back(cur);
  }
  sort(v.begin(), v.end(), cmp);
  v.erase(unique(v.begin(), v.end()), v.end());
  int pt = 0;
  while (true) {
    if (pt > v.size() || wzor[pt] != v[pt]) {
      cout << wzor[pt] << '\n';
      return;
    }
    pt++;
  }
}

void gen(string &a, int const ex) {
  if (a.size() == ex) {
    wzor.push_back(a);
    return;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    a.push_back(char(i));
    gen(a, ex);
    a.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string k;
  gen(k, 1);
  gen(k, 2);
  gen(k, 3);
  sort(wzor.begin(), wzor.end(), cmp);
  // for(int i=0; i<wzor.size(); i++)
  //     cout<<wzor[i]<<'\n';
  int t = 1;
  cin >> t;
  while (t--) solution();
}
