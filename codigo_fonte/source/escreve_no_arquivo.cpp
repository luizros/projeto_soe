#include "escreve_no_arquivo.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <string>

using namespace std;
//Este programa escreve a placa no arquivo entrada_dos_carros.txt e saida_dos_carros.txt
int verifica_placa_no_arquivo(char placa[7]){
    string linha;
        ifstream arquivo("../base_de_dados/placas_cadastradas.txt");
        if (arquivo.is_open()) {
            while (getline(arquivo, linha)) {
                if (linha == placa) {
                    arquivo.close();
                    return 0;
                }
            }
            arquivo.close();
            return 1;
        } else {
            cout << "Não foi possível abrir o arquivo" << endl;
            return 1;
        }
}
void escrever(char placa[7], int flag ){
    //cria a estrutura para pegar a data
    string meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    //escreve o valor da placa e o horário no arquivo
    int flag2 = verifica_placa_no_arquivo(placa);
    if (flag2==1){
        if (flag==1){
        // escreve que o carro entrou mas nao ta cadastrado
            fstream f;
            f.open("../base_de_dados/entrada_dos_carros.txt", ios::app);
            f << "placa: " << placa << " NÃO ESTÁ no banco de dados e entrou em:" << " data: "<< tm.tm_mday << " de " << meses[tm.tm_mon] << " de " << tm.tm_year + 1900 << ", horário: "<< tm.tm_hour << "h" << tm.tm_min << "m"<< tm.tm_sec << "s" <<endl;
            f.close();
        }else{
            //escreve que o carro saiu mas nao ta cadastrado
            fstream f;
            f.open("../base_de_dados/saida_dos_carros.txt", ios::app);
            f << "placa: " << placa << " NÃO ESTÁ no banco de dados e saiu em:" << " data: "<< tm.tm_mday << " de " << meses[tm.tm_mon] << " de " << tm.tm_year + 1900 << ", horário: "<< tm.tm_hour << "h" << tm.tm_min << "m"<< tm.tm_sec << "s" <<endl;
            f.close();
        }
    }
    else if (flag2==0){
        if (flag==1){
        // escreve que o carro entrou e esta cadastrado
            fstream f;
            f.open("../base_de_dados/entrada_dos_carros.txt", ios::app);
            f << "placa: " << placa << " ESTÁ no banco dados e entrou em:" << " data: "<< tm.tm_mday << " de " << meses[tm.tm_mon] << " de " << tm.tm_year + 1900 << ", horário: "<< tm.tm_hour << "h" << tm.tm_min << "m"<< tm.tm_sec << "s" <<endl;
            f.close();
        }else{
            //escreve que o carro saiu e esta cadastrado
            fstream f;
            f.open("../base_de_dados/saida_dos_carros.txt", ios::app);
            f << "placa: " << placa << " ESTÁ no banco de dados e saiu em:" << " data: "<< tm.tm_mday << " de " << meses[tm.tm_mon] << " de " << tm.tm_year + 1900 << ", horário: "<< tm.tm_hour << "h" << tm.tm_min << "m"<< tm.tm_sec << "s" <<endl;
            f.close();
        }        
    }
}