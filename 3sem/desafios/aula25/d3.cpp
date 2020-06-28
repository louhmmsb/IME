#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;


const int MAXC = 1024;
int c1[MAXC], c2[MAXC];

int main () {
  memset(c1, 0, sizeof c1);
  memset(c2, 0, sizeof c2);

  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);

  
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    c1[t] += 1;
  }


  for (int i = 0, qt = 0; i < k; i++, qt = 0)
    if (!(i & 1)) {
      for (int j = 0; j < MAXC; j++) {
        if (c1[j] == 0) continue;
        c2[j^x] += c1[j]/2;
        c2[j]   += c1[j]/2;
        c1[j] & 1 ? (qt & 1 ? (c2[j] += 1) : (c2[j^x] += 1)) : (0);
        qt += c1[j];
        c1[j] = 0;
      }
    } else {
      for (int j = 0; j < MAXC; j++) {
        if (c2[j] == 0) continue;
        c1[j^x] += c2[j]/2;
        c1[j]   += c2[j]/2;
        c2[j] & 1 ? (qt & 1 ? (c1[j] += 1) : (c1[j^x] += 1)) : (0);
        qt += c2[j];
        c2[j] = 0;
      }
    };


  //c[!(i & 1)][j^x] = c[(i & 1)][j]/2;

  int maximo = 0, minimo;

    
  for (int i = MAXC-1; i >= 0; i--)
    if (c1[i] || c2[i]) {
      maximo = i;
      break;
    }
    
  for (int i = 0; i < MAXC; i++)
    if (c1[i] || c2[i]) {
      minimo = i;
      break;
    } 


  printf("%d %d\n", maximo, minimo);
  
  return 0;
}
