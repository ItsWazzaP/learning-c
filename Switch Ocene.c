#include <stdio.h>

int main()
{
    int ocena;
    
    printf("Unesite ocenu: ");
    scanf("%d", &ocena);
    
    printf("Opis ocene je: ");
    
    switch (ocena)
    {
        case 1:
         printf("NEDOVOLJAN");
         break;
         
        case 2:
         printf("DOVOLJAN");
         break;
         
        case 3:
         printf("DOBAR");
         break;
         
        case 4:
         printf("VRLO DOBAR");
         break;
         
        case 5:
         printf("ODLICAN");
         break;
        
        default:
         printf("Unesi ispravan broj :}");
         break;
    }
}