#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;
	fptr = fopen("Okuma.txt", "a+");
    
	int i,i_2,i_3,a,n;//i,i_2 saya�--a kelime say�s�
	int N=0;//genislik
	int s;//kelimeyi yazd�rcakken ki ka� eleman oldu�unu tutan de�i�ken
	int kalan;//sat�r sonuna kalan mesefe
    char blnn[10000][100];//metindeki kelimeleri saklayan dizi
    
    
    printf("genislik:"); scanf("%d",&N); n=N;
    
    
    i=0;
    while(!(feof(fptr))){//doya bo�kende 1 veriyor
	fscanf(fptr,"%s",&blnn[i]);
	i++;
    }
    a=i;
	//printf("kac kelime:%d",a);
	for(i=0;i<a;i++)
	{
		s=0;
		for(i_2=0;blnn[i][i_2]!='\0';i_2++)//uzunlu�u hesaplama
			s++;

		if(N<s)
		{
			kalan=s-N;
			for(i_3=0;i_3<N;i_3++)
			{
				printf("%c",blnn[i][i_3]);
			}
			printf("\n");
			
			int a_2,a_2_;
			a_2=N; a_2_=N;
			N=n;
			if(kalan>N){
		
				while(kalan>N)//birka� defa b�lmek gerekirse
				{
					for(i_3=a_2;i_3<N+a_2;i_3++)
					{
						printf("%c",blnn[i][i_3]);
					}
					printf("\n");
					kalan=s-i_3;
					a_2=N+a_2;
				}
				if(kalan!=0)
				{
					for(i_3=a_2;i_3<s;i_3++)
						printf("%c",blnn[i][i_3]);
					
					printf(" ");
					
					N=n-kalan-1;
				}
				
			}
			else
			{
				for(i_3=a_2_;i_3<s;i_3++)
					printf("%c",blnn[i][i_3]);
			
				printf(" ");
				
				N=n-kalan-1;
			}

		}
		else if(N==s)
		{
			printf("%s",blnn[i]);
			printf("\n");
			N=n;
		}
		else
		{
			printf("%s",blnn[i]); 	printf(" ");

			N=N-s-1;
		}
			
	}
	printf("\n");
	scanf("%d",&N);//beklesin diye
	return 0;
}
