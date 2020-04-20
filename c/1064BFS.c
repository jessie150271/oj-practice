#include <stdio.h>
#pragma GCC optimize ("O3")
const int moves_i[4] = { -1,1,0,0 }, moves_j[4] = { 0,0,-1,1 };
char map[1000000];
int que_i[100000], que_j[100000], que_f[100000];
main() {
    int tmp,tmp2,head, tail, ni, nj,flag,n;
    char in[1000];
    while (scanf("%d ", &n)==1) {
        for (int i = 0; i < n; i++) {
            gets(in);
            tmp2=i*n;
            for (int j = 0; j < n; j++) {
                tmp=tmp2+j;
                map[tmp]=in[j];
                if (in[j] == 'T') {
                    ni = i;
                    nj = j;
                }
            }
        }
        head = 0; tail = 1;
        que_i[0] = ni; que_j[0] = nj;
        que_f[0] = 0;
        flag = 0;
        int new_i,new_j;
        while (head < tail) {
            if(flag)break;
            ni = que_i[head]; nj = que_j[head];
            for (int i = 0; i < 4; ++i) {
                new_i=ni + moves_i[i];new_j=nj + moves_j[i];tmp=new_i*n+new_j;
                if (new_i < 0 || new_j < 0|| new_i >= n || new_j >= n || map[tmp] == '*')continue;
                que_i[tail] = new_i; que_j[tail] = new_j;
                que_f[tail] = que_f[head]+1;++tail;
                if(map[tmp]=='S'){
                    flag=1;
                    break;
                }
                map[tmp]='*';
            }
            ++head;
        }
        if (flag)printf("%d\n", que_f[head - 1]+1);
        else puts("No");
    }
}