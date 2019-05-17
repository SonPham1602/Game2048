#include<stdio.h>
#include<conio.h>
#include<console.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
struct TaoDo
{
	int x;
	int y;
	int GiaTri;
};
void logogame(char &key)
{
	int iN=0;
	while(iN==0)
	{
		for(int i=1;i<16;i++)
		{
			TextColor(i);
			printf("          MMMMM       MMMMMM           MM     MMMMMM \n");
			printf("         MMMMMMMM    MMM  MMM        MMMM    MME   MM \n");
			printf("         M    MMM    MM    MM      MMM MM    SMMMMMM \n");
			printf("             MMM     MM    MM     MM   MM     7MMMMM \n");
			printf("            MMM      MM    MM   MMMMMMMMMM   MMM MMMM \n");
			printf("           MM    M   MM    MM   MMMMMMMMMM   MM    MM \n");
			printf("         MMMMMMMMM   MMM  MMM          MM    MMMBzMMM\n");
			printf("        MMMMMMMMM     MMMMMM           MM     MMMMMM\n");
			TextColor(7);
			printf("================================================================\n");
			printf("                   NHAN ENTER BAT DAU GAME\n");
			printf("================================================================\n");
			Sleep(100);
			clrscr();
			if(kbhit())
			{
				key=getch();
				iN=1;
				break;	
			}
		}
	}
}
void map()// map 2045
{
	printf("*********************************\n");// map 2048
	printf("*       *       *       *       *\n");
	printf("*       *       *       *       *\n");
	printf("*       *       *       *       *\n");
	printf("*********************************\n");
	printf("*       *       *       *       *\n");
	printf("*       *       *       *       *\n");
	printf("*       *       *       *       *\n");
	printf("*********************************\n");
	printf("*       *       *       *       *\n");
	printf("*       *       *       *       *\n");
	printf("*       *       *       *       *\n");
	printf("*********************************\n");
	printf("*       *       *       *       *\n");
	printf("*       *       *       *       *\n");
	printf("*       *       *       *       *\n");
	printf("*********************************\n");
}
void thaydoiA(TaoDo A[4][4],int n)
{
	int temp;
	for (int i=0;i<3;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			if(A[n][i].GiaTri==0 && A[n][j].GiaTri!=0)
			{
				temp=A[n][i].GiaTri;
				A[n][i].GiaTri=A[n][j].GiaTri;
				A[n][j].GiaTri=temp;
			}
		}
	}

}
void thaydoiW(TaoDo A[4][4],int n)
{
	int temp;
	for (int i=0;i<3;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			if(A[i][n].GiaTri==0 && A[j][n].GiaTri!=0)
			{
				temp=A[i][n].GiaTri;
				A[i][n].GiaTri=A[j][n].GiaTri;
				A[j][n].GiaTri=temp;
			}
		}
	}
}
void thaydoiD(TaoDo A[4][4],int n)
{
	int temp;
	for (int i=3;i>=0;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(A[n][i].GiaTri==0 && A[n][j].GiaTri!=0)
			{
				temp=A[n][i].GiaTri;
				A[n][i].GiaTri=A[n][j].GiaTri;
				A[n][j].GiaTri=temp;
			}
		}
	}

}
void thaydoiS(TaoDo A[4][4],int n)
{
	int temp;
	for (int i=3;i>=0;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(A[i][n].GiaTri==0 && A[j][n].GiaTri!=0)
			{
				temp=A[i][n].GiaTri;
				A[i][n].GiaTri=A[j][n].GiaTri;
				A[j][n].GiaTri=temp;
			}
		}
	}
}
void rutmangA(TaoDo A[4][4],int n)
{
	for (int i=0;i<4;i++)
	{
		if(A[n][i].GiaTri==A[n][i+1].GiaTri)
		{
			A[n][i].GiaTri=A[n][i].GiaTri*2;
			for(int j=i+1;j<4;j++)
			{
				A[n][j].GiaTri=A[n][j+1].GiaTri;

			}
			A[n][3].GiaTri=0;
		}
	}
}
void rutmangW(TaoDo A[4][4],int n)
{
	for (int i=0;i<4;i++)
	{
		if(A[i][n].GiaTri==A[i+1][n].GiaTri)
		{
			A[i][n].GiaTri=A[i][n].GiaTri*2;
			for(int j=i+1;j<4;j++)
			{
				A[j][n].GiaTri=A[j+1][n].GiaTri;

			}
			A[3][n].GiaTri=0;
		}
	}
}
void rutmangD(TaoDo A[4][4],int n)
{
	for (int i=3;i>=0;i--)
	{
		if(A[n][i].GiaTri==A[n][i-1].GiaTri)
		{
			A[n][i].GiaTri=A[n][i].GiaTri*2;
			for(int j=i-1;j>=0;j--)
			{
				A[n][j].GiaTri=A[n][j-1].GiaTri;

			}
			A[n][0].GiaTri=0;
		}
	}
}
void rutmangS(TaoDo A[4][4],int n)
{
	for (int i=3;i>=0;i--)
	{
		if(A[i][n].GiaTri==A[i-1][n].GiaTri)
		{
			A[i][n].GiaTri=A[i][n].GiaTri*2;
			for(int j=i-1;j>=0;j--)
			{
				A[j][n].GiaTri=A[j-1][n].GiaTri;

			}
			A[0][n].GiaTri=0;
		}
	}
}
void xuliphimA(TaoDo A[4][4])
{
	for(int i=0;i<4;i++)
	{
		thaydoiA(A,i);
		rutmangA(A,i);
	}

}
void xuliphimW(TaoDo A[4][4])
{
	for(int j=0;j<4;j++)
	{
		thaydoiW(A,j);
		rutmangW(A,j);
	}

}
void xuliphimD(TaoDo A[4][4])
{
	for(int i=0;i<4;i++)
	{
		thaydoiD(A,i);
		rutmangD(A,i);
	}

}
void xuliphimS(TaoDo A[4][4])
{
	for(int j=0;j<4;j++)
	{
		thaydoiS(A,j);
		rutmangS(A,j);
	}

}
void taoSo(TaoDo A[4][4])
{
	int x;
	int y;
	x=rand()%4;
	y=rand()%4;
	if(A[x][y].GiaTri==0)
	{
		A[x][y].GiaTri=2;
	}
}
void khoitao(TaoDo taoDo[4][4])
{
	int B[4]={4,12,20,28};
	int A[4]={2,6,10,14};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			taoDo[i][j].x=B[j];
			taoDo[i][j].y=A[i];
			taoDo[i][j].GiaTri=0;
		}
	}
	taoSo(taoDo);	
}
void xuatmangGame(TaoDo A[4][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			int iX,iY;
			iX=A[i][j].x;
			iY=A[i][j].y;
			gotoXY(iX,iY);
			if(A[i][j].GiaTri==0)
			{
				printf("");
			}
			else
				printf("%d",A[i][j].GiaTri);
		}
	}
}
void xulichinh(TaoDo taoDo[4][4])
{
	taoSo(taoDo);
	xuatmangGame(taoDo);
	char phim;
	phim=getch();

	if(phim=='a' || phim =='A')
	{
		xuliphimA(taoDo);
	}
	if(phim=='d' || phim == 'D')
	{
		xuliphimD(taoDo);
	}
	if(phim=='s'|| phim =='S')
	{
		xuliphimS(taoDo);
	}
	if(phim=='w' || phim =='W')
	{
		xuliphimW(taoDo);
	}
	clrscr();
	gotoXY(0,18);
	printf("Huong dan: Nhan cac phim A,S,D,W");
	gotoXY(0,0);
}
int main()
{
	TaoDo A[4][4];
	khoitao(A);
	int kt=1;
	char key;
	srand(time(0));
	logogame(key);
	if(key==13)
	{
		while(kt==1)
		{
			map();
			gotoXY(0,18);
			printf("Huong dan: Nhan cac phim A,S,D,W");
			gotoXY(0,0);
			xulichinh(A);
		}
	}	
	getch();
}
