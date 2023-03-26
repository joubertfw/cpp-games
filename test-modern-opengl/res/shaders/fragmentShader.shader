#version 330 core

out vec4 color;
in vec4 gl_FragCoord;

void main()
{
    color = vec4(vec3(gl_FragCoord), 1.0);
}