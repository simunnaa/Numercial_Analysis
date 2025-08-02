#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double a[n][n+1];
    double x[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
     {
         for (int k = i + 1; k < n; k++) 
         {
            double r = a[k][i] / a[i][i];
            for (int j = i; j <= n; j++)
            {
                a[k][j] -= r * a[i][j];
            }
         }
    }
     for (int i = n - 1; i >= 0; i--) 
    {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
