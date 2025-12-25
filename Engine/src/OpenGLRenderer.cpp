#include "Dwigatel/OpenGLRenderer.h"

#include <GLFW/glfw3.h>

#include <stdio.h>

#include <cmath>

#include <Dwigatel/dwiVec.h>
#include <Dwigatel/CoreSystems.h>

#include <cstdlib>
#include <time.h>

void OpenGLRenderer::init(ISubSystem* subSystem)
{
	int version = gladLoadGL(glfwGetProcAddress);

	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	glViewport(0, 0, config.width, config.height);


	glShaderSource(VertexShaderID, 1, &vertexShaderSource, NULL);
	glCompileShader(VertexShaderID);

	glShaderSource(FragmentShaderID, 1, &fragmentShaderSource, NULL);
	glCompileShader(FragmentShaderID);

	programID = glCreateProgram();
	glAttachShader(programID, VertexShaderID);
	glAttachShader(programID, FragmentShaderID);
	glLinkProgram(programID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	ratioID = glGetUniformLocation(programID, "ratio");
	positionID = glGetUniformLocation(programID, "position");
	sizeID = glGetUniformLocation(programID, "size");
	rotationID = glGetUniformLocation(programID, "rotation");

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	if (config.nearest)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}


	unsigned char* data = new unsigned char[40 * 40 * 4];

	srand(time(0));

	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			int i = (y * 40 + x) * 4;


			unsigned char r = rand() % 256;

			unsigned char g = rand() % 256;

			unsigned char b = rand() % 256;


			data[i + 0] = r;
			data[i + 1] = g;
			data[i + 2] = b;
			data[i + 3] = 255;
		}
	}

	GLenum format = (4 == 4) ? GL_RGBA : GL_RGB;

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		format,
		40,
		40,
		0,
		format,
		GL_UNSIGNED_BYTE,
		data
	);

	glGenerateMipmap(GL_TEXTURE_2D);

	delete[] data;
}

double size = 0.15;
double rotation = 0.0;

void OpenGLRenderer::draw()
{
	frame++;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glUniform1i(glGetUniformLocation(programID, "uTexture"), 0);

	dwiVec::Vec2 cursor = CoreSystems::Get().subSystem->getCursor();

	if (CoreSystems::Get().subSystem->getMouseClick(FORWARD))
	{
		rotation += 0.05;
	}

	if (CoreSystems::Get().subSystem->getMouseClick(BACK))
	{
		rotation -= 0.05;
	}
	
	glUniform1f(ratioID, (double)config.height/(double)config.width);
	glUniform2f(positionID, cursor.x, cursor.y);
	glUniform2f(sizeID, size, size);


	glUniform1f(rotationID, rotation);


	glUseProgram(programID);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void OpenGLRenderer::close()
{
	glDeleteProgram(programID);
}

void OpenGLRenderer::getConfig(RendererConfig* config)
{
	*config = this->config;
}
void OpenGLRenderer::setConfig(RendererConfig config)
{
	this->config = config;
}

void OpenGLRenderer::apply()
{

}