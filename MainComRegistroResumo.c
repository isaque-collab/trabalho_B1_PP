
/*
Grupo

Nome 1: Guilherme Henrique Mascena de Sousa
Nome 2: *
Nome 3: *
*/

/*

O registro do campeonato e resumo estão feitos, o restante simulação e regulamento é com vocês

Aviso:
Na hora de declarar novas variaveis, evite abreviar, use camelCase e escreva em portugues para facilitar entendimento do grupo.
Além disso, sempre comente nos códigos para falar o que cada parte faz

"8. Organização e entrega:
• Inclua os nomes dos três integrantes em um comentário inicial.
• Entregue o código-fonte completo em um arquivo .c.
• Comente as principais partes e use nomes de variáveis relacionados à sua função.
• Todos os integrantes deverão conhecer o funcionamento do programa completo."
*/


#include <stdio.h>

int main()
{   
    //Variaveis condicionais e loops
	int option; // opções do menu de 1 a 5
	int entradaValida; // validador
    int registroCompleto = 0; // variavel se o registro foi feito ou nao

    //Variaveis de Registros
	int vitoria, derrota, empate, pontuacao;// resultado
	int quantidadeEquipe = 0, quantidadeJogos = 0; // quantidade de equipes e quantidade de jogos

    //Variaveis de Resumo
    int quantidadeExcelente, quantidadeBoa, quantidadeRegular, quantidadeRuim; // quantidade de situações entre as equipes
    int totalVitoria, totalDerrota, totalEmpate; // quantidade de vitorias, derrotas e empates 
    int totalPontuacao; // total da pontuação do campeonato
    float mediaPontuacao; // media da pontuação do campeonato
    int equipeMaiorPontuacao, equipeMenorPontuacao; // equipes que tem menor e maior pontuação
    int maiorPontuacao, menorPontuacao, empatadosMaior, empatadosMenor; // maior quantidade de pontos e a menor e empates


    // Entrada da quantidade de equipes
    printf("===== Sistema de Controle de Campeonato ====\n\n");
    printf("------------------------------------------------------------- \n"); //decorativo
    printf("-> Digite a quantidade de equipes do campeonato\n");
	while (1)
	{
		printf("-> Quantidade de equipes (3 a 10): ");
		scanf("%d", &quantidadeEquipe);
		if (quantidadeEquipe >= 3 && quantidadeEquipe <= 10)
		{
			break;
		}
		printf("Quantidade de equipe insuficiente ou invalido.\n");
	}
    printf("------------------------------------------------------------- \n"); //decorativo
    // Entrada da quantidade de jogos
    printf("-> Digite a quantidade de jogos do campeonato\n");
	while (1)
	{
		printf("-> Quantidade de jogos por equipe (1 a 10): ");
		scanf("%d", &quantidadeJogos);
		if (quantidadeJogos >= 1 && quantidadeJogos <= 10)
		{
			break;
		}
		printf("Quantidade de jogos insuficiente ou invalido.\n");
	}
    printf("------------------------------------------------------------- \n"); //decorativo

    // Menu na Estrutura em Loop
	do
	{
		printf("\n=== Menu do Sistema de Controle de Campeonato ===\n");
		printf("1..............Registrar resultados do campeonato\n");
		printf("2....................Mostrar resumo do campeonato\n");
		printf("3............................ Mostrar regulamento\n");
		printf("4..................Simular campanha de uma equipe\n");
		printf("5................................Encerrar sistema\n\n");

		printf("Digite a opcao: ");
		scanf("%d", &option);

		switch (option)
		{

        //Registro do campeonato
		case 1:

            //Caso um novo registro seja feito, o resumo anterior não será valido
            registroCompleto = 0;

            //Reset dos valores das variaveis, caso um novo registro seja feito
            pontuacao = 0;
            quantidadeExcelente = 0;
            quantidadeBoa = 0;
            quantidadeRegular = 0;
            quantidadeRuim = 0;
            totalVitoria = 0;
            totalEmpate = 0;
            totalDerrota = 0;
            totalPontuacao = 0;
            mediaPontuacao = 0;
            maiorPontuacao = 0;
            menorPontuacao = 0;
            equipeMaiorPontuacao = 0;
            equipeMenorPontuacao = 0;
            empatadosMaior = 0;
            empatadosMenor = 0;


            //Laço de repetição
            printf("------------------------------------------------------------- \n");  //decorativo
			for (int i = 1; i <= quantidadeEquipe; i++){
				entradaValida = 0;

                //Entrada dos resultados
				while (entradaValida == 0){

					printf("Digite a quantidade de vitorias da Equipe %d: ", i);
					scanf("%d", &vitoria);
                    
					printf("Digite a quantidade de empates da Equipe %d: ", i);
					scanf("%d", &empate);
                    
					printf("Digite a quantidade de derrotas da Equipe %d: ", i);
					scanf("%d", &derrota);
                    
                    //Validação dos jogos
					if (vitoria < 0 || empate < 0 || derrota < 0){
                        printf("------------------------------------------------------------- \n");  //decorativo
						printf("         Nenhum resultado pode ser negativo.\n");
                        printf("------------------------------------------------------------- \n");  //decorativo
					}
					else if (vitoria + empate + derrota != quantidadeJogos){
                        printf("------------------------------------------------------------- \n");  //decorativo
						printf("           A soma deve ser igual a %d jogos.\n", quantidadeJogos);
                        printf("------------------------------------------------------------- \n");  //decorativo
					}

                    //Caso quantidade de jogos sejam validos, o código pode por fim, continuar
					else{
                        
                        //Processamento dos dados das equipes
                        pontuacao = (vitoria*3)+(derrota*0)+empate; // calcula a pontuação da equipe
                        totalPontuacao+=pontuacao; // acrescenta a pontuação na váriavel, somando
                        totalVitoria+=vitoria;  // acrescenta a quantidade de vitoria, somando
                        totalEmpate+=empate; // acrescenta a quantidade de empate, somando
                        totalDerrota+=derrota; // acrescenta a quantidade de derrota, somando

                        registroCompleto = 1; // todas equipes foram registradas, então o resumo será possivel ser feito

                        //Estrutura Condicional que verifica qual equipe fez mais pontos e menos, mais empates e menos .
                        if(i==1){ 

                            //cada equipe será comparada com a anterior
                            maiorPontuacao = pontuacao;
                            menorPontuacao = pontuacao;

                            equipeMaiorPontuacao = i;
                            equipeMenorPontuacao = i;

                            empatadosMaior = 1;
                            empatadosMenor = 1;
                        }
                        else{

                            // verifica as equipes empatadas de maior pontuação
                            if(pontuacao > maiorPontuacao){
                                
                                maiorPontuacao = pontuacao;
                                equipeMaiorPontuacao = i;
                                empatadosMaior = 1; 
                            }
                            else if(pontuacao == maiorPontuacao){

                                empatadosMaior++;
                            }

                            // verifica as equipes empatadas de menor pontuação
                            if(pontuacao < menorPontuacao){

                                menorPontuacao = pontuacao;
                                equipeMenorPontuacao = i;
                                empatadosMenor = 1;
                            }
                            else if(pontuacao == menorPontuacao){

                                empatadosMenor++;
                            }
                        }

                        //entrada e valida
						entradaValida = 1;
                        
                        //Desempenho da equipe
                        printf("------------------------------------------------------------- \n");  //decorativo
                        printf("Desempenho da Equipe %d: %d vitorias, %d derrotas e %d empates\n", i, vitoria, derrota, empate);
                        printf("Pontuacao da Equipe %d: %d pontos\n", i, pontuacao);
                        
                        //Estrutura Condicional que verifica a situação da equipe
                        if(pontuacao>=15){
                            printf("Situacao da Equipe %d: Excelente campanha\n", i);
                            printf("------------------------------------------------------------- \n");  //decorativo
                            quantidadeExcelente++;
                        }
                        else if(pontuacao>=10){
                            printf("Situacao da Equipe %d: Boa campanha\n", i);
                            printf("------------------------------------------------------------- \n");  //decorativo
                            quantidadeBoa++;
                        }
                        else if(pontuacao>=5){
                            printf("Situacao da Equipe %d: Campanha regular\n", i);
                            printf("------------------------------------------------------------- \n");  //decorativo
                            quantidadeRegular++;
                        }
                        else{
                            printf("Situacao da Equipe %d: Campanha ruim\n", i);
                            printf("------------------------------------------------------------- \n");  //decorativo
                            quantidadeRuim++;
                        }
					}
				}
			}

            // calculo da média dos pontos de todas equipes
            mediaPontuacao = (float)totalPontuacao/quantidadeEquipe; 
			break;
		case 2:
            
            // verifica se o registro foi feito
            if(registroCompleto == 0){
                printf("------------------------------------------------------------- \n");  //decorativo
                printf("             Registre os resultados primeiro.\n");
                printf("------------------------------------------------------------- \n");  //decorativo
            }

            // imprime resumo quando o registro estiver completo
            else{
                printf("------------------------------------------------------------- \n");  //decorativo
                printf("                  Resumo do Campeonato\n");  //decorativo
                printf("------------------------------------------------------------- \n");  //decorativo
                printf("-> Quantidade de equipes: %d\n", quantidadeEquipe);
                printf("-> Quantidade de jogos por equipe: %d\n", quantidadeJogos);
                printf("-> Quantidade de equipes em situação excelente: %d\n", quantidadeExcelente);
                printf("-> Quantidade de equipes em situação boa: %d\n", quantidadeRegular);
                printf("-> Quantidade de equipes em situação regular: %d\n", quantidadeRegular);
                printf("-> Quantidade de equipes em situação ruim: %d\n", quantidadeRuim);
                printf("-> Total de vitorias: %d\n", totalVitoria);
                printf("-> Total de Empates: %d\n", totalEmpate);
                printf("-> Total de Derrotas: %d\n", totalDerrota);
                printf("-> Total de pontos da partida: %d\n", totalPontuacao);
                printf("-> Media de todos pontos: %.2f\n", mediaPontuacao);
                printf("-> Maior pontuacao: %d pontos (Equipe %d)\n", maiorPontuacao, equipeMaiorPontuacao);
                printf("-> Equipes empatadas na maior pontuacao: %d\n", empatadosMaior);
                printf("-> Menor pontuacao: %d pontos (Equipe %d)\n", menorPontuacao, equipeMenorPontuacao);
                printf("-> Equipes empatadas na menor pontuacao: %d\n", empatadosMenor);
                printf("------------------------------------------------------------- \n");  //decorativo
            }
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
