#include <iostream>
#include <vector>
#include <string>
using namespace std;


// =============================
// Classe base: Pessoa
// =============================
class Pessoa {
protected:
    string nome;
    int idade;


public:
    Pessoa(string nome, int idade) : nome(nome), idade(idade) {}
    virtual void exibirInfo() const {
        cout << "Nome: " << nome << "\nIdade: " << idade << endl;
    }
    string getNome() const { return nome; }
};


// =============================
// Classe Aluno
// =============================
class Aluno : public Pessoa {
private:
    int matricula;


public:
    Aluno(string nome, int idade, int matricula)
        : Pessoa(nome, idade), matricula(matricula) {}


    void exibirInfo() const override {
        cout << "=== Aluno ===" << endl;
        Pessoa::exibirInfo();
        cout << "Matricula: " << matricula << endl;
    }


    int getMatricula() const { return matricula; }
};


// =============================
// Classe Alunos (sistema de alunos)
// =============================
class Alunos {
private:
    vector<Aluno> lista;


public:
    void adicionar(const Aluno &aluno) {
        lista.push_back(aluno);
    }


    void listar() const {
        cout << "\n=== Lista de Alunos ===" << endl;
        for (const auto &a : lista) {
            a.exibirInfo();
            cout << endl;
        }
    }


    void buscar(int matricula) const {
        bool encontrado = false;
        for (const auto &a : lista) {
            if (a.getMatricula() == matricula) {
                cout << "\nAluno encontrado:" << endl;
                a.exibirInfo();
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
            cout << "\nAluno nao encontrado!" << endl;
    }


    vector<Aluno> getLista() const {
        return lista;
    }
};


// =============================
// Classe Professor
// =============================
class Professor : public Pessoa {
private:
    string disciplina;


public:
    Professor(string nome, int idade, string disciplina)
        : Pessoa(nome, idade), disciplina(disciplina) {}


    void exibirInfo() const override {
        cout << "=== Professor ===" << endl;
        Pessoa::exibirInfo();
        cout << "Disciplina: " << disciplina << endl;
    }


    string getDisciplina() const { return disciplina; }
};


// =============================
// Classe Turma
// =============================
class Turma {
private:
    string codigo;
    Professor professor;
    vector<Aluno> alunos;


public:
    Turma(string codigo, Professor professor)
        : codigo(codigo), professor(professor) {}


    void adicionarAluno(const Aluno &aluno) {
        alunos.push_back(aluno);
    }


    void exibirTurma() const {
        cout << "\n===== Turma " << codigo << " =====" << endl;
        cout << "Professor responsavel:" << endl;
        professor.exibirInfo();
        cout << "\n--- Alunos ---" << endl;
        for (const auto &a : alunos) {
            a.exibirInfo();
            cout << endl;
        }
    }


    string getCodigo() const { return codigo; }
};


// =============================
// Classe Setor
// =============================
class Setor {
private:
    string nome;
    Pessoa responsavel;


public:
    Setor(string nome, Pessoa responsavel)
        : nome(nome), responsavel(responsavel) {}


    void exibirSetor() const {
        cout << "\n=== Setor: " << nome << " ===" << endl;
        cout << "Responsavel: " << responsavel.getNome() << endl;
    }


    string getNome() const { return nome; }
};


// =============================
// Classe Secretaria (controladora do sistema)
// =============================
class Secretaria {
private:
    vector<Turma> turmas;
    Alunos alunos;
    vector<Professor> professores;
    vector<Setor> setores;


public:
    // Cadastro
    void cadastrarAluno(const Aluno &aluno) { alunos.adicionar(aluno); }
    void cadastrarProfessor(const Professor &professor) { professores.push_back(professor); }
    void criarTurma(const Turma &turma) { turmas.push_back(turma); }
    void cadastrarSetor(const Setor &setor) { setores.push_back(setor); }


    // Listagens
    void listarAlunos() const { alunos.listar(); }


    void listarTurmas() const {
        cout << "\n=== Turmas Cadastradas ===" << endl;
        for (const auto &t : turmas)
            t.exibirTurma();
    }


    void listarSetores() const {
        cout << "\n=== Setores da Escola ===" << endl;
        for (const auto &s : setores)
            s.exibirSetor();
    }


    // Busca
    void buscarAluno(int matricula) const { alunos.buscar(matricula); }
};


// =============================
// Função principal
// =============================
int main() {
    Secretaria secretaria;


    // Professores
    Professor prof1("Katia Barboza", 40, "Matematica");
    Professor prof2("Cristiane Baliero", 44, "Português");
    Professor prof3("Paulo Medeiros", 44, "Ingles");
    Professor prof4("Anusa Patricia", 35, "Historia");
    Professor prof5("Pedro", 40, "Filosofia");
    Professor prof6("Cleise Aquino", 35, "Biologia");
    Professor prof7("Lorena Campos", 44, "Quimica");
    Professor prof8("Lucas", 35, "Fisica");
    Professor prof9("Andreza Souza", 40, "Artes");
    Professor prof10("Deyla Garsez", 35, "Sociologia");
    Professor prof11("Denilson", 44, "Geografia");
    Professor prof12("Paulo medeiros", 35, "Linguagens");
    Professor prof13("Andreza Souza", 35, "Ed. Fisica");
    Professor prof14("Katia Barboza", 44, "Let.Mat");
    Professor prof15("Priscila Gonçalves", 35, "EPAEM");
    secretaria.cadastrarProfessor(prof1);
    secretaria.cadastrarProfessor(prof2);
    secretaria.cadastrarProfessor(prof3);
    secretaria.cadastrarProfessor(prof4);
    secretaria.cadastrarProfessor(prof5);
    secretaria.cadastrarProfessor(prof6);
    secretaria.cadastrarProfessor(prof7);
    secretaria.cadastrarProfessor(prof8);
    secretaria.cadastrarProfessor(prof9);
    secretaria.cadastrarProfessor(prof10);
    secretaria.cadastrarProfessor(prof11);
    secretaria.cadastrarProfessor(prof12);
    secretaria.cadastrarProfessor(prof13);
    secretaria.cadastrarProfessor(prof14);
    secretaria.cadastrarProfessor(prof15);



    // Alunos
    
    Aluno a1("Joao", 16, 101);
    Aluno a2("Yasmin", 16, 102);
    Aluno a3("Otavio", 17, 103);
    Aluno a4("Helio", 15, 104);
    Aluno a5("Edma", 16, 105);
    Aluno a6("Argenis", 16, 106);
    Aluno a7("Maria Luiza", 16, 107);
    Aluno a8("Shymenne", 17, 108);
    Aluno a9("John", 15, 109);
    Aluno a10("Nicole", 16, 110);
    Aluno a11("Maria Eduarda", 16, 111);
    Aluno a12("Nayane", 15, 112);
    Aluno a13("Julita", 15, 113);
    Aluno a14("Ana Ester", 15, 114);
    Aluno a15("Miguel", 16, 115);
    Aluno a16("Francinei", 15, 116);
    Aluno a17("Francisco", 16, 117);
    Aluno a18("Bruno", 15, 118);
    Aluno a19("Leo Felipe", 16, 119);
    Aluno a20("Ana Julia", 16, 120);
    Aluno a21("Henrique", 16, 121);
    Aluno a22("Jonatha", 15, 122);
    Aluno a23("Gustavo", 15, 123);
    Aluno a24("Vitoria", 15, 124);
    secretaria.cadastrarAluno(a1);
    secretaria.cadastrarAluno(a2);
    secretaria.cadastrarAluno(a3);
    secretaria.cadastrarAluno(a4);
    secretaria.cadastrarAluno(a5);
    secretaria.cadastrarAluno(a6);
    secretaria.cadastrarAluno(a7);
    secretaria.cadastrarAluno(a8);
    secretaria.cadastrarAluno(a9);
    secretaria.cadastrarAluno(a10);
    secretaria.cadastrarAluno(a11);
    secretaria.cadastrarAluno(a12);
    secretaria.cadastrarAluno(a13);
    secretaria.cadastrarAluno(a14);
    secretaria.cadastrarAluno(a15);
    secretaria.cadastrarAluno(a16);
    secretaria.cadastrarAluno(a17);
    secretaria.cadastrarAluno(a18);
    secretaria.cadastrarAluno(a19);
    secretaria.cadastrarAluno(a20);
    secretaria.cadastrarAluno(a21);
    secretaria.cadastrarAluno(a22);
    secretaria.cadastrarAluno(a23);
    secretaria.cadastrarAluno(a24);


    // Turmas
    Turma t1("A1", prof1);
    t1.adicionarAluno(a1);
    t1.adicionarAluno(a2);
    t1.adicionarAluno(a3);
    t1.adicionarAluno(a4);
    t1.adicionarAluno(a5);
    t1.adicionarAluno(a6);
    t1.adicionarAluno(a7);
    t1.adicionarAluno(a8);
    t1.adicionarAluno(a9);
    t1.adicionarAluno(a10);
    t1.adicionarAluno(a11);
    t1.adicionarAluno(a12);
    Turma t2("B2", prof2);
    t2.adicionarAluno(a13);
    t1.adicionarAluno(a14);
    t1.adicionarAluno(a15);
    t1.adicionarAluno(a16);
    t1.adicionarAluno(a17);
    t1.adicionarAluno(a18);
    t1.adicionarAluno(a19);
    t1.adicionarAluno(a20);
    t1.adicionarAluno(a21);
    t1.adicionarAluno(a22);
    t1.adicionarAluno(a23);
    t1.adicionarAluno(a24);
    secretaria.criarTurma(t1);
    secretaria.criarTurma(t2);


    // Setores
    Pessoa func1("Fernanda Alves", 32);
    Pessoa func2("Ricardo Lima", 45);
    Setor s1("Secretaria", func1);
    Setor s2("Biblioteca", func2);
    secretaria.cadastrarSetor(s1);
    secretaria.cadastrarSetor(s2);


    // Exibições
    secretaria.listarAlunos();
    secretaria.buscarAluno(102);
    secretaria.listarTurmas();
    secretaria.listarSetores();


    return 0;
}
