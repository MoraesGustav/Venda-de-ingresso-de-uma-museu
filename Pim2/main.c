#include <stdio.h>
#include <stdlib.h>

#define MAX_INGRESSOS 400
#define PRECO_INTEIRA 60.00
#define PRECO_MEIA 30.00
#define PRECO_GRATIS 0.00

int main() {
    int ingressosDisponiveis = MAX_INGRESSOS;
    int opcao, ingressosComprados, formaPagamento, totalIngressosVendidos = 0;
    double faturamentoTotal = 0.0;

    // Apresentação
    printf("\t============================================================\n");
    printf("\t===================== MUSEU DA UNIP ========================\n");
    printf("\t============================================================\n");
    printf("\tUMA VIAGEM PELA HISTORIA DO MUSEU A OBRAS DE VAN GOGH\n");
    printf("\t------------------------------------------------------------\n");

    do {
        printf("\t[1] VENDA DE INGRESSOS\n");
        printf("\t[2] FATURAMENTO\n");
        printf("\t[0] SAIR\n");
        printf("\nIngressos disponíveis: %d\n", ingressosDisponiveis);
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch(opcao) {
            case 1: // Venda de ingressos
                printf("\t----------------------------------\n");
                printf("\tEscolha uma sessão:\n");
                printf("\t[1] Sessão 12:30 hrs\n");
                printf("\t[2] Sessão 16:00 hrs\n");
                printf("\t[3] Sessão 19:00 hrs\n");
                printf("\t----------------------------------\n");

                int secao;
                scanf("%d", &secao);

                printf("\tInforme quantos bilhetes deseja comprar (máx. 20): ");
                scanf("%d", &ingressosComprados);

                if (ingressosComprados > 20 || ingressosComprados > ingressosDisponiveis) {
                    printf("\tNúmero de ingressos inválido ou não há ingressos disponíveis.\n");
                    break;
                }

                // Escolher forma de pagamento
                printf("\t----------------------------------\n");
                printf("\t FORMAS DE PAGAMENTO\n");
                printf("\t[1] Inteira: R$ %.2f\n", PRECO_INTEIRA);
                printf("\t[2] Meia (Estudante ou Idoso): R$ %.2f\n", PRECO_MEIA);
                printf("\t[3] Grátis (Crianças menores de 5 anos): R$ %.2f\n", PRECO_GRATIS);
                printf("\t----------------------------------\n");
                scanf("%d", &formaPagamento);

                // Atualiza o faturamento e a quantidade de ingressos vendidos
                double preco = 0.0;
                switch(formaPagamento) {
                    case 1:
                        preco = PRECO_INTEIRA;
                        printf("\tPagamento: INTEIRA\n");
                        break;
                    case 2:
                        preco = PRECO_MEIA;
                        printf("\tPagamento: MEIA\n");
                        break;
                    case 3:
                        preco = PRECO_GRATIS;
                        printf("\tPagamento: GRÁTIS\n");
                        break;
                    default:
                        printf("\tForma de pagamento inválida.\n");
                        continue; // Retorna ao início do loop
                }

                // Calcula o total a pagar
                double totalAPagar = preco * ingressosComprados;
                printf("\t----------------------------------\n");
                printf("\tTotal a pagar: R$ %.2f\n", totalAPagar);
                printf("\tDeseja finalizar a compra? (1: Sim / 0: Não): ");
                int finalizar;
                scanf("%d", &finalizar);

                if (finalizar == 1) {
                    // Atualiza os dados
                    ingressosDisponiveis -= ingressosComprados;
                    totalIngressosVendidos += ingressosComprados;
                    faturamentoTotal += totalAPagar;

                    printf("\tSessão %d - OBRAS DE VAN GOGH\n", (secao == 1) ? 12 : (secao == 2) ? 16 : 19);
                    printf("\tTenha uma boa experiência! Agradecemos a preferência.\n");
                } else {
                    printf("\tCompra cancelada.\n");
                }
                break;

            case 2: // Faturamento
                printf("\t----------------------------------\n");
                printf("\t FATURAMENTO DE INGRESSOS VENDIDOS\n");
                printf("\tTotal de ingressos vendidos: %d\n", totalIngressosVendidos);
                printf("\tFaturamento total: R$ %.2f\n", faturamentoTotal);
                break;

            case 0: // Sair
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
