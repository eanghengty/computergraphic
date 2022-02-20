#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define maxSize 480.0
#define minSize 20.0
#define radius 20.0
void display(){
    float half = (maxSize-20)/(minSize*2.0);
    float mid = (maxSize/2.0)+ 10.0;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(minSize,mid);
    glVertex2f(maxSize,mid);
    glVertex2f(mid,maxSize);
    glVertex2f(mid,minSize);
    for(float i= half ; i > 1.0  ; i--){
        glVertex2f(minSize*i,255.0);
        glVertex2f(minSize*i,245.0);
    }
    for(float i=1.0 ; i < half  ; i++){
        glVertex2f(mid + (20.0*i),255.0);
        glVertex2f(mid + (20.0*i),245.0);
    }
    for(float i=half; i > 1.0  ; i--){
        glVertex2f(245.0,20.0*i);
        glVertex2f(255.0,20.0*i);
    }
    for(float i=1.0; i < half  ; i++){
        glVertex2f(245.0,mid+(20.0*i));
        glVertex2f(255.0,mid+(20.0*i));
    }
    
    //arrow y
    glVertex2f(240.0,470.0);
    glVertex2f(mid,maxSize);
    glVertex2f(mid,maxSize);
    glVertex2f(260.0,470.0);
    //arrow x
    glVertex2f(470.0,240.0);
    glVertex2f(maxSize,mid);
    glVertex2f(maxSize,mid);
    glVertex2f(470.0,260.0);
    glEnd();
    //second Q
    glBegin(GL_LINE_STRIP);
    for(float i=1.0 ; i<360.0 ; i++){
        float angle = (i*3.14)/180;
        glVertex2f(90 + 40.0*cos(angle),350 +  40.0 * sin(angle));
        
    }
    glEnd();
    //First Q
    glBegin(GL_LINE_STRIP);
    for(float i=1.0 ; i<360.0 ; i++){
        float angle = (i*3.14)/180;
        glVertex2f(410 + 40.0*cos(angle),350 +  40.0 * sin(angle));
        
    }
    glEnd();
    //fourth Q
    glBegin(GL_LINE_STRIP);
    for(float i=1.0 ; i<360.0 ; i++){
        float angle = (i*3.14)/180;
        glVertex2f(410 + 40.0*cos(angle),150 +  40.0 * sin(angle));
        
    }
    glEnd();
    //third q
     glBegin(GL_LINE_STRIP);
    for(float i=1.0 ; i<360.0 ; i++){
        float angle = (i*3.14)/180;
        glVertex2f(90 + 40.0*cos(angle),150 +  40.0 * sin(angle));
        
    }
    glEnd();
    glFlush();

}
void view(){
   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0,500.0,0.0,500.0);
}
int main(int argc , char** argv){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("lab2");
    view();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}