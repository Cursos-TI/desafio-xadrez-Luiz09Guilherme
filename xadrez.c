/*
 * ==============================================================================
 *  XADREZ - Movimentação das Peças - Nível Aventureiro
 *  Linguagem: C
 * ==============================================================================
 *
 *  Descrição:
 *      Programa que simula o movimento de quatro peças de xadrez:
 *        - Torre:  5 casas para a DIREITA (usando for)
 *        - Bispo:  5 casas na diagonal CIMA + DIREITA (usando while)
 *        - Rainha: 8 casas para a ESQUERDA (usando do-while)
 *        - Cavalo: 2 casas para BAIXO + 1 casa para ESQUERDA (usando for + while aninhados)
 *
 *  Conceitos aplicados:
 *      - Estruturas de repetição: for, while, do-while
 *      - Loops aninhados (um loop dentro de outro)
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
     * ------------------------------------------------------------------
     */

    int casasTorre = 5;      // Torre move 5 casas para a direita
    int casasBispo = 5;      // Bispo move 5 casas na diagonal
    int casasRainha = 8;     // Rainha move 8 casas para a esquerda
    int passosVerticais = 2; // Cavalo: 2 casas para baixo (parte vertical do L)
    int passosHorizontais = 1; // Cavalo: 1 casa para a esquerda (parte horizontal do L)
    int i;                   // Variável contadora (loop externo)
    int j;                   // Variável contadora (loop interno / aninhado)

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
     * ==================================================================
     */

    printf("--- Movimento da Torre ---\n");
    printf("Direção: Direita | Casas: %d\n\n", casasTorre);

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
     *  O laço while repete enquanto a condição for verdadeira.
     *  A inicialização e o incremento são feitos MANUALMENTE.
     * ==================================================================
     */

    printf("--- Movimento do Bispo ---\n");
    printf("Direção: Cima, Direita (diagonal) | Casas: %d\n\n", casasBispo);

    i = 0;

    while (i < casasBispo) {
        printf("Cima\n");
        printf("Direita\n");
        i++;
    }

    printf("\n");

    /*
     * ==================================================================
     *  3. RAINHA - Movimento: 8 casas para a ESQUERDA
     *
     *  Estrutura utilizada: DO-WHILE
     *
     *  O laço do-while garante pelo menos 1 execução do bloco,
     *  pois a condição é verificada DEPOIS.
     * ==================================================================
     */

    printf("--- Movimento da Rainha ---\n");
    printf("Direção: Esquerda | Casas: %d\n\n", casasRainha);

    i = 0;

    do {
        printf("Esquerda\n");
        i++;
    } while (i < casasRainha);

    printf("\n");

    /*
     * ==================================================================
     *  4. CAVALO - Movimento: 2 casas para BAIXO + 1 casa ESQUERDA
     *
     *  O Cavalo se move em "L": duas casas em uma direção e depois
     *  uma casa perpendicularmente. Neste caso:
     *    - 2 casas para BAIXO (parte vertical do L)
     *    - 1 casa para ESQUERDA (parte horizontal do L)
     *
     *  Estrutura utilizada: LOOPS ANINHADOS (for + while)
     *
     *  LOOPS ANINHADOS são loops DENTRO de outros loops.
     *  O loop externo controla a "macro" repetição (cada salto em L),
     *  e o loop interno controla a "micro" repetição (cada casa
     *  dentro de um segmento do movimento).
     *
     *  Estrutura:
     *
     *    for (i = 0; i < 1; i++) {          ← Loop EXTERNO (for)
     *        while (j < 2) {                ← Loop INTERNO (while)
     *            printf("Baixo\n");         ← 2 casas para baixo
     *            j++;
     *        }
     *        printf("Esquerda\n");           ← 1 casa para esquerda
     *    }
     *
     *  Fluxo de execução:
     *    1. for: i = 0, condição (0 < 1) é verdadeira → entra no bloco
     *    2. while: j = 0, condição (0 < 2) é verdadeira → imprime "Baixo", j = 1
     *    3. while: j = 1, condição (1 < 2) é verdadeira → imprime "Baixo", j = 2
     *    4. while: j = 2, condição (2 < 2) é FALSA → sai do while
     *    5. Imprime "Esquerda" (fora do while, dentro do for)
     *    6. for: i = 1, condição (1 < 1) é FALSA → sai do for
     *
     *  Resultado: "Baixo", "Baixo", "Esquerda" → movimento em L completo!
     * ==================================================================
     */

    printf("--- Movimento do Cavalo ---\n");
    printf("Direção: 2 Baixo + 1 Esquerda (movimento em L)\n\n");

    /*
     *  Loop EXTERNO: for
     *  Controla cada salto em L do cavalo.
     *  Neste caso, executamos apenas 1 salto, mas a estrutura
     *  permite facilmente repetir múltiplos saltos alterando
     *  o valor da condição.
     */
    for (i = 0; i < 1; i++) {

        /*
         *  Loop INTERNO: while
         *  Controla a parte vertical do L (2 casas para baixo).
         *  O loop while é usado aqui para mostrar que é possível
         *  combinar diferentes tipos de loops em estruturas aninhadas.
         */
        j = 0;
        while (j < passosVerticais) {
            printf("Baixo\n");
            j++;
        }

        /*
         *  Parte horizontal do L
         *  Não usamos loop aqui pois é apenas 1 casa,
         *  mas poderíamos usar outro loop se fosse mais casas.
         *  A variável passosHorizontais define essa quantidade.
         */
        j = 0;
        while (j < passosHorizontais) {
            printf("Esquerda\n");
            j++;
        }
    }

    printf("\n");
    printf("==============================================\n");
    printf("     Movimentação concluída com sucesso!\n");
    printf("==============================================\n\n");

    return 0;
}
