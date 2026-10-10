#include <stdio.h>
// colocar um for para as pontuações e aumentar em um cada comparação, quando achar uma pontuação maior guardar esse i para saber qual foi a primeira eguipe a atingir a maior basta olhar quantas empataram na maior pontuação. se pegar uma nova pontuação maior a gnt zera o empate
int main(void)
{
    int quantegp = 0;
    int pontos = 0, vitoria = 0, empate = 0, derrota = 0, maiorpont = 0, empatema = 0, empateme = 0, eguipema = 0, eguipeme = 0, menorpont = 0;
    int totalvit = 0, totalemp = 0, totaldert = 0, totalruim = 0, totalregular = 0, totalboa = 0, totalexcelente = 0;
    for (int i = 1; i < quantegp; i++) {
    switch (i) {
        case 1:
            
            pontos = (vitoria * 3) + (empate * 1) + (derrota * 0);
            maiorpont = pontos;
            eguipema = 1;
            menorpont = pontos;
            eguipeme = 2;
            printf("Eguipe 1: %d vitorias, %d empates, %d derrotas\n", vitoria, empate, derrota);
            printf("Pontuação: %d", pontos);
            printf("Situação: ");
            if(pontos < 5)
            {
                printf("Campanha ruim!\n");
                totalruim++;    
            }else if(pontos >= 5 && pontos <= 9){
                printf("Campanha regular!\n");
                totalregular++;
            }else if(pontos >=10 && pontos<= 14){
                printf("Boa campanha!\n");
                totalboa++;
            }else if(pontos >= 15){
                printf("Excelente campanha!\n");
                totalexcelente++;
            }
            vitoria = 0, empate = 0, derrota = 0;
            break;
        case 2:
            if(pontos > maiorpont)
            {
                maiorpont = pontos;
                eguipema = i;
                empatema = 0;
            }else if( pontos == maiorpont)
            {
                empatema++;
            }else if(pontos < menorpont)
            {
                menorpont = pontos;
                eguipeme = i;
                empateme = 0;
            }else if(pontos == menorpont)
            {
                empateme++;
            }
            break;
        case 3:
            break;
    }
}   
    for(int i = 1; i < quantegp; i++)
    {
        
    }

    
}