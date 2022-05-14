#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#define SIZE 8
#define MAX_ITER 20


//fonction qui mesure la valeur de toute les solutions
int f(int x){
	return x*x*x-60*x*x+900*x+100;
}

typedef char sol[SIZE+1];

int decod(sol s){
	int val=0;
	int i;
	for(i=0;i<SIZE;i++){
		val=val*2+(s[i]-'0');
	}
	return val;
}

void local_Search(){
	srand(1);
	sol s0="";
	int i,b,j;
	for(i=0;i<SIZE;i++){
		b=rand()%RAND_MAX;
		if(b%10>5)
		s0[i]='1';
		else
		s0[i]='0';
	}
	
	sol s_best="";
	sol s_curr="";
	sol s_curr1="";
	sol s_best_iter="";
	int f_best;
	int num_ite;
	strcpy(s_best,s0);
	f_best=f(decod(s_best));
	strcpy(s_best_iter,s_best);
	strcpy(s_curr1,s_best_iter);
	f_best=f(decod(s_best));
	num_ite=1;
	while(num_ite<MAX_ITER){
		if(f(decod(s_best_iter))<f_best){
			strcpy(s_best,s_best_iter);
			f_best=f(decod(s_best));
		}
		strcpy(s_curr1,s_best_iter);
		do{
		b=rand()%RAND_MAX;
		b=b%10;	
		}while(b>7);
		//printf("%d\n",b);	
		for(i=0;i<SIZE;i++){
			if(i==b)
			continue;
			strcpy(s_curr,s_curr1);
			if(s_curr[i]=='0'){
				s_curr[i]='1';
			}else
			s_curr[i]='0';
			//printf(">:%s  %d\n",s_curr,f(decod(s_curr)));
			if(f(decod(s_best_iter))>f(decod(s_curr))){
			strcpy(s_best_iter,s_curr);
		}
		}
			printf("\n");
		num_ite++;
	}
	printf("valeur Initiale est :%s\n",s0);
	printf("The Best Value est :%s\n + %s",s_best,s_best_iter);
}
int main(void){
	local_Search();
	return 0;
}
