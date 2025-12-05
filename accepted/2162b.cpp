#include <iostream>
#include <string>
using namespace std;

bool palindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

// returns length of longest non-decreasing substring starting at i
int largeNonDec(const string& s, int i) {
    if (i >= (int)s.size()) return 0;
    int k = i;
    for (int j = i; j < (int)s.size() - 1; j++) {
        if (s[j+1] < s[j]) break;
        k = j + 1;
    }
    return k - i + 1; // +1: convert last-index to length
}

string substring(const string& s, int &a, int &b) {
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        int length = largeNonDec(s, i);         // number of chars in non-decreasing run
        for (int j = 0; j < length; j++) {      // j = 0..length-1: remove substring [i..i+j]
            int removeLen = j + 1;
            // build candidate by removing [i .. i+removeLen-1]
            string candidate = s.substr(0, i) + s.substr(i + removeLen);
            int cn = (int)candidate.size();
            if (palindrome(candidate, 0, cn - 1))
              {a=i;
              b=i+removeLen-1; 
               return candidate;}
        }
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin >> s;
        int a=0,b=0;
        string c=substring(s,a,b);
        if(c.size()!=0) {cout<<c.size()<<endl;
            for(int i=a;i<=b;i++) cout<<i<<" ";}
else cout<<c.size()<<endl;
        cout<<endl;
    }
}
