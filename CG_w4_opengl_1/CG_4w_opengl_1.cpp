#include <iostream>
#include <gl/glew.h> 
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <vector>
#include <math.h>

std::vector<GLclampf> GLrgbacf;

GLclampf cyan[4] = { 0.0f, 1.0f, 1.0f, 0.0f };
GLclampf magenta[4] = { 1.0f, 0.0f, 1.0f, 0.0f };
GLclampf yellow[4] = { 1.0f, 1.0f, 0.0f, 0.0f };
GLclampf white[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
GLclampf black[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
GLclampf tmprgba[4] = { 0, };

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid Keyboard(unsigned char key, int x, int y);
void change_color_screen(const GLclampf* color);
void random_color();
void main_init();

void main(int argc, char** argv)
{
	srand((unsigned int)time(NULL));
	GLrgbacf.assign(4, NULL);
	main_init();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
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

void main_init() {
	change_color_screen(white);
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
		change_color_screen(cyan);
		break;

	case 'm':
		change_color_screen(magenta);
		break;

	case 'y':
		change_color_screen(yellow);
		break;

	case 'a':
		random_color();
		change_color_screen(tmprgba);
		break;

	case 'w':
		change_color_screen(white);
		break;

	case 'k':
		change_color_screen(black);
		break;
	}
	glutPostRedisplay(); 
}


void change_color_screen(const GLclampf *color) {
	for (int i = 0; i < 4; i++) {
		GLrgbacf[i] = color[i];
	}
}

void random_color() {
	for (int i = 0; i < 4; i++) {
		tmprgba[i] = float(rand() % 256) / (float)256;
	}
}