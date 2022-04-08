#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
float color[3] = {1.0,1.0,1.0};
void selectAxisColor(int);

void createMenu(){
  int submenu;
  int menu;

  //create submenu
  submenu = glutCreateMenu(selectAxisColor);
  glutAddMenuEntry("Blue", 1);
  glutAddMenuEntry("Red", 2);
  glutAddMenuEntry("Yellow", 3);

  // create menu
  menu = glutCreateMenu(selectAxisColor);
  // add submenu to menu
  glutAddSubMenu("Axis Color", submenu);

  // attach menu to mouse's right button
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void selectAxisColor(int menuId){
   printf("User choose menu %d", menuId);
   //   		color[0] = 0.5;
   //		color[1] = 1.0;
   //		color[2] = 0.0;

}

void display(void)
{

	// clear background of current window
	glClear(GL_COLOR_BUFFER_BIT);
	// draw a filled polygon
    glBegin(GL_POINTS);
        glColor3f(color[0],color[1],color[2]);
        glVertex2d(0,0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2d(150, 0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2d(0, 150);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2d(150, 150);
 
    glEnd();
    glFlush();
    glutPostRedisplay();
}
void init(void)
{
    glPointSize(5);
	//Clear background color to white
	glClearColor (1.0, 1.0, 1.0, 0.0);

	//change projection mode
	glMatrixMode(GL_PROJECTION);

	//set current matrix to identiy matrix
	glLoadIdentity();
	gluOrtho2D(0, 150.0, 0, 150.0);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Simple Drawing");
	init();
	createMenu();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
