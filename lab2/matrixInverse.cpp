#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
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

vector<vector<double>> transpose(vector<vector<double>> &u){
    const int N = u.size(), M = u.front().size();
    vector<vector<double>> v(M, vector<double>(N));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            v[j][i] = u[i][j];
    return v;
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

void solve2(){
    fin("input.txt");
    fout("output.txt");

    string s, cur;
    getline(cin, s);
    vector<vector<double>> a, a_;
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
    a_ = transpose(a);
    double detA = det(a);
    vector<vector<double>> adj(a_.size(), vector<double>(a_.front().size(), 0));
    for(int i = 0; i < a_.size(); i++){
        for(int j = 0; j < a_.front().size(); j++){
            vector<vector<double>> x;
            for(int ii = 0; ii < a_.size(); ii++){
                vector<double> tx;
                if(ii == i)
                    continue;
                for(int jj = 0; jj < a_.front().size(); jj++)
                    if(jj != j)
                        tx.push_back(a_[ii][jj]);
                x.push_back(tx);
            }
            double detX = det(x);
            adj[i][j] = ((i + j) % 2 == 0) ? detX / detA : -detX / detA;
        }
    }

    for(int i = 0; i < adj.size(); i++){
        for(int j = 0; j < adj.front().size(); j++)
            cout << fixed << setprecision(2) << adj[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    //solve1();
    solve2();
}