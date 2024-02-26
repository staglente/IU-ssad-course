#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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

void solve2(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s, cur;
    vector<string> words;
    set<int> res;
    cin >> s;
    while(cin >> cur)
        words.push_back(cur);
    do{
        string t;
        for(auto &i: words)
            t += i;
        for(int i = 0; i + t.length() <= s.length(); i++)
            if(s.substr(i, t.length()) == t)
                res.insert(i);
    } while(next_permutation(words.begin(), words.end()));
    string t;
    for(auto &i: words)
        t += i;
    for(int i = 0; i + t.length() <= s.length(); i++)
        if(s.substr(i, t.length()) == t)
            res.insert(i);
    for(auto &i: res)
        cout << i << " ";
}

int main(){
    //solve1();
    solve2();
}