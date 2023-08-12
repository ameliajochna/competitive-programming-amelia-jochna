#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
  int n, l, r, s;
  cin >> n >> l >> r >> s;
  int len = r - l + 1;
  int sum = 0, minwin = 1, maxwin = len, minpos = 0, maxpos = 0;
  for (int i = 1; i <= len; i++) sum += i;
  minpos = sum;
  maxpos = sum - 1 + n;
  int lastpt = len + 1;
  int found = -1, fsum = -1;
  for (int i = 1; i <= n - len + 1; i++) {
    // cout<<i<<" "<<sum<<" "<<minpos<<" "<<maxpos<<'\n';
    if (minpos <= s && s <= maxpos) {
      found = i;
      fsum = sum;
      break;
    }
    sum -= i;
    sum += lastpt++;
    minpos = sum - (lastpt - 1) + 1;
    if (i == n - len)
      maxpos = sum;
    else
      maxpos = sum - (i + 1) + n;
  }
  if (found == -1) {
    cout << "-1\n";
    return;
  }
  int shift = found, start = found, end = found + len - 1, erased, diff;
  // cout<<start<<" "<<end<<'\n';
  vector<int> subseq;
  vector<bool> used(n + 1);
  for (int i = start; i <= end; i++) subseq.push_back(i), used[i] = true;
  for (int i = 0; i < len; i++) {
    erased = i + shift;
    int cursum = sum - erased;
    diff = s - cursum;
    if (diff < start || diff > end) {
      subseq[i] = diff;
      used[erased] = false;
      used[diff] = true;
      break;
    }
  }
  /*cout<<"Subseq:\n";
     for(auto x:subseq){
      cout<<x<<" ";
     }
     cout<<'\n';
     cout<<"Used:\n";
     for(int i=1; i<=n; i++){
      cout<<i<<": "<<used[i]<<"\n";
     }
     cout<<erased<<" "<<diff<<'\n';
     cout<<'\n';*/
  int npt = 1, sspt = 0;
  for (int i = 1; i <= n; i++) {
    // cout<<i<<": ";
    if (l <= i && i <= r) {
      cout << subseq[sspt] << " ";
      sspt++;
    } else {
      while (used[npt]) npt++;
      cout << npt << " ";
      npt++;
    }
    // cout<<'\n';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
