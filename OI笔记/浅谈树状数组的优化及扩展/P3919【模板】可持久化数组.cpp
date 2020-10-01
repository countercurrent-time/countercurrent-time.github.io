#include<cstdio>
const int N = 1000010;
int n, m, rtsize = 1, tot;
int root[N];
int val[N * 20], lc[N * 20], rc[N * 20];
inline int lowbit(int x) {return x & (-x);}
#define div
#ifdef div
//递归版本
int build(int x) {
	int p = ++tot;
	if (x % 2 == 0)lc[p] = build(x - lowbit(x) / 2);
	if (x <= n)scanf("%d", &val[p]);
	if (x % 2 == 0 && x < n)rc[p] = build(x + lowbit(x) / 2);
	return p;
}
int upd(int p, int x, int v, int k) {
	if (x == v) {val[++tot] = k; lc[tot] = lc[p]; rc[tot] = rc[p]; return tot;}
	int lastp = p;
	val[++tot] = val[p], p = tot;
	if (x < v)lc[p] = upd(lc[lastp], x, v - lowbit(v) / 2, k), rc[p] = rc[lastp];
	else rc[p] = upd(rc[lastp], x, v + lowbit(v) / 2, k), lc[p] = lc[lastp];
	return p;
}
int query(int p, int x, int v) {
	if (x == v)return val[p];
	else if (x < v)return query(lc[p], x, v - lowbit(v) / 2);
	else return query(rc[p], x, v + lowbit(v) / 2);
}
#else
//迭代版本
int build() {
	while (rtsize * 2 <= n)rtsize *= 2;
	while (++tot <= n) {
		scanf("%d", &val[tot]);
		lc[tot] = tot - lowbit(tot) / 2;
		rc[tot] = tot + lowbit(tot) / 2;
	}
	tot--;
	int v = rtsize, p = rtsize;
	while (n != v) {
		//printf("%d\n",lowbit(v));
		if (v + lowbit(v) / 2 <= n)rc[p] = v + lowbit(v) / 2, v += lowbit(v) / 2, p = rc[p];
		else if (v < n)rc[p] = ++tot, v += lowbit(v) / 2, p = rc[p];
		else if (v - lowbit(v) / 2 > n)lc[p] = ++tot, v -= lowbit(v) / 2, p = lc[p];
		else lc[p] = v - lowbit(v) / 2, v -= lowbit(v) / 2, p = lc[p];
	}
	return rtsize;
}
void upd(int p, int x, int v, int k) { //bp是原版本，ap是新版本
	int bp = p, ap = ++tot;
	while (x != v) {
		//printf("%d\n",v);
		val[ap] = val[bp];
		if (x < v)lc[ap] = ++tot, rc[ap] = rc[bp], v -= lowbit(v) / 2, bp = lc[bp];
		else rc[ap] = ++tot, lc[ap] = lc[bp], v += lowbit(v) / 2, bp = rc[bp];
		ap = tot;
	}
	val[ap] = k;
	lc[ap] = lc[bp]; //
	rc[ap] = rc[bp]; //这里最后也要复制一份 (因为此时的最终节点不一定是叶子结点，不同于动态线段树)
}
int query(int p, int x, int v) {
	while (x != v) {
		if (x < v)p = lc[p], v -= lowbit(v) / 2;
		else p = rc[p], v += lowbit(v) / 2;
	}
	if (val[p] == 0)printf("%d %d\n", p, tot);
	return val[p];
}
#endif
int main() {
	scanf("%d%d", &n, &m);
	#ifdef div
	while (rtsize * 2 <= n)rtsize *= 2; //普通树状数组上根节点编号根节点
	root[0] = build(rtsize);
	#else
	root[0] = build();
	#endif
	//for(int i=1;i<=8;i++)printf("%d %d %d\n",lc[i],rc[i],val[i]);
	//printf("%d\n",tot);
	for (int i = 1; i <= m; i++) {
		int op, id, x, k;
		scanf("%d%d%d", &id, &op, &x);
		switch (op) {
			case 1:
				scanf("%d", &k);
				root[i] = tot + 1;
				upd(root[id], x, rtsize, k);
				break;
			case 2:
				printf("%d\n", query(root[id], x, rtsize));
				root[i] = root[id]; //这里复制的是root[id]，我调到最后才发现
				break;
		}
	}
	return 0;
}