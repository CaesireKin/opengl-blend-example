#include "assist.h"

#define PI 3.1415927

GLdouble eyeX = 0.0;
GLdouble eyeY = 10.0;
GLdouble eyeZ = 51.0;

GLdouble centerX = 0.0;
GLdouble centerY = 0.0;
GLdouble centerZ = 1.0;

GLdouble upX = 0.0;
GLdouble upY = 1.0;
GLdouble upZ = 0.0;

GLdouble angleX = 0.0;	//以X轴为轴的旋角
GLdouble angleY = 0.0;	//以Y轴为轴的旋角

void Resize(int width,int height)
{
	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(0.0f,3.0f,0.0f,3.0f,1.0f,2000.0);
}

void Render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ);

	DrawGround();

	glutSwapBuffers();
}

void ProcessingKeyEvent(int key,int x,int y)
{

	switch(key)
	{
	case GLUT_KEY_LEFT:
		eyeX -= 5.0;
		centerX -= 5.0;
		break;
	case GLUT_KEY_RIGHT:
		eyeX += 5.0;
		centerX += 5.0;
		break;
	case GLUT_KEY_UP:
		eyeY += 5.0;
		centerY += 5.0;
		break;
	case GLUT_KEY_DOWN:
		eyeY -= 5.0;
		centerY -= 5.0;
		break;
	case GLUT_KEY_F1:
		eyeZ -= 5.0;
		centerZ -= 5.0;
		break;
	case GLUT_KEY_F2:
		eyeZ += 5.0;
		centerZ += 5.0;
		break;
	case GLUT_KEY_PAGE_UP:
		angleX += 0.1;
		centerY = 40.0*cos(angleX);
		break;
	case GLUT_KEY_PAGE_DOWN:
		angleX -= 0.1;
		centerY = 40.0*cos(angleX);
		break;
	}

	glutPostRedisplay();
}

void ContextMenu(int value)
{


	glutPostRedisplay();
}

void Configure(void)
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);

	glFrontFace(GL_CCW);
}

void DrawGround()
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	glBegin(GL_QUADS);

	for(int row = 0; row < 200; row++)
	{
		for(int col = 0; col < 200; col++)
		{
			x = col*20.0f;

			if(row % 2 == 0)
			{
				if(col % 2 == 0)
					glColor3f(1.0f,1.0f,1.0f);
				else
					glColor3f(0.25f,0.25f,0.25f);
			}
			else
			{
				if(col % 2 == 0)
					glColor3f(0.25f,0.25f,0.25f);
				else
					glColor3f(1.0f,1.0f,1.0f);
			}


			glVertex3f(x,y,z-20.0f);
			glVertex3f(x,y,z);
			glVertex3f(x+20.0f,y,z);
			glVertex3f(x+20.0f,y,z-20.0f);
		}

		z -= 20.0;
	}

	glEnd();
}