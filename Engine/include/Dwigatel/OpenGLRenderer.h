#pragma once
#include <glad/gl.h>
#include "IRenderer.h"
#include <string>


class OpenGLRenderer : public IRenderer
{
public:
	void init(ISubSystem* subSystem) override;
	void draw() override;
	void close() override;

    void getConfig(RendererConfig* config) override;
    void setConfig(RendererConfig config) override;

    void apply() override;
private:
    GLuint textureID;
    GLuint programID;
    GLuint ratioID;
    GLuint positionID;
    GLuint sizeID;
    GLuint rotationID;

    int frame = 0;

private:
    RendererConfig config;
    const char* vertexShaderSource = R"glsl(
    #version 330 core

    uniform float ratio;
    uniform vec2 position;
    uniform vec2 size;
    uniform float rotation;

    out vec2 TexCoord;

    void main()
    {
        float c = cos(-rotation);
        float s = sin(-rotation);

        // Quad from -0.5 to 0.5 (centered)
        vec2 positions[4] = vec2[](
            vec2(-1.0, -1.0),
            vec2( 1.0, -1.0),
            vec2(-1.0,  1.0),
            vec2( 1.0,  1.0)
        );

        vec2 uvs[4] = vec2[](
            vec2(0.0, 0.0),
            vec2(1.0, 0.0),
            vec2(0.0, 1.0),
            vec2(1.0, 1.0)
        );

        vec2 pos = positions[gl_VertexID];

        // Rotate
        pos = vec2(
            pos.x * c - pos.y * s,
            pos.x * s + pos.y * c
        );

        // Scale and translate
        pos *= size;
        pos += position;

        // Aspect ratio
        pos.x *= ratio;

        gl_Position = vec4(pos, 0.0, 1.0);

        TexCoord = uvs[gl_VertexID];
    }

    )glsl";
    const char* fragmentShaderSource = R"glsl(
    #version 330 core

    out vec4 FragColor;
    in vec2 TexCoord;

    uniform sampler2D uTexture;

    void main()
    {
        FragColor = texture(uTexture, TexCoord);
    }
    )glsl";
};