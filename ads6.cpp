 #include<iostream>
using namespace std;
class graph
{
public:
int city,i,j,u,v,time,flg;
int flag=0;
int mat[10][10];
int visi[10];
int read(){

cout<<"Enter no. of city:";
cin>>city;
cout<<"Enter no. of flights:";
cin>>flg;
for(i=0;i<=city;i++){
      for(j=0;j<=city;j++){
         mat[i][j]=0;
     visi[i]=0;
}
}
        cout<<"enter the time to visit:"<<endl;
        for(i=0;i<flg;i++){
        cin>>u>>v>>time;
        mat[u][v]=mat[v][u]=time;
        }
        for(i=0;i<=city;i++){
              for(j=0;j<=city;j++){
                 cout<<mat[i][j];
        }
              cout<<""<<endl;
        }
        return 0;
    }
	int con(){
        for(i=0;i<=city;i++){
        for(j=0;j<=city;j++){
        if(mat[i][j]!=0 && mat[j][i]!=0 && visi[i]==0 ){
        cout<<"Path is from"<<i<<"to"<<j<<endl;
        visi[i]=1;

        }

        }
        }
        for(i=0;i<flg;i++){
        if(visi[i]==1){
        flag=1;
        }
        }

        if(flag==1){
        cout<<"cities are connected"<<endl;
        }
        else{
        cout<<"Cities are not connected";
        }
     return 0;
}

};



int main()
{
graph g;
g.read();
g.con();


return 0;
}

