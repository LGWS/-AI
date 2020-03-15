#ifdef Begin_AI
int zhihuo[2][6]={{0,5,25,84,1000000,10000000},{0,4,18,1000000,1000000,10000000}};  //0 ох 1 ╨С 
int xiehuo[2][6]={{0,5,30,96,1000000,10000000},{0,4,24,1000000,1000000,10000000}};
int zhichong[2][6]={{0,2,20,42,1000000,10000000},{0,3,10,102,1000000,10000000}};
int xiechong[2][6]={{0,3,25,63,1000000,10000000},{0,3,15,110,1000000,10000000}};
int zhisi[2][6]={{0,1,10,15,125,10000000},{0,1,10,45,120,10000000}};
int xiesi[2][6]={{0,1,10,18,160,10000000},{0,1,10,59,140,10000000}};
int zhikong[2][6]={{0,4,42,232,1000000,10000000},{0,5,44,1000000,1000000,10000000}};
int xiekong[2][6]={{0,3,45,240,1000000,10000000},{0,3,50,1000000,1000000,10000000}}; //left+right
//huo
inline bool henzhihuo(Gird gird,int x,int y,int k){
	if(y+k>11)return 0;
	bool all=1;
	for(int i=x,j=y;j<y+k;++j)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and (gird.G[x][y-1]==0) and (gird.G[x][y+k]==0))return 1;
	return 0;
}
inline bool shuzhihuo(Gird gird,int x,int y,int k){
	if(x+k>11)return 0;
	bool all=1;
	for(int i=x,j=y;i<x+k;++i)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and (gird.G[x-1][y]==0) and (gird.G[x+k][y]==0))return 1;
	return 0;
}
inline bool xiaxiehuo(Gird gird,int x,int y,int k){ 
	if(y+k>11 or y+k>11)return 0;
	bool all=1;
	for(int i=x,j=y;i<x+k and j<y+k;++i,++j)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and (gird.G[x-1][y-1]==0) and (gird.G[x+k][y+k]==0))return 1;
	return 0;
}
inline bool shangxiehuo(Gird gird,int x,int y,int k){
	if(x+k>11 or y-k<0)return 0;
	bool all=1;
	for(int i=x,j=y;i<x+k and j>y-k;++i,--j)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and (gird.G[x-1][y+1]==0) and (gird.G[x+k][y-k]==0))return 1;
	return 0;
}
inline bool iszhihuo(Gird gird,int x,int y,int k){
	return henzhihuo(gird,x,y,k) or shuzhihuo(gird,x,y,k);
}
inline bool isxiehuo(Gird gird,int x,int y,int k){
	return shangxiehuo(gird,x,y,k) or xiaxiehuo(gird,x,y,k);
}

//chong
inline bool henzhichong(Gird gird,int x,int y,int k){
	if(y+k>11)return 0;
	bool all=1;
	for(int i=x,j=y;j<y+k;++j)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and ((gird.G[x][y-1]==0)+(gird.G[x][y+k]==0))==1)return 1;
	return 0;
}
inline bool shuzhichong(Gird gird,int x,int y,int k){
	if(x+k>11)return 0;
	bool all=1;
	for(int i=x,j=y;i<x+k;++i)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and ((gird.G[x-1][y]==0)+(gird.G[x+k][y]==0))==1)return 1;
	return 0;
}
inline bool xiaxiechong(Gird gird,int x,int y,int k){
	if(y+k>11 or y+k>11)return 0;
	bool all=1;
	for(int i=x,j=y;i<x+k and j<y+k;++i,++j)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and ((gird.G[x-1][y-1]==0)+(gird.G[x+k][y+k]==0))==1)return 1;
	return 0;
}
inline bool shangxiechong(Gird gird,int x,int y,int k){
	if(x+k>11 or y-k<0)return 0;
	bool all=1;
	for(int i=x,j=y;i<x+k and j>y-k;++i,--j)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and ((gird.G[x-1][y+1]==0)+(gird.G[x+k][y-k]==0))==1)return 1;
	return 0;
}
inline bool iszhichong(Gird gird,int x,int y,int k){
	return henzhichong(gird,x,y,k) or shuzhichong(gird,x,y,k);
}
inline bool isxiechong(Gird gird,int x,int y,int k){
	return shangxiechong(gird,x,y,k) or xiaxiechong(gird,x,y,k);
}

//si
inline bool henzhisi(Gird gird,int x,int y,int k){
	if(y+k>11)return 0;
	bool all=1;
	for(int i=x,j=y;j<y+k;++j)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and ((gird.G[x][y-1]==0)+(gird.G[x][y+k]==0))==2)return 1;
	return 0;
}
inline bool shuzhisi(Gird gird,int x,int y,int k){
	if(x+k>11)return 0;
	bool all=1;
	for(int i=x,j=y;i<x+k;++i)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and ((gird.G[x-1][y]==0)+(gird.G[x+k][y]==0))==2)return 1;
	return 0;
}
inline bool xiaxiesi(Gird gird,int x,int y,int k){
	if(y+k>11 or y+k>11)return 0;
	bool all=1;
	for(int i=x,j=y;i<x+k and j<y+k;++i,++j)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and ((gird.G[x-1][y-1]==0)+(gird.G[x+k][y+k]==0))==2)return 1;
	return 0;
}
inline bool shangxiesi(Gird gird,int x,int y,int k){
	if(x+k>11 or y-k<0)return 0;
	bool all=1;
	for(int i=x,j=y;i<x+k and j>y-k;++i,--j)if(gird.G[i][j]!=gird.G[x][y])all=0;
	if(gird.G[x][y] and all and ((gird.G[x-1][y+1]==0)+(gird.G[x+k][y-k]==0))==2)return 1;
	return 0;
}
inline bool iszhisi(Gird gird,int x,int y,int k){
	return henzhisi(gird,x,y,k) or shuzhisi(gird,x,y,k);
}
inline bool isxiesi(Gird gird,int x,int y,int k){
	return shangxiesi(gird,x,y,k) or xiaxiesi(gird,x,y,k);
}
//kong
inline bool henzhikong(Gird gird,int x,int y,int k){
	if(y+k>10)return 0;
	int all=2;
	for(int i=x,j=y;j<y+k+1;++j)if(gird.G[i][j]==3-gird.G[x][y])all=0;else if(gird.G[i][j]==0)--all;
	if(gird.G[x][y] and all==1 and ((gird.G[x][y-1]!=3-gird.G[x][y]) or (gird.G[x][y+k+1]!=3-gird.G[x][y])))return 1;
	return 0;
}
inline bool shuzhikong(Gird gird,int x,int y,int k){
	if(x+k>10)return 0;
	int all=2;
	for(int i=x,j=y;i<x+k+1;++i)if(gird.G[i][j]==3-gird.G[x][y])all=0;else if(gird.G[i][j]==0)--all;
	if(gird.G[x][y] and all==1 and ((gird.G[x-1][y]!=3-gird.G[x][y]) or (gird.G[x+k+1][y]!=3-gird.G[x][y])))return 1;
	return 0;
}
inline bool xiaxiekong(Gird gird,int x,int y,int k){
	if(x+k>10 or y+k>10)return 0;
	int all=2;
	for(int i=x,j=y;i<x+k+1 and j<y+k+1;++i,++j)if(gird.G[i][j]==3-gird.G[x][y])all=0;else if(gird.G[i][j]==0)--all;
	if(gird.G[x][y] and all==1 and ((gird.G[x-1][y-1]!=3-gird.G[x][y]) or (gird.G[x+k+1][y+k+1]!=3-gird.G[x][y])))return 1;
	return 0;
}
inline bool shangxiekong(Gird gird,int x,int y,int k){
	if(x+k>10 or y-k<1)return 0;
	int all=2;
	for(int i=x,j=y;i<x+k+1 and j>y-k-1;++i,--j)if(gird.G[i][j]==3-gird.G[x][y])all=0;else if(gird.G[i][j]==0)--all;
	if(gird.G[x][y] and all==1 and ((gird.G[x-1][y+1]!=3-gird.G[x][y]) or (gird.G[x+k+1][y-k-1]!=3-gird.G[x][y])))return 1;
	return 0;
}
inline bool iszhikong(Gird gird,int x,int y,int k){
	return henzhikong(gird,x,y,k) or shuzhikong(gird,x,y,k);
}
inline bool isxiekong(Gird gird,int x,int y,int k){
	return shangxiekong(gird,x,y,k) or xiaxiekong(gird,x,y,k);
}
inline pair<int,int> CountValue(Gird gird,pair<int,int>isxs){
	if(debug)gird.Debug_Print(1);
	int val[3];val[0]=0,val[1]=0,val[2]=0;
	int xs[3];xs[1]=isxs.first;xs[2]=isxs.second;
	for(int i=1;i<=10;++i){
		for(int j=1;j<=10;++j){
			for(int k=1;k<=5;++k){
				if(gird.G[i][j]==0)continue;if(debug)cout<<i<<' '<<j<<' '<<k<<' '<<gird.G[i][j]<<'\n';
				if(iszhihuo(gird,i,j,k))val[gird.G[i][j]]+=zhihuo[xs[gird.G[i][j]]][k];	
				if(isxiehuo(gird,i,j,k))val[gird.G[i][j]]+=xiehuo[xs[gird.G[i][j]]][k];
				if(iszhichong(gird,i,j,k))val[gird.G[i][j]]+=zhichong[xs[gird.G[i][j]]][k];
				if(isxiechong(gird,i,j,k))val[gird.G[i][j]]+=xiechong[xs[gird.G[i][j]]][k];
				if(iszhisi(gird,i,j,k))val[gird.G[i][j]]+=zhisi[xs[gird.G[i][j]]][k];
				if(isxiesi(gird,i,j,k))val[gird.G[i][j]]+=xiesi[xs[gird.G[i][j]]][k];
				if(iszhikong(gird,i,j,k))val[gird.G[i][j]]+=zhikong[xs[gird.G[i][j]]][k];
				if(isxiekong(gird,i,j,k))val[gird.G[i][j]]+=xiekong[xs[gird.G[i][j]]][k];
				if(debug){//Debug kong
					if(k<=2)continue;
					if(iszhikong(gird,i,j,k) or isxiekong(gird,i,j,k)){
						cout<<"KONG!!\n";
						system("pause");
					}
				}
			}
		}
	}
	return mp(val[1],val[2]);
}
inline pair<int,int>GetCount(Gird gird,int xs){
	if(xs==1)return CountValue(gird,mp(0,1));
	else return CountValue(gird,mp(1,0));
}
#endif
