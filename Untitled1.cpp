#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
int const Cmax=100;
class player{
	private:
		int a;
		char PBOARD[Cmax][Cmax];// zaidejo lentele su laivais
		char letter;
		int number;
		int direction;
		int lett;
	protected:
		char BOARD[Cmax][Cmax];
	public:
		player(){
			//A=1; B=2; C=3; D=4; E=5; F=6; G=7; H=8; I=9; J=10;
		}
		void boardprinting(char BOARD[Cmax][Cmax]){
			for(int i=0; i<10; i++){
				if(i!=0){
					cout<<endl;	
				}
				if(i==0){
					cout<<"   ";
					for(char q='A'; q<='J'; q++){
						cout<<q<<" ";
					}
					cout<<endl;
				}
				for(int j=0; j<10; j++){
					if(j==0){
						if(a==9){
						cout<<"10 ";
					}
					else{
						a++;
						cout<<a<<"  ";
					}
					}
					BOARD[i][j]='-';
					cout<<BOARD[i][j]<< " ";
				}
			}
		}
		void ships(int size){ 
			cout<<"iveskite laivo krypti (1- desine, 2- kaire, 3- apacia, 4- virsus)"<<endl;
			cin>>direction;
			cout<<"Iveskite laivo pradine koordinate, pvz: A 5"<<endl;
			cin>>letter>>number;
			convert();
			if(direction==1){
				for(int i=lett; i<lett+size; i++){
					PBOARD[i][number]='*';
				}
				show(PBOARD);
			}
			else if(direction==2){
				for(int i=lett+size; i>lett; i--){
					PBOARD[i][number]='*';
				}
				show(PBOARD);
			}
			else if(direction==3){
				for(int i=number; i<number+size; i++){
					PBOARD[lett][i]='*';
				}
				show(PBOARD);
			}
			else if(direction==4){
				for(int i=number+size; i>number; i--){
					PBOARD[lett][i]='*';
				}
				show(PBOARD);
			}
		}
		void show(char BOARD[Cmax][Cmax]){
			int a=0;
			for(int i=0; i<10; i++){
				if(i!=0){
					cout<<endl;	
				}
				if(i==0){
					cout<<"   ";
					for(char q='A'; q<='J'; q++){
						cout<<q<<" ";
					}
					cout<<endl;
				}
				for(int j=0; j<10; j++){
					if(j==0){
						if(a==9){
						cout<<"10 ";
					}
					else{
						a++;
						cout<<a<<"  ";
					}
					}
					cout<<BOARD[i][j]<<" ";
				}
			}
		}
		convert(){
			if(letter=='A'){
				lett=1;
			}
			else if(letter=='B'){
				lett=2;
			}
			else if(letter=='C'){
				lett=3;
			}
			else if(letter=='D'){
				lett=4;
			}
			else if(letter=='E'){
				lett=5;
			}
			else if(letter=='F'){
				lett=6;
			}
			else if(letter=='G'){
				lett=7;
			}
			else if(letter=='H'){
				lett=8;
			}
			else if(letter=='I'){
				lett=9;
			}
			else if(letter=='J'){
				lett=10;
			}
		}
};
/**************************************************************************************************************************************************************************/
class computer: public player{
	protected:
		char CBOARD[Cmax][Cmax];//Kompiuterio lentele su laivais
		int LETTERS[Cmax], let;
		int NUMBERS[Cmax], numb;
		int DIRECTION[Cmax], dir;
	public:
		void randoms(){
			int LETTERS[11]={10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			let=LETTERS[rand()%10 + 1];
			//////////////////////////////////////////////////////// Raidziu random
			//cout<<endl;
		//	cout<<let<<" CHAR"<<endl;		
			int NUMBERS[11]={10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			numb=NUMBERS[rand()%10 + 1];
			/////////////////////////////////////////////////////// Skaiciu random
		//	cout<<numb<<" INT"<<endl;
			int DIRECTION[5]={4, 1, 2, 3, 4};
			dir=DIRECTION[rand()%4 + 1];
			//////////////////////////////////////////////////////  Krypties random 1- desine, 2- kaire, 3- virsus, 4-apacia
		//	cout<<dir<<" direction";
		}
		void randomships(int n){
			randoms();
			if(dir==1){
				for(int i=let; i<let+n; i++){
					CBOARD[i][numb]='B';
				}
			}
			else if(dir==2){
				for(int i=let+n; i>let; i--){
					CBOARD[i][numb]=='B';
				}
			}
			else if(dir==3){
				for(int i=numb; i<numb+n; i++){
					CBOARD[let][i]=='B';
				}
			}
			else if(dir==4){
				for(int i=numb+n; i>numb; i--){
					CBOARD[let][i]=='B';
				}
			}
			//show(CBOARD);
		}
};
/***************************************************************************************************************************************************************************/
int main(){
	srand (time(NULL));
	char CBOARD[Cmax][Cmax], PBOARD[Cmax][Cmax];
	player A;
	computer B;
	////////////////////////////////////////
	cout<<"Zaidejo zemelapis"<<endl;	////
	A.boardprinting(PBOARD);			////
	cout<<endl;							////
	cout<<"----------------------";		////		Zemelapiu isspausdinimas i ekrana
	cout<<endl;;						////
	cout<<"Kompiuterio zemelapis"<<endl;////
	B.boardprinting(CBOARD);			////
	////////////////////////////////////////
	cout<<endl;
	B.randomships(4);
	cout<<endl;
	//B.show(CBOARD);
	A.ships(4);	
	cout<<endl;
	return 0;
}
