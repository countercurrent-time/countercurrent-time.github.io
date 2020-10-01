#include<cstdio>
#include<cmath>
const int N=500005;
int a[N];
int f[100]={1,1};
int n=32;
#define tri
#ifdef bin//二叉树状数组
int main(){
    freopen("tree.out","w",stdout);
    for(int i=1;i<=n;i++){
        a[i]=log(i&(-i))/log(2);
        printf(
        "Polygon\n"
        "%d %d\n"
        "%d %.1lf\n"
        "%.1lf %.1lf\n"
        "%.1lf %d\n"
        "...\n",
        i-(i&(-i)),a[i],
        i-(i&(-i)),a[i]+0.7,
        i-0.3,a[i]+0.7,
        i-0.3,a[i]
        );
    }
    return 0;
}
#elif defined(fib)//斐波那契树状数组
int main(){
    freopen("tree.out","w",stdout);
    int now=2;
    for(int i=2;i<=30;i++)f[i]=f[i-1]+f[i-2];
    a[1]=1;
    a[2]=2;
    for(int i=1;i<=2;i++){
        printf(
        "Polygon\n"
        "%d %d\n"
        "%d %.1lf\n"
        "%.1lf %.1lf\n"
        "%.1lf %d\n"
        "...\n",
        i-f[a[i]],a[i],
        i-f[a[i]],a[i]+0.7,
        i-0.3,a[i]+0.7,
        i-0.3,a[i]
        );
    }
    for(int i=3;i<=n;i++){
        a[i]=a[i-f[now]];
        if(a[i]==now-1)a[i]=++now;
        printf(
        "Polygon\n"
        "%d %d\n"
        "%d %.1lf\n"
        "%.1lf %.1lf\n"
        "%.1lf %d\n"
        "...\n",
        i-f[a[i]],a[i],
        i-f[a[i]],a[i]+0.7,
        i-0.3,a[i]+0.7,
        i-0.3,a[i]
        );
    }
    return 0;
}
#elif defined(tri)//三叉树状数组
int main(){
    freopen("tree.out","w",stdout);
    for(int i=1,cnt=0;i<=n;i*=3,cnt++){
        for(int j=i;j<=n;j+=i){
            a[j]=cnt;
        }
    }
    for(int i=1;i<=n;i++){
        printf(
        "Polygon\n"
        "%.1lf %d\n"
        "%.1lf %.1lf\n"
        "%.1lf %.1lf\n"
        "%.1lf %d\n"
        "...\n",
        i-pow(3,a[i]),a[i],
        i-pow(3,a[i]),a[i]+0.7,
        i-0.3,a[i]+0.7,
        i-0.3,a[i]
        );
    }
    return 0;
}
#elif defined(tag)//树状数组+延迟标记
int main(){
    freopen("tree.out","w",stdout);
    for(int i=1;i<=n;i++){
        a[i]=log(i&(-i))/log(2);
        printf(
        "Polygon\n"
        "%d %d\n"
        "%d %.1lf\n"
        "%.1lf %.1lf\n"
        "%.1lf %d\n"
        "...\n",
        i-(i&(-i)),a[i],
        i-(i&(-i)),a[i]+0.7,
        i-0.3,a[i]+0.7,
        i-0.3,a[i]
        );
        printf(
        "Segment %d %.1lf %d %.1lf\n"
        "Segment %.1lf %.1lf %.1lf %.1lf\n",
        i,a[i]+0.2,i,a[i]+0.5,
        i-0.3+(i&(-i)),a[i]+0.2,i-0.3+(i&(-i)),a[i]+0.5);
        for(int j=i;j<=i-0.3+(i&(-i));j++){
            printf(
            "Segment %d %d %.1lf %d\n"
            "Segment %d %.1lf %.1lf %.1lf\n",
            j,a[i],j+0.5,a[i],
            j,a[i]+0.7,j+0.5,a[i]+0.7);
        }
    }
    return 0;
}
#endif
