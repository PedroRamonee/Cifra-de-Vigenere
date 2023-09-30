#include "src/TabelaVigenere.hpp"

int main(int argc, char const *argv[]) {
    TabelaVigenere tabela;

    string palavra;
    string chave;

    int controle = 0;

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

    cout << "Digite:\n 1 para criptografar\n 2 para descriptografar" << endl;

    cin >> controle;

    // tabela.imprimeTabela();
    if (controle == 1) {

        tabela.criptografar(palavra, chave);

        cout << "Palavra criptografada em vigenere: " << palavra << endl;
    } else if (controle == 2) {
        
        tabela.descriptografar(palavra, chave);

        cout << "Palavra descriptografada em vigenere: " << palavra << endl;
    } else {
        cout << "Chave invalida" << endl;
    }
    return 0;
}
