#ifndef _box_h_
#define _box_h_


class box
{
	public:
		box(int xleft,int xtop,int xright,int xbottom,int xtbgcolour,
			int xtecolour,int xkey,int xkey2,int xhdr,char* xmsg)
			:buffer(0),left(xleft),top(xtop)
			,right(xright),bottom(xbottom)
			,tbgcolour(xtbgcolour),tecolour(xtecolour)
			,key(xkey),key2(xkey2),hdr(xhdr),msg(xmsg)
		{}
		box() : buffer(0) {}

		~box()
		{
			free();
		}

		void save();
		void load();
		void show();
		void show2(int key);
		void showbar(int y);
		int menubox(int,int,int,int,char[6][39],int);
		void menubar(int,int,int,int);
		void hide();
		void free()
		{
			if(buffer)
			{
				delete[] buffer;
				buffer=0;
			}
		}
		void smallbar(int,int,int);

	protected:
		int key,key2,tecolour,tbgcolour,left,top,right,bottom,hdr;
		char* msg,*buffer;

};


#endif

