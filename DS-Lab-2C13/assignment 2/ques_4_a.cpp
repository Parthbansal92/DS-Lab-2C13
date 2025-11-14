#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char s1[100], s2[100];
    cin >> s1 >> s2;
    strcat(s1, s2);
    cout << s1;
}
