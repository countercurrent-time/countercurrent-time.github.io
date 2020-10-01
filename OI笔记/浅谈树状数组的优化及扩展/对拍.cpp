#include<iostream>
#include<cstdio>
#include<ctime>
typedef long long ll;
using namespace std;
ll random(ll n){
	return (((long long)rand()<<47)+((long long)rand()<<31)+(rand()<<15)+(rand()/2))%n;
}
int main(){
	for(int i=1;i<=100;i++){
		system("random>in");
		int now;
		/* 
		now=clock();
		system("\"草稿 (2)\"<in>out1");
		printf("线段树:%ld\n",clock()-now);
		
		now=clock();
		system("\"树状数组延迟标记\"<in>out2");
		printf("树状数组:%ld\n",clock()-now);
		if(system("fc out1 out2"))return 0;
		*/
		now=clock();
		if(system("\"普通树状数组\"<in>out1"))return 1;
		printf("树状数组:%ld\n",clock()-now);
		
		now=clock();
		if(system("\"查询优化\"<in>out2"))return 2;
		printf("优化:%ld\n",clock()-now);
		if(system("fc out1 out2"))return 2333;
	}
	system("pause");
	system("pause");
	system("pause");
	return 0;
}
