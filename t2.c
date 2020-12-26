#include <stdio.h>

#include <time.h>

void ending (int g[3],double);
void beginning(int g[3],double);

int new_c;


int main(void){
 int g[3];
 double bankroll;

  beginning(g,bankroll);


//////
 printf("win%d lose%d bus%d  bank=%f . \n",g[0],g[1],g[2],bankroll);


return 0 ;}




void beginning(int g[3],double bankroll){
 int i,c[3];
char input;

FILE *fpr=fopen("game.txt","r");
fscanf(fpr, "%f", & bankroll);

for (i=0; i<=3; i++){
 fscanf(fpr,"%d",&c[i]);
}
fclose(fpr);
if (bankroll<=0){
  bankroll=1000;
  printf("You do not have any bankroll, let us play a new game!\n");
}
else printf("new game or continual game? please enter the \"N\"or\"C\".\n");
scanf("%c",&input);

       switch (input){
         //New//
         case 'N':
         case 'n':
           printf("player>New game\n");
           bankroll=1000;
           break;

           //Continual//
         case 'C':
         case 'c':
           printf("player>Continual game\n");

           break;


         default : break;}
}



