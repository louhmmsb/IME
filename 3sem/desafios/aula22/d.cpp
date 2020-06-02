#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 500007;

char seq[MAX];
char op[MAX];
int indices[MAX];
int id[MAX];
int P[MAX];

int main ()
{

    int n, m, p;
    char *q;
    
    scanf("%d%d%d\n", &n, &m, &p);
    q = fgets(seq, MAX, stdin);

    if (q == nullptr) return 0;

    int i;
    int t = 0;

    for (i = 0; i <= n; i++)
        id[i] = i;
    int comp = 0;
    int ini = -1;
    
    for (i = 0; i < n; i++) {
        if (seq[i] == '(') {
            P[t++] = i;
            id[i] = comp;
            if (ini == -1) ini= i;
        }
        else if (seq[i] == ')') {
            indices[i] = P[--t];
            indices[P[t]] = i;
            id[i] = comp;
            if (P[t] == ini) {
                comp += 1;
                ini = -1;                
            }
        }
    }
    //for(int a = 0; a<n; a++) cout<<indices[a]<<" ";cout<<endl;
    q = fgets(op, MAX, stdin);    
    p--;
    int sas = n;
    for (i = 0; i < m; i++) {
        
        if (op[i] == 'R') {
            
            while (id[++p] == -1) {
                p = indices[p];
            }                        
        } else if (op[i] == 'L') {
            
            while (id[indices[--p]] == -1) {
                p = indices[p];
            }
            
        }  else if (op[i] == 'D') {

            int aux;
            
            if (seq[p] == '(') {
                aux = p;
            } else {
                aux = indices[p];
            }

            id[aux] = -1;
            
            if(indices[aux] != sas-1) {
                if(id[indices[aux]+1] == -1){
                    indices[aux] = indices[indices[aux]+1];
                    indices[indices[aux]] = aux;
                }       
            }
            if(aux != 0) {
                if(id[indices[aux-1]] == -1){
                    indices[indices[aux]] = indices[aux-1];
                    indices[indices[aux-1]] = indices[aux];
                }
            }
            if(indices[aux] != sas-1){
                aux = indices[aux]+1;
            }
            else{
                aux = indices[indices[aux]]-1;
            }
            p = aux;                                
        } 
    }

    i = 0;
    //for(int a = 0; a<n; a++) cout<<indices[a]<<" ";cout<<endl;
    while (i <= n) {
        if (id[i] == -1) {
            i = indices[i]+1;
            
        } else {
            putchar(seq[i]);
            i++;
        }
    }
        
    return 0;
}
