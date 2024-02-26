#include <iostream>
#include <vector>

using namespace std;

void solve1(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s, cur;
    vector<int> a;
    getline(cin, s);
    for(int i = 0; i <= s.length(); i++){
        if(i == s.length() || s[i] == ' '){
            a.push_back(stoi(cur));
            cur.clear();
        }
        else{
            cur += s[i];
        }
    }
    int ans = -1e9 - 7;
    const int N = a.size();
    for(int x = 1; x <= N; x++){
        int sum = 0;
        for(int i = 0; i < x; i++)
            sum += a[i];
        ans = max(ans, sum);
        for(int i = x; i < N; i++){
            sum = sum + a[i] - a[i - x];
            ans = max(ans, sum);
        }
    }
    cout << ans;
}


int main(){
    solve1();
}