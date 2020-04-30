#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

vector<ull> v;
vector<ull> p;

ull maxArea = 0;

int main(){
    ull n;

    while(1){
        scanf("%llu", &n);
        p.clear();
        v.clear();
        maxArea = 0;
        if(!n) break;

        ull j = 0;
        for(ull i=0; i<n; i++){
            ull c;
            scanf("%llu", &c);
            v.push_back(c);

            if(!p.empty() && v[p.back()] > c){
                while(!p.empty() && v[p.back()] > c){
                    j =p.back();
                    maxArea = max(maxArea, (i-j)*v[j]);
                    v[j] = c;
                    p.pop_back();
                }
                if(p.empty() || v[p.back()] < c){
                    p.push_back(j);
                }
            }
            
            else if(p.empty() || v[p.back()] < c){
                p.push_back(i);
            }
        }

        while(!p.empty() && v[p.back()] > 0){
            maxArea = max(maxArea, (n-p.back())*v[p.back()]);
            p.pop_back();
        }
        printf("%llu\n", maxArea);
    }
    
    return 0;
    
}
