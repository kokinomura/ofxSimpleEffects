#version 120

//varying vec4 globalColor;

// the time value is passed into the shader by the OF app.
uniform float time;

void main()
{
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_Position = ftransform();
    
    // in OpenGL 2.0 we must get the global color using the gl_Color command,
    // and store it in a globalColor (varying) that is passed to our frag shader.
    // please note that the frag shader also has a globalColor (varying),
    // and this is the standard way of passing data from the vertex shader to the frag shader.
    //globalColor = gl_Color;
}