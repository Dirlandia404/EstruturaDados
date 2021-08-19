#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string.h>
#include <array>
#include <iterator>
#include <cstring>
#include <cstdlib>
using namespace std;

void imprimir(int matriz[9][9]) {
	
	for(int i = 0; i < 9; i++){
        if(i % 3 == 0){
            cout << "\n";
        }
        for(int j = 0; j < 9; j++){
            if(j % 3 == 0){
                cout << "|";
            }
            if(matriz[i][j] == 0){
                cout << 0;
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

bool vazio(int matriz[9][9], int linha, int coluna, int n){
	if (matriz[linha][coluna] != 0) return false;
	bool status = true;
	int coluna3x3 = (coluna / 3) * 3;
	int linha3x3 = (linha / 3) * 3;
	for (int i = 0; i < 9; i++) {
		if (matriz[linha][i] == n) { status = false; break; }
		if (matriz[i][coluna] == n) { status = false; break; }
		if (matriz[linha3x3 + i / 3][coluna3x3 + i % 3] == n) { status = false; break; }
	}
	return status;
}

void proximoVazio(int matriz[9][9], int linha, int coluna, int& linha2, int& coluna2){
	int aux = 9 * 9 + 1;
	for (int i = linha * 9 + coluna + 1; i < 9 * 9; i++) {
		if (matriz[i / 9][i % 9] == 0) {

			aux = i;
			break;
		}
	}
	linha2 = aux / 9;
	coluna2 = aux % 9;
}

void escrever(int matriz[9][9], int matrizAux[9][9]){
    for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
			matrizAux[y][x] = matriz[y][x];
}
std::vector<int> encontrarVazio(int matriz[9][9], int linha, int coluna) {
	vector<int> encontrar = {};
	for (int n = 1; n <= 9; n++)
		if (vazio (matriz, linha, coluna, n)) encontrar.push_back(n);
	return encontrar;
}


bool resolver(int matriz[9][9], int linha, int coluna){
	if (linha > 8) return true;
	if (matriz[linha][coluna] != 0) {
		int linha2, coluna2;
		proximoVazio(matriz, linha, coluna, linha2, coluna2);
		return resolver(matriz, linha2, coluna2);
	}

	std::vector<int> encontrar = encontrarVazio(matriz, linha, coluna);
    
	if (encontrar.size() == 0) {
		
		return false; 
	
	};

	bool status = false;
	for (int i = 0; i < encontrar.size(); i++) {
		int n = encontrar[i];
		int matrizAux[9][9];
		escrever(matriz, matrizAux);
		

		matrizAux[linha][coluna] = n;
		int linha2 = linha;
		int coluna2 = coluna;
		proximoVazio(matrizAux, linha, coluna, linha2, coluna2);
		if (resolver(matrizAux, linha2, coluna2)) {
			escrever(matrizAux, matriz);
			status = true;
			break;
		}
	}
	return status;
}
void remover(int quantidade, int matriz[9][9]){
    int matrizAux[9][9];
   
    for(int cont = 0; cont <= quantidade; cont++){
        for(int i = 0; i <= cont; i++){
            for(int j = 0; j <= quantidade; j++){
                if(matrizAux[rand() % 10 - 1][rand() % 8+1] == matriz[i][j]){
                    matriz[i][j] = 0;
                    if (quantidade != 81)
                    {
                        quantidade--;
                       
                    }
                    
                }
                
            }
        } 
    }
}

bool salvar(string nome, int matriz[9][9]){
    FILE * arquivo = fopen(nome.c_str(), "w");
    
    
    if(arquivo){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                fprintf (arquivo, "%d ", matriz[i][j]);
        fclose(arquivo);
        return true;
    }
    return false;
}


int main(int argc, char * args[]){

    int M1[9][9]={
        {0,0,8,4,7,0,3,0,6},
		{0,6,0,0,0,2,0,1,0},
		{1,4,0,5,0,0,0,0,8},
		{0,0,9,1,5,0,4,0,3},
		{0,7,0,0,0,0,0,5,0},
		{5,0,4,0,8,3,2,0,0},
		{7,0,0,0,0,6,0,8,5},
		{0,9,0,7,0,0,0,3,0},
		{6,0,2,0,9,5,1,0,0}
		
    };

    int M2[9][9]={
        {0,2,7,4,0,5,9,6,0},
        {4,9,0,2,0,6,0,5,1},
        {0,0,1,0,0,0,0,7,0},
        {7,0,0,0,8,0,0,0,9},
        {0,0,9,0,0,0,7,0,0},
        {1,0,0,0,6,0,0,0,5},
        {0,7,0,0,0,0,5,0,0},
        {5,1,0,6,0,7,0,3,4},
        {0,4,2,8,0,3,6,1,0}
    };

    int M3[9][9]={
        {7,0,8,0,3,0,0,0,6},
        {0,3,0,8,0,0,1,4,0},
        {0,5,0,0,4,2,0,0,9},
        {0,0,7,0,2,0,0,6,0},
        {5,0,2,3,0,9,8,0,4},
        {0,9,0,0,7,0,5,0,0},
        {8,0,0,1,9,0,0,2,0},
        {0,1,6,0,0,7,0,3,0},
        {3,0,0,0,8,0,7,0,1}
    };

    int M4[9][9]={
        {5,0,6,0,7,8,4,0,0},
        {9,0,0,0,0,0,0,2,0},
        {0,2,8,0,0,4,3,6,0},
        {0,0,0,1,2,0,8,5,4},
        {0,0,0,9,0,3,0,0,0},
        {2,5,7,0,8,6,0,0,0},
        {0,1,3,6,0,0,9,8,0},
        {0,4,0,0,0,0,0,0,5},
        {0,0,5,8,3,0,7,0,1}
    };

    int M5[9][9]={
        {5,0,0,0,8,0,0,0,0},
        {0,0,0,1,0,7,3,8,0},
        {6,0,0,0,0,2,1,7,9},
        {3,7,4,0,9,0,0,0,0},
        {0,0,1,2,0,8,6,0,0},
        {0,0,0,0,1,0,5,9,3},
        {7,9,6,3,0,0,0,0,4},
        {0,4,8,6,0,5,0,0,0},
        {0,0,0,0,4,0,0,0,2}
    };

    int M6[9][9]={
        {0,0,0,0,9,4,7,0,0},
        {0,9,1,6,0,8,0,2,0},
        {4,0,0,7,3,0,5,0,6},
        {0,0,0,8,0,0,1,0,5},
        {1,0,6,0,0,0,2,0,9},
        {3,0,4,0,0,2,0,0,0},
        {5,0,2,0,8,9,0,0,3},
        {0,6,0,5,0,7,4,8,0},
        {0,0,7,1,6,0,0,0,0}
    };

    int M7[9][9]={
        {0,0,3,1,0,4,0,5,0},
        {6,8,0,3,0,0,2,7,0},
        {0,5,0,7,0,2,0,0,1},
        {2,0,6,0,0,0,8,1,7},
        {0,0,0,0,0,0,0,0,0},
        {5,4,8,0,0,0,6,0,9},
        {8,0,0,9,0,1,0,2,0},
        {0,7,4,0,0,3,0,6,8},
        {0,3,0,6,0,8,4,0,0}
    };

    int M8[9][9]={
        {0,4,0,0,0,2,3,0,8},
        {0,3,1,0,6,0,0,0,0},
        {7,9,0,1,8,0,0,6,0},
        {1,0,4,8,0,6,0,0,9},
        {0,7,0,0,0,0,0,4,0},
        {9,0,0,7,0,4,5,0,2},
        {0,2,0,0,3,1,0,9,6},
        {0,0,0,0,4,0,1,5,0},
        {3,0,5,6,0,0,0,7,0}
    };

    int M9[9][9]={
        {5,0,6,0,0,9,0,0,8},
        {9,4,0,0,7,0,5,0,0},
        {0,8,0,5,0,2,0,1,0},
        {0,5,0,4,6,0,0,0,7},
        {8,0,3,0,0,0,6,0,4},
        {7,0,0,0,8,1,0,3,0},
        {0,9,0,7,0,6,0,5,0},
        {0,0,2,0,3,0,0,4,9},
        {1,0,0,8,0,0,7,0,2}
    };
    int M10[9][9] = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};
    int M11[9][9]={
        {0,7,0,4,0,0,5,0,0},
        {0,1,0,3,2,0,0,8,4},
        {9,0,0,0,6,1,0,0,0},
        {0,0,5,0,8,0,0,2,9},
        {0,2,9,7,0,5,1,6,0},
        {6,8,0,0,4,0,7,0,0},
        {0,0,0,8,1,0,0,0,7},
        {8,0,0,0,5,4,0,3,0},
        {0,0,2,0,0,3,0,4,0}
    };

	if(argc >= 2){
        if((strcmp(args[1], "--criar") == 0) && argc == 3){
            stringstream ss;
            ss << args[2];
            int quantidade;
            ss >> quantidade;

            if(quantidade ==1){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("SDK/sudoku01", M1);
            }
                
            
            if(quantidade == 2){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("SDK/sudoku01.txt", M1);

                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sudoku02.txt", M2);
            }
            if(quantidade == 3){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("./SDK/sudoku01", M1);

                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sudoku02", M2);

                resolver(M3, 0, 0);
                imprimir(M3);
                salvar("SDK/sudoku03", M3);
            }
            if(quantidade == 4){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("./SDK/sudoku01", M1);

                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sudoku02", M2);

                resolver(M3, 0, 0);
                imprimir(M3);
                salvar("SDK/sudoku03", M3);

                resolver(M4, 0, 0);
                imprimir(M4);
                salvar("SDK/sudoku04", M4);
            }
            if(quantidade == 5){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("./SDK/sudoku01", M1);

                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sudoku02", M2);

                resolver(M3, 0, 0);
                imprimir(M3);
                salvar("SDK/sudoku03", M3);

                resolver(M4, 0, 0);
                imprimir(M4);
                salvar("SDK/sudoku04", M4);

                resolver(M5, 0, 0);
                imprimir(M5);
                salvar("SDK/sudoku05", M5);
            }
            if(quantidade == 6){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("./SDK/sudoku01", M1);

                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sudoku02", M2);

                resolver(M3, 0, 0);
                imprimir(M3);
                salvar("SDK/sudoku03", M3);

                resolver(M4, 0, 0);
                imprimir(M4);
                salvar("SDK/sudoku04", M4);

                resolver(M5, 0, 0);
                imprimir(M5);
                salvar("SDK/sudoku05", M5);

                resolver(M6, 0, 0);
                imprimir(M6);
                salvar("SDK/sudoku06", M6);
            }
            if(quantidade == 7){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("./SDK/sudoku01", M1);

                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sudoku02", M2);

                resolver(M3, 0, 0);
                imprimir(M3);
                salvar("SDK/sudoku03", M3);

                resolver(M4, 0, 0);
                imprimir(M4);
                salvar("SDK/sudoku04", M4);

                resolver(M5, 0, 0);
                imprimir(M5);
                salvar("SDK/sudoku05", M5);

                resolver(M6, 0, 0);
                imprimir(M6);
                salvar("SDK/sudoku06", M6);

                resolver(M7, 0, 0);
                imprimir(M7);
                salvar("SDK/sudoku07", M7);
            }
            if(quantidade == 8){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("./SDK/sudoku01", M1);

                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sudoku02", M2);

                resolver(M3, 0, 0);
                imprimir(M3);
                salvar("SDK/sudoku03", M3);

                resolver(M4, 0, 0);
                imprimir(M4);
                salvar("SDK/sudoku04", M4);

                resolver(M5, 0, 0);
                imprimir(M5);
                salvar("SDK/sudoku05", M5);

                resolver(M6, 0, 0);
                imprimir(M6);
                salvar("SDK/sudoku06", M6);

                resolver(M7, 0, 0);
                imprimir(M7);
                salvar("SDK/sudoku07", M7);

                resolver(M8, 0, 0);
                imprimir(M8);
                salvar("SDK/sudoku08", M8);
            }
            if(quantidade == 9){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("./SDK/sudoku01", M1);

                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sudoku02", M2);

                resolver(M3, 0, 0);
                imprimir(M3);
                salvar("SDK/sudoku03", M3);

                resolver(M4, 0, 0);
                imprimir(M4);
                salvar("SDK/sudoku04", M4);

                resolver(M5, 0, 0);
                imprimir(M5);
                salvar("SDK/sudoku05", M5);

                resolver(M6, 0, 0);
                imprimir(M6);
                salvar("SDK/sudoku06", M6);

                resolver(M7, 0, 0);
                imprimir(M7);
                salvar("SDK/sudoku07", M7);

                resolver(M8, 0, 0);
                imprimir(M8);
                salvar("SDK/sudoku08", M8);

                resolver(M9, 0, 0);
                imprimir(M9);
                salvar("SDK/sudoku09", M9);
            }
            if(quantidade == 10){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("./SDK/sudoku01", M1);

                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sudoku02", M2);

                resolver(M3, 0, 0);
                imprimir(M3);
                salvar("SDK/sudoku03", M3);

                resolver(M4, 0, 0);
                imprimir(M4);
                salvar("SDK/sudoku04", M4);

                resolver(M5, 0, 0);
                imprimir(M5);
                salvar("SDK/sudoku05", M5);

                resolver(M6, 0, 0);
                imprimir(M6);
                salvar("SDK/sudoku06", M6);

                resolver(M7, 0, 0);
                imprimir(M7);
                salvar("SDK/sudoku07", M7);

                resolver(M8, 0, 0);
                imprimir(M8);
                salvar("SDK/sudoku08", M8);

                resolver(M9, 0, 0);
                imprimir(M9);
                salvar("SDK/sudoku09", M9);

                resolver(M10, 0, 0);
                imprimir(M10);
                salvar("SDK/sudoku10", M10);
            }
        }

       else if(strcmp(args[1], "--rem") == 0){
            stringstream ss;
            ss << args[2];
            int quantidade;
            ss >> quantidade;

            if(strcmp(args[3], "sudoku01") == 0){
                resolver(M1, 0, 0);
                remover(quantidade, M1);
                imprimir(M1);
                salvar("SDK/rem_sudoku01", M1);

            }
            if(strcmp(args[3], "sudoku02") == 0){
                resolver(M2, 0, 0);
                remover(quantidade, M2);
                imprimir(M2);
                salvar("SDK/rem_sudoku02", M2);

            }
            if(strcmp(args[3], "sudoku03") == 0){
                resolver(M3, 0, 0);
                remover(quantidade, M3);
                imprimir(M3);
                salvar("SDK/rem_sudoku01", M3);

            }
            if(strcmp(args[3], "sudoku04") == 0){
                resolver(M4, 0, 0);
                remover(quantidade, M4);
                imprimir(M4);
                salvar("SDK/rem_sudoku01", M4);

            }
            if(strcmp(args[3], "sudoku05") == 0){
                resolver(M5, 0, 0);
                remover(quantidade, M5);
                imprimir(M5);
                salvar("SDK/rem_sudoku05", M5);

            }
            if(strcmp(args[3], "sudoku06") == 0){
                resolver(M6, 0, 0);
                remover(quantidade, M6);
                imprimir(M6);
                salvar("SDK/rem_sudoku06", M6);

            }
            if(strcmp(args[3], "sudoku07") == 0){
                resolver(M7, 0, 0);
                remover(quantidade, M7);
                imprimir(M7);
                salvar("SDK/rem_sudoku07", M7);

            }
            if(strcmp(args[3], "sudoku08") == 0){
                resolver(M8, 0, 0);
                remover(quantidade, M8);
                imprimir(M8);
                salvar("SDK/rem_sudoku08", M8);

            }
            if(strcmp(args[3], "sudoku09") == 0){
                resolver(M9, 0, 0);
                remover(quantidade, M9);
                imprimir(M9);
                salvar("SDK/rem_sudoku09", M9);

            }
            if(strcmp(args[3], "sudoku10") == 0){
                resolver(M10, 0, 0);
                remover(quantidade, M10);
                imprimir(M10);
                salvar("SDK/rem_sudoku10", M10);

            }

        }
        
        else if(strcmp(args[1], "--resolver") == 0){
            if(strcmp(args[2], "sudoku01") == 0){
                resolver(M1, 0, 0);
                imprimir(M1);
                salvar("SDK/sol__sudoku01", M1);

            }
            if(strcmp(args[2], "sudoku02") == 0){
                resolver(M2, 0, 0);
                imprimir(M2);
                salvar("SDK/sol_sudoku02", M2);

            }
            if(strcmp(args[2], "sudoku03") == 0){
                resolver(M3, 0, 0);
                imprimir(M3);
                salvar("SDK/sol_sudoku01", M3);

            }
            if(strcmp(args[2], "sudoku04") == 0){
                resolver(M4, 0, 0);
                imprimir(M4);
                salvar("SDK/sol_sudoku01", M4);

            }
            if(strcmp(args[2], "sudoku05") == 0){
                resolver(M5, 0, 0);
                imprimir(M5);
                salvar("SDK/sol_sudoku05", M5);

            }
            if(strcmp(args[2], "sudoku06") == 0){
                resolver(M6, 0, 0);
                imprimir(M6);
                salvar("SDK/sol_sudoku06", M6);

            }
            if(strcmp(args[2], "sudoku07") == 0){
                resolver(M7, 0, 0);
                imprimir(M7);
                salvar("SDK/sol_sudoku07", M7);

            }
            if(strcmp(args[2], "sudoku08") == 0){
                resolver(M8, 0, 0);
                imprimir(M8);
                salvar("SDK/sol_sudoku08", M8);

            }
            if(strcmp(args[2], "sudoku09") == 0){
                resolver(M9, 0, 0);
                imprimir(M9);
                salvar("SDK/sol_sudoku09", M9);

            }
            if(strcmp(args[2], "sudoku10") == 0){
                resolver(M10, 0, 0);
                imprimir(M10);
                salvar("SDK/sol_sudoku10", M10);

            }

        }
    }
    
   

	return 0;
}