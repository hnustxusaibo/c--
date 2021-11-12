#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int N = 1e5+5;

class Matrix {
public:
    int high,width;
    vector<vector<int> > data;
    static Matrix IdentityMatrix(int m){
        Matrix* ans = new Matrix(m,m);
        for(int i=0;i<m;i++)ans->data[i][i]=1;
        return *ans;
    }

    Matrix(){}

    Matrix(const Matrix &x): high(x.high),width(x.width){
        this->data = vector<vector<int> >(high,vector<int>(width,0));
        for(int i=0;i<high;i++){
            for(int j=0;j<width;j++){
                data[i][j]=x.data[i][j];
            }
        }
    }

    Matrix(int m,int n): high(m),width(n){
        this->data = vector<vector<int> >(high,vector<int>(width,0));
    }

    Matrix(int m,int n,int** d): high(m),width(n){
        this->data = vector<vector<int> >(high,vector<int>(width,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                data[i][j]=*((int *)d+n*i+j);
            }
        }
    }

    Matrix(int m,int n,vector<vector<int> > d): high(m),width(n),data(d){}
        
    
    Matrix operator*(const Matrix& b){
        // a.width = b.high
        assert(this->width == b.high);
        const Matrix *y=(&b);
        Matrix* ans = new Matrix(this->high,b.width);
        for(int i=0;i<(this->high);i++){
            for(int j=0;j<(y->width);j++){
                int sum = 0;
                for(int k=0;k<(this->width);k++){
                    sum = (sum+1ll*(this->data[i][k])*(y->data[k][j]))%mod;
                }
                ans->data[i][j]=sum;
            }
        }
        return *ans;
    }

    Matrix pow(int power){
        // a.width = a.high
        assert(this->width == this->high);
        Matrix ans = Matrix::IdentityMatrix(this->high);
        Matrix base = Matrix(*this);
        while(power){
            if(power&1) ans=ans*base;
            power>>=1;
            base = base*base;
        }
        return ans;
    }
};

int fib(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    int F[2][1]={1,0};
    int init[2][2] = {{1,1},{1,0}};
    Matrix f(2,1,(int**)F);
    Matrix C(2,2,(int**)init);
    Matrix ans = (C.pow(n-1))*f;
    return ans.data[0][0];
}


int main()
{
    cout << fib(999999) << endl;
    return 0;
}