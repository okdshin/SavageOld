#ifndef SAVAGE_SHADER_ADAPTED_GLSL_VERTEX_ARRAY_H
#define SAVAGE_SHADER_ADAPTED_GLSL_VERTEX_ARRAY_H
//20140327
#include <GL/glew.h>
namespace savage { namespace shader { 
	namespace adapted {	namespace glsl {
		class vertex_array {
		private:
			typedef savage::shader::adapted::glsl::
				instances::traits::handle_type<vertex_array>::type handle_type;
		public:
			explicit vertex_array(GLsizei vertex_num) : 
					handle_(0), vertex_num_(vertex_num) {
				glGenVertexArrays(1, &handle_);
			}
			~vertex_array(){
				glDeleteVertexArrays(1, &handle_);
			}
			handle_type get_handle() const {
				return handle_;
			}
			GLsizei get_vertex_num() const {
				return vertex_num_;
			}
		private:
			vertex_array(const vertex_array&);
			vertex_array& operator=(const vertex_array&);
			handle_type handle_;
			GLsizei vertex_num_;
		};
	}// namespace glsl
	}// namespace adapted
	namespace vertex_arrays {
		namespace traits {
			//nothing
		}// namespace traits
		namespace policy {
			template<>
			struct bind<savage::shader::adapted::glsl::vertex_array> {
			private:
				typedef savage::shader::adapted::glsl::vertex_array vertex_array_type;
			public:
				static void call(const vertex_array_type& vertex_array) {
					glBindVertexArray(savage::shader::adapted::glsl::
							get_handle(vertex_array));
				}
			};
			template<>
			struct draw<savage::shader::adapted::glsl::vertex_array> {
			private:
				typedef savage::shader::adapted::glsl::vertex_array vertex_array_type;
			public:
				static void call(const vertex_array_type& vertex_array) {
					glDrawArrays(GL_TRIANGLES, /*start_index=*/0, 
							vertex_array.get_vertex_num());
				}
			};
		}// namespace policy
	}// namespace vertex_array
}// namespace shader
}// namespace savage
#endif //SAVAGE_SHADER_ADAPTED_GLSL_VERTEX_ARRAY_H
