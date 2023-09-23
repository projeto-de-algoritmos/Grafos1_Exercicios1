class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:

        visitados = set()                       # Variavel para guardar os genes que ja foram visitados

        fila = collections.deque()              # Criando uma fila

        # Verificando se o gene final esta no banco de genes
        if endGene is not bank:
            return -1
        
        mutacoes = 0
        
        fila.append((startGene, mutacoes))                 # Adicionando na fila o no inicial
        visitados.add((startGene, mutacoes))               # Adicionando o no inicial nos visitados

        while fila:
            gene, mutacoes = fila.popleft()           # Pegando o gene e seu no na fila
            
            if gene == endGene:                 # Veriicando se o gene eh o final
                return mutacoes                       # Retornando o no (indice do vetor) caso sim
            
            # Verificando as mutacoes
            auxGene = gene.split()          

            for gen in bank:  
                proxGene = gen.split()

                if len(auxGene.difference(proxGene)) < 2 and gen not in visitados:
                    fila.append((gen, mutacoes+1))                  # Adicionando na fila o no inicial
                    visitados.add((gen, mutacoes))                  # Adicionando o no inicial nos visitados
                elif auxGene.difference(proxGene) in 'ACGT':
                    mutacoes = mutacoes + 1

        return -1
