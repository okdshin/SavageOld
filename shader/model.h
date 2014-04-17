#ifndef SAVAGE_SHADER_MODEL_H
#define SAVAGE_SHADER_MODEL_H
//20140412
#include <savage/static_assert.h>
namespace savage { namespace shader {
	namespace models {
		namespace traits {
		}// namespace traits
		namespace policy {
			template<typename Model, typename VertexArray, 
				typename TextureCoordinateArray>
			struct construct {
				static Model call(const VertexArray& vertex_array,
						const TextureCoordinateArray& texture_coordinate_array) {
					SAVAGE_NOT_IMPLEMENTED_STATIC_ASSERT;
				}
			};
		}// namespace policy
		template<typename Model, typename VertexArray, 
			typename TextureCoordinateArray>
		void construct(const VertexArray& vertex_array,
				const TextureCoordinateArray& texture_coordinate_array) {
			return savage::shader::models::policy::
				construct<Model, VertexArray, TextureCoordinateArray>::call(
						vertex_array, texture_coordinate_array);
		}
		namespace policy {
			template<typename Model>
			struct draw {
				static void call(const Model& model) {
					SAVAGE_NOT_IMPLEMENTED_STATIC_ASSERT;
				}
			};
		}// namespace policy
		template<typename Model>
		void draw(const Model& model) {
			savage::shader::models::policy::draw<Model>::call(model);
		}
	}// namespace models
}// namespace shader
}// namespace savage
#endif //SAVAGE_SHADER_MODEL_H
