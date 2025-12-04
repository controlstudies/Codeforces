#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<int,int> alreadyCal; // position -> time
const int LIMIT = 1000000;
// use -2 as "visiting"
int timeToShore(const vector<int> &v, int i) {
    if (i < 0 || i >= (int)v.size()) return 0;
    if (v[i] == 2) return 0;

    auto it = alreadyCal.find(i);
    if (it != alreadyCal.end()) {
        if (it->second == -2) return -1; // found a cycle
        return it->second;               // cached final value
    }

    alreadyCal[i] = -2; // mark as visiting

    int res;
    if (v[i] != 0) {
        int child = timeToShore(v, i + v[i]);
        if (child == -1) res = -1;
        else {
            long long cand = 1LL + child;
            res = (cand > LIMIT) ? -1 : (int)cand;
        }
    } else {
        int leftChild = timeToShore(v, i - 1);
        int rightChild = timeToShore(v, i + 1);
        if (leftChild == -1 || rightChild == -1) res = -1;
        else {
            long long cand = 1LL + max(leftChild, rightChild);
            res = (cand > LIMIT) ? -1 : (int)cand;
        }
    }

    alreadyCal[i] = res; // overwrite visiting marker with final result
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string s;
        cin >> s;
        s = ' ' + s + ' ';
// spaces denote shore
        vector<int> v;
        v.reserve(s.size());
        for (char c : s) {
            if (c == '>') v.push_back(1);
            else if (c == '<') v.push_back(-1);
            else if (c == '*') v.push_back(0);
            else if (c == ' ') v.push_back(2); // shore
            else v.push_back(0);
        }

        alreadyCal.clear(); // clear memo for each testcase
        vector<long> time(s.size());
        for(int pos=0;pos<s.size();pos++)
        time[pos]= timeToShore(v, pos);
sort(time.begin(),time.end());
if(*min_element(time.begin(), time.end())) cout<<-1<<'\n';       
else cout<<*max_element(time.begin(), time.end())<< "\n";
    }}