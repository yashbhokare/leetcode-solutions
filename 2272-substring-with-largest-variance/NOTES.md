```
int largestVariance(string s) {
int result = 0;
for(int j=0;j<s.size();j++){
vector<int> charsMax(26,0);
for(int i=j;i<s.size();i++){
charsMax[s[i]-'a']++;
int maxVal,minVal;
getMaxMin(charsMax,maxVal,minVal);
result = max(result,maxVal-minVal);
}
}
return result;
}
​
void getMaxMin(vector<int>& charsMax,int& maxVal,int& minVal){
minVal = INT_MAX;
maxVal = 0;
for(int i=0;i<26;i++){
if(charsMax[i]>0 && charsMax[i]<minVal){
minVal = charsMax[i];
}
maxVal = max(maxVal,charsMax[i]);
}
​
}
```