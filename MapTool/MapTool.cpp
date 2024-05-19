#include "glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

const int windowWidth = 1280;
const int windowHeight = 720;

/// <summary>
/// Setup of custom error msgs.
/// Default msg is "There was an error! Code: codeNum"
/// </summary>
/// <param name="Code number"></param>
/// <returns>int</returns>
static int ErLg(int code) {
	const char* text = "There was an error!";
	switch (code) {
	case -1:
		text = "GLFW failed to initialize!";
		break;
	case -2:
		text = "The window failed to be created!";
		break;
	case -3:
		text = "Glad failed to load OpenGL!";
		break;
	}
	std::cout << text << "\nCode: " << code << std::endl;
	return code;
}

int main() {
	//Initialize GLFW
	if (glfwInit() == false)
		return ErLg(-1);
	//Create the window instance
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "D&D Map Tool", nullptr, nullptr);
	//Check if the window was succfully created...
	if (window == nullptr) {
		//...terminate process if failed
		glfwTerminate();
		return ErLg(-2);
	}
	//Make the window context the current on the calling thread - thats what glfw says
	glfwMakeContextCurrent(window);
	//Have Glad load OpenGL...
	if (!gladLoadGL()) {
		//...terminate process if failed
		glfwDestroyWindow(window);
		glfwTerminate();
		return ErLg(-3);
	}
	//Print the current OpenGL version to the console
	printf("GL: %i.%i\n", GLVersion.major, GLVersion.minor);
	//Close if the window closes or the ESC key is pressed
	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		//logic here

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//Terminate the process
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
