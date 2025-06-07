#include <stdio.h>

int main()
{
    float x, y, R;
    char op;
    
    printf("Unesite broj x: \n");
    scanf("%f", &x);
    
    printf("Unesite broj y: \n");
    scanf("%f", &y);
    
    printf("Unesite operator: \n");
    scanf("%s", &op);
    
    switch(op)
    {
        case '+':
          R = x + y;
          printf("%f", R);
          break;
        
        case '-':
          R = x - y;
          printf("%f", R);
          break;
        
        case '*':
          R = x * y;
          printf("%f", R);
          break;
        
        case '/':
          if (x == 0 || y == 0)
          {
              printf("Invalid operation");
          }
          else
          {
              R = x / y;
              printf("%f", R);
          }
          break;
        
        default:
          printf("Invalid");
    }
}