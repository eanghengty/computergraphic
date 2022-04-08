#include <stdio.h>
#include <GL/freeglut.h>
#include <string.h>
#include <math.h>
char label[] = "input the parameter by using key I";
char label2[] = "input q to quit the window";
char label3[] = "input d to display the result in terminal";
char label4[] = "display only shown when the window quit.";
float xaxis1;
float xaxis2;
float yaxis1;
float yaxis2;
int menuchoice = 0;
float deltax;
float deltay;
float slopem;
float step;
float xincrement;
float yincrement;
float color[3] = {1.0,1.0,1.0}; 


void printresult(){
    printf("result x1,y1,x2,y2 : %f, %f, %f, %f",xaxis1,yaxis1,xaxis2,yaxis2);
}


void keyboard(unsigned char key , int x, int y){
    if(key == 'i'){
        printf("please input the parameter respectively\n");
        for(int i  = 1 ; i <=2 ;i++){
            
            if(i==1){
                printf("input x%d :",i);
                scanf("%f",&xaxis1);
                printf("input y%d :",i);
                scanf("%f",&yaxis1);

            }else if(i==2){
                printf("input x%d :",i);
                scanf("%f",&xaxis2);
                printf("input y%d :",i);
                scanf("%f",&yaxis2);
                break;
            }
            
        }
    }
    else if(key  == 'd'){
        printresult();
    }
    else if (key == 'q'){
        exit(0);
    }
}


void lineselection(int menuid){
    if(menuid == 1){
        menuchoice = 1;
    }else if(menuid ==2){
        menuchoice=2;
    }
    else if(menuid==3){
        color[0]=0.0;
        color[1]=0.0;
        color[2]=1.0;
    }else if(menuid==4){
        color[0]=0.0;
        color[1]=1.0;
        color[2]=0.0;
    }
}

void menu(){
    int menu;
    int submenu;
    int submenu2;
    
    submenu=glutCreateMenu(lineselection);
    glutAddMenuEntry("DDA LINE",1);
    glutAddMenuEntry("MIDPOINT LINE",2);
    submenu2=glutCreateMenu(lineselection);
    glutAddMenuEntry("Blue",3);
    glutAddMenuEntry("green",4);
    menu=glutCreateMenu(lineselection);
    glutAddSubMenu("LINE SELECTION",submenu);
    glutAddSubMenu("COLOR SELECTION",submenu2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void displaylabel(){
    glRasterPos2f(10,20);
    for(int i = 0 ; i < strlen(label) ; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,label[i]);
    }
    glRasterPos2f(10,18);
    for(int i = 0 ; i < strlen(label2) ; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,label2[i]);
    }
    glRasterPos2f(10,16);
    for(int i = 0 ; i < strlen(label3) ; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,label3[i]);
    }
    glRasterPos2f(10,14);
    for(int i = 0 ; i < strlen(label4) ; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,label4[i]);
    }
}

void ddaline(){
    deltax = xaxis2-xaxis1;
    deltay = yaxis2-yaxis1;
    slopem = deltay/deltax;
    step= deltax;
    if(step == 0){
        step = deltay;
    }
    xincrement = round(deltax/step);
    yincrement = round(deltay/step);

    
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_LINE_STRIP);
    glVertex2f(xaxis1,yaxis1);
    glVertex2f(xaxis2,yaxis2);
    for(int i = xaxis1 ; i < xaxis2 ; i++){
        glVertex2f(xaxis2 + xincrement, yaxis2+yincrement);
    }

    
    glEnd();
}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    if(menuchoice == 0){
        displaylabel();
    }else if(menuchoice ==1){
        ddaline();
    }
    glFlush();
    glutPostRedisplay();


}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,50.0,0,50.0);
}

int main( int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("lab7 line");
     init();
     menu();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();

    return 0;
}