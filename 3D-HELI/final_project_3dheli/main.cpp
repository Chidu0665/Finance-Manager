#include<windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include<stdio.h>

float spinlef = 1.0, spin = 0.0, zoom = 1.0, raise =0.0, rotate = 0.0, con = .017453;
int p = 0, fire = 0, h = 1,n=6;
int rocka, rockb, rockc, rockd, rocke;
float angle = 0, radius = 0, i = 0;
float counter = 0.0;
float stepper = 0.0;
char sel;
bool flag;
void stopDisplay();
void torso()
{
    glPushMatrix();  // Torso (body of an doll)
        glTranslatef(0.0, 0.0, 0.0);
        glColor3f(.0, 0.0, 0.0);
	glScalef(0.9, 2.9, 0.5);
        glutSolidSphere(0.5, 10, 15);
      glPopMatrix();

      glPushMatrix();  // Left Leg
        glRotatef(20*sin(spin/5),1.0,0.0,0.0);
        glTranslatef(-0.25, -0.75, 0.0);
        glColor3f(0.0, 0.0, 1.0);
	glScalef(0.3, 2.0, 0.3);
        glutSolidSphere(0.5, 10, 15);
      glPopMatrix();

      glPushMatrix();  // Right Leg
        glRotatef(20*cos(spin/5),1.0,0.0,0.0);
        glTranslatef(0.25, -0.65, 0.001);
        glColor3f(0.0, 0.0, 1.0);
	glScalef(0.3, 2.0, 0.3);
        glutSolidSphere(0.5, 10, 15);
      glPopMatrix();


      glPushMatrix();  // Head
        glTranslatef(0.0, 1.0, 0.0);
        glColor3f(0.0, 0.7, 1.0);
        glutSolidSphere(0.3, 10, 15);
      glPopMatrix();

glPushMatrix(); // Right eye
glTranslatef(0.1,1.2,0.24);
glColor3f(0.0,0.0,0.0);
glScalef(0.3, 0.3, 0.1);
glutSolidSphere(0.1,10,15);
glPopMatrix();

glPushMatrix(); // Left eye
glTranslatef(-0.1,1.2,0.24);
glColor3f(0.0,0.0,0.0);
glScalef(0.3, 0.3, 0.1);
glutSolidSphere(0.1,10,15);
glPopMatrix();


glPushMatrix(); // Lips
glTranslatef(0.0,1.0,0.3);
glColor3f(1.0,0.0,0.0);
glScalef(0.3, 0.1, 0.1);
glutSolidSphere(0.3,10,15);
glPopMatrix();

}
void helicopter()
{
      glPushMatrix();  // Helicopter
	glTranslatef(0.0+counter, 10.0+raise, -20.0+stepper);
	glRotatef(45,1.0,0.0,0.0);
        glColor3f(0.2, 0.7, 0.6);
	glScalef(3.0, 2.0, 6.0);
        glutSolidSphere(0.5, 10, 10);
      glPopMatrix();

       glPushMatrix();  // Helicopter left leg
	glTranslatef(2.0+counter, 9.0+raise, -20.0+stepper);
	glRotatef(45,1.0,0.0,0.0);
        glColor3f(0.2, 0.7, 0.6);
	glScalef(0.5, 0.5, 6.0);
        glutSolidSphere(0.5, 10, 10);
      glPopMatrix();

      glPushMatrix();  // Helicopter right leg
	glTranslatef(-2.0+counter, 9.0+raise, -20.0+stepper);
	glRotatef(45,1.0,0.0,0.0);
        glColor3f(0.2, 0.7, 0.6);
	glScalef(0.5, 0.5, 6.0);
        glutSolidSphere(0.5, 10, 10);
      glPopMatrix();

      glPushMatrix();  // Helicopter prop cylinder
	glTranslatef(0.0+counter, 10.0+raise, -19.0+stepper);
	glRotatef(45,1.0,0.0,0.0);
        glColor3f(0.2, 0.7, 0.6);
	glScalef(0.5, 2.0, 0.5);
        glutSolidSphere(0.5, 10, 10);
      glPopMatrix();

      glPushMatrix();  // Helicopter back cylinder
	glTranslatef(0.0+counter, 12.0+raise, -22.0+stepper);
	glRotatef(-15,1.0,0.0,0.0);
        glColor3f(0.2, 0.7, 0.6);
	glScalef(1.0, 2.0, 0.7);
        glutSolidSphere(0.5, 10, 10);
      glPopMatrix();

      glPushMatrix();  // Helicopter prop 1
       glTranslatef(0.0+counter, 10.0+raise, -19.0+stepper);
	glRotatef(spin*100,0.0,1.0,1.0);
	glTranslatef(0.0, 1.5, -0.25);
	glRotatef(45,1.0,0.0,0.0);
        glColor3f(0.0, 0.0, 0.0);
	glScalef(0.5, 0.5, 5.0);
        glutSolidCube(0.5);
      glPopMatrix();

      glPushMatrix();  // Helicopter prop 2
       glTranslatef(0.0+counter, 10.0+raise, -19.0+stepper);
	glRotatef(spin*100,0.0,1.0,1.0);
	glTranslatef(0.0, -0.5, 1.75);
	glRotatef(45,1.0,0.0,0.0);
        glColor3f(0.0, 0.0, 0.0);
	glScalef(0.5, 0.5, 5.0);
        glutSolidCube(0.5);
      glPopMatrix();

      glPushMatrix();  // Helicopter prop 3
	glTranslatef(0.0+counter, 10.0+raise, -19.0+stepper);
	glRotatef(spin*100,0.0,1.0,1.0);
	glTranslatef(-1.0, 0.5, 0.75);
	glRotatef(45,1.0,0.0,0.0);
        glColor3f(0.0, 0.0, 0.0);
	glScalef(5.0, 0.5, 0.5);
        glutSolidCube(0.5);
      glPopMatrix();

      glPushMatrix();  // Helicopter prop 4
	glTranslatef(0.0+counter, 10.0+raise, -19.0+stepper);
	glRotatef(spin*100,0.0,1.0,1.0);
	glTranslatef(1.0, 0.5, 0.75);
	glRotatef(45,1.0,0.0,0.0);
        glColor3f(0.0, 0.0, 0.0);
	glScalef(5.0, 0.5, 0.5);
        glutSolidCube(0.5);
      glPopMatrix();
}

void rock()
{
    rocka=0;

      glPushMatrix();  // Rock1a
        glTranslatef(50.0, 20.0, (20.0 -(spin/2))+rocka);
        glColor3f(0.4, 0.4, 0.3);
	//glScalef(11.0, 3.0, 10.0);
        glutSolidSphere(1.5, 10, 10);
      glPopMatrix();

       if(-30-spin/5 < -100)
	rockb = 200;
	else
	rockb=0;

      glPushMatrix();  // Rock1b
        glTranslatef(-20.0, 20.0, (-30.0 -(spin/2))+rockb);
        glColor3f(0.4, 0.4, 0.3);
	//glScalef(1.0, 2.0, 5.0);
        glutSolidSphere(1.5, 10, 10);
      glPopMatrix();

      if(30-spin/5 < -100)
	rockc = 200;
	else
	rockc=0;

      glPushMatrix();  // Rock1c
        glTranslatef(40.0, 20.0, (30.0 -(spin/2))+rockc);
        glColor3f(0.4, 0.4, 0.3);
	//glScalef(21.0, 9.0, 10.0);
        glutSolidSphere(1.5, 10, 10);
      glPopMatrix();

        if(40-spin/5 < -100)
	rockd = 200;
	else
	rockd=0;

      glPushMatrix();  // Rock1d
        glTranslatef(-20.0, 20.0, (40.0 -(spin/2))+rockd);
        glColor3f(0.4, 0.4, 0.3);
	//glScalef(7.0, 2.0, 14.0);
        glutSolidSphere(2.0, 10, 10);
      glPopMatrix();

      if(30-spin/5 < -100)
	rocke = 200;
	else
	rocke=0;

       glPushMatrix();  // Rock1e
        glTranslatef(-10.0, 0.0, (30.0 -(spin/2))+rocke);
        glColor3f(0.4, 0.4, 0.3);
	//glScalef(6.0, 7.7, 6.0);
        glutSolidSphere(1.0, 10, 10);
      glPopMatrix();

}
void mouse(int button, int state, int x, int y)
{
  switch (button) {
     case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
           glutIdleFunc(stopDisplay);
        break;
     case GLUT_MIDDLE_BUTTON:
     case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
           glutIdleFunc(NULL);
        break;
     default:
        break;
   }
}

void myinit(void)
{
    // Light Properties
    GLfloat light_ambient[] = {0.5, 0.5, 0.5, 0.5};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {0.6, 0.8, 1.0, 0.7};
    GLfloat light_position[] = {0.0, 0.0, -100.0, 1.0};
    GLfloat mat_specular[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat mat_shininess[]= {50.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Material Properties
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    // Enable Various Components
    glEnable(GL_COLOR_MATERIAL);
   glEnable(GL_LIGHT0);
     glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);


}

void display(void)
{



    if(zoom < 10)
    zoom =10;
    glLoadIdentity();
    gluPerspective( 40.0, 1.0 , 0.1,  100.0);
    glMatrixMode(GL_MODELVIEW);



    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if(p==0){     // in firsdt perspective, calculates the positions of camera
    gluLookAt((zoom/10)*(10*sin(spinlef/100))+(zoom/10), 10.0-(zoom/100),(zoom/10)*(10*cos(spinlef/100))+(zoom/10),  0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }else
    {
   	if(raise < 0 || raise > 355)
	raise = 0;   //in 2nd view, calculates position we are looking at
        gluLookAt(0.0,1.0,1.0,100*cos(rotate*con)*cos(raise*con),100*sin(raise*con),100*cos(raise*con)
        *sin(rotate*con), 0.0, 1.0, 0.0);
    }


      if(fire==1 || angle != 0)
       {
       	 glPushMatrix();  // Projectile
           glTranslatef(0.0+counter, 10.0-(4*angle), -20.0+(6.28*angle));
           glColor3f(1.0, 0.0, 0.0);
           glutSolidSphere(0.5, 10, 10);
         glPopMatrix();

	 if(fire ==1)
     {
	 angle+=.1;
     }
	 if(angle > 4)
	 { angle =0;
	 while(radius <= 2)
	 {
	   glPushMatrix();  // Projectile
	     glColor3f(1.0, 0.6, 0.0);
             glutSolidSphere(radius, 10, 10);
           glPopMatrix();
	   radius+=.1;
	 }
	   radius = 0;
	   fire = 0;
	 }
       }

      glBegin(GL_POLYGON); //the ground surface where the man is standing..
        glColor3f(0.0,0.8,0.1);
	glVertex3f(-100.0, -2.0, -100.0);
	glVertex3f(100.0, -2.0, -100.0);
	glVertex3f(100.0,-2.0,100.0);
	glVertex3f(-100.0,-2.0,100.0);
	glVertex3f(-100.0, -2.0, -100.0);
      glEnd();
     if(p==0)
     {
        torso();
	}

	if(20-(spin/5) < -100){
	rocka = 200;
	}else{
	rock();
	glTranslatef(3.0,-3.0,5.0);
	glRotatef(i,0,1,0);
	glTranslatef(3.0,3.0,-5.0);
    helicopter();
    i+=0.2;
    glutPostRedisplay();
    }

      if(p==0)
      {
      glTranslatef(0.0, 0.5, 0.0);
      glRotatef(90.0,0.0,1.0,0.0);
      glRotatef(-90,0.0,0.0,1.0);
      glRotatef(45*cos(spin/5),0.0,0.0,1.0);
      glTranslatef(-0.5, 0, .4);
      glPushMatrix();  // Right Arm
        glColor3f(0.0, 0.7, 1.0);
	glScalef(1.0, 0.3, 0.3);
        glutSolidSphere(0.5, 10, 15);
      glPopMatrix();


      glTranslatef(0, 0, -0.8);

      glPushMatrix();  // Left Arm
        glColor3f(0.0, 0.7, 1.0);
	glScalef(1.0, 0.3, 0.3);
        glutSolidSphere(0.5, 10, 15);
     glPopMatrix();
    }
    glPopMatrix();
    glutSwapBuffers();


	        glutPostRedisplay();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective( 40.0, (GLfloat) h / (GLfloat) w , 0.1,  200.0);
    glMatrixMode(GL_MODELVIEW);

}

void stopDisplay() //freezes program
{ if(spin > 1000)
    spin = 0;
  spin+=h;
  glutPostRedisplay();
}


  //key commands for all changes input by keyboard
static void spinleft() {spinlef -= 5; }
static void spinright() {spinlef += 5;}
static void zoomout() {zoom += 5; }
static void zoomin() {zoom -= 5; }
static void moveup() {raise += 0.1; }
static void movedown() {raise -= 0.1; }
static void lookleft() {rotate -= 5;}
static void lookright() {rotate += 5;}
static void speed() {h++;}
static void slow() {h-=1;}
static void moveleft() {counter-=1.0;}
static void moveright() {counter+=1.0;}
static void movefront() {stepper+=1.0;}
static void moveback() {stepper-= 1.0;}

static void keypress(unsigned char key, int x, int y)
{  //calls the key functions
	switch(key)
	{
		case 'a': spinleft(); break;
		case 'd': glClearColor(2.6,2.6,0.0,0.0); break;
		case 'n': glClearColor(0.0,0.0,0.0,0.0); break;
		case 's': spinright(); break;
		case 'q': zoomout(); break;
		case 'z': zoomin(); break;
		case 'p': if(p == 0)p = 1; else p=0; break;
		case '8': moveup(); break;
		case '2': movedown(); break;
		case 'h': lookleft(); break;
		case 'k': lookright(); break;
		case 'x': if(fire == 0)fire = 1;
                    else fire=0; break;
		case 'm': speed(); break;
		case 'b': slow(); break;
		case '4': moveleft(); break;
		case '6': moveright(); break;
		case '7': movefront(); break;
		case '9': moveback(); break;
		case GLUT_KEY_RIGHT: for(int i=0;i<=n;i++)
                            {
                                torso();
                                glTranslatef(0.0,0.0,1.0);
                                torso();

                            }
                            break;

	}
	glutPostRedisplay();
}


void display_string(int x, int y, char *string, int font)//now
{
    int len, i;
    glRasterPos2f(x, y);
    len = (int) strlen(string);
     glColor3f(0.0,0.0,0.0);
	for (i = 0; i < len; i++) {
    if(font==1)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	else
    if(font==2)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
    else
		if(font==3)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
		else
			if(font==4)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Scene");
    myinit();
        printf("\n\t\t\tDSATM COMPUTER SCIENCE DEPT.\n");
		printf("\n\n\n\t\t\t  3D HELICOPTER FIRING ON TARGET \n");
		printf("\n \n\n\n Design and Developed By :       \t\t\t Project Guide :\n");
		printf("\n\t\t\t\t\t\t\t Mr. ANOOP.G.L\n\t\t\t\t\t\t\t Mrs. JHANAVI SHANKAR\n");
		printf("\n\n  ANKUSH M  [1DT16CS011]\n");
		printf("\n  CHIDAMBAR P BANGRE  [1DT16CS023]\n");
        printf("\n                   INSTRUCTIONS ");
        printf("\n");
		printf("\n press q for zoom in");
		printf("\n press z for  zoom out");
		printf("\n press x for shooting");
		printf("\n press a for spin left" );
		printf("\n press s for spin right");
		printf("\n press 4 for moving helicopter left");
		printf("\n press 6 for moving helicopter right");
		printf("\n press 8 for moving helicopter upwards");
		printf("\n press 2 for moving helicopter downwards");
		printf("\n press d for daylight");
		printf("\n press n for night");
		printf("\n press 1 and hit enter for position of an boy\t");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:if(sel==1)
                  		           glutDisplayFunc(display);
                  		           glutKeyboardFunc(keypress);
			           break;
			case 2:if (sel>2)
					{
						printf("WRONG CHOICE\n");
						exit(0);
					}
		}






glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keypress);
    glutMainLoop();
    return 0;
}
