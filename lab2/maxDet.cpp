#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define fin(str) freopen(str, "r", stdin)
#define fout(str) freopen(str, "w", stdout)

double det(vector<vector<double>> u){
    if(u.size() == 1)
        return u[0][0];
    if(u.size() == 2)
        return u[0][0] * u[1][1] - u[0][1] * u[1][0];
    else{
        double res = 0;
        for(int x = 0; x < u.size(); x++){
            vector<vector<double>> v;
            for(int i = 1; i < u.size(); i++){
                vector<double> t;
                for(int j = 0; j < u.size(); j++)
                    if(j != x)
                        t.push_back(u[i][j]);
                v.push_back(t);
            }
            res += pow(-1, x) * u[0][x] * det(v);
        }
        return res;
    }

}

void solve1(){
    fin("input.txt");
    fout("output.txt");

    string s, cur;
    getline(cin, s);
    vector<vector<double>> a;
    vector<double> t;

    for(int i = 1; i < s.length() - 1; i++){
        if(s[i] == '{' || (s[i] == ',' && s[i - 1] == '}'))
            continue;
        if(s[i] == '}'){
            t.push_back(stod(cur));
            a.push_back(t);
            t.clear();
            cur.clear();
        }
        else if(s[i] == ','){
            t.push_back(stod(cur));
            cur.clear();
        }
        else
            cur += s[i];
    }
    cout << det(a);
}

int main(){
    solve1();
}