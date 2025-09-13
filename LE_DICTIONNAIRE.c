#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h> 
struct dictionnaires
{
    char fr [20];
    char en [20];
};
    struct dictionnaires N[5];
    int i,j;
    char mot[30],imot [30];
 void minuscule (){
    int i = 0;
    while (mot[i] != mot[(strlen(mot) +1)]) 
      {
        if (mot[i] >= 'A' && mot[i] <= 'Z') 
        {
            mot[i] =mot[i]+ 32;
        }    i++;
      }    
  }
 void remplissage (struct dictionnaires N[5]){
  printf("\n-----------------------INSUALISATION LES MOTS POUR LE DICTIONNAIRE-----------------------\n");
  printf("----------------------------<ATTENTION AVANT ENTER UN MOT !! >-----------------------------\n");
  printf("\n- Premier mot en français ( espace ) deuxième mot leur traduction en anglais \n");
  printf("- |EXAMPLE| --> ( | salut | ('espace') | hello | ) \n\n");
     for ( i = 0; i <5; i++)
      {
         printf("le (%d) mot : ",i+1);
         gets(mot);
         minuscule ();
         j=0;
          while ((j < strlen(mot)) && (mot[j] != ' '))
          {
            j++;
          }
         strncpy(((N[i]).fr), mot, j);
         strncpy(((N[i]).en), (mot + j+1 ), strlen(mot));
      }
  }
void TriselectionFR(struct dictionnaires N[5]) {
    int x;
    struct dictionnaires temp;
    for (i = 0; i < 4; i++) {
        x = i;
        for (j = i + 1; j < 5; j++) {
            if (strcmp(N[j].fr, N[x].fr) < 0) {
                x = j;
            }
        }
        temp = N[i];
        N[i] = N[x];
        N[x] = temp;
    }
}
void TriselectionEN(struct dictionnaires N[5]) {
    int x;
    struct dictionnaires temp;
    for (i = 0; i < 4; i++) {
        x = i;
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(N[j].en, N[x].en) < 0) {
                x = j;
            }
        }
        temp = N[i];
        N[i] = N[x];
        N[x] = temp;
    }
}
void Traduiremot (struct dictionnaires N[5]){
  bool trouve;
  trouve=false;
  i=0;
    printf("\n---------------- < dictionnaires > ----------------\n");
    printf ("donner un mot pour traduer :");
    scanf("%s",imot);
  while ((!trouve) && (i<5))
   {
      if (((strcmp(imot,(N[i].fr)))==0 )|| ((strcmp(imot,(N[i].en)))==0))
      {
         trouve =true;
      }  i++;
   }
      if ((trouve) && ((strcmp(imot,N[i-1].fr))==0))
      {
         printf("\nle mot : %s  en anglais est : %s\n\n\n",imot,N[i-1].en);
      }else if ((trouve) && ((strcmp(imot,N[i-1].en))==0))
      {
         printf("\nle mot : %s  en francais est : %s\n\n\n",imot,N[i-1].fr);
      } else
      {
         printf("Le mot n''existe pas");
      } 
  }
 void affichageFR (struct dictionnaires N[5]){
     printf("\n----------------les mots en français----------------\n");
     printf("                      < tri >                         ");
     for ( i = 0; i <5; i++)
      {
      printf("\n- %s ",(N[i].fr));
      }
  }
 void affichageEN (struct dictionnaires N[5]){
     printf("\n----------------les mots en anglais----------------\n");
     printf("                      < tri >                         ");
     for ( i = 0; i <5; i++)
      {
      printf("\n- %s ",(N[i].en));
      }
  }
int main() {
  int choix;
  remplissage (N);
  printf("\n---------------- Menu de choix ----------------\n");
  printf("\n1- Pour afficher les mots en français tri [ 1 ]");
  printf("\n2- Pour afficher les mots en englais tri [ 2 ]");
  printf("\n3- Pour traduire un mots [ 3 ]");
  printf("\n - Mon choix est : ");
  scanf("%d",&choix);
  switch (choix)
  {
  case 1 :
    TriselectionFR(N);
    affichageFR(N);
    break;
  case 2:
    TriselectionEN(N);
    affichageEN(N);
    break;
  case 3:
    Traduiremot(N);
    break;
  }
  return 0;
} 

