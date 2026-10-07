#include <stdio.h>

int main(){
	
	//variaveis
	int option;
	
	//menu e estrutura em loop
	do{
		printf("=== Sistema de Controle de Campeonato ===\n");
		printf("1......Registrar resultados do campeonato\n");
		printf("2............Mostrar resumo do campeonato\n");
		printf("3.................... Mostrar regulamento\n");
		printf("4..........Simular campanha de uma equipe\n");
		printf("5........................Encerrar sistema\n\n");
		//escolha de opcoes do usuario
		printf("Digite a opcao: ");
		scanf("%d", &option);
		
		//switch case
		switch(option){
			case 1:
				printf("\nRegistro escolhido\n\n");
			break;
			case 2:
				printf("\nResumo escolhido\n\n");
			break;
			case 3: 
				printf("\nRegulamento escolhido\n\n");
			break;
			case 4: 
				printf("\nSimulacao escolhido\n\n");
			break;
			case 5:
				printf("\nSaindo do Sistema........");
			break;
			default:
				printf("\nOpcao Invalida\n\n");
		}
	
	}
	while(option!=5);
	return 0;
}
