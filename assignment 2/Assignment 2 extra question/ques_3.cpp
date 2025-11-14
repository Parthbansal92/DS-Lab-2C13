// String Anagrams
// Given two strings str1 and str2, determine if they form an anagram pair.
// Note: Two strings are considered anagrams if one string can be rearranged to form the other
// string.
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a,b;
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a==b) cout << "YES";
    else cout << "NO";

    return 0;
}
