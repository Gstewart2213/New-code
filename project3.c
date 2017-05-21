#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>



#define DELAY 30000;


int main(int argc, char *argv[]) {
 int x = 0, y = 0;								// sets x and y coordinates
 int row, col;
 int max_y = 0, max_x = 0;						// gives a max x and y
 int next_x = 0;	
 int next_y = 0;
 int x_direction = 1;
 int y_direction = 1;
 int fig_direction =1;
 int new_figdir = 0;
 int fig_x , fig_y = 1;
 int c = getch();
 int cycles = 1;
 int score;
 int target;
 
initscr(); 
keypad(stdscr,TRUE); //enables use of the keyboard in the main screen
noecho();
curs_set(FALSE);
cbreak();	
nodelay(stdscr, TRUE); 

getmaxyx(stdscr, max_y, max_x); // gets the max x and y values for the 'centipede'


 while(1) {
	clear();
	mvprintw(y, x, "o");
	mvprintw(max_y - 1 , fig_direction , "W");     //sets the figure to its original positon
	mvprintw( 10 , 7 , "your score is: %d", score);
	

		c = getch();
	switch((c)){				// lets various keys be used in order for movement of the 'shooter'

		case KEY_LEFT:
			fig_direction <= max_x-1;
			fig_direction = fig_direction -1;
		break;
		
	case KEY_RIGHT:
			fig_direction = fig_direction + 1, fig_direction <= max_x - 1;
		break;
		
	case KEY_UP:
		if (fig_direction == next_x)
		{ 
			score = score++;
		}
		break;
		
		
	}
 

 refresh();
 


	usleep(1);
			new_figdir = fig_x + fig_direction;
			next_x = x + x_direction;
			next_y = y + y_direction;
 
 
	
	usleep(30000);
		if (next_x >= max_x || next_x < 0) {
			x_direction*= -1;
			y = next_y;
			} 
		
		else {
				x+= x_direction;
			 }
	}
endwin();
}

