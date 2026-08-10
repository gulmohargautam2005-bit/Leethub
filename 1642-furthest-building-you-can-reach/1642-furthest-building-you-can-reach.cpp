class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int count =0;
        int n = heights.size();
        priority_queue<int> pq;
        int i;
        for( i=0;i<n-1;i++)
        {
            int diff = heights[i+1]-heights[i];
            if(heights[i]>=heights[i+1])
            {
                count = count+1;
                continue;
            }
            if(diff<=bricks)
            {
                pq.push(diff);
                count=count+1;
                bricks=bricks-diff;
                 
            }
            else if(ladders>0)
            {
                if(!pq.empty())
                {
                    int max_prev_diff=pq.top();
                    if(max_prev_diff>diff)
                    {
                        pq.pop();
                        count=count+1;
                        bricks= bricks+max_prev_diff;
                        pq.push(diff);
                        bricks=bricks-diff;
                        
                    }
                }
                count=count+1;
                ladders--;

            }
            else
            {
                break;
            }
        }
        return i;
    }
};