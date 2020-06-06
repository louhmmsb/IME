#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d", &x);
#define pi(x) printf("%d\n", x);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int ll;
typedef unsigned long long int ull;

int N;

int pilha[507][107], face[505][105], cubos[507][107];

/*
  0 = frente
  1 = atrás
  2 = esq
  3 = dir
  4 = cima
  5 = baixo
*/
string faceToStr(int sas){
    switch(sas){
    case 0: return "front";
    case 1: return "back";
    case 2: return "left";
    case 3: return "right";
    case 4: return "top";
    case 5: return "bottom";
    }
}

void resp(int cubo, int cor){
    if(cubo == N) return;

    if(face[cubo][cor] == 6) resp(cubo+1, cor);
    else{
        int sas = face[cubo][cor];
        resp(cubo+1, cubos[cubo][sas]);

        cout<<(N-cubo)<<" "<<faceToStr(face[cubo][cor])<<"\n";
    }
}

int taska(int cubo, int cor){
    if(cubo == N) return 0;

    int &jooj = pilha[cubo][cor];

    if(jooj == -1){
        jooj = 0;
        int &jooj2 = face[cubo][cor];
        jooj2 = 6;

        for(int i=0; i<6; i++){
            if(cubos[cubo][i] == cor){
                int cabess = i^1;
                int quanto = taska(cubo+1, cubos[cubo][cabess])+1;

                if(quanto > jooj){
                    jooj = quanto;
                    jooj2 = cabess;
                }
            }
        }

        int quanto = taska(cubo+1, cor);
        if(quanto > jooj){
            jooj = quanto;
            jooj2 = 6;
        }
    }
    return jooj;
}

int main(){
    int T = 1;
    while(cin >> N, N){
        for(int i=N-1; i>=0; i--){
            for(int j = 0; j<6; j++){
                cin>>cubos[i][j];
            }
        }
        memset(pilha, -1, sizeof(pilha));
        int melhor = 1, melhorC = 1, melhorCor;

        for(int cubo = 0; cubo<N; cubo++){
            for(int face = 0; face<6; face++){
                int sas = taska(cubo, cubos[cubo][face]);
                if(sas > melhor){
                    melhor = sas;
                    melhorC = cubo;
                    melhorCor = cubos[cubo][face];
                }
            }
        }
        if(T > 1)
            cout<<"\n";
        cout<<"Case #"<<T++<<"\n";
        cout<<melhor<<"\n";
        resp(melhorC, melhorCor);
    }
}
