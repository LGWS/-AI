//10*10版本的 
//这其实是个人工智障 
//有点智商了 
#include<windows.h>
#include<bits/stdc++.h>
#define Begin_AI
#define uint unsigned int
#define ll long long
#define ld long double
#define mp make_pair
using namespace std;
int debug=0;
inline void Load(){
	cout<<"Loading.......\n";
	for(int i=0;i<20;++i){
		cout<<'-';
		Sleep(rand()%80+10); 
	}cout<<'\n';
}
#include"data.cpp"
#include"AI.cpp"
#include"Player_to_player.cpp"
#include"Player_to_computer.cpp"
int main(){
	srand(time(NULL)*3+1);
	srand(time(NULL)+64*rand()+123);
	if(!debug){
		cout<<"Welcome to the Backgammon Game!\n";
		Sleep(1200);
		cout<<"Let's Begin!\n";
		Sleep(800);
		cout<<"Have a good time!\n";
		Sleep(1500);
		Load();		
	}
	for(;;){
		int Type;
		cout<<"-----------------------------------------------\n";
		cout<<"Type 1:Player VS Player\n";
		cout<<"Type 2:Player VS Computer\n";
		cout<<"Type 3:Exit the game\n";
		cout<<"Please enter the type number\n";
		cin>>Type;
		if(Type==1){
			if(!debug){
				cout<<"The first player is X.\n";
				Sleep(500);
				cout<<"The second player is O.\n";
				Sleep(500);				
			}
			Player_to_player(); 
		}
		if(Type==2){
			if(!debug){
				cout<<"You are X.\n"; 
				Sleep(500);
				cout<<"Computer is O.\n";
				Sleep(500);				
			}
			Player_to_computer();
		}
		if(Type==3){
			exit(0);
		}
	}
}
