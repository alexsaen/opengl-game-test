#include "shaderprogram.ih"

std::string const fragDataName = "outColor";

void ShaderProgram::linkShaders(vector<std::string> &uniformNames)
{
	glBindFragDataLocation(d_shaderProgram, 0, fragDataName.c_str());

	// Link and use the shader program
	glLinkProgram(d_shaderProgram);
	glUseProgram(d_shaderProgram);

	// Set up matrix uniforms
	for (auto &uniform : uniformNames)
		uniforms[uniform] = glGetUniformLocation(d_shaderProgram, uniform.c_str());

}