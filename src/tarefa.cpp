#include "./include/Tarefas/tarefa.hpp"

void pause(){
    std::cout << "> ";
    std::cin.ignore();

}


Tarefa::Tarefa(std::string t_tarefa):titulo(t_tarefa),concluida(false){}
std::string Tarefa::getTarefa(){
    std::stringstream ss;
    if(concluida){
        ss << " [X] " << titulo << '\n';
    }else{
        ss << " [ ] " << titulo << '\n';
    }
    return ss.str();
}
void Tarefa::setCheck(){
    if(concluida){
        concluida = false;
    }else{
        concluida = true;
    }
}

Tarefas::Tarefas(){}
std::string Tarefas::minusculo(std::string palavra){
    std::transform(palavra.begin(),palavra.end(), palavra.begin(), ::tolower);
    return palavra;
}
void Tarefas::carregar(std::vector<Tarefa> c_tarefas){ v_tarefas = c_tarefas; }
int Tarefas::pesquisar(std::string p_titulo){
    p_titulo = minusculo(p_titulo);
    int index = -1;
    for(size_t i = 0; i < v_tarefas.size(); ++i){
        if(v_tarefas[i].getTitulo() == p_titulo){ index = i; }
    }
    return index;
}
bool Tarefas::adicionar(std::string add_titulo){
    add_titulo = minusculo(add_titulo);
    bool sucesso = false;
    if(pesquisar(add_titulo) == -1){
        v_tarefas.push_back(Tarefa(add_titulo));
        sucesso = true;
    }
}
bool Tarefas::remover(std::string rem_titulo){
    rem_titulo = minusculo(rem_titulo);
    bool sucesso = false;
    int index = pesquisar(rem_titulo);
    if(index != -1){
        v_tarefas.erase(v_tarefas.begin() + index);
        sucesso = true;
    }
    return sucesso;
}
bool Tarefas::modificar(std::string mod_titulo){
    mod_titulo = minusculo(mod_titulo);
    bool sucesso = false;
    int index = pesquisar(mod_titulo);
    if(index != -1){  v_tarefas[index].setCheck();  sucesso = true; }
    return sucesso;
}
void Tarefas::mostrar(){
    std::stringstream ss;
    for(Tarefa& tarefa: v_tarefas){
        ss << tarefa.getTarefa();
    }
    std::cout << ss.str() << '\n';
}


Usuario::Usuario():ativo(true){}
void Usuario::limparTela(){
    #ifdef _WIN32 
        std::system("cls");
    #else
        std::system("clear");
    #endif
}
void Usuario::listatarefas(){
    std::stringstream ss;
    ss << "=== Lista De Tarefas ===" << '\n';
    ss << "= 1. Mostrar Tarefas   =" << '\n';
    ss << "= 2. Adicionar Tarefa  =" << '\n';
    ss << "= 3. Modificar Tarefa  =" << '\n';
    ss << "= 4. Remover Tarefa    =" << '\n';
    ss << "= 0. Sair              =" << '\n';
    ss << "> ";
    while(ativo){
        limparTela();
        std::cout << ss.str();
        int entrada;
        std::cin >> entrada;

        switch(entrada){
            case 1:{
                limparTela();
                std::cout << "=== Tarefas ===" << '\n';
                tarefas.mostrar();
                pause();
                std::cout << ""; // ele apenas pula se nao tivesse esse
                std::cin.get();
                break;
            }
            case 2:{
                limparTela();
                std::string titulo;
                std::cout << "=== Tarefas ===" << '\n';
                tarefas.mostrar();
                std::cout << "Adicionar> ";
                std::cin.ignore();
                std::getline(std::cin, titulo);
                
                if(tarefas.adicionar(titulo)){
                    std::cout << "Info: Adicionado Com Sucesso!" << '\n';
                }else{
                    std::cout << "Info: Erro Ao Adicionar A Tarefa Ela Nao Existe!" << "\n";
                }
                
                pause();
                break;
            }
            case 3:{
                limparTela();
                std::cout << "=== Tarefas ===" << '\n';
                tarefas.mostrar();
                std::string titulo;
                std::cout << "Modificar> ";
                std::cin.ignore();
                std::getline(std::cin, titulo);

                if(tarefas.modificar(titulo)){
                    std::cout << "Info: Modificado Com Sucesso!" << '\n';
                }else{
                    std::cout << "Info: Erro Ao Modificar A Tarefa Nao Existe!" << '\n';
                }
                
                pause();
                break;
            }
            case 4:{
                limparTela();
                std::string titulo;
                std::cout << "=== Tarefas ===" << '\n';
                tarefas.mostrar();
                std::cout << "Remover> ";
                std::cin.ignore();
                std::getline(std::cin, titulo);
                if(tarefas.remover(titulo)){
                    std::cout << "Info: Removido Com Sucesso!" << '\n';
                }else{
                    std::cout << "Info: Erro ao Remover Essa Tarefa Nao Existe!" << '\n';
                }
                pause();
                break;
            }
            case 0:
            limparTela();
                std::cout << "Saindo ..." << '\n';
                pause();
                ativo = false;
                break;
            default:
                std::cout << "Comando Desconhecido" << '\n';
        }
    }
}