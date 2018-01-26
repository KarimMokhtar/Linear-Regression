#include <bits/stdc++.h>
#include "Linear_Regression.h"
using namespace std;


int main()
{
    // for test
    int F , N , T ;
    cin >> F >> N;
    // to take data from file and put them
    fstream f;
    f.open("f.txt",ios::in|ios::out);
    double *Y = new double[N];
    double **X = new double*[N];
    for( int i = 0; i < N; ++i){
        X[i] = new double[F];
    }
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < F+1; ++j){
            if(j == F)cin >> Y[i];
            else cin >> X[i][j];
        }
    }
    cin >> T;
    f << N << F << T;
    double **arr = new double*[T];
    for( int i = 0; i < T; ++i){
        arr[i] = new double[F];
    }
    for(int i = 0 ; i < T ; ++i){
        for(int j = 0 ; j < F ; ++j)cin >> arr[i][j];
    }
    Linear_Regression obj(X, Y, N , F);
    obj.GradiantDescent();
    vector<double>v = obj.predict(arr,T);
    for(int i = 0 ; i < v.size() ; ++i){
        cout << fixed << setprecision(2) <<v[i] << endl;
    }
    return 0;
}
