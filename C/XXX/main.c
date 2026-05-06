#include <stdio.h>
//#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*int main(int argc, char *argv[]) {
	return 0;
}*/
#include <glut.h> 
void display(void) 
{
glClear(GL_COLOR_BUFFER_BIT); 
glBegin(GL_POLYGON);
glVertex2f(-0.3, -0.3); 
glVertex2f(-0.3, 0.3); 
glVertex2f(0.3, 0.3); 
glVertex2f(0.3, -0.3);
glEnd();
glFlush();
}
int main(void) {
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutCreateWindow("Ola Mundo"); 
glutDisplayFunc(display);
glutMainLoop();
}

