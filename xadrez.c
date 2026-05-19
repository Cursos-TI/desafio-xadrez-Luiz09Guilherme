/*
 * ==============================================================================
 *  XADREZ - Movimentação das Peças - Nível Novato
 *  Linguagem: C
 * ==============================================================================
 *
 *  Descrição:
 *      Programa que simula o movimento de três peças de xadrez:
 *        - Torre: 5 casas para a DIREITA (usando for)
 *        - Bispo: 5 casas na diagonal CIMA + DIREITA (usando while)
 *        - Rainha: 8 casas para a ESQUERDA (usando do-while)
 *
 *  Conceitos aplicados:
 *      - Estruturas de repetição: for, while, do-while
 *      - Variáveis inteiras para contadores
 *      - printf para exibição das direções
 *
 * ==============================================================================
 */

#include <stdio.h>

/* ==============================================================================
 *  FUNÇÃO PRINCIPAL
 * ============================================================================== */

int main(void) {

    /*
     * ------------------------------------------------------------------
     *  VARIÁVEIS
     *
     *  Usamos apenas variáveis do tipo inteiro (int) conforme solicitado.
     *  Cada variável armazena o número de casas que a peça vai percorrer.
     * ------------------------------------------------------------------
     */

    int casasTorre = 5;    // Torre move 5 casas
    int casasBispo = 5;    // Bispo move 5 casas
    int casasRainha = 8;   // Rainha move 8 casas
    int i;                 // Variável contadora usada nos loops

    /*
     * ==================================================================
     *  TELA INICIAL
     * ==================================================================
     */

    printf("==============================================\n");
    printf("       SIMULAÇÃO DE XADREZ\n");
    printf("       Movimentação das Peças\n");
    printf("==============================================\n\n");

    /*
     * ==================================================================
     *  1. TORRE - Movimento: 5 casas para a DIREITA
     *
     *  Estrutura utilizada: FOR
     *
     *  O laço for é ideal quando sabemos EXATAMENTE quantas vezes
     *  queremos repetir algo. Sua sintaxe em três partes:
     *    1. Inicialização: i = 0 (começa do zero)
     *    2. Condição:      i < 5 (repete enquanto i for menor que 5)
     *    3. Incremento:    i++ (aumenta 1 a cada volta)
     *
     *  A cada iteração, o printf imprime "Direita", simulando
     *  o movimento da torre casa por casa para a direita.
     * ==================================================================
     */

    printf("--- Movimento da Torre ---\n");
    printf("Direção: Direita | Casas: %d\n\n", casasTorre);

    /*
     *  for (inicialização; condição; incremento)
     *  Executa o bloco 5 vezes: i = 0, 1, 2, 3, 4
     */
    for (i = 0; i < casasTorre; i++) {
        printf("Direita\n");
    }

    printf("\n");

    /*
     * ==================================================================
     *  2. BISPO - Movimento: 5 casas na diagonal (CIMA + DIREITA)
     *
     *  Estrutura utilizada: WHILE
     *
     *  O laço while é ideal quando queremos repetir algo enquanto
     *  uma condição for verdadeira. Diferente do for, a inicialização
     *  e o incremento são feitos MANUALMENTE dentro ou fora do bloco.
     *
     *  Sintaxe:
     *    1. Inicializamos i = 0 ANTES do while
     *    2. O while verifica: i < 5 ?
     *    3. Dentro do bloco: fazemos algo E incrementamos i++
     *    4. Volta ao passo 2 até a condição ser falsa
     *
     *  Como o bispo se move na diagonal, cada casa combina duas
     *  direções: "Cima" e "Direita".
     * ==================================================================
     */

    printf("--- Movimento do Bispo ---\n");
    printf("Direção: Cima, Direita (diagonal) | Casas: %d\n\n", casasBispo);

    /* Inicialização da variável contadora (feito manualmente) */
    i = 0;

    /*
     *  while (condição)
     *  Repete enquanto i for menor que casasBispo (5)
     *  Precisamos incrementar i++ DENTRO do bloco!
     */
    while (i < casasBispo) {
        printf("Cima\n");
        printf("Direita\n");
        i++;   /* Incremento manual - sem isso, loop infinito! */
    }

    printf("\n");

    /*
     * ==================================================================
     *  3. RAINHA - Movimento: 8 casas para a ESQUERDA
     *
     *  Estrutura utilizada: DO-WHILE
     *
     *  O laço do-while é ideal quando queremos que o bloco execute
     *  PELO MENOS UMA VEZ, mesmo que a condição já seja falsa.
     *  A diferença do while é que a condição é verificada DEPOIS.
     *
     *  Sintaxe:
     *    1. Executa o bloco (pelo menos 1 vez)
     *    2. Verifica a condição: i < 8 ?
     *    3. Se verdadeiro, volta ao passo 1
     *    4. Se falso, sai do loop
     *
     *  A rainha se move em todas as direções, mas aqui simulamos
     *  apenas 8 casas para a esquerda.
     * ==================================================================
     */

    printf("--- Movimento da Rainha ---\n");
    printf("Direção: Esquerda | Casas: %d\n\n", casasRainha);

    /* Inicialização da variável contadora */
    i = 0;

    /*
     *  do { ... } while (condição);
     *  Executa o bloco primeiro, DEPOIS verifica a condição.
     *  Garante pelo menos 1 execução do bloco.
     */
    do {
        printf("Esquerda\n");
        i++;   /* Incremento manual */
    } while (i < casasRainha);

    printf("\n");
    printf("==============================================\n");
    printf("     Movimentação concluída com sucesso!\n");
    printf("==============================================\n\n");

    return 0;
}
