#include<stdio.h>
void main(){
	int i, n, key, flag=0, pos=-1;
	printf("");
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &key);
	for(i=0; i<n; i++){
		if(a[i] == key){
			flag =1;
			pos=i;
			break;
		}
	}
	if(flag == 1){
		printf("found at position %d\n", pos);
	} else{
		printf("%d not found\n", key);
	}
}
