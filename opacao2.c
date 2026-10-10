#include <stdio.h>
int pontos  ;
int main(void){
    if(pontos == 0)
    {
        printf("Registre os resultados primeiro.\n");
    }else{
    printf("Quantidade de eguipes: %d");
    printf("Quantidade de Jogos: %d");
    printf("Total de: \n %d vitorias.\n %d empates.\n %d derrotas.\n");
    printf("Total de pontos: %d\n");
    printf("Media: %.2f\n");
    printf("Quantidade de equipes em cada situação:\n %dexcelente. \n %dboa\n %dregular\n %druim\n");
    printf("Maior pontuacao: %d, atingida por: eguipe %d\n");
    printf("Menor pontuacao: %d, atingida por: eguipe %d\n");
    printf("Quantidade de eguipes empatadas na maior pontuacao: %d\nQuantidade de eguipes empatadas na menor pontuacao:%d");
    }
}