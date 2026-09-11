class Solution {
public:
queue<int> que1;
queue<int> que2;
int counter =0;
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for(int i =0 ;i< students.size();i++)
        {
            que1.push(students[i]);
            que2.push(sandwiches[i]);
        }
        while(!que1.empty() && counter <que1.size())
        {
           
             if(que1.front()==que2.front())
             {
                que1.pop();
                que2.pop();
                counter = 0;
             }
             else if(que1.front()!=que2.front())
             {
                int x = que1.front();
                que1.pop();
                que1.push(x);
                 counter++;
                
             }
        }
     
         return que1.size();
    

    }
};