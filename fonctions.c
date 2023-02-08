#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct enrg{
     char T[100];
     int e;
  }enrg;
typedef struct objet *pile;
typedef struct objet{
enrg inf;
  pile svt;
}nods;
enrg SommetPile(pile p){
 return (p->inf);
}

void Empiler(pile *p , enrg x){
 pile tmp=NULL;
 tmp=(pile)malloc(sizeof(nods));
 if(tmp != NULL){
  tmp->inf=x;
  tmp->svt=*p;
 }
 *p=tmp;
}
void Desempiler(pile *p , enrg *x ){
pile tmp;
(*x)=SommetPile(*p);
tmp=*p;
*p=(*p)->svt;
free(tmp);
}

void affichage(pile p){
while(p != NULL){

 printf("%s",(p->inf).T);
      p=p->svt;
}

}
 int Operande(char str){
if( (str <'0' || str >'9')){
 return -1;
}
     return 1;
}

  int Operateur(char str){
    if ((str== '+') || (str == '-') || (str == '*') || (str =='/') || (str =='%')) {
     return 1;
}
return -1;
}

int  Verifierparontase(char str){
  if( str == '(' || str == ')'){
     return 1;
  }
    return -1;
}
int Priorite(enrg x){
if(x.T[0]=='('){
return 0;
}
if(x.T[0] =='+' || x.T[0]== '-'){
return 1;
}
if(x.T[0] =='*' || x.T[0]=='/'){
return 2;
}
}

int VerifierOperateur(enrg str){
if(str.e==2){
return 1;
}
    return 0;
}

int VerifierNombre(enrg str){
  if(str.e==0){
return 1;
}
    return 0;
}
//*********************** Operation ****************
enrg Operation(char x[] , char y[] , char opr[]){
enrg res;
res.e=0; //Le resultat de l'operation est un operande
switch(opr[0]){
      case '+' :  sprintf(res.T,"%f",(atof(x)+atof(y)));  break;
      case '-' :  sprintf(res.T,"%f",(atof(x)-atof(y)));  break;
      case '*' :  sprintf(res.T,"%f",(atof(x)*atof(y)));  break;
      case '/' :  sprintf(res.T,"%f",(atof(x)/atof(y)));  break;
      case '%' :  sprintf(res.T,"%d",((int)atof(x)%(int)atof(y))); break;
}

return res;
}
//*********************** Evalution*****************
void Evalution(pile P){
	pile R=NULL;
	enrg x , x1,x2 ,res;
	while(P !=NULL){
		Desempiler (&P,&x); // x=22.5
		if(VerifierNombre(x)==1){
			Empiler (&R,x);
		}else{
			Desempiler(&R,&x1);
			Desempiler(&R,&x2);
			res=Operation(x2.T,x1.T,x.T);
			Empiler (&R,res);
		}
	}

	printf("\n-Voici le resultat de votre expression:\t");
	affichage(R); printf("\n");

}
//**************************************************

void Transformation_postfixee(enrg str[] , int n){
pile P=NULL; int i=0;
pile R=NULL;
enrg x;
for(i=0;i<n;i++){
if(VerifierNombre(str[i])==1)
    Empiler (&R,str[i]);
   if(str[i].T[0]=='('){
     Empiler (&P,str[i]);
   }
if( VerifierOperateur(str[i])==1){

while(P !=NULL && (VerifierOperateur(SommetPile(P))==1)&&(Priorite(str[i])<= Priorite(SommetPile(P)))){
 Desempiler (&P,&x);
              Empiler (&R,x);
}
     Empiler(&P,str[i]);
}
if(str[i].T[0]==')'){
while(P!=NULL && SommetPile(P).T[0]!='('){
Desempiler (&P, &x);
            Empiler (&R, x) ;
}
    Desempiler (&P,&x);
   }
}
while(R !=NULL) {
Desempiler (&R,&x);
        Empiler (&P, x);
}

printf("\n-la forme postfixee:\t");
affichage(P); printf("\n");
Evalution(P);

}

void verParentheses(enrg expr[] , int l)
{
  int i,p=0;
   i=0;
 for(i=0;i<l;i++)
   {
     if (expr[i].T[0]=='(')
       p++;
     else if (expr[i].T[0]==')'){
       p--;
    if (p<0)
        break;
     }
   }
  if(p!=0){
  printf("\n-erreur de parenthese\n");

  }else{
  Transformation_postfixee(expr,l);
  }
}
//**************************************
void suprEspace(char str[])
{int i,j,n;
n=strlen(str);
for (i=1;i<=n;i++){
  if (str[i]==' ')
    {for(j=i;j<n;j++)
      str[j]=str[j+1];
      i=i-1;
 }}}
//*****************************************
 void chaine_vrs_T( char exp[], enrg str[]){
   suprEspace(exp);
   int l;
  char tmp[10]; int i=0,j=0,k=0,n=0;

  while (exp[i]!='\0')
    {

    if(Verifierparontase(exp[i])==1){
      j=0; n=0;
      tmp[j]=exp[i];
      tmp[j+1]='\0';
       str[k].T[n]= tmp[n];
       str[k].T[n+1]='\0';
       str[k].e=1; // 1 pour les parenthes
         i++; k++;
     }
      if (Operateur(exp[i]) ==1){
           j=0; n=0;
          if(i==0 && exp[i]=='-'){
            tmp[j]= exp[i];
            j++; i++;
            if (Operateur(exp[i])==1){

              str[k].T[n]= tmp[n];
              str[k].e=2; // pour les opirat
                    k++;
            }else if(Operande(exp[i])==1) {

             while(Operande(exp[i])==1 || exp[i]=='.' &&exp[i] !='\0' ){

                     tmp[j]= exp[i];
                     j++;i++;
                              }
                     tmp[j]='\0';
                         n=0;
                      while (tmp[n] !='\0'){
                          str[k].T[n]= tmp[n];
                          str[k].e=0; // pour les nombre
                               n++;
                        }
                        str[k].T[n]='\0';
                             k++;
                                     }
           }else{
                    tmp[j]= exp[i];
                    tmp[j+1]='\0';
                    str[k].T[n]= tmp[n];
                    str[k].e=2; // pour les opira
                    str[k].T[n+1]='\0';
                     k++; i++;
            if ( exp[i]=='-' ){
                       tmp[j]= exp[i];
                        j++;i++;
            if(Operande(exp[i])==1){

              while(Operande(exp[i])==1 || exp[i]=='.'&& exp[i]!='\0' ){
                     tmp[j]=exp[i];
                     j++;i++;}
                     tmp[j]='\0';
                         n=0;
                      while (tmp[n]!='\0'){
                           str[k].T[n]= tmp[n];
                           str[k].e=0;
                               n++;
                             }
                        str[k].T[n]='\0';
                           k++;
  }
                        }
                      }
                  }
                  if( Operande(exp[i])==1 ){
                   j=0;
                   while( exp[i]!='\0' && (exp[i]=='.' || Operande(exp[i])==1)){
                     tmp[j]= exp[i];
                     j++;i++; }
                      tmp[j]='\0';
                       n=0;
                      while (tmp[n]!='\0'){
                       str[k].T[n]= tmp[n];
                        str[k].e=0;
                           n++;
                        }
                        str[k].T[n]='\0';
                               k++; }
         }
verParentheses(str , k);
 }

int  VerifierExpression(char exp[] ){
   int i=0 , trouve=1;
 while(exp[i] !='\0' && trouve!=-1){
  if(Operande(exp[i])==1 ||Operateur(exp[i])==1 || Verifierparontase(exp[i])==1 || exp[i]=='.' ||exp[i]==' '){
       trouve=1;
  } else{
       trouve=-1;
  }
  i++;
 }
 if(trouve ==-1){
    printf("\n-Erreur Lexicale: caractere non autoriser.\n");
  return -1;
 }
  return 0;
}
