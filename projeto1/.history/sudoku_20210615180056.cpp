/*

matriz 9x9
e o numero não pode ser o mesmo na coluna
atributos 
int* matriz
int restantes

construtor
Sudoku()
desconstrutor
~Sudoku()

metodos
bool jogar(int fila, int coluna, int numero)
int getRestantes()

void imprimir
*/

#include <iostream>

namespace sudoku{
    class Sudoku{
        int **matriz;
        int restantes;
        public: 
            Sudoku();
            ~Sudoku();
            bool jogar(int fila, int coluna, int numero);
            int getRestantes();
            void imprimir();

    };
    using namespace std;

    int Sudoku::getRestantes(){
        return restantes;
    }
};