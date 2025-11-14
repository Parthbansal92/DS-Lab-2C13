#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n;
    cin >> n;
    char s[100][100], t[100];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(t, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], t);
            }
        }
    }
    for (int i = 0; i < n; i++) cout << s[i] << " ";
}
