#include <iostream>
#include <gl/glew.h> 
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <vector>
GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid Keyboard(unsigned char key, int x, int y);

std::vector<GLclampf> GLrgbacf;

void main(int argc, char** argv)
{
	GLrgbacf.assign(4, NULL);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(250, 250);
	glutCreateWindow("Example1");

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW Initialized\n";
	glutDisplayFunc(drawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
}

GLvoid drawScene() 
{
	glClearColor(GLrgbacf[0], GLrgbacf[1], GLrgbacf[2], GLrgbacf[3]); 
	glClear(GL_COLOR_BUFFER_BIT); 
	glutSwapBuffers(); 
}


GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

GLvoid Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'c':
		GLrgbacf[0] = 0.0f;
		GLrgbacf[1] = 1.0f;
		GLrgbacf[2] = 1.0f;
		GLrgbacf[3] = 0.0f;
		break;
	}
	glutPostRedisplay(); 
}