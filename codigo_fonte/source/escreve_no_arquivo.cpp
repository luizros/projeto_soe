#include "escreve_no_arquivo.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;
//Este programa escreve a placa no arquivo entrada_dos_carros.txt e saida_dos_carros.txt
void escrever(char placa[7], int flag ){
    //cria a estrutura para pegar a data
    string meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    //escreve o valor da placa e o horário no arquivo
    if (flag==1){
    // escreve que o carro entrou
        fstream f;
        f.open("../base_de_dados/entrada_dos_carros.txt", ios::app);
        f << "placa: " << placa << "," << " data: "<< tm.tm_mday << " de " << meses[tm.tm_mon] << " de " << tm.tm_year + 1900 << ", horário: "<< tm.tm_hour << "h" << tm.tm_min << "m"<< tm.tm_sec << "s" <<endl;
        f.close();
    }else{
        //escreve que o carro saiu
        fstream f;
        f.open("../base_de_dados/saida_dos_carros.txt", ios::app);
        f << "placa: " << placa << "," << " data: "<< tm.tm_mday << " de " << meses[tm.tm_mon] << " de " << tm.tm_year + 1900 << ", horário: "<< tm.tm_hour << "h" << tm.tm_min << "m"<< tm.tm_sec << "s" <<endl;
        f.close();
    }
}