#pragma once
#include <string>

#include "IShader.h"

#include <GL/glew.h>

#include "glm\glm.hpp"

#include "glm\gtc\type_ptr.hpp"

// General purpose shader object. Compiles from file, generates
// compile/link-time error messages and hosts several utility 
// functions for easy management.
class OpenGLShader : public IShader
{
public:
    // state
    unsigned int ID; 
    // constructor
    OpenGLShader() { }
    // sets the current shader as active
    OpenGLShader& Use() override;
    void Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr) override;

    void SetFloat(const char* name, float value, bool useShader = false) override;
    void SetInteger(const char* name, int value, bool useShader = false) override;
    void SetVector2f(const char* name, const std::array<float, 2>& value, bool useShader = false) override;
    void SetVector3f(const char* name, const std::array<float, 3>& value, bool useShader = false) override;
    void SetVector4f(const char* name, const std::array<float, 4>& value, bool useShader = false) override;
    void SetMatrix4(const char* name, const std::array<float, 16>& value, bool useShader = false) override;


    void SetOGLVector2f(const char* name, const glm::vec2& value, bool useShader);

private:
    // checks if compilation or linking failed and if so, print the error logs
    void checkCompileErrors(unsigned int object, std::string type) override; 
};