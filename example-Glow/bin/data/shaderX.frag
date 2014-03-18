#version 120

uniform sampler2DRect tex0;
uniform float glowAmount;
uniform int blurSize;

void main()
{
    float x = gl_TexCoord[0].x;
    float y = gl_TexCoord[0].y;
    
    vec4 vsum = vec4(0, 0, 0, 0);
    
    if (blurSize > 0) {
        float sum = 0;
        for (int i=-blurSize; i<blurSize; i+=int(blurSize/20)+1) {
            float scale = smoothstep(1, 0, abs(i)/blurSize);
            vsum += texture2DRect(tex0, vec2(x+i, y)) * scale;
            sum += scale;
        }
        vsum /= sum;
        vsum *= glowAmount;
    } else {
        vsum = texture2DRect(tex0, vec2(x, y));
        vsum *= max(glowAmount, 1);
    }
    gl_FragColor = vsum;
}