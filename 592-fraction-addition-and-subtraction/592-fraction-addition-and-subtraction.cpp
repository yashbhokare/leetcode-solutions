// class Solution {
// public:
//     string fractionAddition(string expression) {
//         stringstream ss(expression);
//         char op;
//         int a,b,c,d;
//         int num,den;
//         ss>>a;ss>>op;ss>>b; //extracting the 1st 2 numbers
//         while(ss>>c) //til we have the number
//         {
//             ss>>op; // op is the operator. which is '/' in our case
//             ss>>d;
//             num= a*d + b*c;
//             den= b*d;
//             a= num/__gcd(abs(num),abs(den));
//             b= den/__gcd(abs(num),abs(den));
//         }
//         c=__gcd(abs(a),abs(b));
//         a=a/c;
//         b=b/c;
//         return to_string(a)+'/'+to_string(b);
//     }
// };

class Solution {
public:
    int gcd(int a, int b){
        if (b == 0)
            return a;
        return gcd(b, a % b); 

    }
    string fractionAddition(string exp) {
        vector<int>num,den;
        int out=1;
        int n=exp.length();
        for(int i=0;i<n;i++){
            if(exp[i]=='-'){
                out=0;
                i++;
            }else if(exp[i]=='+'){
                out=1;
                i++;
            }
            string a="";
            while(i<n && exp[i]!='/'){
                a+=exp[i];
                i++;
            }
            // cout << a << "/";
            if(out==0){
                num.push_back(-stoi(a));
            }else{
                num.push_back(stoi(a));
            }
            if(exp[i]=='/'){
                i++;
            }
            a="";
            while(i<n && exp[i]!='-' && exp[i]!='+'){
                a+=exp[i];
                i++;
            }
            // cout << a << "\n";
            den.push_back(stoi(a));
            i--;
        }
        int proden=1;
        for(int i=0;i<den.size();i++){
            proden*=den[i];
        }
        int sum=0;
        for(int i=0;i<den.size();i++){
            int a=proden/den[i];
            sum+=(num[i]*a);
        }
        if(abs(sum)%proden==0){
            return to_string(sum/proden)+"/1";
        }
        int a=gcd(sum,proden);
        if(proden<0 || sum<0){
            return "-"+to_string(abs(sum/a))+"/"+to_string(abs(proden/a));
        }
        return to_string(sum/a)+"/"+to_string(proden/a);
    }
};