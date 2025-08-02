#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x)
{
    return log(3 * x) - 3;
}

double falsePosition(double a, double b, double tol = 1e-4, int maxIter = 100)
    {
    if (f(a) * f(b) >= 0)
    {
        cout<<"Invalid initial guesses."<<endl;
        return -1;
    }

    double c = a;
    double c_old = a; // Initialize c_old to a valid value
    int iter = 0;

    while (iter < maxIter)
     {
        c = b - (f(b) * (a - b)) / (f(a) - f(b));

        if (iter > 0 && fabs(c - c_old) < tol)
        {
            cout<< iter << " iterations." << endl;
            return c;
        }

      
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        c_old = c;
        iter++;
    }
    // If maximum iterations reached without convergence, return the last computed value
    cout << "Maximum iterations reached." << endl;
    return c;
}

int main() {
    double root = falsePosition(1,7);
    cout << "Root = " << fixed << root << endl;
    return 0;
}
