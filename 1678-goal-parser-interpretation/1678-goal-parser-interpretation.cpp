class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        string s="";
        for(int i=0;i<n;i++)
        {
            if(command[i]=='G')
                s=s+"G";
            else if(command[i]=='a')
            {
                if(command[i+1]=='l')
                    s=s+"al";
            }
            else if(command[i]=='(')
            {
                if(command[i+1]==')')
                    s=s+"o";
            }
                
        }
        return s;
    }
};