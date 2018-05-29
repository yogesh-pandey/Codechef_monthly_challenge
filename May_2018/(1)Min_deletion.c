#include <stdio.h>
#include <stdlib.h>
 
int gcd(long int a,long int b){
    long int lar=0,sml=0;
    if(a>=b){
        lar=a;
        sml=b;
    }
    else{
        lar=b;
        sml=a;
    }
    if(sml==0)
        return lar;
    return (gcd(lar%sml,sml));
}
int Min_deletion(long int A[],int n){
    long int res=0,j=0,k=0;
    int i;
    res=A[0];
    for(i=1;i<n;i++){
        res=gcd(A[i],res);
    }
    if(res==1)
        return 0;
        
    for(i=0;i<n;i++){
        if(A[i]%res==0)
            j++;
        else
            k++;
    }
    if(j==n)
        return -1;
    else
        return  j;
    
}
int main() {
    int n,t,val=0,i;
    long int *Ai;
	scanf("%d\n",&t); 
	while(t--){
	    scanf("%d\n",&n);
	    Ai=(long int *)malloc(n*sizeof(long int));
	    for(i=0;i<n;i++)
	        scanf("%ld\n",&Ai[i]);
	    val=Min_deletion(Ai,n);
	    printf("%d\n",val);
	    free(Ai);
	}
	return 0;
} 
