#include "stdafx.h"
#include <stdlib.h>
/* підключаємо бібліотеку GLUT */
#include <glut.h>
/* початкова ширина і висота вікна */
GLint Width = 512, Height = 512;
/* розмір куба */
 int CubeSize = 150;
 int X = 0;
/* ця функція керує всім виведенням на екран */
 void DrawTrinangle1(int left, int right, int top,int bottom)
 {
	 glColor3ub(255, 0, 0);
	 glBegin(GL_TRIANGLES);
	 glVertex2f(left+X, bottom + X);
	 glVertex2f(left + X, top + X);
	 glVertex2f(right + X, top + X);
	 glEnd();
	
}
 void DrawTrinangle2(int left, int right, int top, int bottom)
 {
	 glColor3ub(240, 0, 0);
	 glBegin(GL_TRIANGLES);
	 glVertex2f((left + right) / 2 + X, top + X);
	 glVertex2f(left + X, bottom + X);
	 glVertex2f(right + X, bottom + X);
	 glEnd();
 }
 void DrawTrinangle3(int left, int right, int top, int bottom)
 {
	 glColor3ub(230, 0, 0);
	 glBegin(GL_TRIANGLES);
	 glVertex2f((left + right)/2 + X, top + X);
	 glVertex2f(left + X, bottom + X);
	 glVertex2f(right + X, bottom + X);
	 glEnd();
 }
 void DrawTrinangle4(int left, int right, int top, int bottom)
 {
	 glColor3ub(220, 0, 0);
	 glBegin(GL_TRIANGLES);
	 glVertex2f(left + X, top + X);
	 glVertex2f(right + X, top + X);
	 glVertex2f((right+left)/2 + X, bottom + X);
	 glEnd();
 }
 void DrawRectangle1(int left, int right, int top, int bottom)
 {
	
glColor3ub(255,0,0);
glBegin(GL_QUADS);
glVertex2f(left + X, bottom + X);
glVertex2f((left+ right)/2 + X, bottom + CubeSize / 4 + X);
glVertex2f(right + X, bottom + X);
glVertex2f((left + right) / 2 + X, bottom-CubeSize/4 + X);
glEnd();
 }
 void DrawRectangle2(int left, int right, int top, int bottom) 
 {
	 glColor3ub(245, 0, 0);
	 glBegin(GL_QUADS);
	 glVertex2f(left + X, top + X);
	 glVertex2f(left + left/10 + X, top + X);
	 
	 glVertex2f(right + left / 10 + X, bottom + X);
	 glVertex2f(right + X, bottom + X);
	 glEnd();
 }
void Display(void)
{
	
	int left, right, top, bottom;
	left = (Width - CubeSize) / 2;
	right = left + CubeSize;
	bottom = ((Height - CubeSize) / 2)-100;
	top = bottom + CubeSize;
	glClearColor(0.1, 1, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawTrinangle1(left, right-right/10, top, bottom);
	DrawTrinangle2(left, right, top+CubeSize/2, bottom+ CubeSize);
	DrawTrinangle3(left, right - right / 10, top- CubeSize/2, bottom);
	DrawTrinangle4(left-left/2, left, bottom, bottom-bottom/10);


	DrawRectangle1((left + right) / 2, right, top + CubeSize , top + CubeSize/2);
	DrawRectangle2((left + right) / 2, right, top + CubeSize- CubeSize/5, top + CubeSize / 2);
	//glEnd();
	glFinish();

}
/* Функція викликається при зміні розмірів вікна */
void Reshape(GLint w, GLint h)
{
	Width = w;

	Height = h;
	/* установлюємо розміри області відображення */
	glViewport(0, 0, w, h);
	/* ортографічна проекція */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* Функція обробляє повідомлення від клавіатури */
void
Keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '+':
		X++;
		
		break;
	case '-':
		X--;
		 break;
	case 'f':
		CubeSize=200;
		 break;
	}
	glutPostRedisplay();
	
	
}
/* Головний цикл додатка */
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("asd");
	glClearColor(0.1, 1, 1, 0.f);
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
}
