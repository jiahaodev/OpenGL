#version 330 //���߱�������Ŀ��GLSL�������汾��3.3

//�󶨶��������������ԣ���ʽ���������Ժ�shader���Զ�Ӧӳ��
layout(location = 0) in vec3 Position;

uniform float gScale; //������shader�ж���һ��һ�±�����

void main()
{
	gl_Position = vec4(gScale * Position.x, gScale * Position.y, Position.z, 1.0 );
}
