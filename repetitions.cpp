#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    string s;
    cin >> s;
    int ans = 1, d = 0;
    char l = 'A';
    for(char c: s) {
        if(c == l){
            d++;
            ans = max(ans, d);
        }else {
            l = c;
            d = 1;
        }
    }
    cout << ans;
}
