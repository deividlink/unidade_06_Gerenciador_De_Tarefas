#ifndef TAREFA_HPP
#define TAREFA_HPP

#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<string>

#include <atomic>
#include <cstdlib>

class Tarefa{
    private:
        std::string titulo;
        bool concluida;
    public:
        Tarefa(std::string t_tarefa);
        void setCheck();
        std::string getTarefa();
        inline std::string getTitulo() const { return this->titulo; }
        inline bool getCheck() const { return this->concluida; }
};

class Tarefas{
    private:
        std::vector<Tarefa> v_tarefas;
        std::string minusculo(std::string palavra);
        
    public:
        Tarefas();
        void carregar(std::vector<Tarefa> c_tarefa);
        int pesquisar(std::string p_titulo);
        bool adicionar(std::string add_titulo);
        bool remover(std::string rem_titulo);
        bool modificar(std::string mod_titulo);
        void mostrar();
};

class Usuario{
    private:
        std::atomic<bool> ativo;
        Tarefas tarefas;
        void limparTela();
    public:
        Usuario();
        void listatarefas();
};


#endif