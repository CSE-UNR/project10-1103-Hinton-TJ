//Name: TJ Hinton
//Project 10
#define FILES "mystery.txt"
#define WDMAX 6
#include <stdio.h>

int wordCheck(char word[], char guess[]);
int wordWinner(int correct);
void wrodDisplay(char word[], char list[][10], int count);
void wrodDisplay2(char word[], char list[][10], int count);
void linef();

int main(){
int attempts = 0;
int answer, count;
char wrod[WDMAX], guess[WDMAX];
char wrodList[10][10];

//-----------------------------------------//
FILE *Fpr = fopen(FILES, "r");
if(Fpr == NULL){
	printf("File couldn't be open!");
	}
	
	fscanf(Fpr,"%s",wrod);
 

printf("%s", wrod);
printf("\n");
	fclose(Fpr);
//-----------------------------------------//
do{
	printf("Attempt number #%d:\n", attempts+1);
	
	if(attempts >= 1){		
	wrodDisplay(wrod, wrodList, attempts);
	}	
					
//printf("%d\n", attempts);	
	
scanf("%s", guess);
	linef();
printf("\n");



//printf("%s\n", guess);

for(count = 0; count < 7; count++){
wrodList[attempts][count] = guess[count];
}

//printf("%s\n", wrodList[attempts]);

//wordStore(
//wordDisplay(
	answer = wordCheck(wrod, guess);
	
attempts++;


}while(answer == 0 && attempts < 6);
printf("\n");

	if(answer == 1){
		printf("`~'` Congrats! You WIN!! `'~`\n");
	}
	else{
		printf("Nice try, NOOOB\nBetter luck next time, bud\n\n");
	}


return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//1.
int wordCheck(char word[], char guess[]){
int correct = 0; int i = 0; int winner = 0;

for(i = 0; i < 5; i++){
	if(word[0] == guess[i] || word[1] == guess[i] || word[2] == guess[i] ||word[3] == guess[i] || word[4] == guess[i]){correct++;}
}	

winner = wordWinner(correct);
printf("--You have %d correct--\n", correct);

return winner;
}

//2.
int wordWinner(int correct){
	if(correct == 5){return 1;}
	else{return 0;}
}

//3.
void wrodDisplay(char word[],char list[][10], int count){
	int touch = 0;
	for(int in = 0; in < count; in++){
		for(int in2 = 0; in2 < WDMAX-1; in2++){
			if(list[in][in2] == word[in2]){
			printf("%c", list[in][in2] - 32);}
			else{
			printf("%c", list[in][in2]);}
		} 
	printf("\n");
	//printf("%s", list[0]);
	//printf("%d", count);
	wrodDisplay2(word, list, touch);
	touch++;
	printf("\n");}
}
//4.
void wrodDisplay2(char word[], char list[][10], int touch){

	
	for(int in = 0; in < WDMAX-1; in++){
	
			if(list[touch][in] == word[in]){
			printf(" ");}
			else{printf("^");}
//I DONT EVEN KNOW WTF D:
}}


void linef(){
printf("----------------------------\n");
}

