#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

const int MAX = 12;

int contaSol = 0;

bool da(int board[MAX][MAX], int size, int row, int col){
    if(board[row][col] == -1) return false;
    
    for(int i=0; i<col; i++){
        if(board[row][i] == 1) return false;
    }
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 1) return false;
    }
    for(int i=row, j=col; j>=0 && i<size; i++, j--){
        if(board[i][j] == 1) return false;
    }
    
    return true;
}

bool nQrec(int board[MAX][MAX], int size, int col){
    if(col >= size){
        contaSol++;
        return true;
    }
    bool res = false;
    for(int i=0; i<size; i++){
        if(da(board, size, i, col)){
            board[i][col] = 1;
            res = nQrec(board, size, col+1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

void nQ(int n, int m){

    int board[MAX][MAX];
    memset(board, 0, sizeof(board));
    contaSol = 0;
    
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        board[x][y] = -1;
    }

    nQrec(board, n, 0);
    cout<<contaSol<<endl;
}

int main(){
    int n, m;
    while(true){
        cin>>n>>m;
        if(n == 0 && m == 0) break;
        nQ(n, m);
    }
    return 0;
}
