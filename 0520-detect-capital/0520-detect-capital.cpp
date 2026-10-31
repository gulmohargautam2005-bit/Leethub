class Solution {
public:
    bool detectCapitalUse(string word) {
        int count =1;
        int count2=1;
        int count3=1;
        if(word.size()==1)
            return true;


            if((int)word[0]>=65 && (int)word[0]<=90)
            {
                for(int j=1;j<word.size();j++)
                {
                    if(word[j]>=65 && word[j]<=90)
                     {
                        count++;
                     }
                }
                if(count==word.size())
                    return true;
                else
                {
                    for(int k =1;k<word.size();k++)
                    {
                        if(word[k]>=97 && word[k]<=122)
                        {
                            count2++;
                        }
                    }
                    if(count2==word.size())
                        return true;
                }

            }
            else if((int)word[0]>=97 && (int)word[0]<=122)
            {
                for(int k =1;k<word.size();k++)
                {
                    if(word[k]>=97 && word[k]<=122)
                        count3++;
                }
                if(count3==word.size())
                    return true;
            }
               
       return false;
    }
};