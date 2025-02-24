#include <iostream>
#include "ListaEncadeada.hpp"

int main() {
    ListaEncadeada lista;

    // Criando alunos
    Aluno aluno1(12345, "João Silva", std::vector<float>{7.5, 8.0, 9.5});
    Aluno aluno2(67890, "Maria Oliveira", std::vector<float>{6.0, 7.0, 8.5});
    Aluno aluno3(11223, "Pedro Souza", std::vector<float>{8.0, 7.5, 9.0});

    // Inserindo alunos na lista
    lista.inserirNoFim(aluno1);
    lista.inserirNoFim(aluno2);
    lista.inserirNoFim(aluno3);

    // Exibindo todos os alunos antes de remover
    std::cout << "Lista de Alunos (Antes da remoção):" << std::endl;
    lista.exibirTodos();
    lista.organizarPorMedia();

    // Remover o primeiro aluno (uma vez por execução)
    try {
        Aluno alunoRemovido = lista.removerDoInicio();
        std::cout << "\nAluno removido: " << alunoRemovido.nome << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Exibindo a lista após a remoção do primeiro aluno
    std::cout << "\nLista após remoção do primeiro aluno:" << std::endl;
    if (!lista.vazia()) {
        lista.exibirTodos();
    } else {
        std::cout << "A lista está vazia." << std::endl;
    }

    return 0;
}
