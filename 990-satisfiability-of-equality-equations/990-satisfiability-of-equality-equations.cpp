class Uf {
private:
    vector<int> root; 
    int size=26;
public:
    Uf(){
        root.resize(26);
        for(int i=0;i<26;i++){
            root[i]=i;
        }
    }
    
    int find(int x){
        if(root[x]==x) return x;
        return root[x]=find(root[x]);
    }
    
    void unionF(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            root[rootX] = rootY;
            size--;
        }
    }
    
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        Uf union_find;

        int index=0;
        vector<string> notEqual;
        for(auto equation:equations){
            if(equation[1]=='!'){
                if(union_find.find(equation[0]-'a')==union_find.find(equation[3]-'a')){
                    return false;
                }
                notEqual.push_back(equation);
                
            }else {
                union_find.unionF(equation[0]-'a',equation[3]-'a');
            }
        }
        for(auto eq:notEqual){
            if(union_find.find(eq[0]-'a')==union_find.find(eq[3]-'a')){
                    return false;
            }
        }
        return true;
    }
};