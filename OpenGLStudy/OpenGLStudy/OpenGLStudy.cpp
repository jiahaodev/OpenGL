// OpenGLStudy.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
//#include "FirstTest.h"
//#include "Tutorial01.h"
//
//int main(int argc, char *argv[])
//{
//	//fistTest(argc,argv);
//	Tutorial01(argc, argv);
//
//	return 0;
//}

#include <stdio.h>
#include <glew.h>        // GLEW��չ��
#include <freeglut.h>  // freeGLUTͼ�ο�
#include "ogldev_math_3d.h" // ����OpenGL��3d��ѧ��,������Ҫ�õ��˶���������ݽṹ������ԭ���ߵ�Դ������ҵ����ͷ�ļ���
// �������п��ܻᱨ���Ҳ���vector3��matrix3x3��matrix4x4�Լ����ߵ�ogldev_utilͷ�ļ�������Դ���������ṩ���������룩����ʱ�Ƚ�����Ķ�ע�͵�����

GLuint VBO;

/**
* ��Ⱦ�ص�����
*/
static void RenderScenceCB(){
	// �����ɫ����
	glClear(GL_COLOR_BUFFER_BIT);

	// ������������
	glEnableVertexAttribArray(0);
	// ��GL_ARRAY_BUFFER������
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// ���߹�����������bufer�е�����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// ��ʼ���Ƽ���ͼ��(����һ����)
	glDrawArrays(GL_POINTS, 0, 1);

	//  ���ö�������
	glDisableVertexAttribArray(0);

	// ����ǰ�󻺴�
	glutSwapBuffers();
}

/**
* �������㻺����
*/
static void CreateVertexBuffer()
{
	// ��������һ������Ķ�������
	Vector3f Vertices[1];
	// ����������Ļ����
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	// ����������
	glGenBuffers(1, &VBO);
	// ��GL_ARRAY_BUFFER������
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// �󶨶�������
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

/**
* ������
*/
int main(int argc, char ** argv) {

	// ��ʼ��GLUT
	glutInit(&argc, argv);

	// ��ʾģʽ��˫���塢RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// ��������
	glutInitWindowSize(480, 320);      // ���ڳߴ�
	glutInitWindowPosition(100, 100);  // ����λ��
	glutCreateWindow("Tutorial 02");   // ���ڱ���

	// ��ʼ��Ⱦ
	glutDisplayFunc(RenderScenceCB);

	// ���GLEW�Ƿ����������Ҫ��GLUT��ʼ��֮��
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	// ������պ����ɫֵ
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// �������㻺����
	CreateVertexBuffer();


	// ֪ͨ��ʼGLUT���ڲ�ѭ��
	glutMainLoop();

	return 0;
}

-------------------- -

�������� Mr_��� ��CSDN ���� ��ȫ�ĵ�ַ������https ://blog.csdn.net/cordova/article/details/52491762?utm_source=copy 