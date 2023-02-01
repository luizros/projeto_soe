#include "escreve_no_arquivo.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;
//Este programa escreve a placa no arquivo txt
void escrever(char placa[7]){
    //cria a estrutura para pegar a data
    string meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    //escreve o valor da placa e o horário no arquivo
    fstream f;
    f.open("../base_de_dados/placas.txt", ios::app);
    f << "placa: " << placa << "," << " data: "<< tm.tm_mday << " de " << meses[tm.tm_mon] << " de " << tm.tm_year + 1900 <<endl;
    f.close();
}