#version 330 core
out vec4 FragColor;

void main()
{
    float alpha = 1/(1 + pow(10.*length(gl_PointCoord - vec2(0.5, 0.5)), 2));
    FragColor = vec4(1.0f, 0.0f, 0.0f, alpha);

} 