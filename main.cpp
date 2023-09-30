/*
CIFRA DE VIGENERE

    É um método de criptografia que usa uma série de diferentes cifras de César
baseadas em letras de uma senha.

 Numa cifra de César, cada letra do alfabeto é
deslocada da sua posição um número fixo de lugares; por exemplo, se tiver um
deslocamento de 3, "A" torna-se "D", "B" fica "E", etc. A cifra de Vigenère
consiste no uso de várias cifras de César em sequência, com diferentes valores
de deslocamento ditados por uma "palavra-chave".

Para cifrar, é usada uma tabela de alfabetos que consiste no alfabeto escrito 26
vezes em diferentes linhas, cada um deslocado ciclicamente do anterior por uma
posição. As 26 linhas correspondem às 26 possíveis cifras de César. Uma palavra
é escolhida como "palavra-chave", e cada letra desta palavra vai indicar a linha
a ser utilizada para cifrar ou decifrar uma letra da mensagem.

*usar função imprime tabela*
*/

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

    cout << "\n\n---------TABELA VIGENERE.--------- \n" << endl;

    tabela.imprimeTabela();
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
