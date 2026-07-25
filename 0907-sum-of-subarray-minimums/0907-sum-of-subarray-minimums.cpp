class Solution {
public:
  vector<int> getNSL(vector<int> &arr,int &n)
  {
     vector<int> res(n);
     stack <int> st;
     for(int i =0;i< n;i++)
     {
        if(st.empty())
        {
            res[i]=-1;
        }
        else
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            res[i]=(!st.empty())? st.top():-1;
        }
        st.push(i);
     }
     return res;
  }
  vector<int> getNSR(vector<int> &arr,int &n)
  {
     vector<int> res(n);
     stack <int> st;
     for(int i =n-1;i>= 0;i--)
     {
        if(st.empty())
        {
            res[i]=n;
        }
        else
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            res[i]=(!st.empty())? st.top():n;
        }
        st.push(i);
     }
     return res;
  }
  int sumSubarrayMins(vector<int> &arr)
  {
    long long sum=0;
    int M=1e9+7;
    int n = arr.size();
    vector<int> NSL = getNSL(arr,n);
    vector<int> NSR = getNSR(arr,n);
    for(int i =0;i<n;i++)
    {
        long long ls=i-NSL[i];
        long long rs= NSR[i]-i;
        long long totalproduct=ls*rs;
        long long totalsum = arr[i]*totalproduct;
        sum = (sum +totalsum)%M;
    }
    return sum;
  }
};