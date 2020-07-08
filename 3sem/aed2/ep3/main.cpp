#include "./bibs/nfa.hpp"
#include "./bibs/color.hpp"

using namespace std;

int main(int argc, char** argv){
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    bool noColor = false;
    if(argc <= 2){
        cout<<"Argumentos..."<<endl;
        return 0;
    }

    if(argc == 4 && argv[3][0] == '-' && argv[3][1] == 'n' && argv[3][2] == 'c') noColor = true;
    string regex(argv[1]), txt(argv[2]);
    NFA nfa(regex);

    if(nfa.match(txt)){
        if(noColor) cout<<txt<<endl;
        else cout<<red<<txt<<def<<endl;
    }
    else cout<<endl;    
    return 0;
}
