#ifndef TABELA_HPP_
#define TABELA_HPP_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class TabelaVigenere {
   public:
    vector<vector<char> > Tabela;
    vector<char> alfabeto;
    TabelaVigenere();
    void imprimeTabela();
    void criptografar(string &palavra, string chave);
    void descriptografar(string &palavra, string chave);
    int getIndex(char letra);
    char findLetter(int index, char letra);
};

#endif  // TABELA_HPP_