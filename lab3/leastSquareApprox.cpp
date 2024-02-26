#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printMatrix(vector<vector<double>> &x){
    for(auto &i: x){
        for(auto &j: i)
            cout << fixed << setprecision(2) << j << " ";
        cout << "\n";
    }
}

vector<vector<double>> matrixMultiplication(vector<vector<double>> &x, vector<vector<double>> &y){
    int nx = x.size(), mx = x.front().size(), my = y.front().size();
    vector<vector<double>> res(nx, vector<double> (my));
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < my; j++){
            double s = 0;
            for(int ij = 0; ij < mx; ij++)
                s += (x[i][ij] * y[ij][j]);
            res[i][j] = s;
        }
    }
    return res;
}

vector<vector<double>> transpose(vector<vector<double>> &x){
    int n = x.size(), m = x.front().size();
    vector<vector<double>> res(m, vector<double> (n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            res[i][j] = x[j][i];
    return res;
}

vector<vector<double>> GaussJordanInverse(vector<vector<double>> &x){
    int n = x.size();
    vector<vector<double>> res(n, vector<double> (n)), u(n, vector<double> (2*n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            u[i][j] = x[i][j];
            u[i][j + n] = (i == j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            double d = u[j][i] / u[i][i];
            for(int v = 0; v < 2*n; v++)
                u[j][v] -= d * u[i][v];
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = n; j < 2*n; j++)
            res[i][j - n] = u[i][j] / u[i][i];
    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<double>> u(m, vector<double> (n + 1)), a(m, vector<double> (n + 1, 1.0)), b(m, vector<double> (1));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n + 1; j++)
            cin >> u[i][j];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            a[i][j + 1] = u[i][j];
    for(int i = 0; i < m; i++)
        b[i][0] = u[i][n];
    cout << "A:\n";
    printMatrix(a);
    cout << "\nb:\n";
    printMatrix(b);
    vector<vector<double>> a_t = transpose(a);
    vector<vector<double>> a_t_a = matrixMultiplication(a_t, a);
    cout << "\nA_T*A:\n";
    printMatrix(a_t_a);
    vector<vector<double>> a_t_a_i = GaussJordanInverse(a_t_a);
    cout << "\n(A_T*A)_-1:\n";
    printMatrix(a_t_a_i);
    vector<vector<double>> a_t_a_i_a_t = matrixMultiplication(a_t_a_i, a_t);
    cout << "\n(A_T*A)_-1*A_T:\n";
    printMatrix(a_t_a_i_a_t);
    vector<vector<double>> x = matrixMultiplication(a_t_a_i_a_t, b);
    cout << "\nx:\n";
    printMatrix(x);
}