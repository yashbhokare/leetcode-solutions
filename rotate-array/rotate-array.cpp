class Solution {
public:
    void swap(vector<int>& nums, int posA, int posB){
        int temp = nums[posA];
        nums[posA]= nums[posB];
        nums[posB] = temp;
    }
    
    void rotate(vector<int>& nums, int k) {
        
            k = k % nums.size();

            int count = 0;
            for(int start=0; count <nums.size(); start++){
                int currrentPosition = start;
                int prevValue = nums[currrentPosition];
                do{
                    int nextPosition = (currrentPosition + k) % nums.size();
                    int temp = nums[nextPosition];
                    nums[nextPosition] = prevValue;
                    prevValue = temp;
                    currrentPosition = nextPosition;
                    count++;
                }while(currrentPosition!=start);
            }        
    }
    
    void display(vector<int>& nums){
       for(int i=0; i< nums.size(); i++){
           cout<<" "<<nums[i];
       }
        cout<<endl;
    }

    

};