/*
 * ==============================================================================
 *  XADREZ - Movimentação das Peças - Nível Mestre
 *  Linguagem: C
 * ==============================================================================
 *
 *  Descrição:
 *      Programa que simula o movimento de quatro peças de xadrez usando
 *      técnicas avançadas de programação:
 *
 *        - Torre:  5 casas para a DIREITA (RECURSIVIDADE)
 *        - Bispo:  5 casas na diagonal CIMA + DIREITA (RECURSIVIDADE + LOOPS ANINHADOS)
 *        - Rainha: 8 casas para a ESQUERDA (RECURSIVIDADE)
 *        - Cavalo: 2 casas CIMA + 1 casa DIREITA (LOOPS COMPLEXOS ANINHADOS)
 *
 *  Conceitos aplicados:
 *      - Funções recursivas (caso base + caso recursivo)
 *      - Loops aninhados com múltiplas variáveis
 *      - Controle de fluxo com continue e break
 *      - Variáveis inteiras para contadores
 *
 * ==============================================================================
 */

#include <stdio.h>

/* ==============================================================================
 *  CONSTANTES
 * ============================================================================== */

#define CASAS_TORRE  5     // Número de casas da Torre
#define CASAS_BISPO  5     // Número de casas do Bispo na diagonal
#define CASAS_RAINHA 8     // Número de casas da Rainha

/* ==============================================================================
 *  PROTÓTIPOS DAS FUNÇÕES RECURSIVAS
 *
 *  Declaramos as funções antes de usá-las para que o compilador
 *  conheça seus parâmetros e tipo de retorno.
 * ==============================================================================
 */

void moverTorreRecursivo(int casas);
void moverBispoRecursivo(int casas);
void moverRainhaRecursiva(int casas);

/* ==============================================================================
 *  FUNÇÃO PRINCIPAL
 * ==============================================================================
 */

int main(void) {

    /*
     * ------------------------------------------------------------------
     *  VARIÁVEIS
     * ------------------------------------------------------------------
     */

    int j;                         // Contador para loops internos
    int passosVerticais   = 2;    // Cavalo: 2 casas para cima
    int passosHorizontais = 1;    // Cavalo: 1 casa para a direita
    int segmento;                 // Controla segmentos do movimento do Cavalo
    int passosCavalo = 0;        // Conta quantos passos o cavalo executou

    /*
     * ==================================================================
     *  TELA INICIAL
     * ==================================================================
     */

    printf("==============================================\n");
    printf("       SIMULAÇÃO DE XADREZ\n");
    printf("       Nível Mestre - Movimentos Complexos\n");
    printf("==============================================\n\n");

    /*
     * ==================================================================
     *  1. TORRE - Movimento: 5 casas para a DIREITA
     *
     *  Técnica: RECURSIVIDADE
     *
     *  Uma função recursiva é aquela que CHAMA A SI MESMA.
     *  Para funcionar corretamente, toda função recursiva precisa de:
     *
     *    1. CASO BASE: condição que PARA a recursão (impede loop infinito)
     *       → if (casas <= 0) return;
     *
     *    2. CASO RECURSIVO: chamada da função com um valor MENOR
     *       → moverTorreRecursivo(casas - 1);
     *
     *  Fluxo para 5 casas (casa = 5):
     *    moverTorreRecursivo(5) → imprime "Direita" → chama(4)
     *    moverTorreRecursivo(4) → imprime "Direita" → chama(3)
     *    moverTorreRecursivo(3) → imprime "Direita" → chama(2)
     *    moverTorreRecursivo(2) → imprime "Direita" → chama(1)
     *    moverTorreRecursivo(1) → imprime "Direita" → chama(0)
     *    moverTorreRecursivo(0) → casas <= 0 → RETORNA (fim)
     *
     * ==================================================================
     */

    printf("--- Movimento da Torre (Recursivo) ---\n");
    printf("Direção: Direita | Casas: %d\n\n", CASAS_TORRE);

    moverTorreRecursivo(CASAS_TORRE);

    printf("\n");

    /*
     * ==================================================================
     *  2. BISPO - Movimento: 5 casas na diagonal (CIMA + DIREITA)
     *
     *  Técnica: RECURSIVIDADE + LOOPS ANINHADOS
     *
     *  A função recursiva controla quantas casas diagonais o Bispo
     *  percorre. Dentro de cada chamada recursiva, usamos LOOPS
     *  ANINHADOS para separar o movimento vertical e horizontal:
     *
     *    Loop EXTERNO (for): controla o movimento VERTICAL (Cima)
     *    Loop INTERNO (for): controla o movimento HORIZONTAL (Direita)
     *
     *  Essa estrutura demonstra que recursão e loops podem
     *  ser combinados para criar movimentos mais complexos.
     *
     *  Fluxo para 5 casas:
     *    moverBispoRecursivo(5)
     *      → for externo: "Cima"
     *        → for interno: "Direita"
     *      → chama moverBispoRecursivo(4)
     *      → chama moverBispoRecursivo(3)
     *      → ... até moverBispoRecursivo(0) que retorna
     *
     * ==================================================================
     */

    printf("--- Movimento do Bispo (Recursivo + Loops Aninhados) ---\n");
    printf("Direção: Cima, Direita (diagonal) | Casas: %d\n\n", CASAS_BISPO);

    moverBispoRecursivo(CASAS_BISPO);

    printf("\n");

    /*
     * ==================================================================
     *  3. RAINHA - Movimento: 8 casas para a ESQUERDA
     *
     *  Técnica: RECURSIVIDADE
     *
     *  Mesma lógica da Torre, mas com 8 casas para a esquerda.
     *
     *  Fluxo para 8 casas (casa = 8):
     *    moverRainhaRecursiva(8) → imprime "Esquerda" → chama(7)
     *    moverRainhaRecursiva(7) → imprime "Esquerda" → chama(6)
     *    ...
     *    moverRainhaRecursiva(1) → imprime "Esquerda" → chama(0)
     *    moverRainhaRecursiva(0) → casas <= 0 → RETORNA (fim)
     *
     * ==================================================================
     */

    printf("--- Movimento da Rainha (Recursivo) ---\n");
    printf("Direção: Esquerda | Casas: %d\n\n", CASAS_RAINHA);

    moverRainhaRecursiva(CASAS_RAINHA);

    printf("\n");

    /*
     * ==================================================================
     *  4. CAVALO - Movimento: 2 casas CIMA + 1 casa DIREITA
     *
     *  Técnica: LOOPS COMPLEXOS ANINHADOS
     *
     *  O Cavalo se move em "L". Neste nível mestre, usamos:
     *    - Loops aninhados com MÚLTIPLAS VARIÁVEIS
     *    - Comando CONTINUE para pular iterações
     *    - Comando BREAK para sair de loops precocemente
     *
     *  Estrutura:
     *
     *    for (segmento = 0; segmento < 2; segmento++) {
     *
     *        if (segmento == 0) {          ← PRIMEIRO SEGMENTO
     *            for (j = 0; j < 2; j++) { ← Loop interno: 2 Cima
     *                printf("Cima\n");
     *            }
     *            continue;                 ← Pula para próximo segmento
     *        }
     *
     *        for (j = 0; j < 1; j++) {     ← SEGUNDO SEGMENTO
     *            printf("Direita\n");
     *            break;                    ← Sai após 1 casa
     *        }
     *    }
     *
     *  Fluxo detalhado:
     *    1. segmento = 0 → entra no if
     *    2. j = 0 → imprime "Cima"
     *    3. j = 1 → imprime "Cima"
     *    4. j = 2 → sai do loop interno
     *    5. continue → volta ao loop externo (ignora o resto)
     *    6. segmento = 1 → NÃO entra no if
     *    7. j = 0 → imprime "Direita"
     *    8. break → sai do loop interno
     *    9. segmento = 2 → sai do loop externo
     *
     *  Resultado: "Cima", "Cima", "Direita" → movimento em L!
     * ==================================================================
     */

    printf("--- Movimento do Cavalo (Loops Complexos) ---\n");
    printf("Direção: 2 Cima + 1 Direita (movimento em L)\n\n");

    /*
     *  Loop EXTERNO: controla os segmentos do movimento L
     *  segmento 0 = parte vertical (Cima)
     *  segmento 1 = parte horizontal (Direita)
     */
    for (segmento = 0; segmento < 2; segmento++) {

        /*
         *  PRIMEIRO SEGMENTO: movimento vertical (2 casas para cima)
         *  Usamos um loop interno com j para contar cada casa.
         *  A variável passosCavalo rastreia o total de passos dados.
         */
        if (segmento == 0) {
            for (j = 0; j < passosVerticais; j++) {
                printf("Cima\n");
                passosCavalo++;

                /*
                 *  Segurança: se por algum motivo excedermos
                 *  o total esperado, usamos break para sair.
                 */
                if (passosCavalo >= 3) {
                    break;
                }
            }

            /*
             *  CONTINUE: pula para a próxima iteração do loop externo.
             *  Isso garante que o código do segundo segmento (Direita)
             *  NÃO seja executado quando segmento == 0.
             *  É como dizer "terminei este segmento, vá para o próximo".
             */
            continue;
        }

        /*
         *  SEGUNDO SEGMENTO: movimento horizontal (1 casa para a direita)
         *  Usamos um loop interno que poderia ter mais iterações,
         *  mas usamos BREAK para sair após a primeira casa.
         */
        for (j = 0; j < passosHorizontais; j++) {
            printf("Direita\n");
            passosCavalo++;

            /*
             *  BREAK: sai imediatamente do loop interno.
             *  Mesmo que o loop pudesse continuar (j < passosHorizontais),
             *  o break força a saída. Isso é útil quando queremos
             *  interromper um loop antes que a condição natural termine.
             */
            break;
        }
    }

    printf("\n");
    printf("==============================================\n");
    printf("     Movimentação concluída com sucesso!\n");
    printf("==============================================\n\n");

    return 0;
}

/* ==============================================================================
 *  FUNÇÕES RECURSIVAS
 * ==============================================================================
 */

/*
 * ==============================================================================
 *  FUNÇÃO: moverTorreRecursivo
 *
 *  Simula o movimento da Torre usando RECURSIVIDADE.
 *  A cada chamada, imprime "Direita" e chama a si mesma
 *  com uma casa a menos, até chegar a zero (caso base).
 *
 *  Parâmetro:
 *    casas - número restante de casas a percorrer
 *
 *  Caso base:     casas <= 0 → para a recursão
 *  Caso recursivo: imprime "Direita" e chama com (casas - 1)
 * ==============================================================================
 */
void moverTorreRecursivo(int casas) {
    /*
     *  CASO BASE: quando casas chega a 0 (ou menos), paramos.
     *  Sem o caso base, a função chamaria a si mesma infinitamente,
     *  causando um estouro de pilha (stack overflow).
     */
    if (casas <= 0) {
        return;
    }

    /* Imprime a direção desta casa */
    printf("Direita\n");

    /*
     *  CASO RECURSIVO: chama a função novamente com UMA CASA A MENOS.
     *  Cada chamada empilha um novo frame na pilha de execução.
     *  Quando o caso base é atingido, as chamadas retornam em ordem
     *  reversa (como uma pilha de pratos).
     */
    moverTorreRecursivo(casas - 1);
}

/*
 * ==============================================================================
 *  FUNÇÃO: moverBispoRecursivo
 *
 *  Simula o movimento do Bispo usando RECURSIVIDADE + LOOPS ANINHADOS.
 *  A recursão controla quantas casas diagonais o Bispo percorre.
 *  Dentro de cada chamada recursiva, loops aninhados controlam
 *  o movimento vertical e horizontal separadamente.
 *
 *  Parâmetro:
 *    casas - número restante de casas diagonais a percorrer
 *
 *  Estrutura dos loops aninhados:
 *    Loop EXTERNO (for, i): movimento vertical → "Cima"
 *    Loop INTERNO (for, j): movimento horizontal → "Direita"
 *
 *  Cada combinação (Cima + Direita) forma UMA casa diagonal.
 * ==============================================================================
 */
void moverBispoRecursivo(int casas) {
    int i, j;  /* Variáveis contadoras para os loops aninhados */

    /* CASO BASE: para quando não há mais casas a percorrer */
    if (casas <= 0) {
        return;
    }

    /*
     *  LOOPS ANINHADOS: simulam UMA casa na diagonal
     *
     *  O loop EXTERNO controla o movimento VERTICAL (Cima).
     *  O loop INTERNO controla o movimento HORIZONTAL (Direita).
     *
     *  Cada loop executa apenas 1 iteração por chamada recursiva,
     *  formando assim uma casa diagonal (Cima + Direita).
     *  A soma das chamadas recursivas cria o efeito diagonal completo.
     *
     *  Por que usar loops com apenas 1 iteração?
     *  Porque a estrutura demonstra o padrão de loops aninhados
     *  (vertical controlando horizontal), que seria útil se o
     *  Bispo precisasse mover, por exemplo, 3 casas para cima
     *  e 2 para a direita em cada passo diagonal.
     */
    for (i = 0; i < 1; i++) {         /* Loop EXTERNO: vertical (Cima) */
        printf("Cima\n");
        for (j = 0; j < 1; j++) {     /* Loop INTERNO: horizontal (Direita) */
            printf("Direita\n");
        }
    }

    /* CASO RECURSIVO: chama com uma casa diagonal a menos */
    moverBispoRecursivo(casas - 1);
}

/*
 * ==============================================================================
 *  FUNÇÃO: moverRainhaRecursiva
 *
 *  Simula o movimento da Rainha usando RECURSIVIDADE.
 *  A cada chamada, imprime "Esquerda" e chama a si mesma
 *  com uma casa a menos, até chegar a zero (caso base).
 *
 *  Parâmetro:
 *    casas - número restante de casas a percorrer
 *
 *  Caso base:     casas <= 0 → para a recursão
 *  Caso recursivo: imprime "Esquerda" e chama com (casas - 1)
 * ==============================================================================
 */
void moverRainhaRecursiva(int casas) {
    /* CASO BASE: para a recursão */
    if (casas <= 0) {
        return;
    }

    /* Imprime a direção desta casa */
    printf("Esquerda\n");

    /* CASO RECURSIVO: chama com uma casa a menos */
    moverRainhaRecursiva(casas - 1);
}
