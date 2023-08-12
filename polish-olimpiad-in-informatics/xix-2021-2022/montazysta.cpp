#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
#define dbpii pair<pii, int>
#define sz(a) a.size()
#define pb push_back
using namespace std;
typedef long long ll;
int const maxN = 5e5 + 10;
int n;
dbpii a[maxN];

bool cmp(dbpii a, dbpii b) {
  if (a.st.nd == b.st.nd) return a.st.st < b.st.st;
  return a.st.nd < b.st.nd;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int t, d;
    scanf("%d", &t);
    scanf("%d", &d);
    a[i] = {{t, d}, i};
  }
  sort(a, a + n, cmp);
  int resspace = 0;
  priority_queue<dbpii> pq;  //{{lenght, due to}, original index}
  for (int i = 0; i < n; i++) {
    int curlen = a[i].st.st, freespace = a[i].st.nd - resspace;
    if (freespace >= curlen) {
      pq.push(a[i]);
      resspace += curlen;
    } else {
      if (!pq.empty()) {
        int longest = pq.top().st.st;
        if (longest > curlen) {
          pq.pop();
          pq.push(a[i]);
          resspace -= longest;
          resspace += curlen;
        }
      }
    }
  }
  vector<dbpii> ans;
  while (!pq.empty()) {
    ans.push_back(pq.top());
    pq.pop();
  }
  sort(ans.begin(), ans.end(), cmp);
  int prevend = 1;
  printf("%d \n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d \n", ans[i].nd + 1, prevend);
    prevend += (ans[i].st.st);
  }
}
