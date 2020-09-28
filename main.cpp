#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define PI acos(-1.0)


int ambul=200;
int am=0;
float c1xp=0.0,c1yp=0.0,c1zp=0.0;
float width=-940,width2=600,width3=2000;
float widthfw=0,width2fw=600,width3fw=2000;
float p1xp=0.0,p1yp=0.0,p1zp=0.0;
GLfloat f=50,g=45,h=15 ;
int wr=255,wg=255,wb=255;
int day=1;
int fg=0,flag=0;
float r=0.0;
float xx=0.0;
float yy=0.0;

static GLfloat spin = 0,v=0,b=0;

void dcircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50;
    GLfloat twicePi = 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
        glEnd();
}

GLvoid drawCircle(GLdouble rad)
{
	GLint points = 50;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0.0;
    GLint i=0;
	glBegin(GL_POLYGON);
	{
		for(i = 0; i <=50; i++, theta += delTheta )
		{
			glVertex2f(rad * cos(theta),rad * sin(theta));
		}
	}
	glEnd();
}
//
//void Car1()
//{
//    glPushMatrix();
//    glColor3ub(255,255,0);
//    glTranslatef(c1xp,c1yp,c1zp);
//    glBegin(GL_QUADS);
//    glVertex3d(-160-700,-608,0);
//    glVertex3d(-80-700,-608,0);
//    glVertex3d(-80-700,-670,0);
//    glVertex3d(-160-700,-670,0);
//    glEnd();
//
//    glColor3ub(45,194,198);
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2i(414-500-700,-612);
//    glVertex2i(445-500-700,-612);
//    glVertex2i(473-500-700,-634);
//    glVertex2i(473-500-700,-662);
//    glVertex2i(414-500-700,-662);
//    glEnd();
//
//    glColor3ub(75,89,89);
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2i(417-500-700,-622);
//    glVertex2i(444-500-700,-622);
//    glVertex2i(463-500-700,-639);
//    glVertex2i(463-500-700,-656);
//    glVertex2i(417-500-700,-656);
//    glEnd();
//
//    glColor3ub(255,0,0);
//    glBegin(GL_QUADS);
//    glVertex2i(-56-700,-642);
//    glVertex2i(-70-700,-642);
//    glVertex2i(-70-700,-632);
//    glVertex2i(-56-700,-632);
//    glEnd();
//
//    glColor3ub(48,48,46);
//    dcircle(-140-700,-670,15);
//    glColor3ub(255,255,255);
//    dcircle(-140-700,-670,10);
//    glColor3ub(0,0,0);
//    dcircle(-140-700,-670,8);
//
//    glColor3ub(48,48,46);
//    dcircle(434-500-700,-670,15);
//    glColor3ub(255,255,255);
//    dcircle(434-500-700,-670,10);
//    glColor3ub(0,0,0);
//    dcircle(434-500-700,-670,8);
//    glPopMatrix();
//}
//
//void CarTranslatefw(int value)
//{
//    widthfw+=1.0;
//    if(widthfw<15006)
//    {
//        c1xp+=0.1;
//    }
//    glutTimerFunc(0,CarTranslatefw,25);
//}
//
//void CarTranslate(int value)
//{
//    width+=1.0;
//    width2-=1.0;
//    if(width<=5503)
//    {
//        c1xp+=0.1;
//    }
//
//    glutTimerFunc(0,CarTranslate,25);
//}

void water()
{
    glColor3f(0.0,1.0,0.0);
    for(int j=0;j<160;j+=20)
    {
        for(int i=0;i<60;i+=20)
        {
            glBegin(GL_LINES);
            glVertex2f(-170+i,-450+j);
            glVertex2f(-160+i,-455+j);
            glEnd();

            glBegin(GL_LINES);
            glVertex2f(-170+i,-450-j);
            glVertex2f(-160+i,-455-j);
            glEnd();
        }
    }
}

void sky()
{
	glColor3f (0.2, 0.6, 0.8);
	glBegin(GL_POLYGON);
    glVertex3f (600, -200, 0);
    glVertex3f (600, 350, 0);
    glVertex3f (-900, 350, 0);
    glVertex3f (-900, -200, 0);
	glEnd();
}


void ground()
{
	glColor3f (0.4, 0.4, 0.2);
	glBegin(GL_POLYGON); //ground
    glVertex3f (600,-900, 0);
    glVertex3f (600, -130, 0);
    glVertex3f (-900, -130, 0);
    glVertex3f (-900, -900, 0);
	glEnd();
}

void sun()
{
    glColor3f(1, .8, 0.0);
	glPushMatrix();
	drawCircle(3.5);
	glPopMatrix();
}

void cloud1()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}
void cloud2()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}

void cloud3()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}
void cloud4()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}
void cloud5()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}

void cloud6()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}

void cloud7()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}

void cloud8()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}
void cloud9()
{
    glColor3f(1, 1, 1);
    glPushMatrix();
    drawCircle(2);
	glPopMatrix();
}
void cloud10()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}

void cloud11()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}
void cloud12()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}
void cloud13()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}
void cloud14()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}
void cloud15()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}
void cloud16()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}

void cloud17()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}

void cloud18()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}

void cloud19()
{
    glColor3f(1, 1, 1);
	glPushMatrix();
	drawCircle(2);
	glPopMatrix();
}

void tree1()
{
    glColor3f (0.19, 0.41, 0.02);
    glBegin(GL_POLYGON);
    glVertex3f (15, -11, 0);
    glVertex3f (12.5, -23, 0);
    glVertex3f (17.5, -23, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -13, 0);
    glVertex3f (12, -28, 0);
    glVertex3f (18, -28, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -19, 0);
    glVertex3f (11, -34, 0);
    glVertex3f (19, -34, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -26, 0);
    glVertex3f (10, -40, 0);
    glVertex3f (20, -40, 0);
    glEnd();

    glColor3f(0.23 , 0.21 , 0.12);
    glBegin(GL_POLYGON);
    glVertex3f (16.5, -40, 0);
    glVertex3f (13.5, -40, 0);
    glVertex3f (13.5, -45, 0);
    glVertex3f (16.5, -45, 0);
    glEnd();

}

void tree4()
{
    glColor3f (0.19, 0.41, 0.02);
    glBegin(GL_POLYGON);
    glVertex3f (15, -11, 0);
    glVertex3f (12.5, -23, 0);
    glVertex3f (17.5, -23, 0);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex3f (15, -13, 0);
    glVertex3f (12, -28, 0);
    glVertex3f (18, -28, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -19, 0);
    glVertex3f (11, -34, 0);
    glVertex3f (19, -34, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -26, 0);
    glVertex3f (10, -40, 0);
    glVertex3f (20, -40, 0);
    glEnd();

    glColor3f(0.23 , 0.21 , 0.12);
    glBegin(GL_POLYGON);
    glVertex3f (16.5, -40, 0);
    glVertex3f (13.5, -40, 0);
    glVertex3f (13.5, -45, 0);
    glVertex3f (16.5, -45, 0);
    glEnd();
}
void tree5()
{
    glColor3f (0.19, 0.41, 0.02);
    glBegin(GL_POLYGON);
    glVertex3f (15, -11, 0);
    glVertex3f (12.5, -23, 0);
    glVertex3f (17.5, -23, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -13, 0);
    glVertex3f (12, -28, 0);
    glVertex3f (18, -28, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -19, 0);
    glVertex3f (11, -34, 0);
    glVertex3f (19, -34, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -26, 0);
    glVertex3f (10, -40, 0);
    glVertex3f (20, -40, 0);
    glEnd();


    glColor3f(0.23 , 0.21 , 0.12);
    glBegin(GL_POLYGON);
    glVertex3f (16.5, -40, 0);
    glVertex3f (13.5, -40, 0);
    glVertex3f (13.5, -45, 0);
    glVertex3f (16.5, -45, 0);
    glEnd();

}
void tree6()
{
    glColor3f (0.19, 0.41, 0.02);
    glBegin(GL_POLYGON);
    glVertex3f (15, -11, 0);
    glVertex3f (12.5, -23, 0);
    glVertex3f (17.5, -23, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -13, 0);
    glVertex3f (12, -28, 0);
    glVertex3f (18, -28, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -19, 0);
    glVertex3f (11, -34, 0);
    glVertex3f (19, -34, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f (15, -26, 0);
    glVertex3f (10, -40, 0);
    glVertex3f (20, -40, 0);
    glEnd();


    glColor3f(0.23 , 0.21 , 0.12);
    glBegin(GL_POLYGON);
    glVertex3f (16.5, -40, 0);
    glVertex3f (13.5, -40, 0);
    glVertex3f (13.5, -45, 0);
    glVertex3f (16.5, -45, 0);
    glEnd();
}

//void drawDisk(double radius)
//{
//	int d;
//	glBegin(GL_POLYGON);
//	for (d = 0; d < 32; d++) {
//		double angle = 2*PI/32 * d;
//		glVertex2d( radius*cos(angle), radius*sin(angle));
//	}
//	glEnd();
//}

void road()
{
    glColor3f (0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f (60, 23, 0);
    glVertex3f (10, 23, 0);
    glVertex3f (10, -20, 0);
    glVertex3f (60, -20, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (15, 0, 0);
    glVertex3f (23, 0, 0);
    glVertex3f (23, 5, 0);
    glVertex3f (15, 5, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (30, 0, 0);
    glVertex3f (38, 0, 0);
    glVertex3f (38, 5, 0);
    glVertex3f (30, 5, 0);
    glEnd();


	glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (45, 0, 0);
    glVertex3f (53, 0, 0);
    glVertex3f (53, 5, 0);
    glVertex3f (45, 5, 0);
    glEnd();

	glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (60, 21, 0);
    glVertex3f (10, 21, 0);
    glVertex3f (10, 16, 0);
    glVertex3f (60, 16, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (60, -12, 0);
    glVertex3f (10, -12, 0);
    glVertex3f (10, -17, 0);
    glVertex3f (60, -17, 0);
    glEnd();
}
//
//void drawheli()
//{
//
//	glPushMatrix();
//	glTranslatef(v/7,b/10,0);
//		glPushMatrix();
//		glTranslated(150,80,0);
//		glColor3f(1.0,0.0,0.0);	//FRONT BODY
//		glBegin(GL_POLYGON);
//			glVertex3f(55,40,0);
//			glVertex3f(70,0+20,0);
//			glVertex3f(140,0+20,0);
//			glVertex3f(160,40,0);
//			glVertex3f(160,70+20,0);
//			glVertex3f(140,100+20,0);
//			glVertex3f(70,100+20,0);
//			glVertex3f(55,78,0);
//		glEnd();
//		glColor3f(1.0,0.0,0.0); //LEGS
//		glBegin(GL_POLYGON);
//			glVertex3f(82,20,0);
//			glVertex3f(82,12,0);
//			glVertex3f(87,12,0);
//			glVertex3f(87,20,0);
//		glEnd();
//		glColor3f(1.0,0.0,0.0);
//		glBegin(GL_POLYGON);
//			glVertex3f(128,20,0);
//			glVertex3f(128,12,0);
//			glVertex3f(123,12,0);
//			glVertex3f(123,20,0);
//		glEnd();
//		glColor3f(0.7,0.0,0.0);
//		glBegin(GL_POLYGON);
//			glVertex3f(70,12,0);
//			glVertex3f(140,12,0);
//			glVertex3f(140,9,0);
//			glVertex3f(70,9,0);
//		glEnd();
//		glColor3f(0.7,0.0,0.0);
//		glBegin(GL_POLYGON);
//			glVertex3f(140,12,0);
//			glVertex3f(143,14,0);
//			glVertex3f(140,9,0);
//		glEnd();
//		glColor3f(0.7,0.0,0.0);
//		glBegin(GL_POLYGON);
//			glVertex3f(70,12,0);
//			glVertex3f(67,14,0);
//			glVertex3f(70,9,0);
//		glEnd();
//glColor3f(0.8,0.8,0.8);		//FRONT GLASS
//glBegin(GL_POLYGON);
//	glVertex3f(70,100+20,0);
//	glVertex3f(55,78,0);
//	glVertex3f(55,40,0);
//	glVertex3f(65,50,0);
//glEnd();
//glColor3f(0.8,0.8,0.8);		//SIDE GLASS
//glBegin(GL_POLYGON);
//	glVertex3f(74,112-5,0);
//	glVertex3f(70,60-5,0);
//	glVertex3f(97,60-5,0);
//	glVertex3f(97,112-5,0);
//glEnd();
//glColor3f(0.7,0.0,0.0);		//DOOR
//glBegin(GL_POLYGON);
//	glVertex3f(100+5,112,0);
//	glVertex3f(130+5,112,0);
//	glVertex3f(145+5,90,0);
//	glVertex3f(145+5,70,0);
//	glVertex3f(125+5,30-2,0);
//	glVertex3f(100+5,30-2,0);
//glEnd();
//glColor3f(1.0,0.0,0.0);		//TAIL
//glBegin(GL_POLYGON);
//	glVertex3f(160,40,0);
//	glVertex3f(260,80,0);
//	glVertex3f(260,120,0);
//	glVertex3f(255,120,0);
//	glVertex3f(250,90,0);
//	glVertex3f(160,90,0);
//glEnd();
//glColor3f(1.0,0.0,0.0);		//BOX
//glBegin(GL_POLYGON);
//	glVertex3f(108,100+20,0);
//	glVertex3f(108,130,0);
//	glVertex3f(102,130,0);
//	glVertex3f(102,100+20,0);
//glEnd();
//glPopMatrix();
//glPushMatrix();			//MAIN SPINING FAN
//glTranslatef(255,210,-100);
//	spin=spin+2;
//	glColor3f(0.8, 0.0, 0.0);
//	glRotatef(spin,0,1,0);
//	glScalef(1.1,0.07,0);
//	glutWireSphere(100, 100, 10);
//	glutPostRedisplay();
//glPopMatrix();
//glPushMatrix();
//glTranslatef(398,181,-100);	//TAIL FAN
//	glColor3f(1.0, 1.0, 1.0);
//	glutSolidSphere(17, 50, 20);
//	glutPostRedisplay();
//glPopMatrix();
//glPushMatrix();
//glTranslatef(398,181,-100);	//TAIL FAN
//	glColor3f(1.0, 0.0, 0.0);
//	glutWireSphere(18, 20, 20);
//	glutPostRedisplay();
//glPopMatrix();
//glPushMatrix();
//glTranslatef(398,181,-100);	//TAIL FAN
//	spin=spin+2;
//	glColor3f(0.8, 0.0, 0.0);
//	glRotatef(spin,0,0,1);
//	glScalef(1.1,0.2,0);
//	glutWireSphere(16, 50, 20);
//	glutPostRedisplay();
//glPopMatrix();
//     glPopMatrix();
//glFlush();
//}

void house()
{
    glColor3f (1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f (20, 25, 0);
    glVertex3f (10, 25, 0);
    glVertex3f (10, -20, 0);
    glVertex3f (20, -20, 0);
    glEnd();

	glBegin(GL_POLYGON);
    glVertex3f (15, 30, 0);
    glVertex3f ( 10, 30, 0);
    glVertex3f (10, -20, 0);
    glVertex3f (15, -20, 0);
	glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (19, 22, 0);
    glVertex3f (16, 22, 0);
    glVertex3f (16, 17, 0);
    glVertex3f (19, 17, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (14, 22, 0);
    glVertex3f (11, 22, 0);
    glVertex3f (11, 17, 0);
    glVertex3f (14, 17, 0);
    glEnd();


	glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (19, 13, 0);
    glVertex3f (16, 13, 0);
    glVertex3f (16, 8, 0);
    glVertex3f (19, 8, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (14, 13, 0);
    glVertex3f (11, 13, 0);
    glVertex3f (11, 8, 0);
    glVertex3f (14, 8, 0);
    glEnd();

	glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (14, 4, 0);
    glVertex3f (11, 4, 0);
    glVertex3f (11, -1, 0);
    glVertex3f (14, -1, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (19, 4, 0);
    glVertex3f (16, 4, 0);
    glVertex3f (16, -1, 0);
    glVertex3f (19, -1, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (14, -5, 0);
    glVertex3f (11, -5, 0);
    glVertex3f (11, -10, 0);
    glVertex3f (14, -10, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (19, -5, 0);
    glVertex3f (16, -5, 0);
    glVertex3f (16, -10, 0);
    glVertex3f (19, -10, 0);
    glEnd();
}

void house2()
{
    glColor3f (	0.37, 0.10, 0.57);
    glBegin(GL_POLYGON);
    glVertex3f (20, 25, 0);
    glVertex3f (10, 25, 0);
    glVertex3f (10, -20, 0);
    glVertex3f (20, -20, 0);
    glEnd();

	glBegin(GL_POLYGON);
    glVertex3f (15, 30, 0);
    glVertex3f ( 10, 30, 0);
    glVertex3f (10, -20, 0);
    glVertex3f (15, -20, 0);
	glEnd();

    glColor3f(0.6 , 0.5 , 0.4);
    glBegin(GL_POLYGON);
    glVertex3f (19, 22, 0);
    glVertex3f (16, 22, 0);
    glVertex3f (16, 17, 0);
    glVertex3f (19, 17, 0);
    glEnd();

    glColor3f(0.6 , 0.5 , 0.4);
    glBegin(GL_POLYGON);
    glVertex3f (14, 22, 0);
    glVertex3f (11, 22, 0);
    glVertex3f (11, 17, 0);
    glVertex3f (14, 17, 0);
    glEnd();


	glColor3f(0.6 , 0.5 , 0.4);
    glBegin(GL_POLYGON);
    glVertex3f (19, 13, 0);
    glVertex3f (16, 13, 0);
    glVertex3f (16, 8, 0);
    glVertex3f (19, 8, 0);
    glEnd();

    glColor3f(0.6 , 0.5 , 0.4);
    glBegin(GL_POLYGON);
    glVertex3f (14, 13, 0);
    glVertex3f (11, 13, 0);
    glVertex3f (11, 8, 0);
    glVertex3f (14, 8, 0);
    glEnd();

	glColor3f(0.6 , 0.5 , 0.4);
    glBegin(GL_POLYGON);
    glVertex3f (14, 4, 0);
    glVertex3f (11, 4, 0);
    glVertex3f (11, -1, 0);
    glVertex3f (14, -1, 0);
    glEnd();

    glColor3f(0.6 , 0.5 , 0.4);
    glBegin(GL_POLYGON);
    glVertex3f (19, 4, 0);
    glVertex3f (16, 4, 0);
    glVertex3f (16, -1, 0);
    glVertex3f (19, -1, 0);
    glEnd();

    glColor3f(0.6 , 0.5 , 0.4);
    glBegin(GL_POLYGON);
    glVertex3f (14, -5, 0);
    glVertex3f (11, -5, 0);
    glVertex3f (11, -10, 0);
    glVertex3f (14, -10, 0);
    glEnd();

    glColor3f(0.6 , 0.5 , 0.4);
    glBegin(GL_POLYGON);
    glVertex3f (19, -5, 0);
    glVertex3f (16, -5, 0);
    glVertex3f (16, -10, 0);
    glVertex3f (19, -10, 0);
    glEnd();
}

void house3()
{
      glColor3f (1, 0, 0);
	  glBegin(GL_POLYGON);
      glVertex3f (20, 25, 0);
      glVertex3f (10, 25, 0);
      glVertex3f (10, -20, 0);
      glVertex3f (20, -20, 0);
      glEnd();

      glBegin(GL_POLYGON);
      glVertex3f (15, 20, 0);
      glVertex3f ( 10, 25, 0);
      glVertex3f (10, -20, 0);
      glVertex3f (15, -20, 0);
	  glEnd();

	  glColor3ub(wr,wg,wb);
	  glBegin(GL_POLYGON);
      glVertex3f (19, 22, 0);
      glVertex3f (16, 22, 0);
      glVertex3f (16, 17, 0);
      glVertex3f (19, 17, 0);
	  glEnd();

	  glBegin(GL_POLYGON);
      glVertex3f (14, 22, 0);
      glVertex3f (11, 22, 0);
      glVertex3f (11, 17, 0);
      glVertex3f (14, 17, 0);
	  glEnd();

	  glBegin(GL_POLYGON);
      glVertex3f (19, 13, 0);
      glVertex3f (16, 13, 0);
      glVertex3f (16, 8, 0);
      glVertex3f (19, 8, 0);
      glEnd();

	  glBegin(GL_POLYGON);
      glVertex3f (14, 13, 0);
      glVertex3f (11, 13, 0);
      glVertex3f (11, 8, 0);
      glVertex3f (14, 8, 0);
	  glEnd();

      glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (14, 4, 0);
      glVertex3f (11, 4, 0);
      glVertex3f (11, -1, 0);
      glVertex3f (14, -1, 0);
	  glEnd();

      glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (19, 4, 0);
      glVertex3f (16, 4, 0);
      glVertex3f (16, -1, 0);
      glVertex3f (19, -1, 0);
	  glEnd();

	  glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (14, -5, 0);
      glVertex3f (11, -5, 0);
      glVertex3f (11, -10, 0);
      glVertex3f (14, -10, 0);
	  glEnd();

      glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (19, -5, 0);
      glVertex3f (16, -5, 0);
      glVertex3f (16, -10, 0);
      glVertex3f (19, -10, 0);
	  glEnd();

}

void house10()
{
    glColor3f (0.15, 0.46, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f (20, 25, 0);
    glVertex3f (10, 25, 0);
    glVertex3f (10, -20, 0);
    glVertex3f (20, -20, 0);
    glEnd();

	glBegin(GL_POLYGON);
    glVertex3f (15, 30, 0);
    glVertex3f ( 10, 30, 0);
    glVertex3f (10, -20, 0);
    glVertex3f (15, -20, 0);
	glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (19, 22, 0);
    glVertex3f (16, 22, 0);
    glVertex3f (16, 17, 0);
    glVertex3f (19, 17, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (14, 22, 0);
    glVertex3f (11, 22, 0);
    glVertex3f (11, 17, 0);
    glVertex3f (14, 17, 0);
    glEnd();


	glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (19, 13, 0);
    glVertex3f (16, 13, 0);
    glVertex3f (16, 8, 0);
    glVertex3f (19, 8, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (14, 13, 0);
    glVertex3f (11, 13, 0);
    glVertex3f (11, 8, 0);
    glVertex3f (14, 8, 0);
    glEnd();

	glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (14, 4, 0);
    glVertex3f (11, 4, 0);
    glVertex3f (11, -1, 0);
    glVertex3f (14, -1, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (19, 4, 0);
    glVertex3f (16, 4, 0);
    glVertex3f (16, -1, 0);
    glVertex3f (19, -1, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (14, -5, 0);
    glVertex3f (11, -5, 0);
    glVertex3f (11, -10, 0);
    glVertex3f (14, -10, 0);
    glEnd();

    glColor3f(1 , 1 , 1);
    glBegin(GL_POLYGON);
    glVertex3f (19, -5, 0);
    glVertex3f (16, -5, 0);
    glVertex3f (16, -10, 0);
    glVertex3f (19, -10, 0);
    glEnd();
}

void house11()
{
      glColor3f (0.56, 0.05, 0.24);
	  glBegin(GL_POLYGON);
      glVertex3f (20, 25, 0);
      glVertex3f (10, 25, 0);
      glVertex3f (10, -20, 0);
      glVertex3f (20, -20, 0);
	  glEnd();

	  glBegin(GL_POLYGON);
      glVertex3f (15, 30, 0);
      glVertex3f ( 10, 30, 0);
      glVertex3f (10, -20, 0);
      glVertex3f (15, -20, 0);
	  glEnd();




	  glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (19, 22, 0);
      glVertex3f (16, 22, 0);
      glVertex3f (16, 17, 0);
      glVertex3f (19, 17, 0);
	  glEnd();

	  glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (14, 22, 0);
      glVertex3f (11, 22, 0);
      glVertex3f (11, 17, 0);
      glVertex3f (14, 17, 0);
	  glEnd();


	  glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (19, 13, 0);
      glVertex3f (16, 13, 0);
      glVertex3f (16, 8, 0);
      glVertex3f (19, 8, 0);
	  glEnd();

	  glColor3f(1 , 1 , 1);
      glBegin(GL_POLYGON);
      glVertex3f (14, 13, 0);
      glVertex3f (11, 13, 0);
      glVertex3f (11, 8, 0);
      glVertex3f (14, 8, 0);
	  glEnd();

	  glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (14, 4, 0);
      glVertex3f (11, 4, 0);
      glVertex3f (11, -1, 0);
      glVertex3f (14, -1, 0);
	  glEnd();

      glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (19, 4, 0);
      glVertex3f (16, 4, 0);
      glVertex3f (16, -1, 0);
      glVertex3f (19, -1, 0);
	  glEnd();

      glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (14, -5, 0);
      glVertex3f (11, -5, 0);
      glVertex3f (11, -10, 0);
      glVertex3f (14, -10, 0);
	  glEnd();

      glColor3f(1 , 1 , 1);
	  glBegin(GL_POLYGON);
      glVertex3f (19, -5, 0);
      glVertex3f (16, -5, 0);
      glVertex3f (16, -10, 0);
      glVertex3f (19, -10, 0);
	  glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    sky();
    ground();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-180,280,0);
    glScalef(8,9.5,0);
    sun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-600,230,0);
    glScalef(42,25,0);
    cloud1();
    glPopMatrix();

   glPushMatrix();
   glTranslatef(-580,260,0);
   glScalef(20,20,0);
   cloud2();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-620,260,0);
   glScalef(20,20,0);
   cloud3();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-620,210,0);
   glScalef(20,20,0);
   cloud4();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-580,210,0);
   glScalef(20,20,0);
   cloud5();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-350,230,0);
   glScalef(42,25,0);
   cloud6();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-330,260,0);
   glScalef(20,20,0);
   cloud7();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-370,260,0);
   glScalef(20,20,0);
   cloud8();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-370,210,0);
   glScalef(20,20,0);
   cloud9();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-330,210,0);
   glScalef(20,20,0);
   cloud10();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-50,230,0);
   glScalef(42,25,0);
   cloud11();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-30,260,0);
   glScalef(20,20,0);
   cloud12();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-70,260,0);
   glScalef(20,20,0);
   cloud13();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-70,210,0);
   glScalef(20,20,0);
   cloud14();
   glPopMatrix();

    glPushMatrix();
    glTranslatef(-30,210,0);
    glScalef(20,20,0);
    cloud15();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200,230,0);
    glScalef(42,25,0);
    cloud16();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(220,260,0);
    glScalef(20,20,0);
    cloud17();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(180,260,0);
    glScalef(20,20,0);
    cloud18();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(180,210,0);
    glScalef(20,20,0);
    cloud19();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-600,0,0);
    glScalef(13.0,9.3,0);
    tree4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-950,20,0);
    glScalef(13.0,12.3,0);
    tree5();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-100,50,0);
    glScalef(7.0,6.0,0);
    tree6();
    glPopMatrix();




  glPushMatrix();
  glTranslatef(-1200,-680,0);
  glScalef(30.0,5.0,0);
  road();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-30,-130,0);
  glScalef(5.0,4.0,0);
  glPopMatrix();
  //Car1();
  glPushMatrix();
  glTranslatef(-340,-380,0);
  glScalef(11.0,7.3,0);
  house3();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-450,-380,0);
  glScalef(11.0,7.3,0);
  house();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-655,-400,0);
  glScalef(10,7.3,0);
  house2();
  glPopMatrix();

    glPushMatrix();
    glTranslatef(180,-130,0);
    glScalef(5.0,3.0,0);
    house10();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(180,-130,0);
    glScalef(5.0,3.0,0);
    //drawheli();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60,-350,0);
    glScalef(8.0,6.0,0);
    house11();
    glPopMatrix();
    if(fg==1)
    {
        water();
    }
    glutSwapBuffers();
	glFlush();

}

void init(void)
{
        glClearColor (1.0, 1.0, 1.0, 0.0);
 	    glColor3f(1.0,1.0,1.0);
 	    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-900.0,600.0,-900.0,350,0.0,250.0);
        glMatrixMode(GL_MODELVIEW);
}

void waterng()
{
    if(fg==0)
    {
        fg=1;
    }else
    {
        fg=0;
    }
}

//void mouse(int button,int state,int x,int y)
//{
//    switch(button)
//    {
//    case GLUT_RIGHT_BUTTON:
//        if(state==GLUT_DOWN)
//        CarTranslate(0);
//        break;
//            case GLUT_LEFT_BUTTON:
//        if(state==GLUT_DOWN){
//            waterng();
//
//        }
//        break;
//    default:
//        break;
//    }
//}

void keyboard(unsigned char key, int x, int y)
{

    if(key=='e')
    {
        CarTranslatefw(0);
        glutPostRedisplay();
    }

    if(key=='f')
    {
        if(wr==255 && wg==255 && wb==255)
        {
            wr=0;
            wg=0;
            wb=0;
        }
    }
    if(key=='s')
    {
        if(wr==0 && wg==0 && wb==0)
        {
            wr=255;
            wg=255;
            wb=255;
        }
    }
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1396, 768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Graphics Final Project");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    init();

    glutMainLoop();
    return 0;

}

