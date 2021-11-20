class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int s:stones){
            maxHeap.push(s);
        }
        while(maxHeap.size()>1){
            int stone1 =maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if(stone1 != stone2){
                maxHeap.push(stone1-stone2);
            }
            // cout<<maxHeap.size()<<" "<<stone2;
        }
        return maxHeap.size() == 0 ? 0 : maxHeap.top();
    }
};