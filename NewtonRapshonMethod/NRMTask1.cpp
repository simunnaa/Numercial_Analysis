#include<bits/stdc++.h>
using namespace std;

double f(double x)
 {
    return pow(x, 5) - 3 * x + 5;
}

double f_1(double x)
 {
    return 5 * pow(x, 4) - 3;
}

void newtonRaphson(double x0, double tol = 1e-3, int maxIter = 100)
 {
    double x1;
    int iter = 0;
    while (iter < maxIter)
     {
        double fx = f(x0);
        double fpx = f_1(x0);

        if (fpx == 0)
         {
            cout << "Derivative is zero. Method fails." << endl;
            return;
        }
        x1 = x0 - fx / fpx;
        if (fabs(x1 - x0) < tol)
        {
            cout << "Root found at x = " << fixed << x1 <<endl;
             cout<<"Total : " << iter + 1 << " iterations." << endl;
            return;
        }

        x0 = x1;
        iter++;
    }
}

int main()
 {
    double initial_guess;
    cout << "Enter initial guess: ";
    cin >> initial_guess;

    newtonRaphson(initial_guess);
    return 0;
}
