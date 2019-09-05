#version 330 //告诉编译器，目标GLSL编译器版本是3.3

//绑定顶点属性名和属性，方式二缓冲属性和shader属性对应映射
layout(location = 0) in vec3 Position;

uniform mat4 gWorld; //平移变换矩阵一致变量。

out vec4 Color; //顶点着色器输出的颜色值


void main()
{
	gl_Position =  gWorld * vec4( Position , 1.0 ); 
	//颜色插值
	Color = vec4(clamp(Position, 0.0, 1.0), 1.0);
}
