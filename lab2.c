#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<GL/gl.h>

#define maxSize 480.0
#define minSize 20.0
#define radius 20.0

float color[3] = {1.0,1.0,1.0};
float geometry_type_color[3]={1.0,1.0,1.0};
unsigned int gl_shape[2] = {GL_LINE_STRIP,GL_LINES};
float unit_color[3]={1.0,1.0,1.0};
int choice = 1;
void pre_multiply(){

}
void post_multiply(){

}
void nagate_multiply(){

}
void selectAxisColor(int);

void createMenu(){
  int submenu;
  int menu;
  int submenu2;
  int submenu3;
  int submenu1;
  //create submenu
  
  submenu2=glutCreateMenu(selectAxisColor);
  glutAddMenuEntry("White color",4);
  glutAddMenuEntry("Brown color",5);
  glutAddMenuEntry("Cyan color",6); 
  submenu3=glutCreateMenu(selectAxisColor);
  glutAddMenuEntry("Point",7);
  glutAddMenuEntry("Plus",8);
  glutAddMenuEntry("Minus",9);
  glutAddMenuEntry("Line",10); 
  submenu = glutCreateMenu(selectAxisColor);
  glutAddMenuEntry("Cyan color", 1);
  glutAddMenuEntry("Purple color", 2);
  glutAddMenuEntry("Orange color", 3);
  glutAddSubMenu("Unit color",submenu3);
  glutAddSubMenu("Geometry types",submenu2);
  submenu1=glutCreateMenu(selectAxisColor);
  glutAddMenuEntry("Parabola",11);
  glutAddMenuEntry("Sine wave",12);
  glutAddMenuEntry("Star", 13);
  // create menu
  menu = glutCreateMenu(selectAxisColor);
  // add submenu to menu
  glutAddSubMenu("Axis Color", submenu);
  glutAddSubMenu("Object Type", submenu1);

   
  // attach menu to mouse's right button
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  }

void selectAxisColor(int menuId){
  if(menuId == 1){
     
      color[0] = 0.5;
      color[1] = 1.0;
      color[2] = 1.0;
     
  }
  else if(menuId == 2){
      
      color[0] = 1.0;
      color[1] = 0.0;
      color[2] = 1.0;
  }
  else if(menuId == 3){
      
      color[0] = 1.0;
      color[1] = 0.5;
      color[2] = 0.0;
  }
  if(menuId == 7){
      gl_shape[0] = GL_POINTS;
      gl_shape[1] = GL_POINTS;
  }
  
  else if(menuId == 10){
      gl_shape[0] = GL_LINE_STRIP;
      gl_shape[1] = GL_LINES;
  }
  if(menuId == 5){
      geometry_type_color[0]=1.0;
      geometry_type_color[1]=0.0;
      geometry_type_color[2]=0.0;
  }
  else if(menuId == 6){
      geometry_type_color[0]=0.5;
      geometry_type_color[1]=1.0;
      geometry_type_color[2]=1.0;
  }
  else if(menuId == 4){
      geometry_type_color[0]=1.0;
      geometry_type_color[1]=1.0;
      geometry_type_color[2]=1.0;
  }
  if(menuId == 13){
      choice = 3;
  }
  else if(menuId == 12){
      choice=2;
  }

}

void multiply_scalar_with_vector(int scalar , int vectxa ,int vectya){
        int result1;
        int result2;
        result1 = scalar * vectxa;
        result2 = scalar * vectya;
}
void add_vector(int vectxa ,int vectya, int vectxb, int vectyb){
    int result1;
    int result2;
    result1 = vectxa + vectxb;
    result2 = vectya + vectyb;

}
void substract_vector(int vectxa ,int vectya, int vectxb, int vectyb){
    int result1;
    int result2;
    result1 = vectxa - vectxb;
    result2 = vectya - vectyb;
}
void compute_magnitude(int vec1, int vec2){
    int result;
    result = sqrt(pow(vec1,2) + pow(vec2,2));
}
void normalize(int vec1 , int vec2){
    int v_prime;
    int v1;
    int v2;
    v_prime = sqrt(pow(vec1,2) + pow(vec2,2));
    v1 = vec1 * (1/v_prime);
    v2 = vec2 * (1/v_prime);
}
void dot_product(int vectxa ,int vectya, int vectxb, int vectyb){
    int result;
    result = (vectxa * vectxb) + (vectya * vectyb);
}
void cross_product(int vectxa ,int vectya, int vectza, int vectxb, int vectyb , int vectzb){
    int result;
    result = ((vectya * vectzb) -(vectyb * vectya)) - ((vectxa * vectzb) -(vectxb * vectya)) + ((vectxa * vectyb) -(vectxb * vectya));
}
void transpose(){

}




void display(){
    float half = (maxSize-20)/(minSize*2.0);
    float mid = (maxSize/2.0)+ 10.0;

    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(color[0],color[1],color[2]);
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
    // glBegin(GL_LINE_STRIP);
    // for(float i=1.0 ; i<360.0 ; i++){
    //     float angle = (i*3.14)/180;
    //     glVertex2f(410 + 40.0*cos(angle),350 +  40.0 * sin(angle));
        
    // }
    // glEnd();
    //star
    
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

    glBegin(GL_POINT);
    for(int i = 20; i <  440; i = i + 20){
        glVertex2f(30 * sin(2 * 3.14 * 30 * i),250);
    }
    // glVertex2f(30, 250);
    // glVertex2f(400, 400);
    glEnd();


    //letter y
    // glColor3f(1.0,0.0,0.0);
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
    glColor3f(geometry_type_color[0],geometry_type_color[1],geometry_type_color[2]);
     //sinewave
     
    

     if(choice == 3){


    glBegin(gl_shape[1]);
    
    for(int i= 0; i<= (425-390)/5 ; i++){
        glVertex2f(390 + ((i) * 5),270 + ((i) * 18.57));
        if(i>0){
            glVertex2f(390 + ((i-1)*5),270 + ((i-1) * 18.57));
        }
        
    }
     for(int i= 0 ;i<= (460-425)/5 ; i++){
        glVertex2f(425 + ((i) * 5),400 - ((i) * 18.57));
        if(i>0){
            glVertex2f(425 + ((i-1)*5),400 - ((i-1) * 18.57));
        }
        
    }
    


    // glVertex2f(390,270);
    // glVertex2f(425,400);
    // glVertex2f(460,270);
    // glVertex2f(425,400);

    glVertex2f(390,270);
    glVertex2f(405,283.13);
    glVertex2f(405,283.13);
    glVertex2f(420,296.26);
    glVertex2f(420,296.26);
    glVertex2f(435,309.39);
    glVertex2f(435,309.39);
    glVertex2f(450,322.52);
    glVertex2f(450,322.52);
    glVertex2f(465,335.65);
    glVertex2f(465,335.65);
    glVertex2f(480,350);

    glVertex2f(460,270);
    glVertex2f(445,283.13);
    glVertex2f(445,283.13);
    glVertex2f(430,296.26);
    glVertex2f(430,296.26);
    glVertex2f(415,309.39);
    glVertex2f(415,309.39);
    glVertex2f(400,322.52);
    glVertex2f(400,322.52);
    glVertex2f(385,335.65);
    glVertex2f(385,335.65);
    glVertex2f(370,350);

    for(int i = 0 ; i <= (480 - 370)/10 ; i++)
    {
    glVertex2f(370 + (i*10),350);
    if(i > 0){
        glVertex2f(370 + ((i-1)*10),350);
    }
    
    }
     glEnd();
     }
    else if(choice ==2){
        glBegin(gl_shape[0]);
    
    for(int i = 0 ; i < 380 ; i = i +20){
        glVertex2f(70 + i,250 + (60*(sin((i*3.14)/180))));
    }
  
    glEnd();
    }
   
    glFlush();
    glutPostRedisplay();

}
void text(){
    glClear(GL_COLOR_BUFFER_BIT);
    // glColor3f(1.0,0.0,0.0);
    
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
    createMenu();
   
    glutDisplayFunc(display);
    
    glutMainLoop();
    
    return 0;
}