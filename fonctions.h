#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
typedef struct enrg{
     char T[100];
     int e; //0=operande ,1=paranthese , 2=operateur
  }enrg;
typedef struct objet *pile;
typedef struct objet{
enrg inf;
  pile svt;
}nods;
enrg SommetPile(pile p);
void Empiler(pile *p , enrg x);
void Desempiler(pile *p , enrg *x );
void affichage(pile p);
int Operande(char str);//verification des operandes
int Operateur(char str);//verification des operateurs
int Verifierparontase(char str);//verifacation si expression[i]=parethese)
int Priorite(enrg x);
int VerifierOperateur(enrg str);
int VerifierNombre(enrg str);
enrg Operation(char x[] , char y[] , char opr[]);
void Evalution(pile P);
void Transformation_postfixee(enrg str[] , int n);
void verParentheses(enrg expr[] , int l);//verifacation des paretheses (si juste ou non )
void suprEspace(char str[]);//suppretion des espases
void chaine_vrs_T( char exp[], enrg str[]);//transfomer une chaine de caractere vers un tab d enregistrement
int  VerifierExpression(char exp[] ); //verification si il ya des ereurs lexical


#endif // FONCTIONS_H_INCLUDED
