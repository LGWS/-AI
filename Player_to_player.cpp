#ifdef Begin_AI
inline void Player_to_player(){
	int Now_Turn=1;
	Load();
	system("cls");
	Gird gird;
	gird.init();
	for(;!gird.Win();){
		int x,y;
		gird.Print(Now_Turn);
		for(;;){
			cout<<"Input where your chess put: \n";
			cout<<"Line: ";cin>>x;cout<<'\n';
			cout<<"Column: ";cin>>y;cout<<'\n';
			if(!gird.G[x][y] and x<=10 and y<=10 and x>=1 and y>=1)break;
			cout<<"Wrong Input!\nPlease enter it again.\n";
		}
		gird.G[x][y]=Now_Turn;
		if(gird.Win()!=0){
			cout<<gird.Get(Now_Turn)<<" wins!\n";
			return;
		}
		Now_Turn=Next_Turn(Now_Turn);
	}
}
#endif
