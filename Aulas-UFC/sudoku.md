Trabalho 01: SUDOKU

  >> Gerar SUDOKU
  >> Remover celulas do SUDOKU
  >> resolver os sudokus que tiveram celulas removidas.

    REGRAS:
        *1 quadrado GRANDE com 9 quadrados MEDIOS, cada um com 9 quadrados PEQUENOS.

        1. cada quadrado medio deve possuir nove numeros de 1 a 9 (SEM REPETIÇÕES)
        2. cada coluna passa por cima de 3 quadrados medios;
           cada linha passa por cima de 3 quadrados medios;
           temos um total de 9 colunas e 9 linhas;
           NAO é permitido repetir numeros nas linhas e colunas.
        3. Todo sudoko vem preenchido com alguns numeros (ALGUNS NÃO SÃO POSSÍVEIS)
        
    O QUE DEVE SER FEITO:
        1. Gerar sudokos (com todas as casas preenchidas);
           >> n_de_sudokos; 
        2. Remover algumas casas (aleatoriamente ou seguir algum criterio rasoavelmente aleatório);
           >> n_de_casas_removidas
        3. Repreencher o sudoko;
           * caso o sudoko tenha mais de uma solução, deve-se disparar uma excessão.

           ENTRADA:
            * GERAR:
                (nome_do_arquivo) --gerar (nº_de_sudokus)
                sudoku --gerar 10
            * REMOVER (aleatoriamente):
                (nome_do_arquivo) --remover (0 < n_de_casas_removidas < 81) (sudoku_especifico)
                sudoku --remover 27 sudoku_01
            * RESOLVER:
                (nome_do_arquivo) --resolver (sudoku_especifico)
                sudoku --resolver sudoku_01

            PS: para evitar conflito com nome dos arquivos recomenda-se nomear os arquivos que forem manipulados
            EX: sudoku_01 (gerado)
                rem_sudoku_01 (removido)
                sol_sudoku_01 (solucionado)
ai o resumo do vídeo e o que ele pede no trabalho
pelo que eu entendi as matrizes podem ser geradas todas iguais... a randomização vai ser quando for remover as celulas