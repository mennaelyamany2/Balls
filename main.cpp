#include <Gl/glut.h>
#include<iostream>
using namespace std;
float angle = 0.05;
float s = 0.0 ;
void Draw()
{

	 glClear(GL_COLOR_BUFFER_BIT);
	 glMatrixMode(GL_MODELVIEW);
	 glColor3f(1.0, 1.0, 0.5);
	 glRotatef(angle, 0.0, 1.0, 1.0);
	 glPushMatrix();
	 glutWireSphere(15.0 , 25 , 25);
	 glPopMatrix();
	 glColor3f(0.5, 1.0, 0.5);
	 glRotatef(angle, 1.0, 0.0, 0.0);
	 glPushMatrix();
     glTranslatef(s , 0.0 , 0.0);
	 glutWireSphere(13.0 , 25 , 25);
	 glPopMatrix();
	 glFlush();
	 glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{

	case 'q':
	case 'Q':
		exit(0);
		break;
    case 'b':
    case 'B':
        glScaled(2.0,2.0,2.0);
        break;
    case 's':
    case 'S':
        glScaled(0.5,0.5,0.5);
        break;
     case 'u':
    case 'U':
        glTranslated(2.0,2.0,0.0);
        break;
    case 'd':
    case 'D':
        glTranslated(-2.0,-2.0,0.0);
        break;
	}
}
void Special_Keys(int key, int x, int y)
{
	switch (key)
	{

        case GLUT_KEY_RIGHT:
            angle += 0.1;
            break;
         case GLUT_KEY_LEFT:
            angle -= 0.1;
             break;
         case GLUT_KEY_DOWN:
             s--;
            break;
         case GLUT_KEY_UP:
             s++;
            break;
	}
}
void init()
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);

}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Balls");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(Special_Keys);
	glutDisplayFunc(Draw);
	glutIdleFunc(Draw);
	init();
	glutMainLoop();
	return EXIT_SUCCESS;
}
