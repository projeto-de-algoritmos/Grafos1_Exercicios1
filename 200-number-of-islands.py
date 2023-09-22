class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        visitados = set()                       # Variavel para guardar os nos que ja foram visitados
        quantIlhas = 0                          # Variavel para guardar a quant. de ilhas

        # Verificando se o grid dado esta vazio
        if not grid:
            return 0                            # Retornando zero ilhas caso sim 
        
        # Caso nao, pegando a quantidade de linhas e colunas da matriz
        # guardando em 'linhas' e 'colunas' respectivamente
        linhas, colunas = len(grid), len(grid[0])

        def bfs(i, j):
            fila = collections.deque()          # Criando uma fila
            fila.append((i, j))                 # Adicionando na fila o no
            visitados.add((i, j))               # Marcando as coordenadas do no, como visitadas

            while fila:
                lin, col = fila.popleft()
                movimentos = [1, -1]
                for mov in movimentos:
                    # Verificando os visinhos de cima e baixo
                    tempLinha = lin + mov
                    if (tempLinha, col) not in visitados and tempLinha in range(linhas) and grid[tempLinha][col] == "1":
                        fila.append((tempLinha, col))
                        visitados.add((tempLinha, col))
                    # Verificando os visinhos da esquerda e direita
                    tempCol = col + mov
                    if (lin, tempCol) not in visitados and tempCol in range(colunas) and grid[lin][tempCol] == "1":
                        fila.append((lin, tempCol))
                        visitados.add((lin, tempCol))

        # Percorrendo a matriz
        for i in range(linhas):
            for j in range(colunas):
                # Verificando se o elemento ja foi visitado e se o valor do elemento eh 1
                if (i, j) not in visitados and grid[i][j] == "1":
                    bfs(i, j)       # Realizando busca em largura para marcar todos os nos 1's como visitados
                    quantIlhas += 1      # Incrementando a qtd de ilhas

        return quantIlhas
