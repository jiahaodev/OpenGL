#version 330 //���߱�������Ŀ��GLSL�������汾��3.3

//�󶨶��������������ԣ���ʽ���������Ժ�shader���Զ�Ӧӳ��
layout(location = 0) in vec3 Position;

uniform mat4 gWorld; //ƽ�Ʊ任����һ�±�����

void main()
{
	gl_Position =  gWorld * vec4( Position, 1.0 );
}
