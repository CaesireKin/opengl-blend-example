#include "assist.h"

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutCreateWindow("BlendLearn");

	glutReshapeFunc(Resize);
	glutDisplayFunc(Render);
	glutSpecialFunc(ProcessingKeyEvent);
	Configure();

	glutMainLoop();

	return 0;
}