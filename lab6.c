#include <stdio.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <GL/gl.h>

int i=250;
int yi=250;
int yi2=250;
int yi3=250;
int yi4=250;
int yi5=250;
int j=270;
int j2=270;
int j3=270;
int j4=270;
int j5=270;
int yj=270;
int yj2=270;
int yj3=270;
int k=230;
int k2=230;
int k3=230;
int k4=230;
int k5=230;
int l=290;
int yl=290;
int yl2=290;
int yl3=290;
int yl4=290;
int yl5=290;
int m=320;
int ym=320;
int ym2=320;
int n=300;
int n2=300;
int o=200;
int o2=200;
int p=220;
int yp=220;
int yp2=220;
void keyboard(unsigned char key, int x, int y){
    create_scaling_matrix(key);

    
}
void special_keyboard(int key, int x,int y){
    create_translation_matrix(key);
    
}
//fix size
void create_translation_matrix(int key){
if(key == 0x0065){
        yl3+=20;
         yi+=20;
         yj+=20;
         yl+=20;
         ym+=20;
         yp+=20;
         yl2+=20;
        ym2+=20;
        yp2+=20;
        yi2+=20;
        yi3+=20;
        yl4+=20;
        yi4+=20;
        yl5+=20;
        yi5+=20;
        
         
    }else if(key == 0x0067){
        yl3-=20;
         yi-=20;
         yj-=20;
         yl-=20;
         ym-=20;
         yp-=20;
         yl2-=20;
        ym2-=20;
        yi3-=20;
        yp2-=20;
        yi2-=20;
        yl4-=20;
        yi4-=20;
        yl5-=20;
        yi5-=20;
    }
    else if(key == 0x0066){
        j2+=20;
        n2+=20;
        i+=20;
        k+=20;
        n+=20;
        j+=20;
        o+=20;
        k2+=20;
        j3+=20;
        o2+=20;
        k3+=20;
        k4+=20;
        k5+=20;
        j5+=20;
        j4+=20;
    }
    else if(key == 0x0064){
        j2-=20;
        n2-=20;
        i-=20;
        k-=20;
        n-=20;
        j-=20;
        o-=20;
        k2-=20;
        j3-=20;
        o2-=20;
        k3-=20;
        k4-=20;
        k5-=20;
        j5-=20;
        j4-=20;
        
    }
}
//fix origin
void create_scaling_matrix(unsigned char key){
    if(key =='q'){
        exit(0);
    }
    else if(key == '+'){
        k2-=20;
        yl2+=20;
        ym2+=30;
        j2+=20;
        yl3+=20;
        n2+=30;
        yp2-=30;
        j3+=20;
        yi2-=20;
        o2-=30;
        k3-=20;
        yi3-=20;
        k4-=20;
        yl4+=20;
        k5-=20;
        yi4-=20;
        j4+=20;
        yi5-=20;
        j5+=20;
        yl5+=20;

    }
    else if(key == '-'){
        k2+=20;
        yl2-=20;
        ym2-=30;
        j2-=20;
        yl3-=20;
        n2-=30;
        yp2+=30;
        j3-=20;
        yi2+=20;
        o2+=30;
        k3+=20;
        yi3+=20;
        k4+=20;
        yl4-=20;
        k5+=20;
        yi4+=20;
        j4-=20;
        yi5+=20;
       
        j5-=20;
        yl5-=20;
    }
}
// fix origin , fix size
void create_rotation_z_matrix(){

}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);
}
void second_part(){

    glColor3f(1.0,0.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(i,yj);
    glVertex2f(k2,yl2);
    glVertex2f(i,ym2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(j2,yl3);
    glVertex2f(i,yj);
    glVertex2f(n2,yj);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(i,yj);
    glVertex2f(i,yp2);
    glVertex2f(j3,yi2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(i,yj);
    glVertex2f(o2,yj);
    glVertex2f(k3,yi3);
    glEnd();
    
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(k4,yj);
    glVertex2f(i,yj);
    glVertex2f(k4,yl4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(i,yl5);
    glVertex2f(j5,yl5);
    glVertex2f(i,yj);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(i,yj);
    glVertex2f(i,yi4);
    glVertex2f(k5,yi4);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(i,yj);
    glVertex2f(j4,yi5);
    glVertex2f(j4,yj);
    glEnd();
    


    second_part();
   
    glFlush();
    glutPostRedisplay();
    
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_keyboard);
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("lab6 display wildmill");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    
}