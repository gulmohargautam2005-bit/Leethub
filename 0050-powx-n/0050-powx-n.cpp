class Solution {
public:
    double fun(double x,int n)
    {
        if(n<0)
        {
            return (1/(x*fun(x,(n+1)*-1)));
        }
        if(n==0)
        {
            return 1;
        }
        if(n%2==0)
        {
            
            return pow(x,n/2)*fun(x,n/2);
            
        }
        if(n%2!=0)
        {
            return x*pow(x,n/2)*fun(x,n/2);
        }

        return x*fun(x,n-1);
    }
    double myPow(double x, int n) {
        return fun(x,n);
    }
};