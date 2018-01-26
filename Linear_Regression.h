#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H
#include <bits/stdc++.h>

using namespace std;

class Linear_Regression
{
    private:
        double *Y_labels, *thetas;
        double **X_labels;
        const double alpha = 0.1; // used in cost function J(theta)
        const int max_num_iterations = 1e4 ;
        int m,n; // number of labels
    public:
        Linear_Regression( double **X, double *Y, int M, int N );
        ~Linear_Regression();
        double Hypothesis(int indOf_row, double **X);
        void GradiantDescent();
        vector<double>predict(double **input_X, int row);
};

#endif // LINEAR_REGRESSION_H
