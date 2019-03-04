//# Magic-Square
//Programming a magic square


#include <stdio.h>
#include <stdlib.h>
int magic_matrix(int **mat,int *used,int n,int val);
int check (int **mat,int n);
int main()
{
    int i,j,**mat,*used,n,count;
    n=3;//scanf("%d",&n);
    mat=malloc(n*sizeof(int *));
    if(mat==NULL)
        {
            printf("Error in memory allocation");
            exit(0);
        }
    for(i=0;i<n;i++)
    {
        mat[i]=malloc(n*sizeof(int));
        if(mat[i]==NULL)
        {
            printf("Error in memory allocation");
            exit(0);
        }
    }
    used=malloc((n*n+1)*sizeof(int));
    if(used==NULL)
        {
            printf("Error in memory allocation");
            exit(0);
        }
    for(i=0;i<=n*n;i++)
    {
        used[i]=0;
    }
    int result=magic_matrix(mat,used,n,0);
    if(result==1)
    {for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %d",mat[i][j]);
        }printf("\n");
    }}
    return 0;

}
int magic_matrix(int **mat,int *used,int n,int val)
{
    if(val==n*n)
    {
        return check(mat,n);
    }
    int r,c,k;
    r=val/n;
    c=val%n;
    for(k=1;k<=n*n;k++)
    {
        if(used[k]==0)
        {
            used[k]=1;
            mat[r][c]=k;
            if(magic_matrix(mat,used,n,val+1))
                return 1;
            used[k]=0;
        }
    }

    return 0;
}
int check (int **mat,int n)
{
    int sum=0,i,j,target=n*(n*n+1)/2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+=mat[i][j];
        }
        if(sum!=target)
            return 0;
        sum=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+=mat[j][i];
        }
        if(sum!=target)
            return 0;
        sum=0;
    }i=0;j=0;sum=0;
    while(i<n&&j<n)
    {
        sum+=mat[i++][j++];
    }
    sum=0;
    if(sum!=target)
        return 0;
    i=0;j=n-1;sum=0;
    while(i<n&&j>=0)
    {
        sum+=mat[i++][j--];
    }
    if(sum!=target)
        return 0;


    return 1;

}
