#ifndef SAVAGE_SHADER_ADAPTED_SAVAGE_MODEL_H
#define SAVAGE_SHADER_ADAPTED_SAVAGE_MODEL_H
//20140412

namespace savage { namespace shader {
	namespace adapted { namespace savage {
		template<typename VertexArray, 
			typename TextureCoordinateArray>
		class basic_model {
		public:
			basic_model(const VertexArray& vertex_array,
					const TextureCoordinateArray& texture_coordinate_array) :
				vertex_array_(vertex_array),
				texture_coordinate_array_(texture_coordinate_array) {}
			VertexArray get_vertex_array() const {
				return vertex_array_;
			}
			TextureCoordinateArray texture_coordinate_array() const {
				return texture_coordinate_array_;
			}

		private:
			VertexArray vertex_array_;
			TextureCoordinateArray texture_coordinate_array_;
		};
	}// namespace savage
	}// namespace adapted
}// namespace shader 
}// namespace savage

#endif //SAVAGE_SHADER_ADAPTED_SAVAGE_MODEL_H
