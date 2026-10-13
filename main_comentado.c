#include <stdio.h>

int main(void)
{
    /* ---------- VARIÁVEIS ---------- */

    // Entrada de cada equipe (reaproveitadas a cada equipe do laço for)
    int pontos = 0, vitoria = 0, empate = 0, derrota = 0;

    // Maior e menor pontuação, e o número da PRIMEIRA equipe que atingiu cada uma
    int maiorpont = 0, menorpont = 0, eguipemaior = 0, eguipemenor = 0;

    // Quantas equipes empataram na maior e na menor pontuação
    int empatemaior = 0, empatemenor = 0;

    // Configuração inicial: jogos por equipe e quantidade de equipes
    int jogosegp = 0, quantegp = 0;

    // Acumuladores do campeonato inteiro
    int totalvit = 0, totalemp = 0, totaldert = 0, totalpontos = 0;

    // Contadores de quantas equipes caíram em cada situação
    int totalruim = 0, totalregular = 0, totalboa = 0, totalexcelente = 0;

    // "Flag": 0 = nenhum registro completo ainda, 1 = já existe registro completo
    int registrado = 0;

    // Opção escolhida no menu
    int option;

    /* ---------- CONFIGURAÇÃO INICIAL (com validação) ---------- */
    // while(1) = laço "infinito" que só termina no break, quando AMBOS os
    // valores estão dentro dos limites. Se qualquer um for inválido, repete.
    while(1)
    {
        printf("Quantidade de equipes (3 a 10): ");
        scanf("%d", &quantegp);
        if(quantegp >= 3 && quantegp <= 10)
        {
            printf("Quantidade de jogos disputados por cada equipe (1 a 10): ");
            scanf("%d", &jogosegp);
            if (jogosegp >= 1 && jogosegp <= 10)
            {
                break; // os dois valores são válidos: sai do laço
            }else{
                printf("Valor inválido\n");
            }       
        }else{
            printf("Valor inválido\n");
        }
    }

    /* ---------- MENU PRINCIPAL ---------- */
    // do-while: o menu aparece pelo menos uma vez e repete até option == 5.
    do
    {
        printf("\n=== Sistema de Controle de Campeonato ===\n");
        printf("1......Registrar resultados do campeonato\n");
        printf("2............Mostrar resumo do campeonato\n");
        printf("3.................... Mostrar regulamento\n");
        printf("4..........Simular campanha de uma equipe\n");
        printf("5........................Encerrar sistema\n\n");

        printf("Digite a opcao: ");
        scanf("%d", &option);

        // switch escolhe qual bloco executar conforme a opção digitada
        switch (option) {

            /* ===== OPÇÃO 1: REGISTRAR RESULTADOS ===== */
            case 1:
                // Zera TODOS os acumuladores: assim, ao registrar de novo, o
                // resumo novo substitui o anterior (não soma por cima).
                totalvit = totalemp = totaldert = totalruim = totalregular = totalboa = totalexcelente = totalpontos = empatemaior = empatemenor = 0;

                // PRIMEIRO FOR: percorre as equipes de 1 até a quantidade
                // configurada. "i" é o número da equipe atual.
                for (int i = 1; i <= quantegp; i++) {

                    // WHILE de validação: fica repetindo a leitura dos três
                    // valores até a entrada ser válida (entradaValida = 1).
                    int entradaValida = 0;
                    while (entradaValida == 0)
                    {
                        printf("\nEquipe %d - Vitorias: ", i);
                        scanf("%d", &vitoria);

                        printf("Equipe %d - Empates: ", i);
                        scanf("%d", &empate);

                        printf("Equipe %d - Derrotas: ", i);
                        scanf("%d", &derrota);

                        if (vitoria < 0 || empate < 0 || derrota < 0)
                        {
                            // Regra 1: nenhum valor pode ser negativo
                            printf("Nenhum resultado pode ser negativo.\n");
                        }
                        else if (vitoria + empate + derrota != jogosegp)
                        {
                            // Regra 2: V + E + D tem que dar o total de jogos
                            printf("A soma deve ser igual a %d jogos.\n", jogosegp);
                        }
                        else
                        {
                            entradaValida = 1; // tudo certo: sai do while
                        }
                    }

                    // Cálculo dos pontos: vitória = 3, empate = 1, derrota = 0
                    pontos = (vitoria * 3) + (empate * 1) + (derrota * 0);

                    // Atualiza os acumuladores gerais do campeonato
                    totalvit += vitoria;
                    totalemp += empate;
                    totaldert += derrota;
                    totalpontos += pontos;

                    // Mostra na hora o resultado da equipe atual
                    printf("Equipe %d: %d vitorias, %d empates, %d derrotas\n", i, vitoria, empate, derrota);
                    printf("Pontuação: %d\n", pontos);
                    printf("Situação: ");

                    // Classificação da campanha (if / else if) + contador da
                    // situação correspondente. Só UMA condição é executada.
                    if(pontos < 5)
                    {
                        printf("Campanha ruim!\n");
                        totalruim++;    
                    }
                    else if(pontos >= 5 && pontos <= 9)
                    {
                        printf("Campanha regular!\n");
                        totalregular++;
                    }
                    else if(pontos >= 10 && pontos <= 14)
                    {
                        printf("Boa campanha!\n");
                        totalboa++;
                    }
                    else if(pontos >= 15)
                    {
                        printf("Excelente campanha!\n");
                        totalexcelente++;
                    }

                    // ---- MAIOR E MENOR PONTUAÇÃO (e empates nelas) ----
                    if (i == 1)
                    {
                        // Primeira equipe: ela é ao mesmo tempo a maior e a
                        // menor (não há com quem comparar). Contagem = 1.
                        maiorpont = menorpont = pontos;
                        eguipemaior = eguipemenor = i;
                        empatemaior = empatemenor = 1;
                    }
                    else
                    {
                        // MAIOR
                        if (pontos > maiorpont)
                        {
                            // Novo recorde: guarda valor e número da equipe,
                            // e reinicia a contagem de empatadas em 1.
                            maiorpont = pontos;
                            eguipemaior = i;
                            empatemaior = 1;
                        }
                        else if (pontos == maiorpont)
                        {
                            // Igualou o recorde: só aumenta a contagem.
                            // NÃO troca eguipemaior (fica a PRIMEIRA equipe).
                            empatemaior++;
                        }

                        // MENOR (mesma lógica, invertida)
                        if (pontos < menorpont)
                        {
                            menorpont = pontos;
                            eguipemenor = i;
                            empatemenor = 1;
                        }
                        else if (pontos == menorpont)
                        {
                            empatemenor++;
                        }
                    }
                }
                // Só chega aqui depois de TODAS as equipes serem validadas
                registrado = 1;
                break;

            /* ===== OPÇÃO 2: MOSTRAR RESUMO ===== */
            case 2:
                // Se nunca registrou, não há o que mostrar
                if(registrado == 0)
                {
                    printf("Registre os resultados primeiro.\n");
                }
                else
                {
                    // (float) força divisão decimal; sem isso, int / int
                    // descartaria as casas decimais.
                    float media = (float)totalpontos / quantegp;
                    printf("\n=== Resumo do Campeonato ===\n");
                    printf("Quantidade de equipes: %d\n", quantegp);
                    printf("Quantidade de Jogos por equipe: %d\n", jogosegp);
                    printf("Total de:\n  - %d vitorias\n  - %d empates\n  - %d derrotas\n", totalvit, totalemp, totaldert);
                    printf("Total de pontos: %d\n", totalpontos);
                    printf("Media de pontos: %.2f\n", media); // %.2f = 2 casas
                    printf("Quantidade de equipes em cada situação:\n");
                    printf("  - Excelente: %d\n", totalexcelente);
                    printf("  - Boa: %d\n", totalboa);
                    printf("  - Regular: %d\n", totalregular);
                    printf("  - Ruim: %d\n", totalruim);
                    printf("Maior pontuacao: %d, atingida por: Equipe %d\n", maiorpont, eguipemaior);
                    printf("Menor pontuacao: %d, atingida por: Equipe %d\n", menorpont, eguipemenor);
                    printf("Quantidade de equipes empatadas na maior pontuacao: %d\n", empatemaior);
                    printf("Quantidade de equipes empatadas na menor pontuacao: %d\n", empatemenor);
                }
                break;

            /* ===== OPÇÃO 3: REGULAMENTO ===== */
            // Só imprime texto; pode ser acessada antes de qualquer registro.
            case 3:
                printf("\n=== Regulamento do Campeonato ===\n");
                printf("1. Cada vitória vale 3 pontos.\n");
                printf("2. Cada empate vale 1 ponto.\n");
                printf("3. Derrotas não concedem pontos.\n");
                printf("4. 15 ou mais pontos é considerado uma excelente campanha.\n");
                printf("5. Entre 10 e 14 pontos é considerado uma boa campanha.\n");
                printf("6. Entre 5 e 9 pontos é considerado uma campanha regular.\n");
                printf("7. Menos de 5 pontos é considerado uma campanha ruim.\n");
                printf("8. O campeonato é disputado entre 3 a 10 equipes, cada uma jogando de 1 a 10 partidas.\n");
                break;

            /* ===== OPÇÃO 4: SIMULAR CAMPANHA ===== */
            // As chaves { } do case são necessárias porque declaramos
            // variáveis novas dentro dele.
            case 4:
            {
                // Variáveis SEPARADAS (sim*) para a simulação NÃO mexer nos
                // acumuladores do campeonato: o resumo continua igual.
                int qtdSim = 0, simVit = 0, simEmp = 0, simDer = 0, simPontos = 0;

                // Valida a quantidade de simulações (1 a 5) com while
                printf("Quantas simulações deseja realizar (entre 1 e 5)? ");
                scanf("%d", &qtdSim);
                while (qtdSim < 1 || qtdSim > 5)
                {
                    printf("Valor inválido. Quantas simulações (entre 1 e 5)? ");
                    scanf("%d", &qtdSim);
                }

                // SEGUNDO FOR: uma volta para cada simulação
                for (int s = 1; s <= qtdSim; s++)
                {
                    printf("\n--- Simulação %d ---\n", s);

                    // Mesma validação da opção 1 (não negativo + soma = jogos)
                    int valido = 0;
                    while (valido == 0)
                    {
                        printf("Vitorias: ");
                        scanf("%d", &simVit);

                        printf("Empates: ");
                        scanf("%d", &simEmp);

                        printf("Derrotas: ");
                        scanf("%d", &simDer);

                        if (simVit < 0 || simEmp < 0 || simDer < 0)
                        {
                            printf("Nenhum resultado pode ser negativo. Informe novamente.\n");
                        }
                        else if (simVit + simEmp + simDer != jogosegp)
                        {
                            printf("A soma deve ser igual a %d jogos. Informe novamente.\n", jogosegp);
                        }
                        else
                        {
                            valido = 1;
                        }
                    }

                    // Mesmos pontos e mesma classificação, mas SÓ exibe,
                    // não acumula nada.
                    simPontos = (simVit * 3) + (simEmp * 1) + (simDer * 0);
                    printf("Pontuação: %d pontos\n", simPontos);
                    printf("Situação: ");
                    if (simPontos < 5)
                    {
                        printf("Campanha ruim!\n");
                    }
                    else if (simPontos >= 5 && simPontos <= 9)
                    {
                        printf("Campanha regular!\n");
                    }
                    else if (simPontos >= 10 && simPontos <= 14)
                    {
                        printf("Boa campanha!\n");
                    }
                    else if (simPontos >= 15)
                    {
                        printf("Excelente campanha!\n");
                    }
                }
                break;
            }

            /* ===== OPÇÃO 5: ENCERRAR ===== */
            // Só imprime as mensagens. Quem encerra o programa é a condição
            // do do-while (option != 5) ficar falsa.
            case 5:
                printf("Sistema encerrado com sucesso.\n");
                printf("Obrigado por utilizar o sistema.\n");
                break;

            // Qualquer outro número: erro e volta ao menu
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while(option != 5);

    return 0;
}
