#include <stdio.h>

int main()
{
    double duzina_stranice_baze;
    double visina_trougla;
    
    // User unosi duzinu stranice baze
    printf("Unesi duzinu stranice baze: ");
    scanf("%lf", &duzina_stranice_baze);
    
    // User unosi visinu trougla
    printf("Unesi duzinu visine trougla: ");
    scanf("%lf", &visina_trougla);
    
    // Debug, printuje variable value
    printf("Duzina stranice baze je: %lf", duzina_stranice_baze);
    printf("\nVisina trougla je: %lf", visina_trougla);
    
    // Definisu se povrsine trougla i baze
    double povrsina_baze = duzina_stranice_baze * duzina_stranice_baze;
    double povrsina_trougla = 2 * ((duzina_stranice_baze * visina_trougla) / (2));
    // Printuje se da se proveri tacnost
    printf("\nPovrsina baze je: %lf", povrsina_baze);
    printf("\nPovrsina trougla je: %lf", povrsina_trougla);
    
    // Definise se povrsina piramide
    double povrsina_piramide = povrsina_baze + (4 * povrsina_trougla);
    // Printuje se povrsina piramide za proveru
    printf("\nPovrsina piramide je: %lf", povrsina_piramide);

    return 0;
}