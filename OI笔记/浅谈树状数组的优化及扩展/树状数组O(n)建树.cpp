for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	for(int j=1;j<lowbit(i);j*=2){
		a[i]+=a[i-j];
	}
}

for(int i=1;i<=n;i++){
	scanf("%lld",&x);
	a[i]+=x;
	if(i+lowbit(i)<=n)a[i+lowbit(i)]+=a[i];//注意这里的条件
}
