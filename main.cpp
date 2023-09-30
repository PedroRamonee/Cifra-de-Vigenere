#include "src/TabelaVigenere.hpp"

int main(int argc, char const *argv[]) {
    TabelaVigenere tabela;

    string palavra;
    string chave;

    cout << "Digite a palavra/frase a ser criptografada ou descriptografada:"
         << endl;

    getline(cin, palavra);

    cout << "Digite a chave de criptografia:" << endl;

    getline(cin, chave);

    for (int i = 0; i < palavra.size(); i++) {
        palavra[i] = tolower(palavra[i]);
    }
    for (int i = 0; i < chave.size(); i++) {
        chave[i] = tolower(chave[i]);
    }

    // tabela.imprimeTabela();

    tabela.criptografar(palavra, chave);

    cout << "Palavra criptografada em vigenere: " << palavra << endl;

    tabela.descriptografar(palavra, chave);

    cout << "Palavra descriptografada em vigenere: " << palavra << endl;

    return 0;
}
