//
// Created by Mike Smith on 2016/12/25.
//

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <memory.h>
#include "display.h"
#include "draw.h"
#include "graphic_functions.h"

unsigned short *vram;

GLFWwindow *win;
const int scale = 3;

static void reshape(GLFWwindow *win, int w, int h)
{
	glLoadIdentity();
	glTranslated(-1.0, 1.0, 0);
	glScaled(2.0 / SCREEN_WIDTH, -2.0 / SCREEN_HEIGHT, 0);
}

void Init_Display(void)
{
	vram = (unsigned short *)malloc(sizeof(unsigned short) * LCD_HEIGHT_PX * LCD_WIDTH_PX);
	
	if (!glfwInit())
		exit(EXIT_FAILURE);
	
	win = glfwCreateWindow(SCREEN_WIDTH * scale, SCREEN_HEIGHT * scale, "Gravity Duck", NULL, NULL);
	if (win == NULL)
		exit(EXIT_FAILURE);
	
	glfwSetWindowPos(win, 100, 100);
	glfwSetWindowSizeCallback(win, reshape);
	glfwMakeContextCurrent(win);
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glTranslated(-1.0, 1.0, 0);
	glScaled(2.0 / SCREEN_WIDTH, -2.0 / SCREEN_HEIGHT, 0);
}

static void SetPoint(int x, int y, unsigned short color)
{
	double red = 1.0 * (color & 0b1111100000000000) / 0b1111100000000000;
	double green = 1.0 * (color & 0b0000011111100000) / 0b0000011111100000;
	double blue = 1.0 * (color & 0b0000000000011111) / 0b0000000000011111;
	
	glBegin(GL_QUADS);
	{
		glColor3d(red, green, blue);
		glVertex2d(x, y);
		glVertex2d(x + scale, y);
		glVertex2d(x + scale, y + scale);
		glVertex2d(x, y + scale);
	}
	glEnd();
}

void Bdisp_PutDisp_DD(void)
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			SetPoint(x, y, vram[y * LCD_WIDTH_PX + x + (LCD_WIDTH_PX - SCREEN_WIDTH) / 2]);
		}
	}
	if (glfwWindowShouldClose(win)) exit(EXIT_SUCCESS);
	//glfwWaitEventsTimeout(0.001);
	glfwSwapBuffers(win);
}

void Bdisp_AllClr_VRAM(void)
{
	memset(vram, 0, sizeof(unsigned short) * LCD_WIDTH_PX * LCD_WIDTH_PX);
}