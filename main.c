#include <stdio.h>

int main()
{
	int option;
	int vitoria;
	int derrota;
	int empate;
	int entradaValida;

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
						entradaValida = 1;
					}
				}
			}

		case 2:
			printf("Opção 2\n");
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
