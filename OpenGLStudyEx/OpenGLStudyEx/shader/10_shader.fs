#version 330 //���߱�������Ŀ��GLSL�������汾��3.3

out vec4 FragColor; //Ƭ����ɫ���������ɫ����

// ����vs�����Ĳ�ֵ�����ɫֵ
in vec4 Color;

//��ɫ����Ψһ��ں���
void main()
{
	// ��ɫֵ��ΪƬ����ɫ��fs�����
	FragColor = Color;
}


