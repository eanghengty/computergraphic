#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int gl_shape[1]={GL_POINTS};
int show = 0;
float graph_color[3] = {1.0,1.0,1.0};
int jan_exp;
int feb_exp;
int mar_exp;
int apr_exp;
int may_exp;
int jun_exp;
int jul_exp;
int aug_exp;
int sep_exp;
int oct_exp;
int nov_exp;
int dec_exp;

int j = 1;
int i = 1;
char singleLine[200];
char janurary[10];
char february[10];
char march[10];
char april[10];
char may[10];
char june[10];
char july[10];
char august[10];
char september[10];
char october[10];
char november[10];
char december[10];

char jan_title[10];
char feb_title[10];
char mar_title[10];
char apr_title[10];
char may_title[10];
char jun_title[10];
char jul_title[10];
char aug_title[10];
char sep_title[10];
char oct_title[10];
char nov_title[10];
char dec_title[10];
int choice = 3;

void read_file() {

  FILE *fPointer;
  fPointer = fopen("lab5_expenses.txt", "r");
  FILE *fPointer2;
  fPointer2 = fopen("lab5_month_title.txt", "r");

  while (fgets(singleLine, 200, fPointer)) {
    switch (j) {
    case 1:
      strcpy(janurary, singleLine);
      break;
    case 2:
      strcpy(february, singleLine);
      break;
    case 3:
      strcpy(march, singleLine);
      break;
    case 4:
      strcpy(april, singleLine);
      break;
    case 5:
      strcpy(may, singleLine);
      break;
    case 6:
      strcpy(june, singleLine);
      break;
    case 7:
      strcpy(july, singleLine);
      break;
    case 8:
      strcpy(august, singleLine);
      break;
    case 9:
      strcpy(september, singleLine);
      break;
    case 10:
      strcpy(october, singleLine);
      break;
    case 11:
      strcpy(november, singleLine);
      break;
    case 12:
      strcpy(december, singleLine);
      break;
    }

    j++;
  }

  while (fgets(singleLine, 200, fPointer2)) {
    switch (i) {
    case 1:
      strcpy(jan_title, singleLine);
      break;
    case 2:
      strcpy(feb_title, singleLine);
      break;
    case 3:
      strcpy(mar_title, singleLine);
      break;
    case 4:
      strcpy(apr_title, singleLine);
      break;
    case 5:
      strcpy(may_title, singleLine);
      break;
    case 6:
      strcpy(jun_title, singleLine);
      break;
    case 7:
      strcpy(jul_title, singleLine);
      break;
    case 8:
      strcpy(aug_title, singleLine);
      break;
    case 9:
      strcpy(sep_title, singleLine);
      break;
    case 10:
      strcpy(oct_title, singleLine);
      break;
    case 11:
      strcpy(nov_title, singleLine);
      break;
    case 12:
      strcpy(dec_title, singleLine);
      break;
    }

    i++;
  }
  jan_exp = atoi(janurary);
  feb_exp = atoi(february);
  mar_exp = atoi(march);
  apr_exp = atoi(april);
  may_exp = atoi(may);
  jun_exp = atoi(june);
  jul_exp = atoi(july);
  aug_exp = atoi(august);
  sep_exp = atoi(september);
  oct_exp = atoi(october);
  nov_exp = atoi(november);
  dec_exp = atoi(december);
}

void select_menu(int menuId) {
  if(menuId == 1){
    gl_shape[0] = GL_POINTS;
    show = 0;
  }
  else if(menuId == 2){
    gl_shape[0] = GL_LINE_STRIP;
    show = 0;
  }else if(menuId == 9){
    show = 1;
  }
  if(menuId == 3){
    choice = 3;
  }
  else if(menuId == 4){
    choice = 4;
  }
  if( menuId == 7){
    graph_color[0] = 0.0;
    graph_color[1] = 1.0;
    graph_color[2] = 0.0;
  }
  else if(menuId == 6){
    graph_color[0] =0.0;
    graph_color[1] = 0.0;
    graph_color[2] = 1.0;

  }
  else if(menuId == 5){
    graph_color[0] = 1.0;
    graph_color[1] = 0.0;
    graph_color[2] = 1.0;
  }
  else if(menuId == 8){
    graph_color[0] = 1.0;
    graph_color[1] = 1.0;
    graph_color[2]=1.0;
  }
}
void create_menu() {
  int menu;
  int toggle_menu;
  int sub_menu;
  int toggle_sub_menu;
  int color_menu;
  int color_sub_menu;
  color_sub_menu = glutCreateMenu(select_menu);
  glutAddMenuEntry("Purple color",5);
  glutAddMenuEntry("Blue color",6);
  glutAddMenuEntry("Green color",7);
  glutAddMenuEntry("White color",8);

  toggle_sub_menu = glutCreateMenu(select_menu);
  glutAddMenuEntry("Label off", 3);
  glutAddMenuEntry("Label on", 4);
  sub_menu = glutCreateMenu(select_menu);
  glutAddMenuEntry("Plot Points", 1);
  glutAddMenuEntry("Plot Lines",2);
  glutAddMenuEntry("Plot Barchart",9);
  
  menu = glutCreateMenu(select_menu);
  glutAddSubMenu("Change charts", sub_menu);
  glutAddSubMenu("Toggle label", toggle_sub_menu);
  glutAddSubMenu("Color setting", color_sub_menu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display_function() {
  
  
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,1.0,1.0);
  
  for(float i=1;i<=12;i++){
    char num12[] = "2000";
    char num11[]="1850";
     char num10[]="1700";
     char num9[]="1550";
     char num8[]="1400";
     char num7[]="1250";
     char num6[]="1100";
     char num5[]="950";
     char num4[]="800";
     char num3[]="650";
     char num2[]="500";
     char num1[]="350";
     
        
        glRasterPos2f(100, 200 + (150 * i)  );
        if(i ==12){
        for(int i=0; i < strlen(num12);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num12[i]);
          }
        }
        if(i == 11)
        for(int i=0 ; i < strlen(num11);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num11[i]);
        }
        if(i == 10)
        for(int i=0 ; i < strlen(num10);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num10[i]);
        }
        if(i == 9)
        for(int i=0 ; i < strlen(num9);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num9[i]);
        }
        if(i == 8)
        for(int i=0 ; i < strlen(num8);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num8[i]);
        }
        if(i == 7)
        for(int i=0 ; i < strlen(num7);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num7[i]);
        }
        if(i == 6)
        for(int i=0 ; i < strlen(num6);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num6[i]);
        }
        if(i == 5)
        for(int i=0 ; i < strlen(num5);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num5[i]);
        }
        if(i == 4)
        for(int i=0 ; i < strlen(num4);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num4[i]);
        }
        if(i == 3)
        for(int i=0 ; i < strlen(num3);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num3[i]);
        }
        if(i == 2)
        for(int i=0 ; i < strlen(num2);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num2[i]);
        }
        if(i == 1)
        for(int i=0 ; i < strlen(num1);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num1[i]);
        }
        
    }

     for(float i=1;i<=12;i++){
   
         
        glRasterPos2f(150 + (150 * i), 100 );
        if(i ==1){
        for(int i=0; i < strlen(jan_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, jan_title[i]);
          }
        }
        if(i == 2)
        for(int i=0 ; i < strlen(feb_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, feb_title[i]);
        }
        if(i == 3)
        for(int i=0 ; i < strlen(mar_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, mar_title[i]);
        }
        if(i == 4)
        for(int i=0 ; i < strlen(mar_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, apr_title[i]);
        }
        if(i == 5)
        for(int i=0 ; i < strlen(apr_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, may_title[i]);
        }
        if(i == 6)
        for(int i=0 ; i < strlen(jun_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, jun_title[i]);
        }
        if(i == 7)
        for(int i=0 ; i < strlen(jul_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, jul_title[i]);
        }
        if(i == 8)
        for(int i=0 ; i < strlen(aug_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, aug_title[i]);
        }
        if(i == 9)
        for(int i=0 ; i < strlen(sep_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, sep_title[i]);
        }
        if(i == 10)
        for(int i=0 ; i < strlen(oct_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, oct_title[i]);
        }
        if(i == 11)
        for(int i=0 ; i < strlen(nov_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, nov_title[i]);
        }
        if(i == 12)
        for(int i=0 ; i < strlen(dec_title);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, dec_title[i]);
        }
        
    }

     for(int i=1;i<=12;i++){
        int point;
        switch(i){
          case 1:
            point = jan_exp;
            break;
          case 2:
            point = feb_exp;
            break;
          case 3:
            point = mar_exp;
            break;
          case 4:
            point = apr_exp;
            break;
          case 5:
            point = may_exp;
            break;
          case 6:
            point = jun_exp;
            break;
          case 7:
            point = jul_exp;
            break;
          case 8:
            point = aug_exp;
            break;
          case 9:
            point = sep_exp;
            break;
          case 10:
            point = oct_exp;
            break;
          case 11:
            point = nov_exp;
            break;
          case 12:
            point = dec_exp;
            break;
        }
         
        glRasterPos2f(180 + (150 * i), point + 100 );
        if(i ==1){
        for(int i=0; i < strlen(janurary);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, janurary[i]);
          }
        }
        if(i == 2)
        for(int i=0 ; i < strlen(february);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, february[i]);
        }
        if(i == 3)
        for(int i=0 ; i < strlen(march);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, march[i]);
        }
        if(i == 4)
        for(int i=0 ; i < strlen(april);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, april[i]);
        }
        if(i == 5)
        for(int i=0 ; i < strlen(may);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, may[i]);
        }
        if(i == 6)
        for(int i=0 ; i < strlen(june);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, june[i]);
        }
        if(i == 7)
        for(int i=0 ; i < strlen(july);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, july[i]);
        }
        if(i == 8)
        for(int i=0 ; i < strlen(august);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, august[i]);
        }
        if(i == 9)
        for(int i=0 ; i < strlen(september);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, september[i]);
        }
        if(i == 10)
        for(int i=0 ; i < strlen(october);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, october[i]);
        }
        if(i == 11)
        for(int i=0 ; i < strlen(november);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, november[i]);
        }
        if(i == 12)
        for(int i=0 ; i < strlen(december);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, december[i]);
        }
        
    }
  
  if(choice == 4){
    char y_label[] = "Monthly - Expenses";
   char x_label[] = "Month";
   glRasterPos2f(200, 2600);
   for(int i = 0 ; i < strlen(y_label); i++){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, y_label[i]);

   
  } 
   glRasterPos2f(2600, 200);
    for(int i=0; i <strlen(x_label);i++){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, x_label[i]);
    }
  }
  glBegin(GL_LINES);
  for(int i = 350 ; i <= 2150; i = i + 150){
    glVertex2f(190 , i);
    glVertex2f(210, i);
  }
  glEnd();
  glBegin(GL_LINES);
  for(int i = 350 ; i <= 2150; i = i + 150){
    glVertex2f(i , 190);
    glVertex2f(i, 210);
  }
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(200, 200);
  glVertex2f(2500, 200);
  glVertex2f(2480, 190);
  glVertex2f(2500, 200);
  glVertex2f(2480, 210);
  glVertex2f(2500, 200);
  glVertex2f(200, 200);
  glVertex2f(200, 2500);
  glVertex2f(190, 2480);
  glVertex2f(200, 2500);
  glVertex2f(200, 2500);
  glVertex2f(210, 2480);

  glEnd();
  glColor3f(graph_color[0],graph_color[1],graph_color[2]);
  if(show == 0){
  glBegin(gl_shape[0]);
  glVertex2f(350, jan_exp);
  glVertex2f(500, feb_exp);
  glVertex2f(650,mar_exp);
  glVertex2f(800,apr_exp);
  glVertex2f(950,may_exp);
  glVertex2f(1100,jun_exp);
  glVertex2f(1250,jul_exp);
  glVertex2f(1400,aug_exp);
  glVertex2f(1550,sep_exp);
  glVertex2f(1700,oct_exp);
  glVertex2f(1850,nov_exp);
  glVertex2f(2000,dec_exp);

  glEnd();
  }
  else if(show == 1){
    glBegin(GL_LINES);
  glVertex2f(300, 200);
  glVertex2f(300, jan_exp);
  glVertex2f(400, 200);
  glVertex2f(400, jan_exp);
  glVertex2f(300, jan_exp);
  glVertex2f(400, jan_exp);

  glVertex2f(450, 200);
  glVertex2f(450, feb_exp);
  glVertex2f(550,200);
  glVertex2f(550,feb_exp);
  glVertex2f(450,feb_exp);
  glVertex2f(550,feb_exp);

  glVertex2f(750,200);
  glVertex2f(750,apr_exp);
  glVertex2f(850,200);
  glVertex2f(850,apr_exp);
  glVertex2f(750,apr_exp);
  glVertex2f(850,apr_exp);

  glVertex2f(600,200);
  glVertex2f(600,mar_exp);
  glVertex2f(700,200);
  glVertex2f(700,mar_exp);
  glVertex2f(600,mar_exp);
  glVertex2f(700,mar_exp);

  glVertex2f(900,200);
  glVertex2f(900,may_exp);
  glVertex2f(1000,200);
  glVertex2f(1000,may_exp);
  glVertex2f(900,may_exp);
  glVertex2f(1000,may_exp);

  glVertex2f(1050,200);
  glVertex2f(1050,jun_exp);
  glVertex2f(1150,200);
  glVertex2f(1150,jun_exp);
  glVertex2f(1050,jun_exp);
  glVertex2f(1150,jun_exp);

  glVertex2f(1200,200);
  glVertex2f(1200,jul_exp);
  glVertex2f(1300,200);
  glVertex2f(1300,jul_exp);
  glVertex2f(1200,jul_exp);
  glVertex2f(1300,jul_exp);

  glVertex2f(1350,200);
  glVertex2f(1350,aug_exp);
  glVertex2f(1450,200);
  glVertex2f(1450,aug_exp);
  glVertex2f(1350,aug_exp);
  glVertex2f(1450,aug_exp);

  glVertex2f(1500,200);
  glVertex2f(1500,sep_exp);
  glVertex2f(1600,200);
  glVertex2f(1600,sep_exp);
  glVertex2f(1500,sep_exp);
  glVertex2f(1600,sep_exp);

  glVertex2f(1650,200);
  glVertex2f(1650,oct_exp);
  glVertex2f(1750,200);
  glVertex2f(1750,oct_exp);
  glVertex2f(1650,oct_exp);
  glVertex2f(1750,oct_exp);

  glVertex2f(1800,200);
  glVertex2f(1800,nov_exp);
  glVertex2f(1900,200);
  glVertex2f(1900,nov_exp);
  glVertex2f(1800,nov_exp);
  glVertex2f(1900,nov_exp);

  glVertex2f(1950,200);
  glVertex2f(1950,dec_exp);
  glVertex2f(2050,200);
  glVertex2f(2050,dec_exp);
  glVertex2f(1950,dec_exp);
  glVertex2f(2050,dec_exp);


  glEnd();
  }
  

  
  
  glFlush();
  
  glutPostRedisplay();
  
}
void init_function() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 4050.0, 0.0, 4050.0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(1350, 1350);
  glutCreateWindow("Lab4 plot the expenses");
  init_function();
  read_file();  
  create_menu();
  glutDisplayFunc(display_function);
  
  glutMainLoop();

  return 0;
}
