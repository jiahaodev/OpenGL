#include "stdafx.h"

void myDisplayFirstTest(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}

int fistTest(int argc, char *argv[])
{
	//���������������ʼ��GLUT.
	//��������ֱ������command line�ģ�������һЩ���õ�ѡ����磺��-sync���͡�-gldebug�������Խ���X���ڵ��첽�������ֱ��Զ�������ʾGL����
	glutInit(&argc, argv);
	//��������һЩGLUT��ѡ�����á�
	//GLUT_DOUBLE �ڶ�����Ⱦ��������˫������ƣ�ά������ͼ�񻺳����ݣ���Ļ��ʾһ��ͼ��ʱ�ں�̨ͬʱ������һ��ͼ�񻺳����ݣ�������ʾ������ɫ���塣
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);// ����λ��
	glutInitWindowSize(400, 400);// ���ڳߴ�
	glutCreateWindow("��һ��OpenGL����");// ���ڱ���
	//������������һ������ϵͳ�й����ģ������еĳ�������Ľ�����ͨ���¼��ص�������
	//GLUT�����ײ㴰��ϵͳ�Ľ���Ϊ�����ṩ�˼����ص�����ѡ�����������ֻ��һ�����ص������һ֡ͼ���������Ⱦ����������ص������᲻�ϵر�GLUT�ڲ�ѭ�����á�
	glutDisplayFunc(&myDisplayFirstTest);
	//����������ô���ָ���GLUT���ڿ�ʼ�����ڲ�ѭ���������ѭ��������������ϵͳ�е��¼���ͨ���������õĻص����ݳ�ȥ��
	//��������������У�GLUT��ֻ���������ע����Ǹ�display�ص���myDisplayFirstTest����������ص������У�myDisplayFirstTest�����ǿ����Զ����������Ⱦ��һ֡��ͼ��
	glutMainLoop();
	return 0;
}