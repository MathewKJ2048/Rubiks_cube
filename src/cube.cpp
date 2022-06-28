#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include <dos.h>
#include<ctype.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdlib.h>
#include<graphics.h>



fstream file1, file2, file3, file4;
int gd=DETECT,gm;


void displeft(int cube [7][3][3])
{
int i,j;

for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	{
		int st[]={50+(33*j),100+(20*j)+(34*i),83+(33*j),120+(20*j)+(34*i),83+(33*j),154+(20*j)+(34*i),50+(33*j),134+(34*i)+(20*j),50+(33*j),100+(34*i)+(20*j)};
		setfillstyle(SOLID_FILL,cube[2][i][j]);
		fillpoly(4,st);

	}

 }

}


void disptop(int cube[7][3][3])
{
int i,j;

for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	{
		int st[]={50+(33*i)+(33*j),100+(20*i)-(20*j),83+(33*i)+(33*j),80+(20*i)-(20*j),116+(33*i)+(33*j),100+(20*i)-(20*j),83+(33*i)+(33*j),120+(20*i)-(20*j),50+(33*i)+(33*j),100+(20*i)-(20*j)};
		setfillstyle(SOLID_FILL,cube[1][i][j]);
		fillpoly(4,st);

	}

 }

}


void dispfront(int cube[7][3][3])
{
int i,j;

for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	{
	 int st[]={149+(33*j),160+(34*i)-(20*j),182+(33*j),140+(34*i)-(20*j),182+(33*j),174+(34*i)-(20*j),149+(33*j),194+(34*i)-(20*j),149+(33*j),160+(34*i)-(20*j)};
	 setfillstyle(SOLID_FILL,cube[3][i][j]);
	 fillpoly(4,st);

	}

 }

}


void dispback(int cube[7][3][3])
{
int i,j;

for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	{

	 int st[]={350+(33*j),100-(20*j)+(34*i),383+(33*j),80-(20*j)+(34*i),383+(33*j),114-(20*j)+(34*i),350+(33*j),134-(20*j)+(34*i),350+(33*j),100-(20*j)+(34*i)};
	 setfillstyle(SOLID_FILL,cube[4][i][j]);
	 fillpoly(4,st);

	}

 }

}


void dispright(int cube[7][3][3])
{
int i,j;

for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	 {

	  int st[]={449+(33*j),40+(20*j)+(34*i),482+(33*j),60+(20*j)+(34*i),482+(33*j),94+(20*j)+(34*i),449+(33*j),74+(20*j)+(34*i),449+(33*j),40+(20*j)+(34*i)};
	  setfillstyle(SOLID_FILL,cube[6][i][j]);
	  fillpoly(4,st);

	 }

 }

}


void dispdown(int cube[7][3][3])
{
int i,j;

for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	{
	 int st[]={350+(33*i)+(33*j),202+(20*i)-(20*j),383+(33*i)+(33*j),182+(20*i)-(20*j),416+(33*i)+(33*j),202+(20*i)-(20*j),383+(33*i)+(33*j),222+(20*i)-(20*j),350+(33*i)+(33*j),202+(20*i)-(20*j)};
	 setfillstyle(SOLID_FILL,cube[5][i][j]);
	 fillpoly(4,st);

	}

 }

}

void print(int n[7][3][3])
{

	displeft(n);
	disptop(n);
	dispfront(n);
	dispback(n);
	dispright(n);
	dispdown(n);

}





class Block
{
    public:
    int id;//id is a 3 digit number ijk of it's correct position
    int pos;//current position encoded by 3 digit number ijk
    int up, down, face, back, right, left;//each colour is encoded by a 3 digit number ijk
    Block()
    {
    }
    Block(Block &b)//copy constructor
    {
	id=b.id;pos=b.pos;
	up = b.up; face = b.face; down = b.down; back = b.back; left = b.left; right = b.right;
    }

    //rotation of block
    //left screw rule
    void y()
    {
	int temp = face;
	face = right;
	right = back;
	back = left;
	left = temp;
    }
    void x()
    {
	int temp = face;
	face = down;
	down = back;
	back = up;
	up = temp;
    }
    void z()
    {
	int temp = up;
	up = left;
	left = down;
	down = right;
	right = temp;
    }
    void yi()
    {
	int temp = face;
	face = left;
	left = back;
	back = right;
	right = temp;
    }
    void zi()
    {
	int temp = left;
	left = up;
	up = right;
	right = down;
	down = temp;
    }
    void xi()
    {
	int temp = face;
	face = up;
	up = back;
	back = down;
	down = temp;
    }


};

double speed=50;
class Cube
{
    private:
    Block cube[3][3][3];
    int c[10][10][10];
    int colours[6];//stores numerical codes for the 6 colours on the six faces
	/*
	u-0
	d-1
	l-2
	r-3
	f-4
	b-5
	*/

    void paint();//initializes colours of blocks
    void update();//updates current position of block in block's memory after moving
    void build_cube();

    //public:
    //primitive functions
    void y(int l);
    void yi(int l);
    void x(int l);
    void xi(int l);
    void z(int l);
    void zi(int l);

    public:
    int n[7][3][3];

    Cube()
    {
	 build_cube();
    }
    void build_copy(Cube c);
    Cube(Cube &c)//copy constructor
    {
	cout << "Copy constructor activated";
	build_copy(c);
    }


    //movement functions
    void u(){y(0);}
    void d(){yi(2);}
    void l(){xi(0);}
    void r(){x(2);}
    void f(){z(2);}
    void b(){zi(0);}
    //
    void ui(){yi(0);}
    void di(){y(2);}
    void li(){x(0);}
    void ri(){xi(2);}
    void fi(){zi(2);}
    void bi(){z(0);}
    //
    void m(){xi(1);}
    void s(){z(1);}
    void e(){yi(1);}
    void mi(){x(1);}
    void si(){zi(1);}
    void ei(){y(1);}
    //
    void uw(){y(0);y(1);}
    void dw(){yi(1);yi(2);}
    void lw(){xi(0);xi(1);}
    void rw(){x(1);x(2);}
    void fw(){z(1);z(2);}
    void bw(){zi(0);zi(1);}
    //
    void uwi(){yi(0);yi(1);}
    void dwi(){y(1);y(2);}
    void lwi(){x(0);x(1);}
    void rwi(){xi(1);xi(2);}
    void fwi(){zi(1);zi(2);}
    void bwi(){z(0);z(1);}
    //
    void x(){x(0);x(1);x(2);};
    void xi(){xi(0);xi(1);xi(2);};
    void y(){y(0);y(1);y(2);};
    void yi(){yi(0);yi(1);yi(2);};
    void z(){z(0);z(1);z(2);};
    void zi(){zi(0);zi(1);zi(2);};
    //
    //accessor functions
    void get_faces(int faces[6][3][3]);//returns the faces as array of 2D integer matrices
    int get_pos_of(int id);//hunts down block of given id and returns it's current pos
    int get_id_of(int pos)//gives id of the block at the given pos
    {
	  return cube[pos/100][(pos/10)%10][pos%10].id;
    }
    int get_col_of(int pos,char f)//gives colour on a given face of a given block
    {
	int i=pos/100,j=(pos/10)%10,k=pos%10,r=0;
	if(f=='u')r=cube[i][j][k].up;
	else if(f=='d')r=cube[i][j][k].down;
	else if(f=='l')r=cube[i][j][k].left;
	else if(f=='r')r=cube[i][j][k].right;
	else if(f=='f')r=cube[i][j][k].face;
	else if(f=='b')r=cube[i][j][k].back;
	return r;
    }
    int is_correct_pos(int id)//checks if the given block is in its correct position
    {
	if(get_pos_of(id)==id)return 1;
	else return 0;
    }
    int is_correct_block(int pos)//checks if given position is being occupied by correct block
    {
	if(get_id_of(pos)==pos)return 1;
	else return 0;
    }
    //
    void print()//to be eliminated once the graphics function is finished
    { 	delay(speed);
	clrscr();
	::print(n);
    }
};
void Cube::get_faces(int faces[6][3][3])//gives colours on 6 faces as an array of 2D arrays
{
    int i,j,k;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			faces[0][i][j]=cube[i][j][0].up;
	for( j=0;j<3;j++)
		for(k=0;k<3;k++)
			faces[1][j][k]=cube[2][j][k].face;
	for( j=0;j<3;j++)
		for(k=0;k<3;k++)
			faces[2][j][k]=cube[0][j][k].back;
	for(i=0;i<3;i++)
		for(k=0;k<3;k++)
			faces[3][i][k]=cube[i][0][k].left;
	for(i=0;i<3;i++)
		for(k=0;k<3;k++)
			faces[4][i][k]=cube[i][2][k].right;
	for(i=0; i<3;i++)
		for(j=0;j<3;j++)
			faces[5][i][j]=cube[i][j][2].down;
}
int face_solved(int f[3][3])//checks if the given face is solved
{
    int col=f[0][0];
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(f[i][j]!=col)return 0;
    return 1;
}
int is_solved(Cube &c)//checks if given cube is in a solved state
{
    int faces[6][3][3];
    c.get_faces(faces);
    for(int i=0;i<6;i++)if(face_solved(faces[i])==0)return 0;
    return 1;
}
void Cube::paint()//initializes colours
 {
    int i,j,k;
    //painting upper face
    for(i=0;i<3;i++)for(j=0;j<3;j++){cube[i][j][0].up=colours[0];}//u-0
    //painting bottom face
    for(i=0;i<3;i++)for(j=0;j<3;j++){cube[i][j][2].down=colours[1];}
    //painting front face
    for(k=0;k<3;k++)for(j=0;j<3;j++){cube[2][j][k].face=colours[4];}
    //painting back face
    for(k=0;k<3;k++)for(j=0;j<3;j++){cube[0][j][k].back=colours[5];}
    //painting left face
    for(i=0;i<3;i++)for(k=0;k<3;k++){cube[i][0][k].left=colours[2];}
    //painting right face
    for(i=0;i<3;i++)for(k=0;k<3;k++){cube[i][2][k].right=colours[3];}
}
void Cube::update()//updates current position
{
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++){cube[i][j][k].pos=100*i+10*j+k;}
    for(i=0;i<3;i++)for(j=0;j<3;j++){n[1][i][j]=cube[i][j][0].up;}
    for(i=0;i<3;i++)for(j=0;j<3;j++){n[5][i][j]=cube[i][j][2].down;}
    for(k=0;k<3;k++)for(j=0;j<3;j++){n[3][k][j]=cube[2][j][k].face;}
    for(k=0;k<3;k++)for(j=0;j<3;j++){n[4][k][j]=cube[0][j][k].back;}
    for(i=0;i<3;i++)for(k=0;k<3;k++){n[2][k][i]=cube[i][0][k].left;}
    for(i=0;i<3;i++)for(k=0;k<3;k++){n[6][k][i]=cube[i][2][k].right;}
}
int Cube::get_pos_of(int id)
{
	  for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)if(cube[i][j][k].id==id)return cube[i][j][k].pos;
	  return -1;
}
void Cube::build_cube()
{
	colours[0]=15; //15
	colours[1]=14; //14
	colours[2]=4;  //4
	colours[3]=6; //6
	colours[4]=1;  //1
	colours[5]=2;  //2
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++){cube[i][j][k].id=i*100+j*10+k;}
	paint();
	update();
}
void Cube::build_copy(Cube c)
{
    for(int i=1;i<7;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
				n[i][j][k] = c.n[i][j][k];
		}
	}
}



//movement functions
void Cube::yi(int l)
{
    int i,j;
    Block temp[3][3];
    for(i=0;i<3;i++)for(j=0;j<3;j++)temp[2-j][i]=cube[i][j][l];
    for(i=0;i<3;i++)for(j=0;j<3;j++){cube[i][j][l]=temp[i][j];cube[i][j][l].yi();}
    update();print();
}
void Cube::x(int l)
{
  int i,j,k; Block temp[3][3];
  for(i=0;i<3;i++)for(k=0;k<3;k++)temp[k][2-i]=cube[i][l][k];
  for(i=0;i<3;i++)for(k=0;k<3;k++){cube[i][l][k]=temp[i][k];cube[i][l][k].x();}
  update();print();
}
void Cube::z(int l)
{
   int i,j,k; Block temp[3][3];
   for(j=0;j<3;j++)for(k=0;k<3;k++)temp[2-k][j]=cube[l][j][k];
   for(j=0;j<3;j++)for(k=0;k<3;k++){cube[l][j][k]=temp[j][k];cube[l][j][k].z();}
   update();print();
}
void Cube::zi(int l)
{
  int i,j,k; Block temp[3][3];
  for(j=0;j<3;j++)for(k=0;k<3;k++)temp[k][2-j]=cube[l][j][k];
  for(j=0;j<3;j++)for(k=0;k<3;k++){cube[l][j][k]=temp[j][k];cube[l][j][k].zi();}
  update();print();
}
void Cube::y(int l)
{
  int i,j,k; Block temp[3][3];
  for(i=0;i<3;i++)for(j=0;j<3;j++)temp[j][2-i]=cube[i][j][l];
  for(i=0;i<3;i++)for(j=0;j<3;j++){cube[i][j][l]=temp[i][j];cube[i][j][l].y();}
  update();print();
}
void Cube::xi(int l)
{
  int i,j,k; Block temp[3][3];
  for(i=0;i<3;i++) for(k=0;k<3;k++)temp[2-k][i]=cube[i][l][k];
  for(i=0;i<3;i++)for(k=0;k<3;k++){cube[i][l][k]=temp[i][k];cube[i][l][k].xi();}
  update();print();
}









int is_face(int id,Cube &c)//checks if the given block is on the face
{
    if(c.get_pos_of(id)/100==2)return 1;
    return 0;
}
int is_down(int id,Cube &c)//checks if the given block in the bottom layer
{
    if(c.get_pos_of(id)%10==2)return 1;
    return 0;
}
int is_up(int id,Cube &c)//checks if the given block in the bottom layer
{
    if(c.get_pos_of(id)%10==0)return 1;
    return 0;
}
void turn_to_face(int id,Cube &c)//turns till given piece is on the face
{
    int f=1;                                     //failsafe mechanism
    while(!is_face(id,c))
    {
	c.y();
	f++;if(f>4){cout<<"error";break;}        //exits if given piece in inappropriate like 110
    }
}
void orient(Cube &c)                             //orients the cube properly with white on top and blue to the face
{
    while(!is_face(110,c)&&!is_face(211,c))c.y();
    if(is_face(110,c)){c.x();turn_to_face(211,c);}//if upper face is encountered
    else while(!c.is_correct_pos(110))c.z();      //if face is found
}
void white_cross(Cube &c)
{
    orient(c);
    int centres[]={211,101,11,121};   //centres of the cube
    int edges[]={210,100,10,120};     //white edges
    for(int i=0;i<4;i++)              //loop for 4 different colours
    {
	if(!is_down(edges[i],c))
	{
	turn_to_face(edges[i],c);//gets the piece on the face

	//gets piece to bottom layer without disturbing the other pieces already in place
	if(is_up(edges[i],c)){c.f();c.f();}                                          //piece is on top
	else if(c.get_pos_of(edges[i])==201){c.fi();c.d();c.f();} //piece is middle left
	else if(c.get_pos_of(edges[i])==221){c.f();c.d();c.fi();} //piece is middle right
	}

	turn_to_face(centres[i],c);
	while(!is_face(edges[i],c)){c.d();}//aligns the piece it's centre

	if(c.get_col_of(212,'f')==c.get_col_of(211,'f')){c.f();c.f();}  //face colour matches centre
	else{c.f();c.u();c.li();c.ui();}                                //face colour is white
    }
}
void white_corners(Cube &c)
{
    orient(c);
    int corners[] ={200,0,20,220};
    int centres[] = {211,101,11,121};
    for(int i=0;i<4;i++)
    {
	if(!is_down(corners[i],c))
	{
	    turn_to_face(corners[i],c);//gets the piece on the face
	    if(c.get_pos_of(corners[i])==220)c.y();//gets piece on left side
	    c.fi();c.d();c.f();//gets piece down

	}

	turn_to_face(centres[i],c);
	while(c.get_pos_of(corners[i])!=202)c.d();//puts piece just below proper place

	int u=c.get_col_of(110,'u');//stores upper colour
	//the piece is at 202 by now
	if(c.get_col_of(202,'d')==u){c.fi();c.d();c.f();c.di();c.di();}
	if(c.get_col_of(202,'f')==u){c.fi();c.di();c.f();}
	else if(c.get_col_of(202,'l')==u){c.l();c.d();c.li();}
    }
}
void second_layer(Cube &c)
{
    orient(c);
    int edges[]={201,1,21,221};
    int centres[]={211,101,11,121};
    for(int i=0;i<4;i++)
    {
	if(!is_down(edges[i],c))
	{
	    turn_to_face(edges[i],c);//gets the piece on the face
		if(c.get_pos_of(edges[i])==221)c.y();//gets piece on left side
		c.l();c.d();c.li();c.di();c.fi();c.di();c.f();//gets piece down
	}

	turn_to_face(centres[i],c);
	while(!is_face(edges[i],c))c.d();   //aligns piece with centre

	if(c.get_col_of(211,'f')==c.get_col_of(212,'f')){c.d();c.l();c.di();c.li();c.di();c.fi();c.d();c.f();}//if colour matches
	else{c.di();c.di();c.fi();c.d();c.f();c.d();c.l();c.di();c.li();}                          //if the colour does not match
    }
}
void orient_yellow_cross(Cube &c)
{
    orient(c);
    c.z();c.z();
    int edges[]={10, 100, 120, 210}, u=c.get_col_of(110,'u'), t[4], o=0;	    //t holds pieces with correct orientation

    for(int i=0; i<4; i++)if(c.get_col_of(edges[i],'u')==u){t[o]=edges[i];o++;}   //filling t and finding o

    if(o==0){c.f();c.r();c.u();c.ri();c.ui();c.fi();c.u();c.u();c.f();c.u();c.r();c.ui();c.ri();c.fi();}   // * - case

    else if(o==2)
    {
	if(abs(t[1]/100-t[0]/100)==1) //L - case
	{
	    while(!(c.get_col_of(10,'u')==u&&c.get_col_of(100,'u')==u))c.u();
	    c.f();c.u();c.r();c.ui();c.ri();c.fi();
	}
	else    // | - case
	{
	    while(!(c.get_col_of(100,'u')==u&&c.get_col_of(120,'u')==u))c.u();
	    c.f();c.r();c.u();c.ri();c.ui();c.fi();
	}
    }
}

void align_yellow_cross(Cube &c)
{
    orient(c);
    while(!c.is_correct_block(212))c.d();//makes the face align with edge
    while(!c.is_correct_block(102)){c.l();c.d();c.li();c.d();c.l();c.di();c.di();c.li();}//makes left edge align
    if(!c.is_correct_block(122)){c.y();c.l();c.d();c.li();c.d();c.l();c.di();c.di();c.li();c.d();}//aligns the other two edges
}
void align_yellow_corners(Cube &c)
{
    orient(c);
    if(c.get_pos_of(202)==2)
    {c.di();c.ri();c.d();c.l();c.di();c.r();c.d();c.li();}

    else while(!c.is_correct_block(202))
    {c.d();c.b();c.di();c.fi();c.d();c.bi();c.di();c.f();}
    while(!c.is_correct_block(2)){c.d();c.l();c.di();c.ri();c.d();c.li();c.di();c.r();}
}

void orient_yellow_corners(Cube &c)

{
    for(int i=1;i<=4;i++)//orients 4 pieces
    {
	while(c.get_col_of(202,'d')!=c.get_col_of(112,'d')){c.f();c.u();c.fi();c.ui();}
	c.d();
    }
    while(c.get_col_of(211,'f')!=c.get_col_of(212,'f'))c.d();//aligns last layer
}







//void process(char m[5],Cube &c)
//{
//interpret commands and execute
//}
void scramble(Cube &c)
{
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	char t[75];
	randomize(); int move;

	for(int i=0;i<20;i++)
	{
		move=random(1000)%12;

		switch(move)
		{
			case 0:
				c.u();
				if(i==0)
					strcpy(t,"u  ");
				else
					strcat(t,"u  ");
				break;
			case 1:
				c.ui();
				if(i==0)
					strcpy(t,"ui ");
				else
					strcat(t,"ui ");
				break;
			case 2:
				c.d();
				if(i==0)
					strcpy(t,"d  ");
				else
					strcat(t,"d  ");
				break;
			case 3:
				c.di();
				if(i==0)
					strcpy(t,"di ");
				else
					strcat(t,"di ");
				break;
			case 4:
				c.f();
				if(i==0)
					strcpy(t,"f  ");
				else
					strcat(t,"f  ");
				break;
			case 5:
				c.fi();
				if(i==0)
					strcpy(t,"fi ");
				else
					strcat(t,"fi ");
				break;
			case 6:
				c.b();
				if(i==0)
					strcpy(t,"b  ");
				else
					strcat(t,"b  ");
				break;
			case 7:
				c.bi();
				if(i==0)
					strcpy(t,"bi ");
				else
					strcat(t,"bi ");
				break;
			case 8:
				c.r();
				if(i==0)
					strcpy(t,"r  ");
				else
					strcat(t,"r  ");
				break;
			case 9:
				c.ri();
				if(i==0)
					strcpy(t,"ri ");
				else
					strcat(t,"ri ");
				break;
			case 10:
				c.l();
				if(i==0)
					strcpy(t,"l  ");
				else
					strcat(t,"l  ");
				break;
			case 11:
				c.li();
				if(i==0)
					strcpy(t,"li ");
				else
					strcat(t,"li ");
				break;
		}
	}

	for(i=0;i<5;i++)
	{
		move=random(100)%3;
		switch(move)
		{
			case 0:
				c.x();
				strcat(t,"x  ");
				break;
			case 1:
				c.y();
				strcat(t,"y  ");
				break;

			case 2:
				c.z();
				strcat(t,"z  ");
				break;
		}
	}

	file1.open("auto_scramble.txt",ios::app);
	file1 << t;
	file1.close();
	file2.open("present_scramble.txt",ios::app);
	file2 << t;
	file2.close();

}

void solve(Cube &c)

{
	if(!is_solved(c))

	{
		white_cross(c);
		white_corners(c);
		second_layer(c);
		c.z();c.z();
		orient_yellow_cross(c);
		align_yellow_cross(c);
		align_yellow_corners(c);
		orient_yellow_corners(c);
	}

}

void countdown()
{
	clrscr();

	for(int i=5;i>=1;i--)
	{
		cout<<i<<"...";
		delay(1000);
		clrscr();
	}
}

void printerror1();

void printerror2();

void printerror3();

void race()
{
	char s[75], ch;
	file1.open("auto_scramble.txt",ios::out);
	file1.close();
	int avg=0;
	char inp[50];
	Cube c;

	do
	{
		avg=0;
		file2.open("present_scramble.txt",ios::out);
		file2<<"Scramble: ";
		file2.close();

		allthepart:

		clrscr();
		cout<<"Enter average solve time (in seconds): ";
		cin>>inp;
		for(int i=0; i<strlen(inp); i++)
		{
			if(isdigit(inp[i]))
				avg = avg*10 + inp[i] - 48;
			else
			{
				printerror1();
				goto allthepart;
			}
		}

		if(avg>=200)
		{
			printerror2();
			delay(500);
			goto here;
		}

		scramble(c);
		speed=(double)avg/(double)30;
		file2.open("present_scramble.txt",ios::in);
		while(!file2.eof())
		{	file2.getline(s,76);
			cout << "\n" << s;
		}file2.close();


		getch();
		countdown();

		clrscr();

		white_cross(c);

		if(kbhit()) goto checkp;
		white_corners(c);

		if(kbhit()) goto checkp;
		second_layer(c);

		if(kbhit()) goto checkp;
		c.z();c.z();

		if(kbhit()) goto checkp;
		orient_yellow_cross(c);

		if(kbhit()) goto checkp;
		align_yellow_cross(c);

		if(kbhit()) goto checkp;
		align_yellow_corners(c);

		if(kbhit()) goto checkp;
		orient_yellow_corners(c);


		checkp:
			if(is_solved(c))
			cout<<"YOU LOST!! BETTER LUCK NEXT TIME!";

			else
			cout<<"YOU WON!!!";


		cout << "\nDO YOU WANT TO TRY AGAIN?(y/n)  ";

		cin >> ch;

	}while(ch!='n');

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nList of the scrambles you did this in this session: ";

	file1.open("auto_scramble.txt",ios::in);

	while(!file1.eof())

	{
		file1.getline(s,76);
		cout << "\n" << s;

	}file1.close();

	here:

	getch();
	closegraph();
	restorecrtmode();

}

void ins()
{
	file3.open("instructions.txt",ios::out);
	file3 << "'r' for right move.'u' for up move.'f' for front move.'l' for left move.'b' for back move.'d' for down move.'s' for scrambling.";
	file3 << "You can use 'x', 'y', 'z' for cube rotation in the respective axes.Type in 'quit' to quit.";
	file3 << "Press 'w' if you want the computer to solve the cube.Press p to save and exit the game.This message can be veiwed any time by pressing 'h'...PRESS ANY KEY TO CONTINUE";
	file3.close();
}
void instructions()
{
	char s[3000];
	ins();
	file3.open("instructions.txt",ios::in);
	while(!file3.eof())
	{
		file3.getline(s,300,'.');
		cout << s << "\n";
	}
	file3.close();
	getch();
}

void play_around()

{
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	cleardevice();
	instructions();
	Cube c;
	int p;
	char m[10];
	file4.open("pause.dat",ios::in|ios::binary);
	file4.seekg(0, ios::end);
	p = file4.tellg()/sizeof(c);
	file4.close();
	if(p!=0)
	{
		char t;
		cout << "\n\nDo you want to continue from previous position?(y/n)\n";
		cin>>t;
		if(t=='y')
		{
			initgraph(&gd,&gm,"C:/TURBOC3/BGI");
			Cube k;
			file4.open("pause.dat",ios::in|ios::binary);
			file4.read((char*)&k,sizeof(k));
			c = k;
			file4.close();
		}
		remove("pause.dat");
	}

	//initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	char a;

	//while(strcmpi(m,"quit")!=0)
	while(1)
	{
		if(strcmpi(m,"quit")!=0)
		{
		cleardevice();
		c.print();

		label:

		cin>>m;
		a = m[0];
		if(strlen(m)>1&&strcmpi(m,"quit")!=0)
		{
			if(strcmpi(m,"xi")==0){c.xi();}
			else if(strcmpi(m,"yi")==0){c.yi();}
			else if(strcmpi(m,"zi")==0){c.zi();}
			else if(strcmpi(m,"ui")==0){c.ui();}
			else if(strcmpi(m,"fi")==0){c.fi();}
			else if(strcmpi(m,"ri")==0){c.ri();}
			else if(strcmpi(m,"di")==0){c.di();}
			else if(strcmpi(m,"bi")==0){c.bi();}
			else if(strcmpi(m,"li")==0){c.li();}
			else
			{
				printerror3();
				goto label;
			}
		}
		else if(a=='x'){c.x();}
		else if(a=='y'){c.y();}
		else if(a=='z'){c.z();}
		else if(a=='u'){c.u();}
		else if(a=='r'){c.r();}
		else if(a=='f'){c.f();}
		else if(a=='b'){c.b();}
		else if(a=='l'){c.l();}
		else if(a=='d'){c.d();}
		else if(a=='o'){orient(c);}
		else if(a=='h')
		{
			clrscr();
			cout << "\n\n\n\n\n\n\n\n";
			instructions();
		}
		else if(a=='p')
		{
			file4.open("pause.dat",ios::out|ios::binary);
			file4.write((char*)&c,sizeof(c));
			file4.close();
			break;
		}
		else if(a=='s'){scramble(c);}
		else if(a=='w'){solve(c);}
		else if(strlen(m)==1)
		{
			printerror3();
			goto label;

		}
		}
		else
		goto lol;
	}
	lol:
	closegraph();restorecrtmode();
}

void printerror1()
{
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	settextstyle(1,0,2);
	outtextxy(200,100,"CAN");
	delay(500);
	outtextxy(250,100,"YOU");
	delay(500);
	outtextxy(300,100,"NOT");
	delay(500);
	outtextxy(350,100,"READ!!!");
	delay(500);
	outtextxy(240,120,"INVALID INPUT!!");
	delay(500);

}

void printerror2()
{
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	cleardevice();
	settextstyle(8,0,1);
	outtextxy(100,100,"TOO SLOW...");
	delay(1000);
	outtextxy(100,130,"NOT WORTH MY TIME !!");
	delay(500);
}

void printerror3()
{
	cout << "\nEnter a valid command.";
	cout << "\nEnter 'h' to see the controls\n";
	delay(1000);
}

void main_page()
{
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");

	for(int i=0;i<3;i++)
	{
		cleardevice();
		delay(800);
		settextstyle(8,0,3);
		outtextxy(150,150,"WELCOME TO ");
		outtextxy(60,180,"CUBING CENTER !! (WCA AFFILIATED)");
		delay(800);

	}
	delay(1000);
}


void main_menu_text()
{

	initgraph(&gd,&gm,"C:/TURBOC3/BGI");

	settextstyle(1,0,2);
	outtextxy(250,0,"MAIN MENU");
	delay(200);
	outtextxy(250,5,"__________");
	delay(200);
	outtextxy(100,30,"Enter 1 to race with the computer,");
	delay(200);
	outtextxy(100,50,"2 to play with the simulation of the computer,");
	delay(200);
	outtextxy(100,70,"0 to end the game and quit");

}

void main()
{


	clrscr();
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	int c;   char g[50];
	char n;
	main_page();
	do{
		clrscr();

		speed=1;
		do{
			main_menu_text();
			cin>>g;
			n=g[0];
			if(n=='1')
			{
				race();c=1;
			}
			else if(n=='2')
			{
				play_around();c=1;
			}
			else if(n=='0')
				break;
			else
			{
				printerror1();
				c=0;
				delay(500);
				clrscr();
			}



		}while(c==0);

	}while(n!='0');
	getch();
	closegraph(); restorecrtmode();

}