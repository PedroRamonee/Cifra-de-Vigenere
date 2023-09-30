#include "TabelaVigenere.hpp"

TabelaVigenere::TabelaVigenere() {
    for (int i = 0; i < 26; i++) {
        char letra = 'a';
        vector<char> alfabeto;
        letra += i;
        for (int j = 0; j < 26; j++) {
            if (letra != 'z') {
                alfabeto.push_back(letra);
                letra++;
            } else {
                alfabeto.push_back(letra);
                letra = 'a';
            }
        }
        this->Tabela.push_back(alfabeto);
    }

    char letra = 'a';
    for (int i = 0; i < 26; i++) {
        this->alfabeto.push_back(letra);
        letra++;
    }
}

void TabelaVigenere ::imprimeTabela() {
    for (int i = 0; i < Tabela.size(); i++) {
        cout << endl;
        for (int j = 0; j < Tabela.size(); j++) {
            cout << Tabela[i][j] << " ";
        }
    }
    cout << "\n\n\n" << endl;
}

void TabelaVigenere ::criptografar(string &palavra, string chave) {
    string troca = palavra;
    int controle = 0;

    cout << "Palavra original: " << palavra << endl;

    for (int i = 0; i < palavra.size(); i++) {
        if (palavra[i] != ' ') {
            if (controle == chave.size()) {
                controle = 0;
            }
            troca[i] = chave[controle];
            controle++;
        } else {
            troca[i] = palavra[i];
        }
    }

    cout << "Chave cifrada: " << troca << endl;

    string aux = palavra;

    for (int i = 0; i < palavra.size(); i++) {
        if (palavra[i] != ' ') {
            palavra[i] = Tabela[getIndex(aux[i])][getIndex(troca[i])];
        }
    }
}

int TabelaVigenere::getIndex(char letra) {
    for (int i = 0; i < alfabeto.size(); i++) {
        if (letra == alfabeto[i]) {
            return i;
        }
    }
}

void TabelaVigenere::descriptografar(string &palavra, string chave) {
    string troca = palavra;
    int controle = 0;

    for (int i = 0; i < palavra.size(); i++) {
        if (palavra[i] != ' ') {
            if (controle == chave.size()) {
                controle = 0;
            }
            troca[i] = chave[controle];
            controle++;
        } else {
            troca[i] = palavra[i];
        }
    }

    string aux = palavra;

    for (int i = 0; i < palavra.size(); i++) {
        if (palavra[i] != ' ') {
            palavra[i] = findLetter(getIndex(troca[i]), aux[i]);
        }
    }
}

char TabelaVigenere::findLetter(int index, char letra) {
    for (int i = 0; i < Tabela.size(); i++) {
        if (Tabela[i][index] == letra) {
            return Tabela[0][i];
        }
    }
}