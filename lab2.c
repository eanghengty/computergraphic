#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#define maxSize 480.0
#define minSize 20.0
#define radius 20.0
void num_on_the_line(){
     
}
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
    //letter y
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(245.0,490.0);
  
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'Y');
    //letter x
    glRasterPos2f(490.0,245.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'X');
    //genterate first q string
    char msg1[]="First Quadrant";
    char msg2[]="Second Quadrant";
    char msg3[]="Third Quadrant";
    char msg4[]="Fourth Quadrant";
    glRasterPos2f(280.0,350);
    for(int i=0; i<strlen(msg1);i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,msg1[i]);
    }
    glRasterPos2f(150.0,350);
    for(int i=0; i<strlen(msg2);i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,msg2[i]);
    }
    glRasterPos2f(280.0,150);
    for(int i=0; i<strlen(msg4);i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,msg4[i]);
    }
    glRasterPos2f(150.0,150);
    for(int i=0; i<strlen(msg3);i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,msg3[i]);
    }
    //left number on the line
    for(float i=half;i>1.0;i--){
       
    char num11[]="-20";
     char num10[]="-40";
     char num9[]="-60";
     char num8[]="-80";
     char num7[]="-100";
     char num6[]="-120";
     char num5[]="-140";
     char num4[]="-160";
     char num3[]="-180";
     char num2[]="-200";
     char num1[]="-220";
     
        
        glRasterPos2f((18.5 * i), 260.0);
       if(i == half)
        for(int i=0 ; i < strlen(num11);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num11[i]);
        }
        if(i == half-1)
        for(int i=0 ; i < strlen(num10);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num10[i]);
        }
        if(i == half-2)
        for(int i=0 ; i < strlen(num9);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num9[i]);
        }
        if(i == half-3)
        for(int i=0 ; i < strlen(num8);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num8[i]);
        }
        if(i == half-4)
        for(int i=0 ; i < strlen(num7);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num7[i]);
        }
        if(i == half-5)
        for(int i=0 ; i < strlen(num6);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num6[i]);
        }
        if(i == half-6)
        for(int i=0 ; i < strlen(num5);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num5[i]);
        }
        if(i == half-7)
        for(int i=0 ; i < strlen(num4);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num4[i]);
        }
        if(i == half-8)
        for(int i=0 ; i < strlen(num3);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num3[i]);
        }
        if(i == half-9)
        for(int i=0 ; i < strlen(num2);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num2[i]);
        }
        if(i == half-10)
        for(int i=0 ; i < strlen(num1);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num1[i]);
        }
    }

    //right number on the line
    for(float i=1.0;i<half;i++){
       
    char num11[]="220";
     char num10[]="200";
     char num9[]="180";
     char num8[]="160";
     char num7[]="140";
     char num6[]="120";
     char num5[]="100";
     char num4[]="80";
     char num3[]="60";
     char num2[]="40";
     char num1[]="20";
     
        
        glRasterPos2f(mid + (19.5 * i), 230.0);
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
     for(float i=half;i>1.0;i--){
       
    char num11[]="-20";
     char num10[]="-40";
     char num9[]="-60";
     char num8[]="-80";
     char num7[]="-100";
     char num6[]="-120";
     char num5[]="-140";
     char num4[]="-160";
     char num3[]="-180";
     char num2[]="-200";
     char num1[]="-220";
     
        
        glRasterPos2f(220.0,(18.5 * i));
       if(i == half)
        for(int i=0 ; i < strlen(num11);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num11[i]);
        }
        if(i == half-1)
        for(int i=0 ; i < strlen(num10);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num10[i]);
        }
        if(i == half-2)
        for(int i=0 ; i < strlen(num9);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num9[i]);
        }
        if(i == half-3)
        for(int i=0 ; i < strlen(num8);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num8[i]);
        }
        if(i == half-4)
        for(int i=0 ; i < strlen(num7);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num7[i]);
        }
        if(i == half-5)
        for(int i=0 ; i < strlen(num6);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num6[i]);
        }
        if(i == half-6)
        for(int i=0 ; i < strlen(num5);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num5[i]);
        }
        if(i == half-7)
        for(int i=0 ; i < strlen(num4);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num4[i]);
        }
        if(i == half-8)
        for(int i=0 ; i < strlen(num3);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num3[i]);
        }
        if(i == half-9)
        for(int i=0 ; i < strlen(num2);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num2[i]);
        }
        if(i == half-10)
        for(int i=0 ; i < strlen(num1);i++){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, num1[i]);
        }
    }
     //right number on the line
    for(float i=1.0;i<half;i++){
       
    char num11[]="220";
     char num10[]="200";
     char num9[]="180";
     char num8[]="160";
     char num7[]="140";
     char num6[]="120";
     char num5[]="100";
     char num4[]="80";
     char num3[]="60";
     char num2[]="40";
     char num1[]="20";
     
        
        glRasterPos2f(260.0, mid + (19.5 * i) );
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

    glFlush();

}
void text(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    
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