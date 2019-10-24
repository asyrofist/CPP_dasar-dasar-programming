#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int spade[] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
string spade_suit[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
char spade_symbol[]={'S','S','S','S','S','S','S','S','S','S','S','S','S'};
int love[] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
string love_suit[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
char love_symbol[]={'L','L','L','L','L','L','L','L','L','L','L','L','L'};
int club[] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
string club_suit[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
char club_symbol[]={'C','C','C','C','C','C','C','C','C','C','C','C','C'};
int diamond[] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
string diamond_suit[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
char diamond_symbol[]={'D','D','D','D','D','D','D','D','D','D','D','D','D'};
int deck[52];
string deck_suit[52];
char deck_symbol[52];
int nplayer;
int hand[6][5];
string hand_suit[6][5];
char hand_symbol[6][5];
int bin;
string bin_suit;
char bin_symbol;
int tcounter = 0;
int counter = 0;
int w1, w2, w3, w4, w5, w6;

int shuffle(){
	srand(time(0));
	for (int i = 0; i < 52;i++){
		if(i < 13){
			deck[i]=spade[i];
			deck_suit[i]=spade_suit[i];
			deck_symbol[i]=spade_symbol[i];
		} else if(i < 26) {
			deck[i]=love[i-13];
			deck_suit[i]=love_suit[i-13];
			deck_symbol[i]=love_symbol[i-13];
		} else if(i < 39){
			deck[i]=club[i-26];
			deck_suit[i]=club_suit[i-26];
			deck_symbol[i]=club_symbol[i-26];
		} else {
			deck[i]=diamond[i-39];
			deck_suit[i]=diamond_suit[i-39];
			deck_symbol[i]=diamond_symbol[i-39];
		}
	}
	for (int i = 0; i < 100;i++){
		int a, b;
		int decka, deckb;
		string deck_suita, deck_suitb;
		char deck_symbola, deck_symbolb;
		a = rand() % 52;
		b = rand() % 52;
		decka = deck[a];
		deckb = deck[b];
		deck_suita = deck_suit[a];
		deck_suitb = deck_suit[b];
		deck_symbola = deck_symbol[a];
		deck_symbolb = deck_symbol[b];
		if (a != b){
			deck[b]=decka;
			deck[a]=deckb;
			deck_suit[b] = deck_suita;
			deck_suit[a] = deck_suitb;
			deck_symbol[b] = deck_symbola;
			deck_symbol[a] = deck_symbolb;
		}
	}
	for (int i = 0; i < nplayer;i++){
		for (int j = 0; j < 4;j++){
			hand[i][j] = deck[0];
			hand_suit[i][j] = deck_suit[0];
			hand_symbol[i][j] = deck_symbol[0];
			for(int k = 1; k < 52; k++){
				deck[k-1] = deck [k];
				deck_suit[k-1] = deck_suit[k];
				deck_symbol[k-1] = deck_symbol[k];
			}
		}
	}
	return 0;
}

int turn(){
	counter = 1 + tcounter % nplayer;
	tcounter = tcounter + 1;
	return counter;
}

class Player1{
	public:
		void drawfromthedeck(){
			cout << "Player 1 Mengambil Kartu : ";
			cout << deck_suit[0] << deck_symbol[0] << endl;
			hand[0][4] = deck[0];
			hand_suit[0][4] = deck_suit[0];
			hand_symbol[0][4] = deck_symbol[0];
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[0][0] << hand_symbol[0][0] << "   1. " << hand_suit[0][1] << hand_symbol[0][1] << "   2. " << hand_suit[0][2] << hand_symbol[0][2] << "   3. " << hand_suit[0][3] << hand_symbol[0][3] << "   4. " << hand_suit[0][4] << hand_symbol[0][4] << endl;
			cin >> a;
			bin = hand[0][a];
			bin_suit = hand_suit[0][a];
			bin_symbol = hand_symbol[0][a];
			cout << "bin : " << bin_suit << bin_symbol << endl;
			hand[0][a] = hand[0][4];
			hand_suit[0][a] = hand_suit[0][4];
			hand_symbol[0][a] = hand_symbol[0][4];
			cout << "0. " << hand_suit[0][0] << hand_symbol[0][0] << "   1. " << hand_suit[0][1] << hand_symbol[0][1] << "   2. " << hand_suit[0][2] << hand_symbol[0][2] << "   3. " << hand_suit[0][3] << hand_symbol[0][3] << endl;
			for(int i = 1; i < 52; i++){
				deck[i-1] = deck[i];
				deck_suit[i-1] = deck_suit[i];
				deck_symbol[i-1] = deck_symbol[i];
			}
		}
		void takefromthebin(){
			cout << "Player 1 Mengambil Kartu : ";
			cout << bin_suit << bin_symbol << endl;
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[0][0] << hand_symbol[0][0] << "   1. " << hand_suit[0][1] << hand_symbol[0][1] << "   2. " << hand_suit[0][2] << hand_symbol[0][2] << "   3. " << hand_suit[0][3] << hand_symbol[0][3] << endl;
			cin >> a;
			secondbin = hand[0][a];
			secondbin_suit = hand_suit[0][a];
			secondbin_symbol = hand_symbol[0][a];
			hand[0][a] = bin;
			hand_suit[0][a] = bin_suit;
			hand_symbol[0][a] = bin_symbol;
			bin = secondbin;
			bin_suit = secondbin_suit;
			bin_symbol = secondbin_symbol;
			cout << "bin : " << bin_suit << bin_symbol << endl;
		}
		int score(){
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			for (int i = 0; i < 4; i++){
				if (hand_symbol[0][i] == 'S'){
					vS = vS + hand[0][i];
				}
				else if(hand_symbol[0][i] == 'L'){
					vL = vL + hand[0][i];
				}
				else if(hand_symbol[0][i] == 'C'){
					vC = vC + hand[0][i];
				}
				else if(hand_symbol[0][i] == 'D'){
					vD = vD + hand[0][i];
				}
			}
			b = abs(vS-vL);
			c = abs(b-vC);
			totalscore = abs(c-vD);
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			return totalscore;
		}
	private:
		int a, b, c, vS, vL, vC, vD, totalscore;
		int secondbin;
		string secondbin_suit;
		char secondbin_symbol;
};

class Player2{
	public:
		void drawfromthedeck(){
			cout << "Player 2 Mengambil Kartu : ";
			cout << deck_suit[0] << deck_symbol[0] << endl;
			hand[1][4] = deck[0];
			hand_suit[1][4] = deck_suit[0];
			hand_symbol[1][4] = deck_symbol[0];
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[1][0] << hand_symbol[1][0] << "   1. " << hand_suit[1][1] << hand_symbol[1][1] << "   2. " << hand_suit[1][2] << hand_symbol[1][2] << "   3. " << hand_suit[1][3] << hand_symbol[1][3] << "   4. " << hand_suit[1][4] << hand_symbol[1][4] << endl;
			cin >> a;
			bin = hand[1][a];
			bin_suit = hand_suit[1][a];
			bin_symbol = hand_symbol[1][a];
			cout << "bin : " << bin_suit << bin_symbol << endl;
			hand[1][a] = hand[1][4];
			hand_suit[1][a] = hand_suit[1][4];
			hand_symbol[1][a] = hand_symbol[1][4];
			cout << "0. " << hand_suit[1][0] << hand_symbol[1][0] << "   1. " << hand_suit[1][1] << hand_symbol[1][1] << "   2. " << hand_suit[1][2] << hand_symbol[1][2] << "   3. " << hand_suit[1][3] << hand_symbol[1][3] << endl;
			for(int i = 1; i < 52; i++){
				deck[i-1] = deck[i];
				deck_suit[i-1] = deck_suit[i];
				deck_symbol[i-1] = deck_symbol[i];
			}
		}
		void takefromthebin(){
			cout << "Player 2 Mengambil Kartu : ";
			cout << bin_suit << bin_symbol << endl;
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[1][0] << hand_symbol[1][0] << "   1. " << hand_suit[1][1] << hand_symbol[1][1] << "   2. " << hand_suit[1][2] << hand_symbol[1][2] << "   3. " << hand_suit[1][3] << hand_symbol[1][3] << endl;
			cin >> a;
			secondbin = hand[1][a];
			secondbin_suit = hand_suit[1][a];
			secondbin_symbol = hand_symbol[1][a];
			hand[1][a] = bin;
			hand_suit[1][a] = bin_suit;
			hand_symbol[1][a] = bin_symbol;
			bin = secondbin;
			bin_suit = secondbin_suit;
			bin_symbol = secondbin_symbol;
			cout << "bin : " << bin_suit << bin_symbol << endl;
		}
		int score(){
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			for (int i = 0; i < 4; i++){
				if (hand_symbol[1][i] == 'S'){
					vS = vS + hand[1][i];
				}
				else if(hand_symbol[1][i] == 'L'){
					vL = vL + hand[1][i];
				}
				else if(hand_symbol[1][i] == 'C'){
					vC = vC + hand[1][i];
				}
				else if(hand_symbol[1][i] == 'D'){
					vD = vD + hand[1][i];
				}
			}
			b = abs(vS-vL);
			c = abs(b-vC);
			totalscore = abs(c-vD);
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			return totalscore;
		}
		
	private:
		int a, b, c, vS, vL, vC, vD, totalscore;
		int secondbin;
		string secondbin_suit;
		char secondbin_symbol;
};

class Player3{
	public:
		void drawfromthedeck(){
			cout << "Player 3 Mengambil Kartu : ";
			cout << deck_suit[0] << deck_symbol[0] << endl;
			hand[2][4] = deck[0];
			hand_suit[2][4] = deck_suit[0];
			hand_symbol[2][4] = deck_symbol[0];
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[2][0] << hand_symbol[2][0] << "   1. " << hand_suit[2][1] << hand_symbol[2][1] << "   2. " << hand_suit[2][2] << hand_symbol[2][2] << "   3. " << hand_suit[2][3] << hand_symbol[2][3] << "   4. " << hand_suit[2][4] << hand_symbol[2][4] << endl;
			cin >> a;
			bin = hand[2][a];
			bin_suit = hand_suit[2][a];
			bin_symbol = hand_symbol[2][a];
			cout << "bin : " << bin_suit << bin_symbol << endl;
			hand[2][a] = hand[2][4];
			hand_suit[2][a] = hand_suit[2][4];
			hand_symbol[2][a] = hand_symbol[2][4];
			cout << "0. " << hand_suit[2][0] << hand_symbol[2][0] << "   1. " << hand_suit[2][1] << hand_symbol[2][1] << "   2. " << hand_suit[2][2] << hand_symbol[2][2] << "   3. " << hand_suit[2][3] << hand_symbol[2][3] << endl;
			for(int i = 1; i < 52; i++){
				deck[i-1] = deck[i];
				deck_suit[i-1] = deck_suit[i];
				deck_symbol[i-1] = deck_symbol[i];
			}
		}
		void takefromthebin(){
			cout << "Player 3 Mengambil Kartu : ";
			cout << bin_suit << bin_symbol << endl;
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[2][0] << hand_symbol[2][0] << "   1. " << hand_suit[2][1] << hand_symbol[2][1] << "   2. " << hand_suit[2][2] << hand_symbol[2][2] << "   3. " << hand_suit[2][3] << hand_symbol[2][3] << endl;
			cin >> a;
			secondbin = hand[2][a];
			secondbin_suit = hand_suit[2][a];
			secondbin_symbol = hand_symbol[2][a];
			hand[2][a] = bin;
			hand_suit[2][a] = bin_suit;
			hand_symbol[2][a] = bin_symbol;
			bin = secondbin;
			bin_suit = secondbin_suit;
			bin_symbol = secondbin_symbol;
			cout << "bin : " << bin_suit << bin_symbol << endl;
		}
		int score(){
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			for (int i = 0; i < 4; i++){
				if (hand_symbol[2][i] == 'S'){
					vS = vS + hand[2][i];
				}
				else if(hand_symbol[2][i] == 'L'){
					vL = vL + hand[2][i];
				}
				else if(hand_symbol[2][i] == 'C'){
					vC = vC + hand[2][i];
				}
				else if(hand_symbol[2][i] == 'D'){
					vD = vD + hand[2][i];
				}
			}
			b = abs(vS-vL);
			c = abs(b-vC);
			totalscore = abs(c-vD);
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			return totalscore;
		}
		
	private:
		int a, b, c, vS, vL, vC, vD, totalscore;
		int secondbin;
		string secondbin_suit;
		char secondbin_symbol;
};

class Player4{
	public:
		void drawfromthedeck(){
			cout << "Player 4 Mengambil Kartu : ";
			cout << deck_suit[0] << deck_symbol[0] << endl;
			hand[3][4] = deck[0];
			hand_suit[3][4] = deck_suit[0];
			hand_symbol[3][4] = deck_symbol[0];
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[3][0] << hand_symbol[3][0] << "   1. " << hand_suit[3][1] << hand_symbol[3][1] << "   2. " << hand_suit[3][2] << hand_symbol[3][2] << "   3. " << hand_suit[3][3] << hand_symbol[3][3] << "   4. " << hand_suit[3][4] << hand_symbol[3][4] << endl;
			cin >> a;
			bin = hand[3][a];
			bin_suit = hand_suit[3][a];
			bin_symbol = hand_symbol[3][a];
			cout << "bin : " << bin_suit << bin_symbol << endl;
			hand[3][a] = hand[3][4];
			hand_suit[3][a] = hand_suit[3][4];
			hand_symbol[3][a] = hand_symbol[3][4];
			cout << "0. " << hand_suit[3][0] << hand_symbol[3][0] << "   1. " << hand_suit[3][1] << hand_symbol[3][1] << "   2. " << hand_suit[3][2] << hand_symbol[3][2] << "   3. " << hand_suit[3][3] << hand_symbol[3][3] << endl;
			for(int i = 1; i < 52; i++){
				deck[i-1] = deck[i];
				deck_suit[i-1] = deck_suit[i];
				deck_symbol[i-1] = deck_symbol[i];
			}
		}
		void takefromthebin(){
			cout << "Player 4 Mengambil Kartu : ";
			cout << bin_suit << bin_symbol << endl;
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[3][0] << hand_symbol[3][0] << "   1. " << hand_suit[3][1] << hand_symbol[3][1] << "   2. " << hand_suit[3][2] << hand_symbol[3][2] << "   3. " << hand_suit[3][3] << hand_symbol[3][3] << endl;
			cin >> a;
			secondbin = hand[3][a];
			secondbin_suit = hand_suit[3][a];
			secondbin_symbol = hand_symbol[3][a];
			hand[3][a] = bin;
			hand_suit[3][a] = bin_suit;
			hand_symbol[3][a] = bin_symbol;
			bin = secondbin;
			bin_suit = secondbin_suit;
			bin_symbol = secondbin_symbol;
			cout << "bin : " << bin_suit << bin_symbol << endl;
		}
		int score(){
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			for (int i = 0; i < 4; i++){
				if (hand_symbol[3][i] == 'S'){
					vS = vS + hand[3][i];
				}
				else if(hand_symbol[3][i] == 'L'){
					vL = vL + hand[3][i];
				}
				else if(hand_symbol[3][i] == 'C'){
					vC = vC + hand[3][i];
				}
				else if(hand_symbol[3][i] == 'D'){
					vD = vD + hand[3][i];
				}
			}
			b = abs(vS-vL);
			c = abs(b-vC);
			totalscore = abs(c-vD);
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			return totalscore;
		}
		
	private:
		int a, b, c, vS, vL, vC, vD, totalscore;
		int secondbin;
		string secondbin_suit;
		char secondbin_symbol;
};

class Player5{
	public:
		void drawfromthedeck(){
			cout << "Player 5 Mengambil Kartu : ";
			cout << deck_suit[0] << deck_symbol[0] << endl;
			hand[4][4] = deck[0];
			hand_suit[4][4] = deck_suit[0];
			hand_symbol[4][4] = deck_symbol[0];
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[4][0] << hand_symbol[4][0] << "   1. " << hand_suit[4][1] << hand_symbol[4][1] << "   2. " << hand_suit[4][2] << hand_symbol[4][2] << "   3. " << hand_suit[4][3] << hand_symbol[4][3] << "   4. " << hand_suit[4][4] << hand_symbol[4][4] << endl;
			cin >> a;
			bin = hand[4][a];
			bin_suit = hand_suit[4][a];
			bin_symbol = hand_symbol[4][a];
			cout << "bin : " << bin_suit << bin_symbol << endl;
			hand[4][a] = hand[4][4];
			hand_suit[4][a] = hand_suit[4][4];
			hand_symbol[4][a] = hand_symbol[4][4];
			cout << "0. " << hand_suit[4][0] << hand_symbol[4][0] << "   1. " << hand_suit[4][1] << hand_symbol[4][1] << "   2. " << hand_suit[4][2] << hand_symbol[4][2] << "   3. " << hand_suit[4][3] << hand_symbol[4][3] << endl;
			for(int i = 1; i < 52; i++){
				deck[i-1] = deck[i];
				deck_suit[i-1] = deck_suit[i];
				deck_symbol[i-1] = deck_symbol[i];
			}
		}
		void takefromthebin(){
			cout << "Player 5 Mengambil Kartu : ";
			cout << bin_suit << bin_symbol << endl;
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[4][0] << hand_symbol[4][0] << "   1. " << hand_suit[4][1] << hand_symbol[4][1] << "   2. " << hand_suit[4][2] << hand_symbol[4][2] << "   3. " << hand_suit[4][3] << hand_symbol[4][3] << endl;
			cin >> a;
			secondbin = hand[4][a];
			secondbin_suit = hand_suit[4][a];
			secondbin_symbol = hand_symbol[4][a];
			hand[4][a] = bin;
			hand_suit[4][a] = bin_suit;
			hand_symbol[4][a] = bin_symbol;
			bin = secondbin;
			bin_suit = secondbin_suit;
			bin_symbol = secondbin_symbol;
			cout << "bin : " << bin_suit << bin_symbol << endl;
		}
		int score(){
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			for (int i = 0; i < 4; i++){
				if (hand_symbol[4][i] == 'S'){
					vS = vS + hand[4][i];
				}
				else if(hand_symbol[4][i] == 'L'){
					vL = vL + hand[4][i];
				}
				else if(hand_symbol[4][i] == 'C'){
					vC = vC + hand[4][i];
				}
				else if(hand_symbol[4][i] == 'D'){
					vD = vD + hand[4][i];
				}
			}
			b = abs(vS-vL);
			c = abs(b-vC);
			totalscore = abs(c-vD);
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			return totalscore;
		}
		
	private:
		int a, b, c, vS, vL, vC, vD, totalscore;
		int secondbin;
		string secondbin_suit;
		char secondbin_symbol;
};

class Player6{
	public:
		void drawfromthedeck(){
			cout << "Player 6 Mengambil Kartu : ";
			cout << deck_suit[0] << deck_symbol[0] << endl;
			hand[5][4] = deck[0];
			hand_suit[5][4] = deck_suit[0];
			hand_symbol[5][4] = deck_symbol[0];
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[5][0] << hand_symbol[5][0] << "   1. " << hand_suit[5][1] << hand_symbol[5][1] << "   2. " << hand_suit[5][2] << hand_symbol[5][2] << "   3. " << hand_suit[5][3] << hand_symbol[5][3] << "   4. " << hand_suit[5][4] << hand_symbol[5][4] << endl;
			cin >> a;
			bin = hand[5][a];
			bin_suit = hand_suit[5][a];
			bin_symbol = hand_symbol[5][a];
			cout << "bin : " << bin_suit << bin_symbol << endl;
			hand[5][a] = hand[5][4];
			hand_suit[5][a] = hand_suit[5][4];
			hand_symbol[5][a] = hand_symbol[5][4];
			cout << "0. " << hand_suit[5][0] << hand_symbol[5][0] << "   1. " << hand_suit[5][1] << hand_symbol[5][1] << "   2. " << hand_suit[5][2] << hand_symbol[5][2] << "   3. " << hand_suit[5][3] << hand_symbol[5][3] << endl;
			for(int i = 1; i < 52; i++){
				deck[i-1] = deck[i];
				deck_suit[i-1] = deck_suit[i];
				deck_symbol[i-1] = deck_symbol[i];
			}
		}
		void takefromthebin(){
			cout << "Player 6 Mengambil Kartu : ";
			cout << bin_suit << bin_symbol << endl;
			cout << "Pilih kartu yang akan dibuang!" << endl;
			cout << "0. " << hand_suit[5][0] << hand_symbol[5][0] << "   1. " << hand_suit[5][1] << hand_symbol[5][1] << "   2. " << hand_suit[5][2] << hand_symbol[5][2] << "   3. " << hand_suit[5][3] << hand_symbol[5][3] << endl;
			cin >> a;
			secondbin = hand[5][a];
			secondbin_suit = hand_suit[5][a];
			secondbin_symbol = hand_symbol[5][a];
			hand[5][a] = bin;
			hand_suit[5][a] = bin_suit;
			hand_symbol[5][a] = bin_symbol;
			bin = secondbin;
			bin_suit = secondbin_suit;
			bin_symbol = secondbin_symbol;
			cout << "bin : " << bin_suit << bin_symbol << endl;
		}
		int score(){
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			for (int i = 0; i < 4; i++){
				if (hand_symbol[5][i] == 'S'){
					vS = vS + hand[5][i];
				}
				else if(hand_symbol[5][i] == 'L'){
					vL = vL + hand[5][i];
				}
				else if(hand_symbol[5][i] == 'C'){
					vC = vC + hand[5][i];
				}
				else if(hand_symbol[5][i] == 'D'){
					vD = vD + hand[5][i];
				}
			}
			b = abs(vS-vL);
			c = abs(b-vC);
			totalscore = abs(c-vD);
			vS = 0;
			vL = 0;
			vC = 0;
			vD = 0;
			return totalscore;
		}
		
	private:
		int a, b, c, vS, vL, vC, vD, totalscore;
		int secondbin;
		string secondbin_suit;
		char secondbin_symbol;
};

int main(){
	cout << "Selamat Datang di EmpatSatu!"<<endl;
	do{
		cout << "Masukkan Jumlah Pemain (2 Sampai 6)" << endl;
		cin >> nplayer;
	} while(nplayer < 2 || nplayer > 6);
	shuffle();
	Player1 Saya;
	Player2 Aku;
	Player3 Kulo;
	Player4 Beta;
	Player5 Ambo;
	Player6 Awak;
	for (int i = 0; i <= nplayer;){
		int jawab;
		cout << "Lanjut Main? (1. Ya 2. Tidak)" << endl;
		cin >> jawab;
		if (jawab == 1){
			cout << "Sekarang Giliran : Player " << turn() << endl;
			if (counter == 1){
				cout << "Kartu di Tangan : " << "0. " << hand_suit[0][0] << hand_symbol[0][0] << "   1. " << hand_suit[0][1] << hand_symbol[0][1] << "   2. " << hand_suit[0][2] << hand_symbol[0][2] << "   3. " << hand_suit[0][3] << hand_symbol[0][3] << endl;
				cout << "Draw dari Deck atau Take dari Bin? 1. Draw   2. Take" << endl;
				int a, w;
				cin >> a;
				if (a == 1){
					Saya.drawfromthedeck();
					w = Saya.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 1 Menang!" << endl;
						break;
					}
				}
				else {
					Saya.takefromthebin();
					w = Saya.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 1 Menang!" << endl;
						break;
					}
				}
				w1 = w;
				cout << "Kartu di Tangan : " << "0. " << hand_suit[0][0] << hand_symbol[0][0] << "   1. " << hand_suit[0][1] << hand_symbol[0][1] << "   2. " << hand_suit[0][2] << hand_symbol[0][2] << "   3. " << hand_suit[0][3] << hand_symbol[0][3] << endl;
			}
			else if (counter == 2){
				cout << "Kartu di Tangan : " << "0. " << hand_suit[1][0] << hand_symbol[1][0] << "   1. " << hand_suit[1][1] << hand_symbol[1][1] << "   2. " << hand_suit[1][2] << hand_symbol[1][2] << "   3. " << hand_suit[1][3] << hand_symbol[1][3] << endl;
				cout << "Draw dari Deck atau Take dari Bin? 1. Draw   2. Take" << endl;
				int a, w;
				cin >> a;
				if (a == 1){
					Aku.drawfromthedeck();
					w = Aku.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 2 Menang!" << endl;
						break;
					}
				}
				else {
					Aku.takefromthebin();
					w = Aku.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 2 Menang!" << endl;
						break;
					}
				}
				w2 = w;
				cout << "Kartu di Tangan : " << "0. " << hand_suit[1][0] << hand_symbol[1][0] << "   1. " << hand_suit[1][1] << hand_symbol[1][1] << "   2. " << hand_suit[1][2] << hand_symbol[1][2] << "   3. " << hand_suit[1][3] << hand_symbol[1][3] << endl;
			}
			else if (counter == 3){
				cout << "Kartu di Tangan : " << "0. " << hand_suit[2][0] << hand_symbol[2][0] << "   1. " << hand_suit[2][1] << hand_symbol[2][1] << "   2. " << hand_suit[2][2] << hand_symbol[2][2] << "   3. " << hand_suit[2][3] << hand_symbol[2][3] << endl;
				cout << "Draw dari Deck atau Take dari Bin? 1. Draw   2. Take" << endl;
				int a, w;
				cin >> a;
				if (a == 1){
					Kulo.drawfromthedeck();
					w = Kulo.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 3 Menang!" << endl;
						break;
					}
				}
				else {
					Kulo.takefromthebin();
					w = Kulo.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 3 Menang!" << endl;
						break;
					}
				}
				w3 = w;
				cout << "Kartu di Tangan : " << "0. " << hand_suit[2][0] << hand_symbol[2][0] << "   1. " << hand_suit[2][1] << hand_symbol[2][1] << "   2. " << hand_suit[2][2] << hand_symbol[2][2] << "   3. " << hand_suit[2][3] << hand_symbol[2][3] << endl;
			}
			else if (counter == 4){
				cout << "Kartu di Tangan : " << "0. " << hand_suit[3][0] << hand_symbol[3][0] << "   1. " << hand_suit[3][1] << hand_symbol[3][1] << "   2. " << hand_suit[3][2] << hand_symbol[3][2] << "   3. " << hand_suit[3][3] << hand_symbol[3][3] << endl;
				cout << "Draw dari Deck atau Take dari Bin? 1. Draw   2. Take" << endl;
				int a, w;
				cin >> a;
				if (a == 1){
					Beta.drawfromthedeck();
					w = Beta.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 4 Menang!" << endl;
						break;
					}
				}
				else {
					Beta.takefromthebin();
					w = Beta.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 4 Menang!" << endl;
						break;
					}
				}
				w4 = w;
				cout << "Kartu di Tangan : " << "0. " << hand_suit[3][0] << hand_symbol[3][0] << "   1. " << hand_suit[3][1] << hand_symbol[3][1] << "   2. " << hand_suit[3][2] << hand_symbol[3][2] << "   3. " << hand_suit[3][3] << hand_symbol[3][3] << endl;
			}
			else if (counter == 5){
				cout << "Kartu di Tangan : " << "0. " << hand_suit[4][0] << hand_symbol[4][0] << "   1. " << hand_suit[4][1] << hand_symbol[4][1] << "   2. " << hand_suit[4][2] << hand_symbol[4][2] << "   3. " << hand_suit[4][3] << hand_symbol[4][3] << endl;
				cout << "Draw dari Deck atau Take dari Bin? 1. Draw   2. Take" << endl;
				int a, w;
				cin >> a;
				if (a == 1){
					Ambo.drawfromthedeck();
					w = Ambo.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 5 Menang!" << endl;
						break;
					}
				}
				else {
					Ambo.takefromthebin();
					w = Ambo.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 5 Menang!" << endl;
						break;
					}
				}
				w5 = w;
				cout << "Kartu di Tangan : " << "0. " << hand_suit[4][0] << hand_symbol[4][0] << "   1. " << hand_suit[4][1] << hand_symbol[4][1] << "   2. " << hand_suit[4][2] << hand_symbol[4][2] << "   3. " << hand_suit[4][3] << hand_symbol[4][3] << endl;
			}
			else if (counter == 6){
				cout << "Kartu di Tangan : " << "0. " << hand_suit[5][0] << hand_symbol[5][0] << "   1. " << hand_suit[5][1] << hand_symbol[5][1] << "   2. " << hand_suit[5][2] << hand_symbol[5][2] << "   3. " << hand_suit[5][3] << hand_symbol[5][3] << endl;
				cout << "Draw dari Deck atau Take dari Bin? 1. Draw   2. Take" << endl;
				int a, w;
				cin >> a;
				if (a == 1){
					Awak.drawfromthedeck();
					w = Awak.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 6 Menang!" << endl;
						break;
					}
				}
				else {
					Awak.takefromthebin();
					w = Awak.score();
					cout << "Skor : " << w << endl;
					if (w == 41){
						cout << "Player 6 Menang!" << endl;
						break;
					}
				}
				w6 = w;
				cout << "Kartu di Tangan : " << "0. " << hand_suit[5][0] << hand_symbol[5][0] << "   1. " << hand_suit[5][1] << hand_symbol[5][1] << "   2. " << hand_suit[5][2] << hand_symbol[5][2] << "   3. " << hand_suit[5][3] << hand_symbol[5][3] << endl;
			}
		} else {
			cout << "Skor Player 1 : " << w1 << "   Skor Player 2 : " << w2 << "   Skor Player 3 : " << w3 << endl;
			cout << "Skor Player 4 : " << w4 << "   Skor Player 5 : " << w5 << "   Skor Player 6 : " << w6 << endl;
			if (w1 > w2 && w1 > w3 && w1 > w4 && w1 > w5 && w1 > w6){
				cout << "Player 1 Menang!" << endl;
			} else if (w2 > w1 && w2 > w3 && w2 > w4 && w2 > w5 && w2 > w6){
				cout << "Player 2 Menang!" << endl;
			} else if (w3 > w1 && w3 > w2 && w3 > w4 && w3 > w5 && w3 > w6){
				cout << "Player 3 Menang!" << endl;
			} else if (w4 > w1 && w4 > w2 && w4 > w3 && w4 > w5 && w4 > w6){
				cout << "Player 4 Menang!" << endl;
			} else if (w5 > w1 && w5 > w2 && w5 > w3 && w5 > w4 && w5 > w6){
				cout << "Player 5 Menang!" << endl;
			} else if (w6 > w1 && w6 > w2 && w6 > w3 && w6 > w4 && w6 > w5){
				cout << "Player 6 Menang!" << endl;
			} else{
				cout << "Draw!" << endl;
			}
			break;
		}
	}
}
