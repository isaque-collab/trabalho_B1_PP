#include <stdio.h>

int main(void)
{
    int quantegp = 0, jogosegp = 0;
    while(1)
    {
    printf("quantidade de equipes: ");
    scanf("%d", &quantegp);
    if(quantegp >= 3 && quantegp<=10)
    {
        break;
    }else
    {
        printf("Valor inválido\n");
    }
    while (1)
    {
        printf("Quantidade de jogos disputados por cada equipe");
        scanf("%d", &jogosegp);
        if (jogosegp >= 1 && jogosegp <= 10)
        {
            break;
        }else
        {
            printf("Valor inválido\n");
        }       
    }
    
}

    }