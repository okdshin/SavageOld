#ifndef SAVAGE_SHADER_ALIAS_H
#define SAVAGE_SHADER_ALIAS_H
//20140327

namespace savage { namespace shader { 
	typedef savage::shader::adapted::glsl::program program;
	typedef savage::shader::adapted::glsl::object<GL_VERTEX_SHADER> vertex_object;
	typedef savage::shader::adapted::glsl::object<GL_GEOMETRY_SHADER> geometry_object;
	typedef savage::shader::adapted::glsl::object<GL_FRAGMENT_SHADER> fragment_object;
	typedef savage::shader::adapted::glsl::vertex_array vertex_array;
}// namespace shader
}// namespace savage

#endif //SAVAGE_SHADER_ALIAS_H
