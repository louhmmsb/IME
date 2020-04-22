#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum=0, c;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
	scanf("%d", &c);
	sum+=c;
    }
    c = sum/5;
    if(sum%5) c++;
    printf("%d", c);
    return 0;
}
