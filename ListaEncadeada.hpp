#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

#include "Aluno.hpp"
#include <stdexcept>
#include <iostream>

// Definição da classe da lista encadeada
class ListaEncadeada {
private:
    struct Elemento {
        Aluno aluno;
        Elemento* proximo;
        Elemento(Aluno aluno) : aluno(aluno), proximo(nullptr) {}
    };

    Elemento* _primeiro;
    size_t _tamanho;

public:
    ListaEncadeada() : _primeiro(nullptr), _tamanho(0) {}

    ~ListaEncadeada() {
        while (_primeiro != nullptr) {
            Elemento* temp = _primeiro;
            _primeiro = _primeiro->proximo;
            delete temp;
        }
    }

    // Verifica se a lista está vazia
    bool vazia() const {
        return _primeiro == nullptr;
    }

    // Adiciona um aluno no final da lista
    void inserirNoFim(Aluno aluno) {
        Elemento* novoElemento = new Elemento(aluno);
        if (_primeiro == nullptr) {
            _primeiro = novoElemento;
        } else {
            Elemento* atual = _primeiro;
            while (atual->proximo != nullptr) {
                atual = atual->proximo;
            }
            atual->proximo = novoElemento;
        }
        _tamanho++;
    }

    void organizarPorMedia() {
        Elemento* atual = _primeiro;
        Elemento* proximo = atual->proximo;
        while (atual != nullptr) {
            while (proximo != nullptr) {
                if (atual->aluno.calcularMedia() < proximo->aluno.calcularMedia()) {
                    Aluno temp = atual->aluno;
                    atual->aluno = proximo->aluno;
                    proximo->aluno = temp;
                }
                proximo = proximo->proximo;
            }
            atual = atual->proximo;
            proximo = atual->proximo;
        }
    }

    // Remove o aluno do início da lista
    Aluno removerDoInicio() {
        if (vazia()) {
            throw std::runtime_error("Lista vazia");
        }
        Elemento* temp = _primeiro;
        Aluno alunoRemovido = temp->aluno;

        // Atualiza o ponteiro _primeiro para o próximo elemento
        _primeiro = _primeiro->proximo;

        // Libera a memória do elemento removido
        delete temp;

        // Decrementa o tamanho da lista
        _tamanho--;

        return alunoRemovido;
    }

    // Busca um aluno pela matrícula
    Aluno buscarPorMatricula(int matricula) const {
        Elemento* atual = _primeiro;
        while (atual != nullptr) {
            if (atual->aluno.matricula == matricula) {
                return atual->aluno;
            }
            atual = atual->proximo;
        }
        throw runtime_error("Aluno não encontrado");
    }

    // Exibe todos os alunos
    void exibirTodos() const {
        Elemento* atual = _primeiro;
        while (atual != nullptr) {
            const Aluno& aluno = atual->aluno;
            cout << "Matrícula: " << aluno.matricula << ", Nome: " << aluno.nome << ", Média: " << aluno.calcularMedia() << endl;
            atual = atual->proximo;
        }
    }

    std::size_t tamanho() const {
        return _tamanho;
    }
};

#endif
