#include <stdio.h>
#include <stdlib.h> //Essa biblioteca e a time são necessarias para as funções
#include <time.h>

int main()
{
    int a;
    double b = 61500;

    for (int i = 0; i < 10; i++)
    {

        srand(time(NULL)); //É para gerar um numero aleatorio todas as vezes que abrir o programa

        do
        {
            a = rand() % 100; // Vai gerar o numero entre 0 e 99
        } while (a == 1 || a == 10 || a == 50);
        if (a >= 1 && a <= 10)
        {
            b = b - (b/8);
        }
        else
        {
            if (a > 10 && a <= 20)
            {
                b = b - (b/16);
            }
            else
            {
                if (a > 20 && a <= 30)
                {
                    b = b - (b/32);
                }
                else
                {
                    if (a > 30 && a <= 40)
                    {
                        b = b - (b/64);
                    }
                    else
                    {
                        if (a > 40 && a <= 50)
                        {
                            b = b - (b/128);
                        }
                        else
                        {
                            if (a > 50 && a <= 60)
                            {
                                b = b + (b/8);
                            }
                            else
                            {
                                if (a > 60 && a <= 70)
                                {
                                    b = b + (b/16);
                                }
                                else
                                {
                                    if (a > 70 && a <= 80)
                                    {
                                        b = b + (b/32);
                                    }
                                    else
                                    {
                                        if (a > 80 && a <= 90)
                                        {
                                            b = b + (b/64);
                                        }
                                        else
                                        {
                                            b = b + (b/128);
                                        }
                                        
                                    }
                                    
                                }
                                
                            }
                        }
                        
                    }
                    
                }
                
            }
            
        }
        printf("%.5f\n", b);
    }
    return 0;
}