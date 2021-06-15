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
    bool Sudoku::jogar(int fila, int coluna, int numero){
        if(numero == 0){
            if(matriz[fila][coluna] != 0) restantes++;
            matriz[fila][coluna] = 0;
            return true;
        }
        if(matriz[fila][coluna] != 0) return false;

        for(int i = 0; i < 9; i++){
            if(numero == matriz[fila][i]) return false;
            if(numero == matriz[i][coluna]) return false;
        }

        int filamenor = fila / 3;
        int colunamenor = coluna / 3;

        for(int i = filamenor; i < filamenor + 3; i++){
            for(int j = colunamenor; j < colunamenor + 3; j++){
                if(numero == matriz[i][j]) return false;
            }
        }
        matriz[fila][coluna] = numero;
        restantes--;
        return true;
    }
    void Sudoku::imprimir(){
        for(int i = 0; i < 9; i++){
            if(i % 3 == 0){
                for(int j = 0; j < 9; j++){
                    if(j % 3 == 0){
                        cout << "+-";
                    }
                    cout << "--";
                }
                cout << "+\n";
            }
            for(int j = 0; j < 9; j++){
                if(j % 3 == 0){
                    cout << "|";
                }
                if(matriz[i][j] == 0){
                    cout << ".";
                }
                else{
                    cout << matriz[i][j];
                }
                cout << " ";
            }
            cout << "|\n";
        }
        for(int j = 0; j < 9; j++){
            if(j % 3 == 0){
                cout << "+-";
            }
            cout << "--";
        }
        cout << "+\n";
    }
    int main(){
        Sudoku* novo = new Sudoku();
        int fila, coluna, numero;
        while(novo->getRestantes() > 0){
            novo->imprimir();
            cout << "Sudoku";
            cout << "insira fila|coluna|numero";
            cin >> fila >> coluna >> numero;

            if(fila >= 1 && fila <= 9 && coluna >= 1 && coluna <= 9){
                if(!novo->jogar(fila-1, coluna-1, numero)){
                    cout << "valor incorreto" << endl;
                }
            }
            else
                cout << "jogada não possivel" << endl;
            
            delete novo;
            return 0;
        }
    }
};
