#include "ft_printf.h"


/*
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("debut __%s__ fin\n____\n", "");
	printf("debut __%s__ fin\n____\n", "");
	ft_printf("debut %c fin\n____\n", '\0');
	printf("debut %c fin\n____\n", '\0');
	return (0);
}
*/
int main(void)
{
    int test1 = 1000000000;
//    short int test2 = 10000;
//    char test3 = 42;
//    long int test4 = 4000000000;
 //   long long int test5 = 8000000000;
    int *test6 = &test1;
    unsigned short test7 = 100;
//    unsigned long test8 = 4000000000;
 //   unsigned long long test9 = 8000000000;
    unsigned int test10 = 4294;
    char *test11 = NULL;
    char *test12 = 0x0;
   // char *str = NULL;
    printf("VRAI PRINTF:\n");
    printf("-----Test normaux-----\n");
    printf("test printf\n");
    ft_printf("test printf\n");
    printf("");
    ft_printf("");
    printf("-----Test %%c-----\n");
    printf("%c\n", 'k');
    ft_printf("%c\n", 'k');
  printf("%c\n", '\n');
  ft_printf("%c\n", '\n');
  printf("%c\n", '\0');
  ft_printf("%c\n", '\0');
  printf("test avec 0 : '%c'\n", 0);
  ft_printf("test avec 0 : '%c'\n", 0);
    printf("-----Test %%s-----\n");
    printf("%s\n", "POULOULOU");
    ft_printf("%s\n", "POULOULOU");
    printf("%s\n", "\0");
    ft_printf("%s\n", "\0");
    printf("%s", "JURE LE YA UN RETOUR LIGNE\n");
    ft_printf("%s", "JURE LE YA UN RETOUR LIGNE\n");
    printf("-----Test %%p-----\n");
    printf("%p\n", test6);
    ft_printf("%p\n", test6);
    printf("%p\n", test11);
    ft_printf("%p\n", test11);
    printf("%p\n", test12);
    ft_printf("%p\n", test12);
    printf("-----Test %%%%-----\n");
    printf("%%\n");
    ft_printf("%%\n");
    printf("-----Test %%d et %%i-----\n");
    printf("%d\n", test1);
    ft_printf("%d\n", test1);
    printf("%i\n", test1);
    ft_printf("%i\n", test1);
    printf("-----Test %%u-----\n");
	printf("%u\n", 1000);
    ft_printf("%u\n", 1000);
    printf("%u\n", test10);
    ft_printf("%u\n", test10);
    printf("%u\n", -1);
    ft_printf("%u\n", -1);
    printf("%u\n", -100);
    ft_printf("%u\n", -100);
    printf("-----Test %%x et %%X-----\n");
    printf("%x\n", 1000);
    ft_printf("%x\n", 1000);
    printf("%X\n", 1000);
    ft_printf("%X\n", 1000);
    printf("%x\n", test7);
    ft_printf("%x\n", test7);
    printf("%X\n", test7);
    ft_printf("%X\n", test7);
    printf("-----Test Minwidth-----\n");
    printf("Pourcent c: '%10c'\n", 'o');
    ft_printf("Pourcent c: '%10c'\n", 'o');
    printf("Pourcent c: '%-10c'\n", 'o');
    ft_printf("Pourcent c: '%-10c'\n", 'o');
    printf("Pourcent s: '%10s'\n", "hihihi");
    ft_printf("Pourcent s: '%10s'\n", "hihihi");
    printf("Pourcent s: '%-10s'\n", "hihihi");
    ft_printf("Pourcent s: '%-10s'\n", "hihihi");
    printf("Pourcent s: '%10s'\n", "hohohohohohohoho");
    ft_printf("Pourcent s: '%10s'\n", "hohohohohohohoho");
    printf("Pourcent s: '%-10s'\n", "hohohohohohohoho");
    ft_printf("Pourcent s: '%-10s'\n", "hohohohohohohoho");
    printf("Pourcent p: '%20p'\n", test6);
    ft_printf("Pourcent p: '%20p'\n", test6);
    printf("Pourcent p: '%-20p'\n", test6);
    ft_printf("Pourcent p: '%-20p'\n", test6);
    printf("Pourcent di: '%10d'\n", 42);
    ft_printf("Pourcent di: '%10d'\n", 42);
    printf("Pourcent di: '%-10d'\n", 42);
    ft_printf("Pourcent di: '%-10d'\n", 42);
    printf("Pourcent di: '%10d'\n", -1000);
    ft_printf("Pourcent di: '%10d'\n", -1000);
    printf("Pourcent di: '%-10d'\n", -1000);
    ft_printf("Pourcent di: '%-10d'\n", -1000);
	printf("Pourcent u: '%10u'\n", 100);
    ft_printf("Pourcent u: '%10u'\n", 100);
    printf("Pourcent u: '%-10u'\n", 100);
    ft_printf("Pourcent u: '%-10u'\n", 100);
    printf("Pourcent x: '%10x'\n", 1000);
    ft_printf("Pourcent x: '%10x'\n", 1000);
    printf("Pourcent X: '%10X'\n", 1000);
    ft_printf("Pourcent X: '%10X'\n", 1000);
    printf("Pourcent X: '%-10X'\n", 1000);
    ft_printf("Pourcent X: '%-10X'\n", 1000);
    printf("Pourcent pourcent : '%10%'\n");
    ft_printf("Pourcent pourcent : '%10%'\n");
    printf("Pourcent pourcent : '%-10%'\n");
    ft_printf("Pourcent pourcent : '%-10%'\n");
    printf("-----Test precision-----\n");
   printf("Pourcent c: '%.10c'\n", 'o');
    ft_printf("Pourcent c: '%.10c'\n", 'o');
    printf("Pourcent s: '%.10s'\n", "hohohohohohohoho");
    ft_printf("Pourcent s: '%.10s'\n", "hohohohohohohoho");
    printf("Pourcent p: '%.20p'\n", test6);
    ft_printf("Pourcent p: '%.20p'\n", test6);
    printf("Pourcent d: '%.10d'\n", 42);
    ft_printf("Pourcent d: '%.10d'\n", 42);
    printf("Pourcent u: '%.10u'\n", 100);
	ft_printf("Pourcent u: '%.10u'\n", 100);
    printf("Pourcent x: '%.10x'\n", 1000);
    ft_printf("Pourcent x: '%.10x'\n", 1000);
    printf("Pourcent X: '%.10X'\n", 1000);
    ft_printf("Pourcent X: '%.10X'\n", 1000);
    printf("Pourcent pourcent : '%.10%'\n");
    ft_printf("Pourcent pourcent : '%.10%'\n");
    printf("Pourcent D: '%5.d' '%5.0d'\n", 0, 0);
    ft_printf("Pourcent D: '%5.d' '%5.0d'\n", 0, 0);
    printf("-----Test +- #0-----\n");
    printf("espace positif '% d'\n", 1000);
    ft_printf("espace positif '% d'\n", 1000);
    printf("espace negatif '% d'\n", -1000);
    ft_printf("espace negatif '% d'\n", -1000);
    printf("plus positif '%+d'\n", 1000);
    ft_printf("plus positif '%+d'\n", 1000);
    printf("plus negatif '%+d'\n", -1000);
    ft_printf("plus negatif '%+d'\n", -1000);
    printf("moins positif '%-10d'\n", 1000);
    ft_printf("moins positif '%-10d'\n", 1000);
    printf("moins negatif '%-10d'\n", -1000);
    ft_printf("moins negatif '%-10d'\n", -1000);
    printf("zero positif '%010d'\n", 1000);
    ft_printf("zero positif '%010d'\n", 1000);
    printf("zero negatif '%010d'\n", -1000);
    ft_printf("zero negatif '%010d'\n", -1000);
    printf("zero negatif '%010.6d'\n", -1000);
    ft_printf("zero negatif '%10.6d'\n", -1000);
    printf("zero + prec '%-010d'\n", -1000);
    ft_printf("zero + prec '%-010d'\n", -1000);
    printf("----------------------------------\n");
//  printf("VALEURS DE RETOUR de \\0 = %d\n", printf("%c", '\0'));
//    ft_printf("VALEURS DE RETOUR de \\0 = %d\n", ft_printf("%c", '\0'));
    printf("vrai printf avec -.2s '%-.2s'\n", "");
    ft_printf("mien printf avec -.2s '%-.2s'\n", "");
    ft_printf("valeur : %d\n", ft_printf("bonjour %12s_\n", ""));
    printf("valeur : %d\n", printf("bonjour %12s_\n", ""));
    printf("bonjour %12s_\n", "\0");
}
