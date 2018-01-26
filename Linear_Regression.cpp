#include "Linear_Regression.h"

Linear_Regression::Linear_Regression(double **X, double *Y, int M , int N){
    m = M;
    n = N+1;

    Y_labels = new double[this->m];
    thetas = new double[this->n];
    X_labels = new double*[this->m];

    for( int i = 0; i < this->m; ++i){
        X_labels[i] = new double[this->n];
    }

    for(int i = 0 ; i < m ; ++i)Y_labels[i] = Y[i];

    for( int i = 0; i < this->m; ++i) // copy the values to X_label
        for( int j = 0; j < this->n-1; ++j){

            if( j == 0 )X_labels[i][j]=1, X_labels[ i ][ j+1 ] = X[ i ][ j ]; // to makee first col = 1s
            else X_labels[ i ][ j+1 ] = X[ i ][ j ];
        }

    for( int i = 0; i < n; ++i) // this line for initialize thetas
        this->thetas[i]=0;

}
Linear_Regression::~Linear_Regression(){
    delete [] Y_labels;
    delete [] thetas;

    for( int i = 0; i < this->n; ++i){
        delete [] X_labels[i];
    }
    delete [] X_labels;
}
double Linear_Regression::Hypothesis(int indOf_row, double **X){
    double result = 0;
    for( int i = 0; i < n; ++i)
        result += X[indOf_row][i]* thetas[i];

    return result;
}
void Linear_Regression::GradiantDescent(){
    double *temp = new double[n];
    int num_iter=max_num_iterations;
    while (num_iter--){
        for(int j = 0; j < this->n; ++j){

            double sum = 0;
            for(int i = 0; i < this->m; ++i)
                sum += ( Hypothesis(i, X_labels) - Y_labels[i] ) * X_labels[i][j];

            temp[j] = thetas[j] - alpha*(1.0/(this->m))*sum;
        }
        for(int i = 0; i < this->n; ++i)
            thetas[i] = temp[i];
    }
    delete[] temp;
}
vector<double> Linear_Regression::predict(double **input_X, int row ){
    vector<double>result;
    for(int i = 0 ; i < row; ++i){
            double sum = 0;
            for(int j = 0 ; j < n ; ++j)sum += input_X[i][j]*thetas[j];
        result.push_back( Hypothesis(i, input_X) );
    }
    return result;
}
