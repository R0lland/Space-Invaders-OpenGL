#pragma once
#include <string>

class IShader
{
public:
    virtual ~IShader() = default;

	virtual IShader& Use() = 0;

	virtual void Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr) = 0;

    virtual void SetFloat(const char* name, float value, bool useShader = false) = 0;
    virtual void SetInteger(const char* name, int value, bool useShader = false) = 0;
    virtual void SetVector2f(const char* name, const std::array<float, 2>& value, bool useShader = false) = 0;
    virtual void SetVector3f(const char* name, const std::array<float, 3>& value, bool useShader = false) = 0;
    virtual void SetVector4f(const char* name, const std::array<float, 4>& value, bool useShader = false) = 0;
    virtual void SetMatrix4(const char* name, const std::array<float, 16>& value, bool useShader = false) = 0;

private:
    virtual void checkCompileErrors(unsigned int object, std::string type) = 0;
};

