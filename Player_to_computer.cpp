#ifdef Begin_AI
inline void Player_to_computer(){
	cout<<"Input 1 if you want first,otherwise input 2.\n";
	int T;cin>>T;
	int Now_Turn=T;
	Load();
	system("cls");
	Gird gird;
	gird.init();
	for(;!gird.Win();){
		int x,y;
		gird.Print(Now_Turn);
		if(Now_Turn==1){
			for(;;){
				cout<<"Input where your chess put: \n";
				cout<<"Line: ";cin>>x;cout<<'\n';
				cout<<"Column: ";cin>>y;cout<<'\n';
				if(!gird.G[x][y] and x<=10 and y<=10 and x>=1 and y>=1)break;
				cout<<"Wrong Input!\nPlease enter it again.\n";
			}
			gird.G[x][y]=Now_Turn;			
		}else{
			gird=AI_esay(gird);
		}
		if(gird.Win()!=0){
			gird.Print(Now_Turn);
			cout<<gird.Get(Now_Turn)<<" wins!\n";
			return;
		}
		Now_Turn=Next_Turn(Now_Turn);
	}
}
#endif
