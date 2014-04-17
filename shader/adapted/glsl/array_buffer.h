#ifndef SAVAGE_SHADER_ADAPTED_GLSL_ARRAY_BUFFER_H
#define SAVAGE_SHADER_ADAPTED_GLSL_ARRAY_BUFFER_H
//20140406
#include <GL/glew.h>
#include <savage/shader/name.h>
#include <savage/shader/data.h>
namespace savage { namespace shader {
	namespace adapted { namespace glsl {
		class array_buffer {
		public:
			array_buffer() {
				glGenBuffers(1, &handle_);
			}
			~array_buffer() {
				glDeleteBuffers(1, &handle_);
			}
			template<typename Program, typename Index, typename Name, typename Hint, 
				typename Data>
			void initialize(Program& program, Index index, const Name& name, Hint hint,
					const Data& data) {
				glBindBuffer(GL_ARRAY_BUFFER, handle_);
				glBufferData(GL_ARRAY_BUFFER, 
						savage::shader::datas::get_byte_size(data), 
						savage::shader::datas::get_pointer(data), GL_STATIC_DRAW);
				glBindAttribLocation(
						savage::shader::adapted::glsl::get_handle(program), 
						index, savage::shader::names::get_pointer(name));
				glEnableVertexAttribArray(index);
				glBindBuffer(GL_ARRAY_BUFFER, handle_);
				glVertexAttribPointer(index, 
						savage::shader::datas::get_dimension_num(data), 
						GL_FLOAT, GL_FALSE, 0, (void*)(0) );
			}

		private:
			GLuint handle_;
		};
	}// namespace glsl
	}// namespace adapted
	namespace array_buffers {
	}// namespace array_buffers
}// namespace shader
}// namespace savage

#endif //SAVAGE_SHADER_ADAPTED_GLSL_ARRAY_BUFFER_H
