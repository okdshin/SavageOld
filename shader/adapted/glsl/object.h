#ifndef SAVAGE_SHADER_ADAPTED_GLSL_OBJECT_H
#define SAVAGE_SHADER_ADAPTED_GLSL_OBJECT_H
//20140326
#include <string>
#include <vector>
#include <stdexcept>
#include <boost/lexical_cast.hpp>
#include <GL/glew.h>
#include <savage/debug.h>
#include <savage/shader/source.h>
#include <savage/shader/adapted/glsl/instance.h>
namespace savage { namespace shader { 
	namespace adapted { namespace glsl {
		template<GLenum ShaderTypeID>
		class object {
		private:
			typedef typename savage::shader::adapted::glsl::
				instances::traits::handle_type<object>::type handle_type;
		public:
			static GLenum get_shader_type_id() {
				return shader_type_id;
			}
			object() : handle_(glCreateShader(object::get_shader_type_id())) {
				SAVAGE_DEBUG_PRINT("object"+boost::lexical_cast<std::string>(handle_)+
						" constructor called");
			}
			~object() {
				SAVAGE_DEBUG_PRINT("object"+boost::lexical_cast<std::string>(handle_)+
						" deconstructor called");
        		glDeleteShader(handle_);
			}
			handle_type get_handle() const {
				return handle_;
			};
		private:
			object(const object&);
			object& operator=(const object&);
			static const GLenum shader_type_id = ShaderTypeID;
			handle_type handle_;
		};
	}// namespace glsl
	}// namespace adapted
	namespace objects {
		namespace traits {
			//use default implementation
		}// namespace traits
		namespace policy {
			template<GLenum ShaderTypeID, typename Source>
			struct compile<
				savage::shader::adapted::glsl::object<ShaderTypeID>, Source> {
			private:
				typedef savage::shader::adapted::glsl::object<ShaderTypeID> 
					object_type;
				typedef Source source_type;
			public:
				static void
				call(const object_type& object, const source_type& source) {
					SAVAGE_DEBUG_PRINT("glsl specialized compile called");
					GLuint handle = static_cast<GLuint>(savage::shader::adapted::glsl::
							get_handle(object));
					const char* src_c_str_p = 
						savage::shader::sources::get_pointer(source);
					const GLint size = static_cast<GLint>(
							savage::shader::sources::get_size(source));
					glShaderSource(handle, 1, &src_c_str_p, &size);
					glCompileShader(handle);
					GLint status = GL_FALSE;
					glGetShaderiv(handle, GL_COMPILE_STATUS, &status);
					if(status == GL_FALSE){
						GLint len;
						glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &len);
						std::vector<char> log(len);
						glGetShaderInfoLog(handle, len, 0, log.data()); 
						std::string log_str(log.begin(), log.end());
						throw std::runtime_error(
								"Failed compile shader object: "+log_str);
					}
				}
			};
		}// namespace policy
	}// namespace objects
}// namespace shader	
}// namespace savage

#endif //SAVAGE_SHADER_ADAPTED_GLSL_OBJECT_H
