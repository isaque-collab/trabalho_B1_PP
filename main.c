#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	system("chcp 65001 > null");
    setlocale(LC_ALL, "pt-BR.UTF-8");
	
	int option, vitoria, empate, derrota, entradaValida, pontos, totalruim, totalregular, totalboa, totalexcelente;
	int quantegp = 0, jogosegp = 0;

	while (1)
	{
		printf("Quantidade de equipes: ");
		scanf("%d", &quantegp);
		if (quantegp >= 3 && quantegp <= 10)
		{
			break;
		}
		printf("Valor inválido.\n");
	}

	while (1)
	{
		printf("Quantidade de jogos por equipe (1 a 10): ");
		scanf("%d", &jogosegp);
		if (jogosegp >= 1 && jogosegp <= 10)
		{
			break;
		}
		printf("Valor invalido.\n");
	}

	do
	{
		printf("=== Sistema de Controle de Campeonato ===\n");
		printf("1......Registrar resultados do campeonato\n");
		printf("2............Mostrar resumo do campeonato\n");
		printf("3.................... Mostrar regulamento\n");
		printf("4..........Simular campanha de uma equipe\n");
		printf("5........................Encerrar sistema\n\n");

		printf("Digite a opcao: ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			vitoria = 0;
			empate = 0;
			derrota = 0;
			pontos = 0;
			totalruim = 0;
			totalregular = 0;
			totalboa = 0;
			totalexcelente = 0;
			for (int i = 1; i <= quantegp; i++)
			{
				entradaValida = 0;

				while (entradaValida == 0)
				{
					printf("\nEquipe %d - vitorias: ", i);
					scanf("%d", &vitoria);

					printf("Equipe %d - empates: ", i);
					scanf("%d", &empate);

					printf("Equipe %d - derrotas: ", i);
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
						pontos = (vitoria * 3) + (empate * 1) + (derrota * 0);
						printf("Eguipe %d: %d vitorias, %d empates, %d derrotas\n", i, vitoria, empate, derrota);
						printf("Pontuação: %d\n", pontos);
						printf("Situação: ");
						if (pontos < 5)
						{
							printf("Campanha ruim!\n");
							totalruim++;
						}
						else if (pontos >= 5 && pontos <= 9)
						{
							printf("Campanha regular!\n");
							totalregular++;
						}
						else if (pontos >= 10 && pontos <= 14)
						{
							printf("Boa campanha!\n");
							totalboa++;
						}
						else if (pontos >= 15)
						{
							printf("Excelente campanha!\n");
							totalexcelente++;
						}
						entradaValida = 1;
					}
				}
			}
			break;

		case 2:

			break;

		case 3:
			printf("Opção 3\n");
			break;

		case 4:
			printf("Opção 4\n");
			break;

		case 5:
			printf("Encerrando o sistema...\n");
			break;

		default:
			printf("Opção inválida. Tente novamente.\n");
			break;
		}
	} while (option != 5);

	return 0;
}
