#include<stdio.h>
#include<GL/glut.h>
void display(){
   
    glClear(GL_COLOR_BUFFER_BIT);
   
    glBegin(GL_LINES);
    
    glVertex2f(0.2,0.1);
    glVertex2f(0.5,0.1);
    glEnd();
    glFlush();
}
int main(int argc , char** argv){
    glutInit(&argc , argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
     glutCreateWindow("lab1");
    
    // glClearColor (1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,3.0,0.0,3.0);
   
    glutDisplayFunc(display);
    glutMainLoop();
}

// #include <GL/glut.h>
// #include <stdio.h>
// void display(void)
// {
//  // clear background of current window
//  glClear(GL_COLOR_BUFFER_BIT);
//  // draw a filled polygon
//  glBegin(GL_POLYGON);

//  glVertex2i(75,85);
//  glVertex2i(20,40);
//  glVertex2i(130,40);
//  glEnd();
//  glFlush ();
// }
// void init(void)
// {


//  glClearColor (1.0, 1.0, 1.0, 0.0);
 
//  glMatrixMode(GL_PROJECTION);

//  glLoadIdentity();
//  gluOrtho2D(0, 150.0, 0, 150.0);
// }
// int main(int argc, char** argv)
// {
//  glutInit(&argc, argv);

//  glutInitWindowSize (500,500);
//  glutInitWindowPosition (100, 100);
//  glutCreateWindow ("Simple Drawing");
//  init();
//  glutDisplayFunc(display);
//  glutMainLoop();
// return 0;
// }
