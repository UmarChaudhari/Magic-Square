#include <stdio.h>
#include <stdlib.h>
int magic(int **mat,int n,int *used,int k);
int check(int **mat,int n);
int main()
{
    int **mat,n=3,*used,i,j;
    mat=malloc(n*sizeof(int *));
    used=malloc((n*n+1)*sizeof(int ));
    if(used==NULL||mat==NULL)
    {
        printf("Error in Memory Allocation");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        mat[i]=malloc(n*sizeof(int ));
        if(mat[i]==NULL)
        {
            printf("Error in Memory Allocation");
            exit(0);
        }
    }
    for(i=0;i<=n*n;i++)
    {
        used[i]=0;
    }
    if(magic(mat,n,used,0))
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf(" %d",mat[i][j]);
            }printf("\n");
        }
    }
    else
    {
        printf("Solution Not Found");
    }
    return 0;
}
int magic(int **mat,int n,int *used,int k)
{
    if(k==n*n)
    {
        return check(mat,n);
    }
    int i=k/n,j=k%n,val;
    for(val=1;val<=n*n;val++)
    {
        if(used[val]==0)
        {
            used[val]=1;
            mat[i][j]=val;
            if(magic(mat,n,used,k+1))
            {
                return 1;
            }
            used[val]=0;

        }
    }
    return 0;
}
int check(int **mat,int n)
{
    int i,j,sum,target=n*(n*n+1)/2;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        {
            sum+=mat[i][j];
        }if(sum!=target)
            return 0;
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
        {
            sum+=mat[j][i];
        }if(sum!=target)
            return 0;
    }
    sum=0;
    for(i=0;i<n;i++)
    {
        sum+=mat[i][i];
    }if(sum!=target)
        return 0;
    j=n-1;sum=0;
    for(i=0;i<n;i++)
    {
        sum+=mat[i][j--];
    }if(sum!=target)
        return 0;
    return 1;
}
