class Solution {
public:
    double solve(double x, int n){
        if(n==0) return 1;
        double temp = solve(x, n/2);
        if(n%2 == 0) return temp*temp;
        return x*temp*temp;
    }

    double myPow(double x, int n) {
        if(n>=0) return solve(x,n);
        return 1/solve(x,n);
    }
};