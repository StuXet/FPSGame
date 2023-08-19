//Request GLSL 3.3
#version 330

uniform mat4 uWorldTransform;
uniform mat4 uViewProj;

in vec3 inPosition;

void main()
{
   vec4 pod = vec4(inPosition, 1.0);
   gl_position = pos * uWorldTransform * uViewProj;
}