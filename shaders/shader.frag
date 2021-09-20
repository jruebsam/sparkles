#version 330 core

uniform vec4 pointColor;

out vec4 FragColor;


void main()
{
    float alpha = 1/(1 + pow(10.*length(gl_PointCoord - vec2(0.5, 0.5)), 2));
    FragColor = vec4(pointColor.xyz, alpha);

} 