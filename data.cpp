#ifdef Begin_AI
struct Gird{
	int G[12][12];//None:0 Player:1 Computer:2
	inline void init(){
		memset(G,0,sizeof(G));
		for(int i=0;i<=11;++i)G[i][0]=3,G[i][11]=3;
		for(int i=0;i<=11;++i)G[0][i]=3,G[11][i]=3;
	}
	inline int check_row(int x,int y){
		if(y+4>10)return 0;
		bool all=1;
		for(int i=x,j=y;j<y+5;++j)if(G[i][j]!=G[x][y])all=0;
		if(all==1 and G[x][y])return G[x][y];
		return 0;
	}
	inline int check_col(int x,int y){
		if(x+4>10)return 0;
		bool all=1;
		for(int i=x,j=y;i<x+5;++i)if(G[i][j]!=G[x][y])all=0;
		if(all==1 and G[x][y])return G[x][y];
		return 0;
	}
	inline int check_sla1(int x,int y){
		if(x+4>10 or y+4>10)return 0;
		bool all=1;
		for(int i=x,j=y;i<x+5,j<y+5;++i,++j)if(G[i][j]!=G[x][y])all=0;
		if(all==1 and G[x][y])return G[x][y];
		return 0;
	}
	inline int check_sla2(int x,int y){
		if(x+4>10 or y-4<1)return 0;
		bool all=1;
		for(int i=x,j=y;i<x+5,j>y-5;++i,--j)if(G[i][j]!=G[x][y])all=0;
		if(all==1 and G[x][y])return G[x][y];
		return 0;
	}
	inline int Win(){
		for(int i=1;i<=10;++i){
			for(int j=1;j<=10;++j){
				int T;
				T=check_row(i,j);
				if(T!=0)return T;
				T=check_col(i,j);
				if(T!=0)return T;
				T=check_sla1(i,j);
				if(T!=0)return T;
				T=check_sla2(i,j);
				if(T!=0)return T;
			}
		}
	}
	inline char Get(int x){
		if(x==0)return '.';
		if(x==1)return 'X';
		if(x==2)return 'O';
	}
	inline void Print(int Turn){
		system("cls");
		cout<<"Turn To: "<<Get(Turn)<<'\n';
		cout<<"   1 2 3 4 5 6 7 8 9 10\n";
		for(int i=1;i<=10;++i){
			cout<<i<<" ";
			if(i!=10)cout<<" ";
			for(int j=1;j<=10;++j)cout<<Get(G[i][j])<<' ';cout<<'\n';
		}
	}
	inline void Debug_Print(int Turn){
//		system("cls");
		cout<<"Turn To: "<<Get(Turn)<<'\n';
		cout<<"   1 2 3 4 5 6 7 8 9 10\n";
		for(int i=1;i<=10;++i){
			cout<<i<<" ";
			if(i!=10)cout<<" ";
			for(int j=1;j<=10;++j)cout<<Get(G[i][j])<<' ';cout<<'\n';
		}
	}
};
inline int Next_Turn(int x){
	if(x==1)return 2;
	return 1;
}
#endif
