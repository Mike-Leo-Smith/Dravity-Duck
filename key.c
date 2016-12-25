#include <unistd.h>
#include <GLFW/glfw3.h>
#include "key.h"

extern GLFWwindow *win;

int key_down(int basic_keycode)
{
	glfwWaitEventsTimeout(0.001);
	return (glfwGetKey(win, basic_keycode) == GLFW_PRESS);
}
