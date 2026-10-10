#include <stdio.h>

int main(void)
{
    int pontos = 0, vitoria = 0, empate = 0, derrota = 0, maiorpont = 0, menorpont = 0, eguipemaior = 0, eguipemenor = 0;
    int empatemaior = 0, empatemenor = 0, jogosegp = 0, quantegp = 0, totalvit = 0, totalemp = 0, totaldert = 0;
    int totalruim = 0, totalregular = 0, totalboa = 0, totalexcelente = 0, totalpontos = 0, registrado = 0, option;

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
                break;
            }else{
                printf("Valor inválido\n");
            }       
        }else{
            printf("Valor inválido\n");
        }
    }

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

        switch (option) {
            case 1:
                // Reinicia os acumuladores para substituir o registro anterior
                totalvit = totalemp = totaldert = totalruim = totalregular = totalboa = totalexcelente = totalpontos = empatemaior = empatemenor = 0;
                // Primeiro for: percorre todas as equipes configuradas
                for (int i = 1; i <= quantegp; i++) {
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
                            printf("Nenhum resultado pode ser negativo.\n");
                        }
                        else if (vitoria + empate + derrota != jogosegp)
                        {
                            printf("A soma deve ser igual a %d jogos.\n", jogosegp);
                        }
                        else
                        {
                            entradaValida = 1;
                        }
                    }

                    pontos = (vitoria * 3) + (empate * 1) + (derrota * 0);
                    totalvit += vitoria;
                    totalemp += empate;
                    totaldert += derrota;
                    totalpontos += pontos;

                    printf("Equipe %d: %d vitorias, %d empates, %d derrotas\n", i, vitoria, empate, derrota);
                    printf("Pontuação: %d\n", pontos);
                    printf("Situação: ");

                    // if, else if, else para definir a situação da equipe
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

                    // Lógica para maior e menor pontuação
                    if (i == 1)
                    {
                        maiorpont = menorpont = pontos;
                        eguipemaior = eguipemenor = i;
                        empatemaior = empatemenor = 1;
                    }
                    else
                    {
                        if (pontos > maiorpont)
                        {
                            maiorpont = pontos;
                            eguipemaior = i;
                            empatemaior = 1;
                        }
                        else if (pontos == maiorpont)
                        {
                            empatemaior++;
                        }

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
                registrado = 1; // Marca que o registro foi concluído com sucesso
                break;
            case 2:
                if(registrado == 0)
                {
                    printf("Registre os resultados primeiro.\n");
                }
                else
                {
                    float media = (float)totalpontos / quantegp;
                    printf("\n=== Resumo do Campeonato ===\n");
                    printf("Quantidade de equipes: %d\n", quantegp);
                    printf("Quantidade de Jogos por equipe: %d\n", jogosegp);
                    printf("Total de:\n  - %d vitorias\n  - %d empates\n  - %d derrotas\n", totalvit, totalemp, totaldert);
                    printf("Total de pontos: %d\n", totalpontos);
                    printf("Media de pontos: %.2f\n", media);
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
            case 4:
            {
                int qtdSim = 0, simVit = 0, simEmp = 0, simDer = 0, simPontos = 0;

                printf("Quantas simulações deseja realizar (entre 1 e 5)? ");
                scanf("%d", &qtdSim);
                while (qtdSim < 1 || qtdSim > 5)
                {
                    printf("Valor inválido. Quantas simulações (entre 1 e 5)? ");
                    scanf("%d", &qtdSim);
                }

                // Segundo for: realiza as simulações
                for (int s = 1; s <= qtdSim; s++)
                {
                    printf("\n--- Simulação %d ---\n", s);

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
            case 5:
                printf("Sistema encerrado com sucesso.\n");
                printf("Obrigado por utilizar o sistema.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while(option != 5);

    return 0;
}