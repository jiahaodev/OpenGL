
#include "stdafx.h"


/**
* ��Ⱦ�ص�����
*/
void RenderScenceCB(){
	// �����ɫ����
	glClear(GL_COLOR_BUFFER_BIT);
	// ����ǰ�󻺴�
	glutSwapBuffers();
}

/**
* ������
*/
int Tutorial01(int argc, char *argv[]) {

	// ��ʼ��GLUT
	glutInit(&argc, argv);

	// ��ʾģʽ��˫���塢RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// ��������
	glutInitWindowSize(480, 320);      // ���ڳߴ�
	glutInitWindowPosition(100, 100);  // ����λ��
	glutCreateWindow("Tutorial 01");   // ���ڱ���

	// ��ʼ��Ⱦ
	glutDisplayFunc(RenderScenceCB);

	// ������պ����ɫֵ
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// ֪ͨ��ʼGLUT���ڲ�ѭ��
	glutMainLoop();

	return 0;
}
