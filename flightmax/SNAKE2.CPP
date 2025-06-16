#include <process.h>
#include <dos.h>
#include <conio.h>
#include <iostream.h>
#include <stdio.h>

/*class length
{
	public:
		length(int x,int y):gridx(x),gridy(y)
		{
			slenth++;
		}


	private:
		static int slenth;
		int gridx,gridy;
};
  */


class snake
{
	public:
		snake():x(1),y(1),n(0)/*,gridx(1),gridy(1)*/{}
		void move();
		void down();
		void up();
		void left();
		void right();
	private:
		int x,y,x2,y2,n/*,gridx,gridy*/;
		char grid[80][50];
//		char ygrid[25];

};

struct des
{
	int gridx;
	int gridy;

};

des len[10000];

void snake::move()
{
	textmode(64);
	for(int arry = 0;arry<50;arry++)
	{
		for(int arrx = 0;arrx<80;arrx++)
		{

			grid[arrx][arry] = '\x0';
			cout<<"0";
		}

	}
	char ch;
	char prev = 'a';
	do
	{
		ch=getch();

		if(ch=='x')
		{
			if(prev=='s')
			{
				len[n].gridx = x;
				len[n].gridy = y;
				if(n>8)
				{
					grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
					gotoxy((len[n-9].gridx),(len[n-9].gridy));
					cout<<" ";
					n--;
				}
				else
				{
					grid[x][y] = '\xDB';
					gotoxy(x,y);
					cout<<grid[x][y];
				}
				y++;
				n++;

			}
			if(prev=='d')
			{
				len[n].gridx = x;
				len[n].gridy = y;
				if(n>8)
				{
					grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
					gotoxy((len[n-9].gridx),(len[n-9].gridy));
					cout<<" ";
					n--;
				}
				else
				{
					grid[x][y] = '\xDB';
					gotoxy(x,y);
					cout<<grid[x][y];
				}
				y++;
				n++;
			}
												 //c9 //link bo
												  //bb //regs bo
											 //c8 //links ond

										  //bc //refs ond
			down();
		}
		if(ch=='d')           //working
		{
			if(prev=='x')
			{
				y--;
				len[n].gridx = x;
				len[n].gridy = y;
				if(n>8)
				{
					grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
					gotoxy((len[n-9].gridx),(len[n-9].gridy));
					cout<<" ";
					n--;
				}
				else
				{
					grid[x][y] = '\xDB';
					gotoxy(x,y);
					cout<<grid[x][y];
				}
				n++;
			}
			if(prev=='e')
			{
				y++;
				len[n].gridx = x;
				len[n].gridy = y;
				if(n>8)
				{
					grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
					gotoxy((len[n-9].gridx),(len[n-9].gridy));
					cout<<" ";
					n--;
				}
				else
				{
					grid[x][y] = '\xDB';
					gotoxy(x,y);
					cout<<grid[x][y];
				}
				n++;
			}

			right();
		}
		if(ch=='s')             //working
		{
			if(prev=='x')
			{
				y--;
				len[n].gridx = x;
				len[n].gridy = y;
				if(n>8)
				{
					grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
					gotoxy((len[n-9].gridx),(len[n-9].gridy));
					cout<<" ";
					n--;
				}
				else
				{

					grid[x][y] = '\xDB';
					gotoxy(x,y);
					cout<<grid[x][y];
				}
				n++;
			}
			if(prev=='e')
			{
				y++;
				len[n].gridx = x;
				len[n].gridy = y;
				if(n>8)
				{
					grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
					gotoxy((len[n-9].gridx),(len[n-9].gridy));
					cout<<" ";
					n--;
				}
				else
				{
					grid[x][y] = '\xDB';
					gotoxy(x,y);
					cout<<grid[x][y];
				}
				n++;
			}

			left();
		}
		if(ch=='e')
		{
			if(prev=='s')
			{
				len[n].gridx = x;
				len[n].gridy = y;
				if(n>8)
				{
					grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
					gotoxy((len[n-9].gridx),(len[n-9].gridy));
					cout<<" ";
					n--;
				}
				else
				{
					grid[x][y] = '\xDB';
					gotoxy(x,y);
					cout<<grid[x][y];
				}
				y--;
				n++;
			}
			if(prev=='d')
			{
				len[n].gridx = x;
				len[n].gridy = y;
				if(n>8)
				{
					grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
					gotoxy((len[n-9].gridx),(len[n-9].gridy));
					cout<<" ";
					n--;
				}
				else
				{
					grid[x][y] = '\xDB';
					gotoxy(x,y);
					cout<<grid[x][y];
				}
				y--;
				n++;
			}

			up();
		}
		prev = ch;
	}while(x<500);


}

void snake::down()
{
	while(!kbhit())
	{
		gotoxy(x,y);
		len[n].gridx = x;
		len[n].gridy = y;
		grid[x][y] = '\xDB';
		if(grid[x][y]!='\x0')
		{
			cout<<grid[x][y];
			n++;
		}
		if(grid[x][y+1]!='\x0')
		{
			gotoxy(74,1);
			cout<<"Crashed";
			getch();
			exit(0);
		}
		gotoxy(75,1);
		cout<<len[n].gridx;
		gotoxy(75,2);
		cout<<len[n].gridy;
		if(n>8)
		{
			grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
			gotoxy((len[n-9].gridx),(len[n-9].gridy));
			cout<<" ";
		}
		delay(50);
		y++;

	}




}

void snake::up()
{

	while(!kbhit())
	{
		gotoxy(x,y);
		grid[x][y] = '\xDB';
		if(grid[x][y]!='\x0')
		{
			cout<<grid[x][y];
		}
		if(grid[x][y-1]!='\x0')
		{
			gotoxy(74,1);
			cout<<"Crashed";
			getch();
			exit(0);
		}
		len[n].gridx = x;
		len[n].gridy = y;
		gotoxy(75,1);
		cout<<len[n].gridx;

		gotoxy(75,2);
		cout<<len[n].gridy;
		if(n>8)
		{
			grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
			gotoxy((len[n-9].gridx),(len[n-9].gridy));
			cout<<" ";
		}
		delay(50);
		n++;
		y--;

	}




}

void snake::left()
{

	while(!kbhit())
	{
		x--;
		gotoxy(x,y);
		grid[x][y] = '\xDB';
		if(grid[x][y]!='\x0')
		{
			cout<<grid[x][y];
		}
		if(grid[x-1][y]!='\x0')
		{
			gotoxy(74,1);
			cout<<"Crashed";
			getch();
			exit(0);
		}
		len[n].gridx = x;
		len[n].gridy = y;
		gotoxy(75,1);
		cout<<len[n].gridx;

		gotoxy(75,2);
		cout<<len[n].gridy;

		if(n>8)
		{
			grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
			gotoxy((len[n-9].gridx),(len[n-9].gridy));
			cout<<" ";
		}
		n++;
		delay(50);

	}



}

void snake::right()
{
	while(!kbhit())
	{
		x++;
		gotoxy(x,y);
		grid[x][y] = '\xDB';
		if(grid[x][y]!='\x0')
		{
			cout<<grid[x][y];
		}
		if(grid[x+1][y]!='\x0')
		{
			gotoxy(74,1);
			cout<<"Crashed";
			getch();
			exit(0);
		}
		len[n].gridx = x;
		len[n].gridy = y;
		gotoxy(75,1);
		cout<<len[n].gridx;
		gotoxy(75,2);
		cout<<len[n].gridy;
		if(n>8)
		{
			grid[len[n-9].gridx][len[n-9].gridy] = '\x0';
			gotoxy((len[n-9].gridx),(len[n-9].gridy));
			cout<<" ";
		}
		n++;
		delay(50);
	}




}

int main()
{
	_setcursortype(_NOCURSOR);
	clrscr();
	snake obj;
	obj.move();
	return 0;
}


