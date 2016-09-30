#include "shader.hpp"
#include <fstream>
#include <iostream>

namespace oc {

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& fileName);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName)
{
    m_program = glCreateProgram();
    m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

    for(unsigned int i=0; i < NUM_SHADERS; i++)
        glAttachShader(m_program, m_shaders[i]);

    glBindAttribLocation(m_program, 0, "position"); // Find name of attributes in the (vertex?!) shader(s?!) and bind it to attribute 0
    // glBindAttribLocation(m_program, 1, "texCoord"); // These values must also correspond to the ones in mesh.cpp

    glLinkProgram(m_program);
    CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Shader program linking failed: ");

    glValidateProgram(m_program);
    CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Shader program is invalid: ");

    // m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform")
}

Shader::~Shader()
{
    for(unsigned int i = 0; i < NUM_SHADERS; i++){
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]  );
    }
    glDeleteProgram(m_program);
}

// Use the shaders of this class!
void Shader::Bind()
{
    glUseProgram(m_program);
}

// void Shader::Update(const Transform& transform)
// {
//     glm::mat4 model = transform.GetModel();
//     glUniformMatrix4fv(m_uniform[TRANSFORM_U], 1, GL_FALSE, &model[][]);
// }

// Takes in the whole shader file as a string and which shader type it represents
static GLuint CreateShader(const std::string& text, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);

    if(shader == 0)
        std::cerr << "Error: Shader creation failed!" << std::endl;

    // OpenGL lets us send in an array of strings, but we have the entire program in ONE string
    // Also the shaders uses the C-language which doesn't have strings, but arrays of chars
    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringsLengths[1];

    // Assign the shader string as a C-compatible "string"
    shaderSourceStrings[0] = text.c_str();
    // C doesn't store length of the string, but we need it
    shaderSourceStringsLengths[0] = text.length();

    // Replace source code of 'shader'
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringsLengths);
    // Compile the shader
    glCompileShader(shader);

    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");

    return shader;
}

// Read from shader files
std::string LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE) {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

} // end of namespace oc
