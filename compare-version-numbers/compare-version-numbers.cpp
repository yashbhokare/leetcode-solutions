class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(version1.size()>0 || version2.size()>0){
            int v1Index = version1.find_first_of('.');
            string v1S = v1Index==-1 ? version1 : version1.substr(0,v1Index);
            stringstream ss1(v1S);
            int v1 = 0;
            ss1>>v1;
            // cout<<v1<<" ";
            int v2Index = version2.find_first_of('.');
            string v2S = v2Index==-1 ? version2 : version2.substr(0,v2Index);
            stringstream ss2(v2S);
            int v2 = 0;
            ss2>>v2;
            // cout<<v2<<endl;
            if(v1<v2) return -1;
            else if(v1>v2) return 1;
            
            version1 = v1Index==-1 ? "0":version1.substr(v1Index+1);
            version2 = v2Index==-1 ? "0":version2.substr(v2Index+1);
            
            if(version1=="0" && version2=="0") break;
            // cout<<version1<<" "<<version2<<endl;
        }
        return 0;
    }
};