#include "ler_o_arquivo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int ler_placas(char placa[7]){
    string searchString = placa; // String a ser procurada
    string line;
    ifstream file("../base_de_dados/placas.txt"); // Nome do arquivo
    int count = 0; // Contador para as ocorrências da string
    vector<string> lines;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find(searchString) == string::npos) {
                lines.push_back(line);
            } else {
                count++;
            }
        }
        file.close();
    } else {
        cout << "Não foi possível abrir o arquivo." << endl;
        return 0;
    }

    ofstream outputFile("../base_de_dados/placas.txt");
    for (string newLine : lines) {
        outputFile << newLine << endl;
    }
    outputFile.close();

    cout << "A placa \"" << searchString << "\" foi encontrada " << count << " vezes no arquivo e removida." << endl;
    return 0;
}

