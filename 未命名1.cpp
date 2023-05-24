#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/*宏定义*/

#define SIZE 4

/*全局变量*/
int a[SIZE][SIZE]={0};
int T[SIZE][SIZE]={0};
int score=0;
int nmd=0;
//初始化数组，随机产生两个数 2（70%） 或  4（30%）
void _2048_over();
void _2048_up();
void _2048_down();
void _2048_left();
void _2048_right();
void _2048_produce();
void _2048_press();
void _2048_interface();
void _2048_plugin()
{
	srand((int)time(0));
//随机数种子
	int m,n,t;
	m=rand()%2+1;
	n=rand()%2+1;
	t=rand()%4;
	a[m][n]=1024;
	if(t==0)
	{
		a[m][n+1]=1024;
	}
	else if(t==1)
	{
		a[m][n-1]=1024;
	}
	else if(t==2)
	{
		a[m+1][n]=1024;
	}
	else
	{
		a[m-1][n]=1024;
	}
	_2048_produce();	
	system("clear");
	_2048_interface();
	_2048_over();	
}
void _2048_exit()
{
	int num;
	printf("确认退出？1:yes  other:no\n");
	scanf("%d",&num);
	getchar();
	if(num==1)
	{
		exit(0);
	}
	else
	{
		printf("游戏继续！\n");
	}
}

int _2048_equal()//不相等 返回会假  相等 返回真
{
	int falg=1; //真
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(a[i][j]!=T[i][j])
			{
				falg=0;//假
			}
		}
	}
	return falg;
}

//移动前！
void _2048_invalid()
{

	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			T[i][j]=a[i][j];
		}
	}
	
}
void _2048_produce()
{
	//每次产生两个随机数
	srand((int)time(0));
//随机数种子
	int count=0;
	for(int m=0;m<SIZE;m++)
	{
		
		for(int n=0;n<SIZE;n++)
		{
			if(a[m][n]==0)
			{
				count++;
			}
		}
	}
	if(count==0)//0的个数count为0      即满了
	{
		printf("无法生成新的数\n");
		return ;
	}
	else if(count==1)//只有一个空格子
	{
		for(int k=0;k<1;k++)
		{
			int m=rand()%15;
			int x=rand()%SIZE;
			int y=rand()%SIZE;
			if(m<11)
			{
				if(a[x][y]==0)
				{
					a[x][y]=2;
				}
				else if(a[x][y]!=0)
				{
					k--;
				}
			}
			else if(m<14)
			{
				if(a[x][y]==0)
				{
					a[x][y]=4;
				}
				else if(a[x][y]!=0)
				{
					k--;
				}
			}
			else
			{
				if(a[x][y]==0)
				{
					a[x][y]=8;
				}
				else if(a[x][y]!=0)
				{
					k--;
				}				
			}
		}
	}
	else if(count>=2&&count!=SIZE*SIZE)//正常情况下 空格子数大于等于2  且  不全为空
	{
		int i,j;
		for(int k=0;k<2;k++)
		{
			int m=rand()%15;//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
			i=rand()%SIZE;//0 1 2 3
			j=rand()%SIZE;//0 1 2 3
			if(m<11)
			{
				if(a[i][j]==0)
				{
					a[i][j]=2;
				}
				else if(a[i][j]!=0)
				{
					k--;
				}
			}
			else if(m<14)
			{
				if(a[i][j]==0)
				{
					a[i][j]=4;
				}
				else if(a[i][j]!=0)
				{
					k--;
				}
			}
			else if(m==14)
			{
				if(a[i][j]==0)
				{
					a[i][j]=8;
				}
				else if(a[i][j]!=0)
				{
					k--;
				}					
			}
		}	

	}
	else if(count==SIZE*SIZE)//初始情况下 0的个数count为size*size  只生成2 和 4
	{
		int i,j;
		for(int k=0;k<2;k++)
		{
			int m=rand()%12;//0 1 2 3 4 5 6 7 8 9 10 11
			i=rand()%4;//0 1 2 3
			j=rand()%4;//0 1 2 3
			if(m<9)
			{
				if(a[i][j]==0)
				{
					a[i][j]=2;
				}
				else if(a[i][j]!=0)
				{
					k--;
				}
			}
			else
			{
				if(a[i][j]==0)
				{
					a[i][j]=4;
				}
				else if(a[i][j]!=0)
				{
					k--;
				}
			}
		}		
	}
	
}

//画出界面
void _2048_interface(void)
{
	system("clear");//清屏
	printf("\n\n\t");
	printf("*********2048小游戏************\n\t");

	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			printf(" _____ \t");
		}
		printf("\n\t");
		for(int j=0;j<SIZE;j++)
		{	
			printf("|     |\t");
		}	
		printf("\n\t");
		for(int j=0;j<SIZE;j++)
		{
			if(a[i][j]==0)
			{
				printf("|     |\t");
			}
			else if(a[i][j]<10&&a[i][j]!=0)
			{
				printf("|  %d  |\t",a[i][j]);
			}
			else if(a[i][j]>=10&&a[i][j]<100)
			{
				printf("| %d  |\t",a[i][j]);
			}
			else if(a[i][j]>=100&&a[i][j]<1000)
			{
				printf("| %d |\t",a[i][j]);
			}
			else if(a[i][j]>=1000&&a[i][j]<10000)
			{
				printf("| %d|\t",a[i][j]);
			}

		}			

		printf("\n\t");
		for(int j=0;j<SIZE;j++)
		{
			printf("|_____|\t");
		}
		printf("\n\t");
	
	}
	printf("\n");
}

//向上
void _2048_up()
{
	_2048_invalid();//移动前
	for(int j=0;j<SIZE;j++)
	{
		int m[SIZE]={0},k=0;
		for(int i=0;i<SIZE;i++)
		{
			if(a[i][j]!=0)
			{
				m[k++]=a[i][j];
			}
		}
		for(k=0;k<SIZE;k++)
		{
			a[k][j]=m[k];
		}
		for(int i=0;i<SIZE-1;i++)
			if(a[i][j]==a[i+1][j]&&a[i][j]!=0)
			{
				a[i][j]=2*a[i][j];
				a[i+1][j]=0;
				score++;
			}
		int n[SIZE]={0};
		for(int i=0,k=0;i<SIZE;i++)
		{
			if(a[i][j]!=0)
			{
				n[k++]=a[i][j];
			}
		}
		for(k=0;k<SIZE;k++)
		{
			a[k][j]=n[k];
		}

	}
	if(!_2048_equal())
	{
		_2048_produce();//生成		
	}
	system("clear");//清屏
	_2048_interface();//画
	_2048_over();	//判断结束
}
//向下
void _2048_down()
{
	_2048_invalid();//移动前
	for(int j=0;j<SIZE;j++)
	{
		int m[SIZE]={0},k=SIZE-1;
		for(int i=SIZE-1;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				m[k--]=a[i][j];
			}
		}
		for(k=0;k<SIZE;k++)
		{
			a[k][j]=m[k];
		}
		for(int i=SIZE-1;i>0;i--)
			if(a[i][j]==a[i-1][j]&&a[i][j]!=0)
			{
				a[i][j]=2*a[i][j];
				a[i-1][j]=0;
				score++;
			}
		int n[SIZE]={0};
		for(int i=SIZE-1,k=SIZE-1;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				n[k--]=a[i][j];
			}
		}
		for(k=0;k<SIZE;k++)
		{
			a[k][j]=n[k];
		}

	}
	if(!_2048_equal())
	{
		_2048_produce();//生成		
	}
	_2048_interface();
	_2048_over();
}

//向右
void _2048_right()
{
	_2048_invalid();//移动前

	for(int i=0;i<SIZE;i++)
	{
		int m[SIZE]={0},k=SIZE-1;
		for(int j=SIZE-1;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				m[k--]=a[i][j];
			}
		}
		for(k=0;k<SIZE;k++)
		{
			a[i][k]=m[k];
		}
		for(int j=SIZE-1;j>0;j--)
		{
			if(a[i][j]==a[i][j-1]&&a[i][j]!=0)
			{
				a[i][j]=2*a[i][j];
				a[i][j-1]=0;
				score++;
			}
		}
		int n[SIZE]={0};
		for(int j=SIZE-1,k=SIZE-1;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				n[k--]=a[i][j];
			}
		}
		for(k=0;k<SIZE;k++)
		{
			a[i][k]=n[k];
		}

	}
	if(!_2048_equal())
	{
		_2048_produce();//生成		
	}

	_2048_interface();	
	_2048_over();
}
//向左
void _2048_left()
{
	_2048_invalid();//移动前

	for(int i=0;i<SIZE;i++)
	{
		int m[SIZE]={0},k=0;
		for(int j=0;j<SIZE;j++)
		{
			if(a[i][j]!=0)
			{
				m[k++]=a[i][j];
			}
		}
		for(k=0;k<SIZE;k++)
		{
			a[i][k]=m[k];
		}
		for(int j=0;j<SIZE-1;j++)
		{
			if(a[i][j]==a[i][j+1]&&a[i][j]!=0)
			{
				a[i][j]=2*a[i][j];
				a[i][j+1]=0;
				score++;
			}
		}
		int n[SIZE]={0};
		for(int j=0,k=0;j<SIZE;j++)
		{
			if(a[i][j]!=0)
			{
				n[k++]=a[i][j];
			}
		}
		for(k=0;k<SIZE;k++)
		{
			a[i][k]=n[k];
		}
	}
	if(!_2048_equal())
	{
		_2048_produce();//生成		
	}

	_2048_interface();//画图
	_2048_over();//判断结束
}
//找到该方向上第一个非0的数
//判断该方向上相邻位置有没有非0且相同的数 
//有的话 求和赋值给相邻位置 然后 原位置化为0
//

//按键
void _2048_press()
{
	char key[10];
	while(1)
	{
		scanf("%s",key);
		if(strlen(key)>1)
		{
			key[0]='k';//长度大于一 则表示输入不正确
		}
		switch (key[0])
		{
			case'W'://向上
			case'w':_2048_up();
				break;
			case'S'://向下
			case's':_2048_down();
				break;
			case'A'://向左
			case'a':_2048_left();
				break;
			case'D'://向右
			case'd':_2048_right();
				break;
			case'q':
			case'Q':_2048_exit();
					break;
			case'g':
			case'G':_2048_plugin();
				break;
			default:
			{
				printf("蠢猪，W A S D都按错啊，没有脑子吗？真的是死蠢，给老子重新按：-\n");
				break;
			}
		}
		
	}
	
}

//结束函数
void _2048_over()
{
	int max=a[0][0];
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(a[i][j]>=max)
			{
				max=a[i][j];
			}
		}
	}
	if(max==2048&&nmd==0)
	{			
		nmd++;
		printf("你的分数为：%d\n",score);
		printf("你的最大值：%d\n",max);
		printf("是否需要继续挑战: 1:yes  other:on\n");
		int num;
		scanf("%d",&num);
		getchar();
		if(num==1)
		{
			printf("游戏继续！\n");
		}
		else
		{
			exit(0);
		}
	}
	//每一个位置不为0 且相邻的没有相等的！每一行没有相等的且每一列没有相等的
	int count=0;
	for(int m=0;m<SIZE;m++)
	{	
		for(int n=0;n<SIZE;n++)
		{
			if(a[m][n]!=0)
			{
				count++;
			}
		}
	}
	int p=0;
	if(count==SIZE*SIZE)
	{
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE-1;j++)
			{
				if(a[i][j]==a[i][j+1]&&a[i][j]!=0)
				{
					p++;
				}
			}
		}
		for(int j=0;j<SIZE;j++)
		{
			for(int i=0;i<SIZE-1;i++)
			{
				if(a[i][j]==a[i+1][j]&&a[i][j]!=0)
				{
					p++; 
				}
			}
		}
		if(p==0)
		{
			printf("game over\n");
			printf("你的分数为：%d\n",score);
			printf("你的最大值：%d\n",max);
			exit(0);
		}		
	}
	
}

int main(int argc,char *argv[])
{
	//生成数组
	_2048_produce();
	//画出界面
	_2048_interface();
	//按键
	_2048_press();
	return 0;
}


