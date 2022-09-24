class Solution {
public:
    double calculatePow(double x, int n){
        double temp;
        if(n==0) return 1;
        temp = calculatePow(x, n/2);
        if(n%2==0) return temp*temp;   
        else return x*temp*temp;      
    }
    
    double myPow(double x, int n) {
        double ans = 1;
        if(n>=0) ans = calculatePow(x,n);
        else ans = 1/calculatePow(x,abs(n));
        return ans;
    }
};