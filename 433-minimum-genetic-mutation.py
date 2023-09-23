class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:

        visitados = set()                       # Variavel para guardar os genes que ja foram visitados

        fila = collections.deque()              # Criando uma fila

        # Verificando se o gene final esta no banco de genes
        if endGene not in bank:
            return -1
        
        mutacoes = 0
        
        fila.append((startGene, mutacoes))                 # Adicionando na fila o no inicial
        visitados.add((startGene, mutacoes))               # Adicionando o no inicial nos visitados

        while fila:
            gene, mutacoes = fila.popleft()                # Pegando o gene e seu no na fila
            
            if gene == endGene:                            # Veriicando se o gene eh o final
                return mutacoes                            # Retornando o no (indice do vetor) caso sim
            
            # Verificando as mutacoes        
            for gen in bank:
                if gen not in visitados:  

                    dif = [char for char in range(len(gene)) if gene[char] != gen[char]]    #Encontradno os indices das diferencas entre as strings

                    if len(dif) == 1:                      # Se a diferenca for igual a 1, o gene eh filho
                        fila.append((gen, mutacoes+1))     # Adicionando na fila o no inicial
                        visitados.add((gen))               # Adicionando o no inicial nos visitados

        return -1
