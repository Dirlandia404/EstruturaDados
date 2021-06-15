#include <iostream>
using namespace std;

namespace sudoku{
    class Sudoku{
        int **matriz;
        int restantes;
        public: 
            Sudoku();
            ~Sudoku();
            bool jogar(int linha, int coluna, int numero);
            int getRestantes();
            void imprimir();

    };
    int Sudoku::getRestantes(){
        return restantes;
    }
    //construtor
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
    //desfazer construtor
    Sudoku::~Sudoku(){
        for(int i = 0; i < 9; i++){
            delete[] matriz[i];
        }
        delete[] matriz;
    }

    bool Sudoku::jogar(int linha, int coluna, int numero){
        //desfazer jogada
        if(numero == 0){  
            if(matriz[linha][coluna] != 0) restantes++;
            matriz[linha][coluna] = 0;
            return true;
        }
        //verificar espaço ocupado
        if(matriz[linha][coluna] != 0) return false;

        //verificar linha e coluna
        for(int i = 0; i < 9; i++){
            if(numero == matriz[linha][i]) return false;
            if(numero == matriz[i][coluna]) return false;
        }

        //verifica 3x3
        int linhamenor = linha / 3;
        int colunamenor = coluna / 3;

        for(int i = linhamenor; i < linhamenor + 3; i++){
            for(int j = colunamenor; j < colunamenor + 3; j++){
                if(numero == matriz[i][j]) return false;
            }
        }
        matriz[linha][coluna] = numero;
        restantes--;
        return true;
    }
    void Sudoku::imprimir(){
        for(int i = 0; i < 9; i++){
            if(i % 3 == 0){
                for(int j = 0; j < 9; j++){
                    if(j % 3 == 0){
                        cout << "-";
                    }
                    cout << "--";
                }
                cout << "\n";
            }
            for(int j = 0; j < 9; j++){
                if(j % 3 == 0){
                    cout << "|";
                }
                if(matriz[i][j] == 0){
                    cout << " ";
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
                cout << "-";
            }
            cout << "--";
        }
        cout << "\n";
    }
};
int main(){
    using namespace sudoku;
    Sudoku* novo = new Sudoku();
    int linha, coluna, numero;
    while(novo->getRestantes() > 0){
        cout << "--------Sudoku--------\n";
        novo->imprimir();
        cout << "insira linha|coluna|numero";
        cin >> linha >> coluna >> numero;

        if(linha >= 1 && linha <= 9 && coluna >= 1 && coluna <= 9){
            if(!novo->jogar(linha-1, coluna-1, numero)){
                cout << "valor incorreto" << endl;
            }
        }
        else
            cout << "jogada não possivel" << endl;
        
    }
    delete novo;
    return 0;
};
