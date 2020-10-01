#include<cstdio>
typedef long long ll;
ll a[600000],v,add[600000];
int n,m,cmd,a,b;
int lg[100005];
void build(int n){
	for(int i=1<<(lg[n]+1);i<=+n;i++)scanf("%d",&a[i]);
	for(int i=(1<<(lg[n]+1))-1;i>0;i--)a[i]=a[i*2]+a[i*2+1];
}
void update(int l,int r,int v){
	
}
ll query(int l,int r){
	
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,j=0;i<=100000;i*=2,j++)lg[i]=j;
	for(int i=3;i<=100000;i++)if(!lg[i])lg[i]=lg[i-1];
	while(m--){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d%d%lld",&a,&b,&v);
			update(a,b,v);
		}
		else if(cmd==2){
			scanf("%d%d",&a,&b);
			printf("%lld",query(a,b));
		}
	}
	return 0;
}
