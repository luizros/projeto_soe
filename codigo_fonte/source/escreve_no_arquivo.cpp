#include "escreve_no_arquivo.h"
#include <iostream>
#include <fstream>

using namespace std;
//Este programa escreve a placa no arquivo txt
void escrever(char placa[7]){
    fstream f;
    f.open("../base_de_dados/placas.txt", ios::app);
    f << placa << endl;
    f.close();
}