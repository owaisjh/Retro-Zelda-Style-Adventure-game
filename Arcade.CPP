
#include<constrea.h>
#include<stdlib.h>
#include<fstream.h>
#include<dos.h>
#include<ctype.h>
char m[24][24];
int *hold;
int color[]={2,14,4};
int endflag;
int* find_a();
int end(int i, int j)
{
	if((m[i][j]=='E'||m[i][j]=='X'||m[i][j]=='I'||m[i][j]=='T')&&endflag==1)
		return 0;
	if(*hold!=2&&*hold!=4&&*hold!=14)
	{
		clrscr();
		for(int i=0;i<80;i++)
		{
			if(i==69)
				cout<<"SHRAVAN FOR HEAD BOY";
			cout<<"GAME OVER";
		}
		delay(4000);
		exit(0);
	}
	return 1;
}
int end()
{
	int i,j,*ptr;
	ptr=find_a();
	i=*ptr;
	j=*(ptr+1);
	if((m[i][j]=='E'||m[i][j]=='X'||m[i][j]=='I'||m[i][j]=='T')&&endflag==1)
		return 0;
	return 1;
}
void gun(char *ptr)
{
	 if(isalpha(*(ptr+1)))
	 {
		ptr++;
		*ptr=' ';
	 }
	 else if(isalpha(*(ptr-1)))
	 {
		ptr--;
		*ptr=' ';
	 }
	 /*else if(isalpha(*(ptr-24)))
	 {
		ptr=ptr-24;
		*ptr=' ';
	 }
	 else if(isalpha(*(ptr+24)))
	 {
		ptr=ptr+24;
		*ptr=' ';
	 }*/
}
void vision_pointh(char *ptr, int chec)
{
	   if(chec==0)
	   {
		ptr--;
		int flag=0;
		while(*ptr!='/')
		{
			/*if(*ptr==' '&&flag==0)
			{
				*ptr='-';
				flag=1;
			}
			else if(*ptr==' '&&*(ptr+1)!='/')
			{
				*ptr=*(ptr+1);
				*(ptr+1)=' ';
			}*/
			if(*ptr=='K')
			{
				hold++;
				break;
			}
			ptr--;
		}
	   }
	   if(chec==1)
	   {
		ptr++;
		int flag=0;
		while(*ptr!='/')
		{
			/*if(*ptr==' '&&flag==0)
			{
				*ptr='-';
				flag=1;
			}
			else if(*ptr==' '&&*(ptr-1)!='/')
			{
				*ptr=*(ptr-1);
				*(ptr-1)=' ';
			} */
			if(*ptr=='K')
			{
				hold++;
				break;
			}
			ptr++;
		}
	   }
}
void vision_pointv(char *ptr, int chec)
{
	if(chec==0)
	{
		ptr=ptr-24;
		int flag=0;
		while(*ptr!='/')
		{
			/*if(*ptr==' '&&flag==0)
			{
				*ptr='-';
				flag=1;
			}
			else if(*ptr==' '&&*(ptr-24)!='/')
			{
				*ptr=*(ptr+24);
				*(ptr+24)=' ';
			}*/
			if(*ptr=='K')
			{
				hold++;
				break;
			}
			ptr=ptr-24;
		}
	}
	if(chec==1)
	{
		ptr=ptr+24;
		int flag=0;
		while(*ptr!='/')
		{
			/*if(*ptr==' '&&flag==0)
			{
				*ptr='-';
				flag=1;
			}
			else if(*ptr==' '&&*(ptr-24)=='/')
			{
				*ptr=*(ptr-24);
				*(ptr-24)=' ';
			}*/
			if(*ptr=='K')
			{
				hold++;
				break;
			}
			ptr=ptr+24;
		}
	}
}

void print()
{
	clrscr();
       /*	for(int i=0;i<24;i++)
	{
		for(int j=0;j<24;j++)
			cout<<m[i][j]<<" ";
		cout<<endl;
	}*/
	char str[]="\0";
	for(int j=0;j<24;j++)
	{
		cprintf(" ");
		for(int i=0;i<24;i++)
		{
			 textcolor(*hold);
			 str[0]=m[j][i];
			 cprintf(str);
			 cprintf(" ");
		 }
		 cprintf("                              ");
		 cprintf("\n\r");

	 }
}
int *find_a()
{
	int a[2];
	for(int i=0;i<24;i++)
	{
		for(int j=0;j<24;j++)
		{
			if(m[i][j]=='K')
			{
				a[0]=i;
				a[1]=j;
			}
		}
	}
	return a;
}

int condition(int i,int j)
{
	if(m[i][j]=='/')
		return 0;
	else if( m[i][j]=='V'||m[i][j]=='M'||m[i][j]=='U'||m[i][j]=='L'||m[i][j]=='H')
		return 0;
	else if((m[i][j]=='E'||m[i][j]=='X'||m[i][j]=='I'||m[i][j]=='T')&&endflag==0)
		return 0;
	return 1;
}
void characters();
int proc(char in)
{
	int *p=find_a();
	int i=*p;
	int j=*(p+1);
	int n;
	switch(in)
	{
		case 'w':
			if(condition(i-1,j))
			{
				n=end(i-1,j);
				m[i-1][j]='K';
				m[i][j]=' ';
			}
			break;
		case 'a':
			if(condition(i,j-1))
			{
				n=end(i,j-1);
				m[i][j-1]='K';
				m[i][j]=' ';
			}
			break;
		case 'd':
			if(condition(i,j+1))
			{
				n=end(i,j+1);
				m[i][j+1]='K';
				m[i][j]=' ';
			}
			break;

		case 's':
			if(condition(i+1,j))
			{
				n=end(i+1,j);
				m[i+1][j]='K';
				m[i][j]=' ';
			}
			break;
		case ' ':
			gun(&m[i][j]);
			break;

	}
	characters();
	print();
	return n;
}
int cond_hor(char *ptr,int alt_flag)
{
	if(*(ptr-1)=='/')
		alt_flag=1;
	else if(*(ptr+1)=='/')
		alt_flag=0;
	if(alt_flag==0)
	{
		if(*(ptr-1)!='/')
		{
			*(ptr-1)=*ptr;
			*ptr=' ';
			ptr=&(*(ptr-1));
		}
	}
	if(alt_flag==1)
	{
		if(*(ptr+1)!='/')
		{
			*(ptr+1)=*ptr;
			*ptr=' ';
			ptr=&(*(ptr+1));
		}
	}
	return alt_flag;
}
int cond_vert(char *ptr,int alt_flag1)
{
	if(*(ptr-24)=='/')
		alt_flag1=1;
	else if(*(ptr+24)=='/')
		alt_flag1=0;
	if(alt_flag1==0)
	{
			*(ptr-24)=*ptr;
			*ptr=' ';
			ptr=&(*(ptr-24));
	}
	else if(alt_flag1==1)
	{
			*(ptr+24)=*ptr;
			*ptr=' ';
			ptr=&(*(ptr+24));
	}
	return alt_flag1;
}
char* find_char(char ch)
{
	char *ptr;
	for(int i=0;i<24;i++)
	{
		for(int j=0;j<24;j++)
		{
			ptr=&m[i][j];
			if(m[i][j]==ch)
				return ptr;
		}
	}
	return 0;
}
void characters()
{
	  static int m,v,u,l,h;
	  v=cond_vert(find_char('V'),v);
	  m=cond_vert(find_char('M'),m);
	  u=cond_vert(find_char('U'),u);
	  l=cond_hor(find_char('L'),l);
	  h=cond_hor(find_char('H'),h);
	  if(find_char('O')==0)
		endflag=1;
	  vision_pointv(find_char('V'),v);
	  vision_pointv(find_char('M'),m);
	  vision_pointv(find_char('U'),u);
	  vision_pointh(find_char('L'),l);
	  vision_pointh(find_char('H'),h);
}
void read()
{
	 ifstream f1;
	 f1.open("lvl3.txt");
	 while(!f1.eof())
	 for(int i=0;i<24;i++)
		for(int j=0;j<24;j++)
				f1.get(m[i][j]);
	 m[0][1]='/';
	 m[1][1]='K';
	 m[3][8]='V';
	 m[14][9]='M';
	 m[14][6]='U';
	 m[1][22]='L';
	 m[9][22]='H';
	 m[13][1]='O';
	 m[0][0]='/';
	 f1.close();
}
void main()
{
	clrscr();
	hold=color;
	read();
	char chl;
	chl=getch();
	print();
	int flag=1;
	while(flag)
	{
	       chl=getch();
	       flag=proc(chl);
	       if(flag==0)
			break;
	       if(chl=='e'||end()==0)
			exit(0);
	}
}