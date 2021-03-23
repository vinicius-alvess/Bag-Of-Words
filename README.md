# Bag of Words
 <p>
 No arquivo main.c, temos o menu no int main com as opções leitura do dicionário (D).
  * Ler o arquivo de texto A (A)
  * Ler o arquivo de texto B (B), 
  * Exibir o BOW de TRA e TRB (T), 
  * mostrar a similiaridade de dois arquivos (t) 
  * opção de sair (S). 
  Nota que a complexidade Big o = O(1), em que não há crescimento do número de operações, realizada a operação da abertura do menu. A complexidade Big Omega Ω(1) pois é a melhor complexidaade encontrada.
 Na função readDictionary temos a leitura das palavras do dicionário. A sua complexidade é  Big o = O(n), pois o crescimento no número de operações é diretamente proporcional ao crescimento do número de itens. 

No arquivo TRAB.c na função TRA a complexidade é Big o = o(2n), pois na função existe dois laços de repetição em que cada um tem uma complexidade de o(n).
Na função printTokens a complexidade Big o = o(2n), pois na função existe dois laços de repetição em que cada um tem uma complexidade de o(n).
Na countOccurrences a complexidade Big o = o(n²), pois na função existe um um laços de repetição dentro do outro.
Na copyString a complexidade Big o = o(n), pois existe uma laço de repetição com a complexidade o(n).

Na fução TRB a complexidade é Big o = o(2n), pois na função existe dois laços de repetição em que cada um tem uma complexidade de o(n).
 </p>