#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <learnopengl/shader_s.h>

#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
GLFWwindow* initWindow();
//void initShaderProgram();
void initShaderData();

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;



//数组引用
unsigned int VBO, VAO;
//shader程序引用
unsigned int shaderProgram;

int main() {


	GLFWwindow* window = initWindow();
	if (window == NULL) {
		glfwTerminate();
		return -1;
	}

	//初始化shader程序
	//initShaderProgram();
	Shader ourShader("shader/3.3.shader.vs", "shader/3.3.shader.fs");
	//初始化shader相关数据
	initShaderData();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //线绘制
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //填充绘制（默认）

	//渲染循环
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		//清除颜色缓存
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//灵活的编程
		//glUseProgram(shaderProgram);
		ourShader.use();

		float offset = 0.5f;
		ourShader.setFloat("xOffset",offset);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents(); //检查并调用事件
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	glfwTerminate();

	return 0;
}


//初始化shader相关数据
void initShaderData()
{
	float vertices[] = {
		// positions         // colors
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
	};

	//unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//位置属性设置
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//颜色属性设置
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	// glBindVertexArray(0);


	// bind the VAO (it was already bound, but just to demonstrate): seeing as we only have a single VAO we can 
	// just bind it beforehand before rendering the respective triangle; this is another approach.
	glBindVertexArray(VAO);
}



//初始化窗口相关
GLFWwindow* initWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to created GLFW window" << std::endl;
		glfwTerminate();
		return NULL;
		//return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return NULL;
		//return -1;
	}
	return window;
}

//处理用户输入按键
void processInput(GLFWwindow *window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

//窗口大小改变时，视口（viewport）大小的调节
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}