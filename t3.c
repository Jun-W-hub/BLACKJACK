#include <stdio.h>
//#include <time.h>

//void ending (int g[3],double);
void beginning(int g[3],double*);

int new_c;


int main(void){
 int g[3]
 ;
 double bankroll//=1000
 ;
//ending (g,bankroll);
  beginning(g,&bankroll);

        ///////////
    printf("win%d lose%d bus%d  bank=%.2f . \n",g[0],g[1],g[2],bankroll);
return 0 ;}

 void ending(int g[3],double bankroll){
  int i;

  FILE *fpw=fopen("game.txt","w");
  fprintf(fpw,"%.2f ",bankroll);
  printf("The bankroll is %.2f $.",bankroll);

  for(i=0;i<=2;i++){
   fprintf(fpw,"%d ",g[i]);

   }
  fclose(fpw);}




void beginning(int g[3],double*b){
 int i,fr;
char input;
double bankroll;
FILE *fpr=fopen("game.txt","r");
 // fscanf(fpr, "%lf", &bankroll);
 fr=fscanf(fpr, "%lf", &bankroll);

 ///////////
    printf("win%d lose%d bus%d  bank=%.2f . \n",g[0],g[1],g[2],bankroll);

 //fr=fscanf(fpr, "%d", &g[0]);
 for(i=0;fr==1;i++) {
 fr=fscanf(fpr,"%d",&g[i]);
 }
//for (i=0; i<=3; i++){

fclose(fpr);
//*bankroll=b;
if (bankroll<=0){
  bankroll=1000;
  for(i=0;i<=2;i++){
  g[i]=0;}
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
           for(i=0;i<=2;i++){
             g[i]=0;}
           break;

           //Continual//
         case 'C':
         case 'c':
           printf("player>Continual game\n");

           break;


         default : break;}
    ///////////
    printf("win%d lose%d bus%d  bank=%.2f . \n",g[0],g[1],g[2],bankroll);
    *b=bankroll;
}



