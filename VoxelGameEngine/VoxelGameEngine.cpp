#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "FileReader.h"
#include "ShaderProgram.h"

constexpr auto WINDOW_WIDTH = 1280;
constexpr auto WINDOW_HEIGHT = 720;
constexpr float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main()
{
	if (!glfwInit()) return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);																	// Set the OpenGL version to 3.3	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);																	// 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);													// Set the Opengl profile to core.	

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "VoxelGameEngine", nullptr, nullptr);		// Init GLFW window.

	if (!window) {
		glfwTerminate();																							// if the window is not initialized terminate GLFW.
		return -1;																									// Exit the program.
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glfwMakeContextCurrent(window);																					// Init OpenGL context to GLFWwindow and initialize glad.
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);															//

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);																	// Set the viewport to the window size.

	unsigned int VAO, VBO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	ShaderProgram* shader = new ShaderProgram("./shaders/VertexShader.glsl", "./shaders/FragmentShader.glsl");		// Setup shaders
	shader->init();																									//


	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		processInput(window);

		shader->use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
