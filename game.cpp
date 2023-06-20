//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : Hassan Saeed (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> 
#include <string>
using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int width = 1020, height = 840; 
int x_blockage[7]  , y_blockage[7] ;int final_X=1020 , final_Y=840 ;
int pas1_x , pas1_y , pas2_x , pas2_y , pas3_x , pas3_y ;
int counter = 0;
char taxi_color;
int score = 0 ;
bool occupied = false ;
bool init = true ;
int timer , timer_1;
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int xI = 0 , yI = 800 , x1I = 200 , y1I = 200 , x2I = 800, y2I = 100 , x3I = 400, y3I =100 ;
int a=100,b=200,c=300,d=400,e=500,f=600,g=700,h=800,i=100,j=700,k=200,l=600,m=300,n=500;


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void draw_obj()
{ 	//x, y , width, lenth, color, radius
	
	           
	DrawRoundRect(a,b,0,0,colors[RED],40);  	
	DrawRoundRect(c,d,0,0,colors[RED],40);  
	DrawRoundRect(e,f,0,0,colors[LIME_GREEN],40);        
	
              
	           
	           
	DrawRoundRect(g,h,0,0,colors[RED],40);  	
	DrawRoundRect(i,j,0,0,colors[RED],40);  
	DrawRoundRect(k,l,0,0,colors[LIME_GREEN],40);        
	DrawRoundRect(m,n,0,0,colors[LIME_GREEN],40); 
	
	
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] );

	
	glutPostRedisplay();       
}


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void isCollision () {
//For detection of collision with obstacles
if (((abs(a-xI))<=40&&(abs(b-yI)<=40)) || ((abs(c-xI))<=40&&(abs(d-yI)<=40)) || ((abs(e-xI))<=40&&(abs(f-yI)<=40)) || ((abs(g-xI))<=40&&(abs(h-yI)<=40)) || ((abs(i-xI))<=40&&(abs(j-yI)<=40)) || ((abs(k-xI))<=40&&(abs(l-yI)<=40)) || ((abs(m-xI))<=40&&(abs(n-yI)<=40)) )
			{
			xI = 0;
			yI = 800;
		        score -= 1 ;
			}
			
//For detection of collision with passengers
if (((abs(pas1_x-xI))<=10&&(abs(pas1_y-yI)<=10)) || ((abs(pas2_x-xI))<=10&&(abs(pas2_y-yI)<=10)) || ((abs(pas3_x-xI))<=10&&(abs(pas3_y-yI)<=10)))
{
	if ( occupied == true )
	xI = 0;
	yI = 800;
	score -= 5;
}
//For detection of collision with moving cars 
if (((abs(x1I-xI))<=10&&(abs(y1I-yI)<=10)) || ((abs(x2I-xI))<=10&&(abs(y2I-yI)<=10)) || ((abs(x3I-xI))<=10&&(abs(y3I-yI)<=10)))
{
	xI = 0;
	yI = 800;
	score -=3;
}

glutPostRedisplay();

 

}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//Different colored taxi option is in main function.
void drawCar() {
		
	if (taxi_color == 'y' || taxi_color =='Y')
	{	
	DrawRoundRect(xI,yI,60,20,colors[YELLOW],10);
	DrawCircle(xI+9,yI,10,colors[BLACK]);
	DrawCircle(xI+50,yI,10,colors[BLACK]);
	}
	if (taxi_color == 'r' || taxi_color =='R')
	{
	DrawRoundRect(xI,yI,60,20,colors[RED],10);
	DrawCircle(xI+9,yI,10,colors[BLACK]);
	DrawCircle(xI+50,yI,10,colors[BLACK]);
	}
	glutPostRedisplay();
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// THESE FUNCTIONS WILL MOVE INITIAL 3 CARS ON THE BOARD 

bool flag=true;	
void moveCar1()
 	{  
 	if (((abs(a-xI))>=10&&(abs(b-yI)>=10)) || ((abs(c-xI))>=10&&(abs(d-yI)>=10)) || ((abs(e-xI))>=10&&(abs(f-yI)>=10)) || ((abs(g-xI))>=10&&(abs(h-yI)>=10)) || 		((abs(i-xI))>=10&&(abs(j-yI)>=10)) || ((abs(k-xI))>=10&&(abs(l-yI)>=10)) || ((abs(m-xI))>=10&&(abs(n-yI)>=10)) || ((abs(pas1_x-xI))>=10&&(abs(pas1_y-yI)>=10)) || ((abs(pas2_x-xI))>=10&&(abs(pas2_y-yI)>=10)) || ((abs(pas3_x-xI))>=10&&(abs(pas3_y-yI)>=10)))
{
		      
	if (y1I > 10 && flag) {
		y1I -= (10+counter);
		
		if(y1I < 100)
			
			flag = false;

	}
	else if (y1I < 800 && !flag) {
		
		y1I += (10+counter);
		if (y1I > 700)
			flag = true;
	}
}
}



bool flag2=true;	
 void moveCar2()
 {  
 	if (((abs(a-xI))>=10&&(abs(b-yI)>=10)) || ((abs(c-xI))>=10&&(abs(d-yI)>=10)) || ((abs(e-xI))>=10&&(abs(f-yI)>=10)) || ((abs(g-xI))>=10&&(abs(h-yI)>=10)) || 		((abs(i-xI))>=10&&(abs(j-yI)>=10)) || ((abs(k-xI))>=10&&(abs(l-yI)>=10)) || ((abs(m-xI))>=10&&(abs(n-yI)>=10)) || ((abs(pas1_x-xI))>=10&&(abs(pas1_y-yI)>=10)) || ((abs(pas2_x-xI))>=10&&(abs(pas2_y-yI)>=10)) || ((abs(pas3_x-xI))>=10&&(abs(pas3_y-yI)>=10)))
{
	
 	
	if (y2I > 10 && flag2) {
		y2I -= (10+counter);
		
		if(y2I < 100)
			
			flag2 = false;

	}
	else if (y2I < 800 && !flag2) {
		
		y2I += (10+counter);
		if (y2I > 700)
			flag2 = true;
	}
 
}
}
bool flag3=true;
void moveCar3()
 {   
 	if (((abs(a-xI))>=10&&(abs(b-yI)>=10)) || ((abs(c-xI))>=10&&(abs(d-yI)>=10)) || ((abs(e-xI))>=10&&(abs(f-yI)>=10)) || ((abs(g-xI))>=10&&(abs(h-yI)>=10)) || 		((abs(i-xI))>=10&&(abs(j-yI)>=10)) || ((abs(k-xI))>=10&&(abs(l-yI)>=10)) || ((abs(m-xI))>=10&&(abs(n-yI)>=10)) || ((abs(pas1_x-xI))>=10&&(abs(pas1_y-yI)>=10)) || ((abs(pas2_x-xI))>=10&&(abs(pas2_y-yI)>=10)) || ((abs(pas3_x-xI))>=10&&(abs(pas3_y-yI)>=10)))
{
	
	if (y3I > 10 && flag3) {
		y3I -= (10+counter);
		
		if(y3I < 100)
			
			flag3 = false;

	}
	else if (y3I < 800 && !flag3) {
		
		y3I += (10+counter);
		if (y3I > 700)
			flag3 = true;
	}
}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int xnI=140, ynI=150 ,xn2I=230, yn2I=150, xn3I=720, yn3I=350 , xn4I=635, yn4I=290 , xn5I=445, yn5I=700;

// THESE FUNCTIONS WILL ADD NEW CARS ON THE BOARD AFTER 2  PASSENGERS BEING PICKED

bool flager4=true;
void movecar4()
{ 	
 
 	
	if (ynI > 10 && flager4)
	 {
		ynI -= 10;
		
		if(ynI < 100)
			
			flager4= false;

	}
	else if (ynI < 1010 && !flager4)
	 {
		
		ynI += 10;
		if (ynI > 900)
			flager4 = true;
	}}
	
bool flager5=true;
void movecar5()
{
 	
 
 	
	if (yn2I > 10 && flager5)
	 {
		yn2I -= 10;
		
		if(yn2I < 100)
			
			flager5= false;

	}
	else if (yn2I < 1010 && !flager5)
	 {
		
		yn2I += 10;
		if (yn2I > 900)
			flager5 = true;
	}

}
bool flager6=true;	
void movecar6()
{
	
 
 	
	if (yn3I > 10 && flager6)
	 {
		yn3I -= 10;
		
		if(yn3I < 100)
			
			flager6= false;

	}
	else if (yn3I < 1010 && !flager6)
	 {
		
		yn3I += 10;
		if (yn3I > 900)
			flager6 = true;
	}
}		


bool flager7=true;	
void movecar7()
{
	
 
 	
	if (yn4I > 10 && flager7)
	 {
		yn4I -= 10;
		
		if(yn4I < 100)
			
			flager7= false;

	}
	else if (yn4I < 1010 && !flager7)
	 {
		
		yn4I += 10;
		if (yn4I > 900)
			flager7 = true;
	}
}	

bool flager8=true;	
void movecar8()
{
	
 
 	
	if (yn5I > 10 && flager8)
	 {
		yn5I -= 10;
		
		if(yn5I < 100)
			
			flager8= false;

	}
	else if (yn5I < 1010 && !flager8)
	 {
		
		yn5I += 10;
		if (yn5I > 900)
			flager8 = true;
	}
}	


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Over taking increases one score function
void Overtaking (){ 
		if((abs(x1I-xI)<=50) && (abs(y1I-yI)<=35)){
			score = score + 1;}
		
		if((abs(x2I-xI)<=50) && (abs(y2I-yI)<=35)){
			score = score + 1;}
		
		if((abs(x3I-xI)<=50) && (abs(y3I-yI)<=35)){
			score = score + 1;}
		
		if((abs(xnI-xI)<=50) && (abs(ynI-yI)<=35)){
			score = score + 1;}
		
		if((abs(xn2I-xI)<=50) && (abs(yn2I-yI)<=35)){
			score = score + 1;}
		
		if((abs(xn3I-xI)<=50) && (abs(yn3I-yI)<=35)){
			score = score + 1;}
		
		if((abs(xn4I-xI)<=50) && (abs(yn4I-yI)<=35)){
			score = score + 1;}
		
		if((abs(xn5I-xI)<=50) && (abs(yn5I-yI)<=35)){
			score = score + 1;}
		

		}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 

// THIS  FUNCTION WILL DISPLAY EVERYTHING ON BOARD


void GameDisplay(){

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors


	//DrawSquare(50, 50 , 50 , colors[BLACK]);	
	
	//Red Square
/*	DrawSquare(50, 700, 50 , colors[RED]);
	
	//Green Square
	DrawSquare( 60 , 750 , 50,colors[RED]); 
	
	//Display Score
	DrawString( 50, 800, "Score = 0", colors[BLUE]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] );*/


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 0   , 0 , 0   ,1000 , 2 , colors[BLACK] );
	DrawLine( 50  , 0 , 50  ,1000 , 2 , colors[BLACK] );	
	DrawLine( 100 , 0 , 100 ,1000 , 2 , colors[BLACK] );	
	DrawLine( 150 , 0 , 150 ,1000 , 2 , colors[BLACK] );	
	DrawLine( 200 , 0 , 200 ,1000 , 2 , colors[BLACK] );	
	DrawLine( 250 , 0 , 250 ,1000 , 2 , colors[BLACK] );	
	DrawLine( 300 , 0 , 300 ,1000 , 2 , colors[BLACK] );
	DrawLine( 350 , 0 , 350 ,1000 , 2 , colors[BLACK] );
	DrawLine( 400 , 0 , 400 ,1000 , 2 , colors[BLACK] );
	DrawLine( 450 , 0 , 450 ,1000 , 2 , colors[BLACK] );
	DrawLine( 500 , 0 , 500 ,1000 , 2 , colors[BLACK] );
	DrawLine( 550 , 0 , 550 ,1000 , 2 , colors[BLACK] );
	DrawLine( 600 , 0 , 600 ,1000 , 2 , colors[BLACK] );
	DrawLine( 650 , 0 , 650 ,1000 , 2 , colors[BLACK] );
	DrawLine( 700 , 0 , 700 ,1000 , 2 , colors[BLACK] );
	DrawLine( 750 , 0 , 750 ,1000 , 2 , colors[BLACK] );
	DrawLine( 800 , 0 , 800 ,1000 , 2 , colors[BLACK] );
	DrawLine( 850 , 0 , 850 ,1000 , 2 , colors[BLACK] );
	DrawLine( 900 , 0 , 900 ,1000 , 2 , colors[BLACK] );
	DrawLine( 950 , 0 , 950 ,1000 , 2 , colors[BLACK] );
	DrawLine( 1000, 0 , 1000,1000 , 2 , colors[BLACK] );
	
	/*DrawCircle(50,670,10,colors[RED]);
	DrawCircle(70,670,10,colors[RED]);
	DrawCircle(90,670,10,colors[RED]);
	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);*/
	
	drawCar();
	draw_obj(); 

	//**************DESTINATION************************
	DrawCircle( final_X , final_Y , 50 ,colors[GREEN]);
	

	//************PASSENGERS*********************************
	DrawRoundRect(pas1_x , pas1_y , 5, 30 , colors[BLACK] , 0);
	DrawCircle(pas1_x + 2.5 , pas1_y +30 , 15 , colors[BLACK]);

	DrawRoundRect(pas2_x , pas2_y , 5, 30 , colors[BLACK] , 0);
	DrawCircle(pas2_x + 2.5 , pas2_y +30 , 15 , colors[BLACK]);

	DrawRoundRect(pas3_x , pas3_y , 5, 30 , colors[BLACK] , 0);
	DrawCircle(pas3_x + 2.5 , pas3_y +30 , 15 , colors[BLACK]);

	//**********MOVING CARS***********************
	DrawRoundRect(x1I,y1I,60,20,colors[BLUE],10);
	DrawCircle(x1I+9,y1I,10,colors[BLACK]);
	DrawCircle(x1I+50,y1I,10,colors[BLACK]);
	DrawRoundRect(x2I,y2I,60,20,colors[BLUE],10);
	DrawCircle(x2I+9,y2I,10,colors[BLACK]);
	DrawCircle(x2I+50,y2I,10,colors[BLACK]);
	DrawRoundRect(x3I,y3I,60,20,colors[BLUE],10);
	DrawCircle(x3I+9,y3I,10,colors[BLACK]);
	DrawCircle(x3I+50,y3I,10,colors[BLACK]);
	
	//************************SCORE**********************************	
	DrawString( 50, 800, "Score = " + to_string(score) , colors[BLUE]); 
	DrawString( 500 ,800 ,"Time = ", colors[BLUE]);
	DrawString( 600 ,800 ,to_string(timer), colors[BLUE]);
	

	//********************CARS WILL INCREASE AFTER PASSENGERS BEING DROPPED*************************
	if(counter>=2)
	{ 
	DrawRoundRect(xnI,ynI,60,20,colors[BLUE],10);
	DrawCircle(xnI+9,ynI,10,colors[BLACK]);
	DrawCircle(xnI+50,ynI,10,colors[BLACK]);
	}
	if(counter>=4)
	{ 
	DrawRoundRect(xn2I,yn2I,60,20,colors[BLUE],10);
	DrawCircle(xn2I+9,yn2I,10,colors[BLACK]);
	DrawCircle(xn2I+50,yn2I,10,colors[BLACK]);
	}
	if(counter>=6)
	{ 
	DrawRoundRect(xn3I,yn3I,60,20,colors[BLUE],10);
	DrawCircle(xn3I+9,yn3I,10,colors[BLACK]);
	DrawCircle(xn3I+50,yn3I,10,colors[BLACK]);
	}
	if(counter>=8)
	{
	DrawRoundRect(xn4I,yn4I,60,20,colors[BLUE],10);
	DrawCircle(xn4I+9,yn4I,10,colors[BLACK]);
	DrawCircle(xn4I+50,yn4I,10,colors[BLACK]);
	}
	if(counter>=10)
	{ 
	DrawRoundRect(xn5I,yn5I,60,20,colors[BLUE],10);
	DrawCircle(xn5I+9,yn5I,10,colors[BLACK]);
	DrawCircle(xn5I+50,yn5I,10,colors[BLACK]);
	}

	
	glutSwapBuffers(); // do not modify this line..



}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void DestinationReached() {
	
		if ((abs(final_X-xI)<=50) && (abs(final_Y-yI)<=50)) 
		{       score += 10 ;
			occupied = false;
			final_X = -1 ;
			final_Y = -1;
			cout <<"PASSENGER DROPPED";
			counter ++;
		}


	
glutPostRedisplay();
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

const int red_speed = 5, yellow_speed =10;

void NonPrintableKeys(int key, int x, int y) {
	// AS YELLOW TAXI MOVES FASTER

	if(taxi_color == 'y' || taxi_color == 'Y'){	
	if (key == GLUT_KEY_LEFT ) {
		if (counter>=2)
		{xI -= 2*yellow_speed;}
		else
		{xI -= 1*yellow_speed;}
		 
		

	} else if (key
			== GLUT_KEY_RIGHT ) {
		if (counter>=2)
		{ xI += 2*yellow_speed;}
		else
		{xI += 1*yellow_speed;}
		 
	} else if (key
			== GLUT_KEY_UP) {
		if (counter>=2)
		{ yI += 2*yellow_speed;}
		else
		{yI += 1*yellow_speed;}
		 
	}

	else if (key
			== GLUT_KEY_DOWN){
		if(counter>=2)
		{ yI -= 2*yellow_speed;}
		else
		{yI -= 1*yellow_speed;}
		 
	}
	
}		
						


	// AS RED TAXI MOVES SLOWER

	if(taxi_color == 'r' || taxi_color == 'R'){	
	if (key
			== GLUT_KEY_LEFT ) {
		if (counter>=2)
		{ xI -= 2*red_speed;}
		else
		{xI -= 1*red_speed;}
		 		
                

	} else if (key
			== GLUT_KEY_RIGHT ) {
		if (counter>=2)
		{ xI += 2*red_speed;}
		else
		{xI += 1*red_speed;}
		 		
	} else if (key
			== GLUT_KEY_UP) {
		if (counter>=2)
		{ yI += 2*red_speed;}
		else
		{yI += 1*red_speed;}
		 		
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if (counter>=2)
		{ yI -= 2*red_speed;}
		else
		{yI -= 1*red_speed;}
			
	}
}


	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();



}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//This Function will pick the passenger when car reaches the coordinates of it 


void PassengerFunc() {

	
	if((abs(pas1_x-xI)<=40) && (abs(pas1_y-yI)<=40) && (occupied == false ))
	{	
		 	
		DrawSquare( pas1_x , pas1_y , 20 ,colors[WHITE]);
		cout<<"PASSENGER PICKED "<< endl;
		occupied = true;
		final_X = rand() % width ;
		final_Y = rand() % height ;
		if((abs(pas1_x-final_X)<=40) && (abs(pas1_y-final_Y)<=40)){
		final_X = rand() % width ;
		final_Y = rand() % height ;
		}

		pas1_x = rand() % width;
		pas1_y = rand() % height; 
	}

	if((abs(pas2_x-xI)<=40) && (abs(pas2_y-yI)<=40) && (occupied == false ))
	{   	
	DrawSquare( pas2_x , pas2_y , 20 ,colors[WHITE]);
	cout<<"PASSENGER PICKED "<< endl;
	occupied = true;
	final_X = rand() % width ;
	final_Y = rand() % height ;
	if((abs(pas2_x-final_X)<=40) && (abs(pas2_y-final_Y)<=40)){
		final_X = rand() % width ;
		final_Y = rand() % height ;
		}
	pas2_x = rand() % width;
	pas2_y = rand() % height;
	}
	if((abs(pas3_x-xI)<=40) && (abs(pas3_y-yI)<=40) && (occupied == false ))
	{   DrawSquare( pas3_x , pas3_y , 20 ,colors[WHITE]);
	    cout<<"PASSENGER PICKED "<< endl;
	    occupied = true;
            final_X = rand() % width ;
	    final_Y = rand() % height ;
	    if((abs(pas3_x-final_X)<=40) && (abs(pas3_y-final_Y)<=40)){
		final_X = rand() % width ;
		final_Y = rand() % height ;
		}	    
	    pas3_x = rand() % width;
	    pas3_y = rand() % height;

	}



glutPostRedisplay();
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	//If r is pressed all the obstacles are randomized and score is again 0 further.
	if (key == 'r' || key == 'R') 
			{
		a = rand() % height;
		b = rand() % width;
		c = rand() % height;
		d = rand() % width;
		e = rand() % height;
		f = rand() % width;
		g = rand() % height;	
		h = rand() % width;
		i = rand() % height;	
		j= rand() % width;
		k= rand() % height;
		l= rand() % width;
		m= rand() % height;	
		n = rand() % width;
		
		cout << "RANDOMIZED AND RESTARTED" << endl;
		init = true ; //New obstacles 
		score = 0 ;

		counter = 0;
		xI = 0 , yI = 800;
	}

        //If space is pressed passenger is picked && passenger is dropped as well

	if ( key == 32 ) {
	PassengerFunc();
	DestinationReached();
	
}

	glutPostRedisplay();
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*void obstacleFunc() {

		for (int i=0 ; i < 7 ; i++)
			x_blockage[i] = rand() % width ;
		for (int i=0 ; i < 7 	; i++)
			y_blockage[i] = rand() % height ;
		for (int i=0 ; i < 7 ; i++)
			for ( int j =0 ; j < 7 ; j ++ )
		{
		DrawSquare( x_blockage[i], y_blockage[j] , 20 , colors[DARK_SLATE_BLUE]);
		cout << x_blockage[i] << y_blockage[j] ;
		}

		
glutPostRedisplay();
}
*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



void Timer(int m) {

	// implement your functionality here
	moveCar1();
	moveCar2();
	moveCar3();	
	//PassengerFunc();
	isCollision ();

	timer_1++;
	if ( timer_1%10 == 0)
	timer++;
	if ( timer == 180 )
	exit(1);
	
	
	draw_obj();

	if(counter>=2)
	movecar4();
	if(counter>=4)
	movecar5();
	if(counter>=6)
	movecar6();
	if(counter>=8)
	movecar7();
	if(counter>=10)
	movecar8();
	
	
	Overtaking();
	
	//DestinationReached();
	
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	pas1_x  = rand() % width ;
	pas1_y  = rand() % height ;

	pas2_x = rand() % width;
	pas2_y = rand() % height;

	pas3_x = rand() % width;
	pas3_y = rand() % height;

	cout <<"\nWhich taxi you want to play with i.e (red or yellow)" << endl
	     <<"Press 'r' for red  OR 'y' for yellow : " ;

	cin  >> taxi_color;
	
	
	

	



	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50 , 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Hassan Saeed"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	//glutTimerFunc(1000.0 , DestinationReached , 0);
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	


	return 1;
}
#endif /* RushHour_CPP_ */
