#include <stdio.h>
#include <time.h>

int new_c;


void play(int g[3],double*);
void card_name(int*);
int  dealing(void);
void ending (int g[3],double);
void beginning(int g[3],double*);

int main(void)
{ double bankroll;
  int gamerecod[3]={0,0,0};
  char input,x;


  srandom((unsigned int)(time(NULL)));
   do{
   beginning(gamerecod,&bankroll);

  play(gamerecod,&bankroll);

   ending (gamerecod,bankroll);
  do{
  printf("Do you want to go on the game? please enter \"Y\"or\"N\".\n");
  scanf("%c%c",&input,&x);

   if(input!='y'&& input!='Y'&& input!='n'&& input!='N')
   printf("The input is unknown!\n");

     }
  while(input!='Y'&& input!='y'&& input!='N'&& input!='n');

  }while(input=='y'||input=='Y');


 return(0);

 }

 int dealing(void){

    new_c= random()%13 + 1;
    return (new_c);

}

void card_name(int *c){

  switch (*c){
     case 1:
       printf("Ace card.\n");
       *c=11;
       break;
     case 3 :case 4 :case 5 :case 6:case 7:case 8:case 9:
       printf("%d card.\n",*c);
       break;
     case 11:
       printf("J card.\n");
       *c=10;
       break;
     case 12:
       printf("Q card.\n");
       *c=10;
       break;
     case 13:
       printf("K card.\n");
       *c=10;
       break;
    default:break;}
   printf("value is %d.\n",*c);

}


void play(int g[3],double* bankroll){

 char input,x;
 int sump=0, sumd=0, hole ;
 double bet,b;



  printf("wellcome to play Casino BlackJack\n");

//betting
  do{
   if (*bankroll<1000) b=*bankroll;
    else b=1000;
  printf("please enter your betting (10-%.2f).\n",b);
  scanf ("%lf%c",&bet,&x);



  if (bet<10 || bet>b)printf("You do not have enough money in bankroll!\n");

    }
  while (bet<=10 || bet>b);
  printf ("your betting is %.2f $\n",bet );

  //the start of game
   printf("Start!\nyour first card.\n");

  //player get the first card
   dealing();
   card_name(&new_c);
   sump=sump+ new_c;

   printf("your second card.\n");
  //player get the second card
   dealing();
   card_name(&new_c);
   sump= sump+ new_c;


  //dealer get the first card
    printf("dealer get the first card.\n" );
    dealing();
    printf("hole card.\n");
    hole=new_c;
    switch (new_c){
     case 11:case 12:case 13:
     new_c=10;
     break;

    default:break;}
    sumd=sumd+ new_c;

  //dealer get the second card
  printf("dealer get the second card.\n" );
    dealing();
    card_name(&new_c);
    sumd=sumd+ new_c;

  if (sump> 21){
   printf ("player busted.\nplayer lose %.2f $.\n",bet);
   *bankroll= *bankroll-bet;
   g[2]=g[2]+1;}
 else


do{

  do{
//Stand or Hit
  printf("player> Stand or Hit? please enter S or H.\n");
  scanf("%c%c",&input,&x);


  if(input!='S'&& input!='s'&& input!='H'&& input!='h')
   printf("The input is unknown!\n");

     }
  while(input!='S'&& input!='s'&& input!='H'&& input!='h');


       //Shand
       switch (input){


         case 'S':
         case 's':
           printf("Stand.\n");

           //bealer
           if (sumd< 17){

           dealing();
           printf("The dealer get\n");
           card_name(&new_c);
           sumd=sumd+ new_c;   }
           else printf("The dealer does not get a card.\n");

         break;


           //H//
         case 'H':
         case 'h':
         //player
           printf("Hit.\n");
           printf("you get a new card\n");
           dealing();
           card_name(&new_c);
           sump=sump+ new_c;


           //bealer
           if (sumd< 17){
           dealing();
           printf("The dealer get a new card\n");
           card_name(&new_c);
           sumd=sumd+ new_c;
             }
           else
            printf("The dealer does not get a card.\n");

           break;
        default:break;

         }
  }
    while (input=='H'||input=='h'&& sump<21);

//win or lose

  //show the hole card
    printf("The dealer's hole card is\n" );
    card_name(&hole);

 //busted


 if (sump> 21){
   printf ("player busted.\nplayer lose %.2f$.\n",bet);
   *bankroll= *bankroll-bet;
   g[2]=g[2]+1;}
 else{

 if (sumd> 21){
   printf ("dealer busted.\nplayer win %.2f$.\n",bet);
   *bankroll= *bankroll+bet;
   g[0]=g[0]+1;}
 else{

 if (sumd==sump)
   printf ("Push.\n plarer's card number %d=dealer's card number %d.\n",sump,sumd);
 else{
 if (sump>sumd){
   printf ("player win %.2f$!\nplarer's card number %d>dealer's card number %d.\n",bet,sump,sumd);
   *bankroll=*bankroll+bet;
   g[0]=g[0]+1;}
  else{

  if(sump<sumd){
   printf ("player lose %.2f$!\nplarer's card number %d<dealer's card number %d.\n",bet,sump,sumd);
   *bankroll=*bankroll-bet;
   g[1]=g[1]+1;}}}}}



 }

 void ending(int g[3],double bankroll){
  int i;

  FILE *fpw=fopen("game.txt","w");
  fprintf(fpw,"%.2f ",bankroll);
  printf("The bankroll is %.2f $.\n",bankroll);

  for(i=0;i<=2;i++){
   fprintf(fpw,"%d ",g[i]);

   }
  fclose(fpw);

   printf("win%d times lose%d times bust%d times  bankroll=%.2f . \n",g[0],g[1],g[2],bankroll);

  }

  void beginning(int g[3],double*b){
 int i,fr;
char input,x;
double bankroll;
FILE *fpr=fopen("game.txt","r");

 fr=fscanf(fpr, "%lf", &bankroll);


 for(i=0;fr==1;i++) {
 fr=fscanf(fpr,"%d",&g[i]);
 }

fclose(fpr);
if (bankroll<=0){
  bankroll=1000;
  for(i=0;i<=2;i++){
  g[i]=0;}
  printf("You do not have any bankroll, let us play a new game!\n");
}
else
do{
printf("new game or continual game? please enter the \"N\"or\"C\".\n");
scanf("%c%c",&input,&x);

 if(input!='N'&& input!='n'&& input!='C'&& input!='c')
   printf("The input is unknown!\n");

     }
  while(input!='N'&& input!='n'&& input!='C'&& input!='c');

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

    printf("win%d times lose%d times bust%d times  bankroll=%.2f$ . \n",g[0],g[1],g[2],bankroll);
    *b=bankroll;
}

