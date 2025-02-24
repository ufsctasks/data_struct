#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <vector>

using namespace std;

// Classe para armazenar os dados de um aluno
class Aluno {
public:
    int matricula;
    string nome;
    vector<float> notas;

    // Construtor
    Aluno(int matricula, string nome, vector<float> notas)
        : matricula(matricula), nome(nome), notas(notas) {}

    // Método para calcular a média das notas
    float calcularMedia() const {
        float soma = 0;
        for (float nota : notas) {
            soma += nota;
        }
        return soma / notas.size();
    }
};

#endif
