#version 330 //告诉编译器，目标GLSL编译器版本是3.3

//绑定顶点属性名和属性，方式二缓冲属性和shader属性对应映射
layout(location = 0) in vec3 Position;

void main()
{
	gl_Position = vec4(0.5 * Position.x, 0.5 * Position.y, Position.z, 1.0 );
}
