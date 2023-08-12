#include <bits/stdc++.h>
using namespace std;
#define pb(a) push_back(a)
typedef long long ll;
int const maxN = 300005;
int n;
vector<vector<int> > st, nd, rd;
vector<vector<int> > a;
ll sum0, sum1, sum2, ans;

void divide() {
  for (int i = 0; i < n; i++) {
    int tmpmax = max({a[i][0], a[i][1], a[i][2]});
    if (tmpmax == a[i][0]) {
      a[i].pb(a[i][1] + a[i][2]);
      st.pb(a[i]);
    } else if (tmpmax == a[i][1]) {
      a[i].pb(a[i][0] + a[i][2]);
      nd.pb(a[i]);
    } else {
      a[i].pb(a[i][0] + a[i][1]);
      rd.pb(a[i]);
    }
    sum0 += a[i][0], sum1 += a[i][1], sum2 += a[i][2];
  }
}

void oneempt(vector<vector<int> > &f0, vector<vector<int> > &f1,
             vector<vector<int> > &to, int ind0, int ind1, int ind2) {
  ll minsum0 = LONG_LONG_MAX, minsum1 = LONG_LONG_MAX;
  int bind0, bind1;
  for (int i = 0; i < f0.size(); i++) {
    ll cursum = 0;
    for (int j = 0; j < 3; j++)
      if (j != ind2) cursum += f0[i][j];
    if (cursum - f0[i][3] < minsum0) {
      minsum0 = cursum - f0[i][3];
      bind0 = i;
    }
  }
  for (int i = 0; i < f1.size(); i++) {
    ll cursum = 0;
    for (int j = 0; j < 3; j++)
      if (j != ind2) cursum += f1[i][j];
    if (cursum - f1[i][3] < minsum1) {
      minsum1 = cursum - f1[i][3];
      bind1 = i;
    }
  }
  ll minsum0a = LONG_LONG_MAX, minsum1a = LONG_LONG_MAX, allsum0, allsum1;
  int bind0a, bind1a;
  if (f0.size() == 1) {
    for (int i = 0; i < f1.size(); i++) {
      ll cursum = 0;
      for (int j = 0; j < 3; j++)
        if (j != ind0) cursum += f1[i][j];
      if (cursum - f1[i][3] < minsum0a) {
        minsum0a = cursum - f1[i][3];
        bind0a = i;
      }
    }
    allsum0 = minsum0a + minsum0;
    if (minsum1 <= allsum0) {
      ans += minsum1 + f1[bind1][3];
      f1[bind1][0] = INT_MAX;
    } else {
      ans += allsum0 + f1[bind0a][3] + f0[bind0][3];
      f0[bind0][0] = INT_MAX;
      f1[bind0a][0] = INT_MAX;
    }
  }

  else if (f1.size() == 1) {
    for (int i = 0; i < f0.size(); i++) {
      ll cursum = 0;
      for (int j = 0; j < 3; j++)
        if (j != ind1) cursum += f0[i][j];
      if (cursum - f0[i][3] < minsum1a) {
        minsum1a = cursum - f0[i][3];
        bind1a = i;
      }
    }
    allsum1 = minsum1a + minsum1;
    if (minsum0 <= allsum1) {
      ans += minsum0 + f0[bind0][3];
      f0[bind0][0] = INT_MAX;
    } else {
      ans += allsum1 + f0[bind1a][3] + f1[bind1][3];
      f0[bind1a][0] = INT_MAX;
      f1[bind1][0] = INT_MAX;
    }
  } else {
    if (minsum1 <= minsum0) {
      ans += minsum1 + f1[bind1][3];
      f1[bind1][0] = INT_MAX;
    } else {
      ans += minsum0 + f0[bind0][3];
      f0[bind0][0] = INT_MAX;
    }
  }
}

pair<pair<int, int>, pair<int, int> > fill(const vector<vector<int> > &f,
                                           const vector<vector<int> > &to0,
                                           const vector<vector<int> > &to1,
                                           const int ind0, const int ind1) {
  ll opt0 = LONG_LONG_MAX, opt1 = LONG_LONG_MAX;
  int bestind0, bestind1;
  for (int i = 0; i < f.size(); i++) {
    ll cursum = 0;
    for (int j = 0; j < 3; j++)
      if (j != ind0) cursum += f[i][j];
    if (cursum - f[i][3] < opt0) {
      opt0 = cursum - f[i][3];
      bestind0 = i;
    }
  }
  for (int i = 0; i < f.size(); i++) {
    ll cursum = 0;
    for (int j = 0; j < 3; j++)
      if (j != ind1) cursum += f[i][j];
    if (cursum - f[i][3] < opt1 && i != bestind0) {
      opt1 = cursum - f[i][3];
      bestind1 = i;
    }
  }
  return {{opt0, bestind0}, {opt1, bestind1}};
}

void twoempt(vector<vector<int> > &f, vector<vector<int> > &to0,
             vector<vector<int> > &to1, int ind0, int ind1) {
  auto res0 = fill(f, to0, to1, ind0, ind1);
  auto res1 = fill(f, to1, to0, ind1, ind0);
  ll sum1 = res0.first.first + res0.second.first;
  ll sum2 = res1.first.first + res1.second.first;
  int e1, e2;
  if (sum1 <= sum2) {
    e1 = res0.first.second;
    e2 = res0.second.second;
    ans += f[e1][3] + f[e2][3] + sum1;
  } else {
    e1 = res1.first.second;
    e2 = res1.second.second;
    ans += f[e1][3] + f[e2][3] + sum2;
  }
  f[e1][0] = INT_MAX;
  f[e2][0] = INT_MAX;
}

void chsempt() {
  const bool ex0 = (st.empty() && sum0), ex1 = (nd.empty() && sum1),
             ex2 = (rd.empty() && sum2);
  const int cnt = ex0 + ex1 + ex2;
  if (cnt == 0) return;
  if (cnt == 2) {
    if (ex0 && ex1)
      twoempt(rd, st, nd, 0, 1);
    else if (ex0 && ex2)
      twoempt(nd, st, rd, 0, 2);
    else if (ex1 && ex2)
      twoempt(st, nd, rd, 1, 2);
  } else {
    if (ex0)
      oneempt(nd, rd, st, 1, 2, 0);
    else if (ex1)
      oneempt(st, rd, nd, 0, 2, 1);
    else if (ex2)
      oneempt(st, nd, rd, 0, 1, 2);
  }
}

ll calcans() {
  for (int i = 0; i < st.size(); i++) {
    if (st[i][0] == INT_MAX) continue;
    ans += st[i][3];
  }
  for (int i = 0; i < nd.size(); i++) {
    if (nd[i][0] == INT_MAX) continue;
    ans += nd[i][3];
  }
  for (int i = 0; i < rd.size(); i++) {
    if (rd[i][0] == INT_MAX) continue;
    ans += rd[i][3];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  a.resize(n, {0, 0, 0});
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
  divide();
  chsempt();
  cout << calcans();
}
