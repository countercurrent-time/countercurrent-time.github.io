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
		system("\"�ݸ� (2)\"<in>out1");
		printf("�߶���:%ld\n",clock()-now);
		
		now=clock();
		system("\"��״�����ӳٱ��\"<in>out2");
		printf("��״����:%ld\n",clock()-now);
		if(system("fc out1 out2"))return 0;
		*/
		now=clock();
		if(system("\"��ͨ��״����\"<in>out1"))return 1;
		printf("��״����:%ld\n",clock()-now);
		
		now=clock();
		if(system("\"��ѯ�Ż�\"<in>out2"))return 2;
		printf("�Ż�:%ld\n",clock()-now);
		if(system("fc out1 out2"))return 2333;
	}
	system("pause");
	system("pause");
	system("pause");
	return 0;
}
