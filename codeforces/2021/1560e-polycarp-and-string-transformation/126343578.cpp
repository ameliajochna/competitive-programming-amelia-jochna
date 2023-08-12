#include <bits/stdc++.h>
#define nd second
#define st first
#define pii pair<int, int>
using namespace std;
typedef long long ll;

bool check(string pref, string &s, vector<char> &seq) {
  // cout<<"CHECK: "<<pref<<" "<<s<<'\n';
  string cur = pref;
  for (int i = 0; i < seq.size(); i++) {
    // cout<<"CUR: "<<cur<<" PREF: "<<pref<<" ERASE: "<<seq[i]<<'\n';
    string nxt;
    for (int j = 0; j < pref.size(); j++) {
      if (seq[i] != pref[j]) nxt.push_back(pref[j]);
    }
    pref = nxt;
    cur = cur + pref;
  }
  // cout<<cur<<" "<<s<<'\n';
  return (s == cur);
}

void solution() {
  string s;
  cin >> s;
  vector<bool> vis(27);
  vector<char> seq;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (!vis[s[i] - 'a']) seq.push_back(s[i]);
    vis[s[i] - 'a'] = true;
  }
  reverse(seq.begin(), seq.end());
  int diff = seq.size();
  vector<int> freq(27);
  for (int i = 0; i < seq.size(); i++) freq[seq[i] - 'a'] = i + 1;

  /*for(auto x:seq)
      cout<<x<<" ";
     for(int i=0; i<26; i++)
      cout<<char(i+'a')<<" "<<freq[i]<<'\n';*/

  vector<int> curcnt(26), gencnt(26);
  for (int i = 0; i < s.size(); i++) gencnt[s[i] - 'a']++;

  for (int i = 0; i < s.size(); i++) {
    curcnt[s[i] - 'a']++;
    /*cout<<"CURENT: ";
       for(int j=0; j<=i; j++)
        cout<<s[j];
       cout<<'\n';*/
    bool ok = true;
    for (int j = 0; j < 26; j++) {
      // cout<<char('a'+j)<<" "<<gencnt[j]<<" "<<curcnt[j]<<" "<<freq[j]<<'\n';
      if (gencnt[j] != curcnt[j] * freq[j]) {
        ok = false;
        break;
      }
    }
    // if(ok) cout<<"GITUWA\n";
    if (ok && check(s.substr(0, i + 1), s, seq)) {
      for (int j = 0; j <= i; j++) {
        cout << s[j];
      }
      cout << ' ';
      for (int j = 0; j < seq.size(); j++) cout << seq[j];
      cout << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int t = 1;
  cin >> t;
  while (t--) solution();
}
