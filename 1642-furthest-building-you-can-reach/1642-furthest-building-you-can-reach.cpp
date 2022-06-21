class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int totalCount = 0;
        priority_queue<int> maxHeap;
        for(int i=0;i<heights.size()-1;i++){
            if(heights[i]>=heights[i+1]){
                continue;
            }else {
                int diff = heights[i+1]-heights[i];
                totalCount+=diff;
                
                if(ladders==0 && totalCount>bricks) return i;
                if(ladders==0 && totalCount<=bricks) continue;
                
                maxHeap.push(diff);
                if(totalCount>bricks){
                    totalCount-=maxHeap.top();
                    maxHeap.pop();
                    ladders--;
                }
            }
        }
        return heights.size()-1;
    }
};