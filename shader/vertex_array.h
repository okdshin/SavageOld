#ifndef SAVAGE_SHADER_VERTEX_ARRAY_H
#define SAVAGE_SHADER_VERTEX_ARRAY_H
//20140327
#include <savage/static_assert.h>
namespace savage { namespace shader { 
	namespace vertex_arrays {
		namespace traits {
			//nothing
		}// namespace traits
		namespace policy {
			template<typename VertexArray>
			struct bind {
			private:
				typedef VertexArray vertex_array_type;
			public:
				static void call(const vertex_array_type& vertex_array) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
				}
			};
			template<typename VertexArray>
			struct draw {
			private:
				typedef VertexArray vertex_array_type;
			public:
				static void call(const vertex_array_type& vertex_array) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
				}
			};
		}// namespace policy
		template<typename VertexArray>
		void bind(const VertexArray& vertex_array) {
			savage::shader::vertex_arrays::policy::bind<VertexArray>::call(vertex_array);
		}
		template<typename VertexArray>
		void draw(const VertexArray& vertex_array) {
			savage::shader::vertex_arrays::policy::draw<VertexArray>::call(vertex_array);
		}
	}// namespace vertex_arrays
	using savage::shader::vertex_arrays::bind;
	using savage::shader::vertex_arrays::draw;
}// namespace shader
}// namespace savage
#endif //SAVAGE_SHADER_VERTEX_ARRAY_H
