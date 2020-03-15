#ifdef Begin_AI
#include"AI_Data.cpp"
const int sma=2;//<2 out of 32767 
const int smb=666;
const int Beg=7;
inline bool Begin(Gird gird){
	int cnt=0;
	for(int i=1;i<=10;++i)for(int j=1;j<=10;++j)if(gird.G[i][j]!=0)++cnt;
	return cnt<=Beg;
}
inline bool First(Gird gird){
	int cnt=0;
	for(int i=1;i<=10;++i)for(int j=1;j<=10;++j)if(gird.G[i][j]!=0)++cnt;
	return cnt<=3;
}
inline Gird AI_esay(Gird gird){   //The first version.Easy! 
	pair<int,int>res;int mx=-2000000000;
	if(First(gird)){
		for(int i=3;i<=7;++i){
			for(int j=4;j<=8;++j){
				if(!gird.G[i][j]){
					if(debug)cerr<<"IJ: "<<i<<' '<<j<<'\n';
					gird.G[i][j]=2;
					pair<int,int>T=GetCount(gird,2);
					if(gird.Win())return gird;
					if(debug)cerr<<"END GETCOUNT\n";
					int delta=T.second-T.first;
					if(delta>mx){
						mx=delta;
						res=mp(i,j);
					}else if(delta==mx){
						if(rand()<smb){
							mx=delta;
							res=mp(i,j);
						}
					}else{
						if(rand()<sma){
							mx=delta;
							res=mp(i,j);
						}
					}
					gird.G[i][j]=0;
				}
			}
		}
	}else if(Begin(gird)){
		for(int i=1;i<=10;++i){
			for(int j=1;j<=10;++j){
				if(!gird.G[i][j]){
					if(debug)cerr<<"IJ: "<<i<<' '<<j<<'\n';
					gird.G[i][j]=2;
					if(gird.Win())return gird;
					pair<int,int>T=GetCount(gird,2);
					if(debug)cerr<<"END GETCOUNT\n";
					if(T.second>1000000)T.second=10000000;           //Going To die
					if(T.first>1000000)T.first=1000000000;
					int delta=T.second-T.first;
					if(T.first==1000000000){
						gird.G[i][j]=0;
						continue;
					}
					if(delta>mx){
						mx=delta;
						res=mp(i,j);
					}else if(delta==mx){
						if(rand()<smb){
							mx=delta;
							res=mp(i,j);
						}
					}else{
						if(rand()<sma){
							mx=delta;
							res=mp(i,j);
						}
					}
					gird.G[i][j]=0;
				}
			}
		}
		gird.G[res.first][res.second]=2;
		pair<int,int>P=GetCount(gird,2);
		if(P.second-P.first==mx){
			res=res;
		}else{
			gird.G[res.first][res.second]=0;
			for(int i=3;i<=8;++i){
				for(int j=3;j<=8;++j){
					if(!gird.G[i][j]){
						if(debug)cerr<<"IJ: "<<i<<' '<<j<<'\n';
						gird.G[i][j]=2;
						if(gird.Win())return gird;
						pair<int,int>T=GetCount(gird,2);
						if(debug)cerr<<"END GETCOUNT\n";
						if(T.second>1000000)T.second=10000000;           //Going To die
						if(T.first>1000000)T.first=1000000000;
						int delta=T.second-T.first;
						if(T.first==1000000000){
							gird.G[i][j]=0;
							continue;
						}		
						if(delta>mx){
							mx=delta;
							res=mp(i,j);
						}else if(delta==mx){
							if(rand()<smb){
								mx=delta;
								res=mp(i,j);
							}
						}else{
							if(rand()<sma){
								mx=delta;
								res=mp(i,j);
							}
						}
						gird.G[i][j]=0;
					}
				}
			}
		}
	}else{
		for(int i=1;i<=10;++i){
			for(int j=1;j<=10;++j){
				if(!gird.G[i][j]){
					if(debug)cerr<<"IJ: "<<i<<' '<<j<<'\n';
					gird.G[i][j]=2;
					if(gird.Win())return gird;
					pair<int,int>T=GetCount(gird,2);
					if(debug)cerr<<"END GETCOUNT\n";
					if(T.second>1000000)T.second=10000000;           //Going To die
					if(T.first>1000000)T.first=1000000000;
					int delta=T.second-T.first;
					if(T.first==1000000000){
						gird.G[i][j]=0;
						continue;
					}
					if(delta>mx){
						mx=delta;
						res=mp(i,j);
					}else if(delta==mx){
						if(rand()<smb){
							mx=delta;
							res=mp(i,j);
						}
					}else{
						if(rand()<sma){
							mx=delta;
							res=mp(i,j);
						}
					}
					gird.G[i][j]=0;
				}
			}
		}
	}
	if(res.first==0 and res.second==0){
		for(int i=1;i<=10;++i){
			for(int j=1;j<=10;++j){
				if(!gird.G[i][j]){
					if(debug)cerr<<"IJ: "<<i<<' '<<j<<'\n';
					gird.G[i][j]=2;
					if(gird.Win())return gird;
					pair<int,int>T=GetCount(gird,2);
					if(debug)cerr<<"END GETCOUNT\n";
					if(T.second>1000000)T.second=10000000;           //Going To die
					if(T.first>1000000)T.first=1000000000;
					int delta=T.second-T.first;
					if(delta>mx){
						mx=delta;
						res=mp(i,j);
					}else if(delta==mx){
						if(rand()<smb){
							mx=delta;
							res=mp(i,j);
						}
					}else{
						if(rand()<sma){
							mx=delta;
							res=mp(i,j);
						}
					}
					gird.G[i][j]=0;
				}
			}
		}
	}
	gird.G[res.first][res.second]=2;
	return gird;
} 
#endif
