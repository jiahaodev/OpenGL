#include "stdafx.h"

void myDisplayFirstTest(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}

int fistTest(int argc, char *argv[])
{
	//调用这个函数来初始化GLUT.
	//参数可以直接引用command line的，而且有一些有用的选项，比如：‘-sync’和‘-gldebug’，可以禁掉X窗口的异步特征并分别自动检查和显示GL错误。
	glutInit(&argc, argv);
	//这里配置一些GLUT的选项设置。
	//GLUT_DOUBLE 在多数渲染结束后开启双缓冲机制（维护两个图像缓冲数据，屏幕显示一副图像时在后台同时绘制另一份图像缓冲数据，交替显示）和颜色缓冲。
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);// 窗口位置
	glutInitWindowSize(400, 400);// 窗口尺寸
	glutCreateWindow("第一个OpenGL程序");// 窗口标题
	//由于我们是在一个窗口系统中工作的，与运行的程序多数的交互是通过事件回调函数。
	//GLUT针对与底层窗口系统的交互为我们提供了几个回调函数选项。这里我们先只用一个主回调来完成一帧图像的所有渲染工作。这个回调函数会不断地被GLUT内部循环调用。
	glutDisplayFunc(&myDisplayFirstTest);
	//这个函数调用传递指令给GLUT现在开始它的内部循环。在这个循环中它监听窗口系统中的事件并通过我们配置的回调传递出去。
	//在我们这个例子中，GLUT将只会调用我们注册的那个display回调（myDisplayFirstTest），在这个回调函数中（myDisplayFirstTest）我们可以自定义代码来渲染这一帧的图像。
	glutMainLoop();
	return 0;
}