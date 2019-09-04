#version 330 //告诉编译器，目标GLSL编译器版本是3.3

//绑定顶点属性名和属性，方式二缓冲属性和shader属性对应映射
layout(location = 0) in vec3 Position;

uniform float gScale; //这里在shader中定义一个一致变量。

void main()
{
	gl_Position = vec4(gScale * Position.x, gScale * Position.y, Position.z, 1.0 );
}
