// String Split Challenge
// You are given a string consisting of lowercase English alphabets. Your task is to determine
// if it's possible to split this string into three non-empty parts (substrings) where one of
// these parts is a substring of both remaining parts
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n=s.size();
    bool ok=false;
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            string a=s.substr(0,i);
            string b=s.substr(i,j-i);
            string c=s.substr(j);
            if((a.find(b)!=string::npos)||(c.find(b)!=string::npos)){
                ok=true;
            }
        }
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}
