#ifndef AVIAO_H
#define AVIAO_H

#include<cstdlib>
#include<string>

using namespace std;

const int NAERO = 129, NCOMP=5;
const string AEROPORTOS[NAERO] = {
    "AKC",
    "ALB",
    "ABQ",
    "ANC",
    "ATW",
    "ATL",
    "ACY",
    "TBA",
    "AUS",
    "BWI",
    "BGR",
    "TBA",
    "BHM",
    "BOI",
    "BOS",
    "BUF",
    "CLT",
    "CHS",
    "TBA",
    "MDW",
    "ORD",
    "CVG",
    "CLE",
    "CMH",
    "LCK",
    "TBA",
    "DFW",
    "DAY",
    "DEN",
    "DSM",
    "DTW",
    "FAI",
    "FLL",
    "RSW",
    "FAT",
    "BDL",
    "GRB",
    "GSO",
    "ITO",
    "TBA",
    "HNL",
    "IAH",
    "HOU",
    "HSV",
    "TBA",
    "IND",
    "JAX",
    "JNU",
    "TBA",
    "MCI",
    "KTN",
    "TBA",
    "EYW",
    "KOA",
    "TBA",
    "TYS",
    "LAL",
    "LAN",
    "LAS",
    "LIT",
    "LAX",
    "SDF",
    "MLB",
    "TBA",
    "MEM",
    "MIA",
    "MAF",
    "TBA",
    "MKE",
    "MSP",
    "MYR",
    "BNA",
    "MSY",
    "JFK",
    "LGA",
    "EWR",
    "SWF",
    "ORF",
    "OAK",
    "OKC",
    "OMA",
    "ONT",
    "SNA",
    "MCO",
    "SFB",
    "PSP",
    "ECP",
    "PNS",
    "PHL",
    "PHX",
    "AZA",
    "PIT",
    "PWM",
    "PDX",
    "PVD",
    "RDU",
    "RNO",
    "RIC",
    "RST",
    "ROC",
    "RFD",
    "TBA",
    "SMF",
    "SLC",
    "SAT",
    "SBD",
    "SAN",
    "SFO",
    "SJC",
    "SRQ",
    "SAV",
    "LKE",
    "TBA",
    "BFI",
    "TBA",
    "SEA",
    "PAE",
    "GEG",
    "STL",
    "PIE",
    "SYR",
    "TLH",
    "TBA",
    "TPA",
    "DCA",
    "IAD",
    "PBI",
    "AVP",
    "ILM"
};
const string COMPANHIAS[NCOMP] = {
    "AA",
    "AB",
    "AC",
    "AD",
    "AE"
};


class Aviao{
    
  private:
    
    string Aero;
    int Emerg;
    int Comb;
    bool Dec;
    int Tempo;
    string Tag;
    int Espera;
    int Fila;
    
  public:
    
    string tag();
    int emerg();
    void setEmerg(int level);
    string aero();
    int comb();
    int tempo();
    int espera();
    void setEspera(int novaEspera);
    void atualiza();
    int fila();
    void setFila(int nFila);
    friend ostream & operator<<(ostream &out, Aviao aviao);
    Aviao(int C, int V);
    Aviao();
//    ~Aviao();
    
};



#endif
