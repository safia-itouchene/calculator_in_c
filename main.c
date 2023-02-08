#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main()
{
  char exp[100];
  enrg str[100];
  do{
        puts ("Donnez une Expression Arithmetique correcte");
        gets (exp);
      }while(VerifierExpression(exp)!=0);
             chaine_vrs_T(exp,str);
return 0;
}
