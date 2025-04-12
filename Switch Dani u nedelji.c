#include <stdio.h>

int main()
{
    int redni_broj_dana_u_nedelji;
    
    printf("Unesite redni broj dana u nedelji: ");
    scanf("%d", &redni_broj_dana_u_nedelji);
    
    printf("Dan u nedelji je: ");
    
    switch (redni_broj_dana_u_nedelji)
    {
        case 1:
         printf("Ponedeljak");
         break;
         
        case 2:
         printf("Utorak");
         break;
         
        case 3:
         printf("Sreda");
         break;
         
        case 4:
         printf("Cetvrtak");
         break;
         
        case 5:
         printf("Petak");
         break;
        
        case 6:
         printf("Subota");
         break;
        
        case 7:
         printf("Nedelja");
         break;
        
        default:
         printf("Nedelja ima 7 dana, ne %d", redni_broj_dana_u_nedelji);
         break;
    }
}