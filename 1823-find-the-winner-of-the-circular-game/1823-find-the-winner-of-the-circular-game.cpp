class Solution {
public:
    int findTheWinner(int n, int k) {
        return josephus(n,k);
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()!=1){
            int x=k;
            while(x>1){
                int r=q.front();
                q.pop();
                q.push(r);
                x--;
            }
            q.pop();
        }
        return q.front();
    }
    
    int josephus(int n, int k)
    {
        if (n == 1)
            return 1;
        else
            /* The position returned by josephus(n - 1, k)
            is adjusted because the recursive call
            josephus(n - 1, k) considers the
            original position k % n + 1 as position 1 */
            return (josephus(n - 1, k) + k - 1) % n + 1;
    }
        
};