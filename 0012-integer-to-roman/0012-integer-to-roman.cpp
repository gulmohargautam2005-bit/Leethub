class Solution {
public:
    int check( int val[],int num,int n,int &idx)
    {
        int low =0;
        int high =n-1;
         while(high>=low)
        {
            int mid = (high+low)/2;
            if(val[mid]<=num)
            {
                idx=mid;
                low=mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return idx;

    }
    string intToRoman(int num) {
        int val[] ={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string sym[] ={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"} ;
        int low =0;
        int high =sizeof(val)/sizeof(val[0]);
        int idx=0;
        string result ="";
        while(num>0)
        {
           int a = check(val,num,high,idx);
           int freq = num/val[a];
           for(int i =0;i<freq;i++)
           {
             result = result +sym[a];
           }
           num = num%val[a];
        }
        return result;
    }
};