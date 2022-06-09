class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res=0;
        for(int index=0;index<rating.size();index++){
            // Pointers for rating[i] < rating[j] < rating[k]
            int leftSmaller=0,rightGreater=0;
            
            // Pointers for rating[i] > rating[j] > rating[k]
            int leftGreater =0, rightSmaller=0;
            
            // Loop for left side of given element
            for(int leftSide=0;leftSide<index;leftSide++){
                if(rating[leftSide]<rating[index]){
                    leftSmaller++;
                }else if(rating[leftSide]>rating[index]){
                    leftGreater++;
                }
            }
            
            // Loop for right side of given element
            for(int rightSide=index+1;rightSide<rating.size();rightSide++){
                if(rating[rightSide]>rating[index]){
                    rightGreater++;
                }else if(rating[rightSide]<rating[index]){
                    rightSmaller++;
                }
            }
            int total = leftSmaller*rightGreater + leftGreater*rightSmaller;
            res = res + total;
        }
        return res;
    }
};