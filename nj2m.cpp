#include<stdio.h>
#include<math.h>
#include<string.h>
#define NUM(a) (sizeof(a) / sizeof(*a))

int main()
{
	int a[]={1,2,8,9,10,11},b[]={3,5,6,4,7,12},n1=NUM(a),n2=NUM(b),i,j;
	int m1[20],m2[20],jo[20],job[20],cnt=0,dec=n2-1,z,flag=0,n=n1,c,s;
	if(n1==n2)
	{
		for(i=0;i<n1;i++)
		{
				m1[i]=a[i];
				m2[i]=b[i];
				jo[i]=i+1;
				job[i]=0;
		}	
		for(z=0;z<n;z++)
		{
			/*for(s=0;s<n1;s++)
			{
				printf("\n%d",jo[s]);	
			}*/
			int j,min1=0,pos1=1;
			min1=m1[0];
			for(j=1;j<n1;j++)
			{
				if(m1[j]<min1)
				{
					min1=m1[j];
					pos1=j+1;
				}
			}
			//printf("%d %d\n",min1,pos1);
			int i,min2=0,pos2=1;
			min2=m2[0];
			for(i=1;i<n2;i++)
			{
				if(m2[i]<min2)
				{
					min2=m2[i];
					pos2=i+1;
				}
			}
			//printf("%d %d",min2,pos2)	;
			if(min1<=min2)
			{
				job[cnt]=jo[pos1-1];
				cnt++;
				flag=1;
			}
			else if(min1>min2)
			{
				job[dec]=jo[pos2-1];
				dec--;
				flag=2;
			}
		
			printf("\nOptimal Job sequence \n");
			for(i=0;i<n;i++)
			{
				printf("%d",job[i]);
			}
			//printf("%d\n",pos1);
			if(flag==1)
			{
				for (c = pos1-1; c < n1 - 1; c++)
         		{
				jo[c] = jo[c+1]; 
				m1[c] = m1[c+1];
         		m2[c] = m2[c+1];
         		
				}
			}
			else if(flag==2)
			{
				for (c = pos2-1 ; c < n1 - 1; c++)
				{
				
         		jo[c] = jo[c+1];
				m1[c] = m1[c+1];
         		m2[c] = m2[c+1];
         		}
			}
			n1--;
			n2--;
		}	
		printf("\n");
		int mt1[10],mt2[10];
		mt1[0]=0;mt2[0]=a[job[0]-1];
		for(i=1;i<=n;i++)
		{
			mt1[i]=mt1[i-1]+a[job[i-1]-1];
			if(mt1[i]>=mt2[i-1])
			{
				mt2[i]=mt1[i]+b[job[i-1]-1];
			}
			else
			{
			
			mt2[i]=mt2[i-1]+b[job[i-1]-1];
			}
			printf("Time taken to finish job %d:\t %d\n",i,mt2[i]);
		}
		
		printf("\nTotal Elapsed Time:%d",mt2[n]);
	}
	return 0;
}
