#include "nfa.hpp"
#include "color.hpp"

using namespace std;

int main(int argc, char** argv){
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    if(argc <= 1){
        cout<<"Argumentos..."<<endl;
        return 0;
    }
    string regex(argv[1]), txt;
    NFA nfa(regex);

    while(cin>>txt){
        if(nfa.match(txt)) cout<<red<<txt<<def<<endl;
    }
    
    return 0;
}
