#include <iostream>
using namespace std;

namespace sudoku{
    class Sudoku{
        int **matriz;
        int resto;
        public: 
            Sudoku();
            ~Sudoku();
            bool jogar(int linha, int coluna, int numero);
            int getResto();
            void imprimir();

    };
    int Sudoku::getResto(){
        return resto;
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
        resto = 9 * 9;
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
            if(matriz[linha][coluna] != 0) resto++;
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
        resto--;
        return true;
    }
    void Sudoku::imprimir(){
        for(int i = 0; i < 9; i++){
            if(i % 3 == 0){
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
    while(novo->getResto() > 0){
        cout << "--------Sudoku--------\n";
        novo->imprimir();
        cout << "linha ";
        cin >> linha;
        cout << "coluna ";
        cin >> coluna;
        cout << "numero ";
        cin >> numero;

        if(linha >= 1 && linha <= 9 && coluna >= 1 && coluna <= 9 && numero >= 1 && numero <= 9){
            if(!novo->jogar(linha-1, coluna-1, numero)){
                cout << "invalido" << endl;
            }
        }
        else
            cout << "jogada não possivel" << endl;
        
    }
    delete novo;
    return 0;
};
