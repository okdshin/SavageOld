#ifndef SAVAGE_SHADER_ADAPTED_GLSL_PROGRAM_H
#define SAVAGE_SHADER_ADAPTED_GLSL_PROGRAM_H
//20140325
#include <string>
#include <vector>
#include <stdexcept>
#include <GL/glew.h>
#include <savage/debug.h>
namespace savage { namespace shader {
	namespace adapted {	namespace glsl {
		class program {
		private:
			typedef savage::shader::adapted::glsl::
				instances::traits::handle_type<program>::type handle_type;
		public:
			program() : handle_(glCreateProgram()) {}
			~program() {
				glDeleteProgram(handle_);
			}
			handle_type get_handle() const {
				return handle_;
			}
		private:
			program(const program&);
			program& operator=(const program&);
			handle_type handle_;
		};
	}// namespace glsl
	}// namespace adapted
	namespace programs {
		namespace traits {
			//use default implementation
		}// namespace traits
		namespace policy {
			template<typename Object>
			struct attach_object<savage::shader::adapted::glsl::program, Object> {
			private:
				typedef savage::shader::adapted::glsl::program program_type;
				typedef Object object_type;
			public:
				static void call(const program_type& program, 
						const object_type& object) {
					glAttachShader(
							savage::shader::adapted::glsl::get_handle(program), 
							savage::shader::adapted::glsl::get_handle(object));
				}
			};
			template<>
			struct link<savage::shader::adapted::glsl::program> {
			private:
				typedef savage::shader::adapted::glsl::program program_type;
			public:
				static void call(const program_type& program) {
					GLuint handle = program.get_handle();
					glLinkProgram(handle);
					GLint status = GL_FALSE;
					glGetProgramiv(handle, GL_LINK_STATUS, &status);
					if(status != GL_TRUE){
						GLint len;
						glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &len);
						std::vector<char> log(len);
						glGetProgramInfoLog(handle, len, NULL, log.data());
						std::string log_str(log.begin(), log.end());
						throw std::runtime_error(log_str);
					}
				}
			};
			template<>
			struct use<savage::shader::adapted::glsl::program> {
			private:
				typedef savage::shader::adapted::glsl::program program_type;
			public:
				static void call(const program_type& program) {
					glUseProgram(program.get_handle());
				}
			};
			template<typename Name, typename Data>
			struct set_uniform<savage::shader::adapted::glsl::program, Name, Data> {
			private:
				typedef savage::shader::adapted::glsl::program program_type;
				typedef Name name_type;
				typedef Data data_type;
			public:
				static void call(const program_type& program, 
						const name_type& name, const data_type& data) {
					GLuint location = glGetUniformLocation(program.get_handle(), 
								savage::shader::names::get_pointer(name));
					glUniformMatrix4fv(location, 1, GL_FALSE, 
							savage::shader::datas::get_pointer(data));
				}
			};
		}// namespace policy
	}// namespace programs
}// namespace shader
}// namespace savage

#endif //SAVAGE_SHADER_ADAPTED_GLSL_PROGRAM_H
