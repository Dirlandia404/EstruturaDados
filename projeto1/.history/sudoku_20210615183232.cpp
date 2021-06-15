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
    Sudoku::Sudoku(){
        matriz = new int*[9];
        for(int i = 0; i < 9; i++){
            matriz[i] = new int [9];
            for(int j = 0; j < 9; j++){
                matriz[i][j] = 0;
            }
        }
        restantes = 9 * 9;
    }
    Sudoku::~Sudoku(){
        for(int i = 0; i < 9; i++){
            delete[] matriz[i];
        }
        delete[] matriz;
    }
};