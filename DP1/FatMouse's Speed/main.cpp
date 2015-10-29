#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
 int wei;
 int spe;
 int num;
}a[1010];
int cmp(const void *a,const void *b)
{
 if((*(struct node *)a).wei!=(*(struct node *)b).wei)
 return (*(struct node *)a).wei-(*(struct node *)b).wei;
 else return (*(struct node *)b).spe-(*(struct node *)a).spe;
}
int l[1010],pre[1010],ans[1010];//l是记录的长度 pre记录的是路径
int main()
{
 int cnt=1,i,j,max_l=0,end;
      while(scanf("%d %d",&a[cnt].wei,&a[cnt].spe)!=EOF)
   {
    a[cnt].num=++cnt;
   }
   qsort(a+1,cnt-1,sizeof(struct node),cmp);
   for(i=1;i<cnt;i++) {l[i]=1;pre[i]=0;}
      for(i=1;i<cnt;i++)
   {
    for(j=1;j<i;j++)
    {
         if(a[i].wei>a[j].wei&&a[i].spe<a[j].spe&&l[i]<l[j]+1)
      {
       l[i]=l[j]+1;
       pre[i]=j;//这里面记录的是倒序 后面要倒着输出
      }
    }
   }
   end=1;
   max_l=l[1];
   for(i=2;i<cnt;i++) if(max_l<l[i]) {max_l=l[i];end=i;}
   printf("%d\n",max_l);
   for(i=1;i<cnt;i++)//记录下来  方便倒着输出
   {
            ans[i]=end;    
   end=pre[end];
   }
   for(i=max_l;i>=1;i--)
   {
             printf("%d\n",a[ans[i]].num);
   }
     return 0;
   
}
