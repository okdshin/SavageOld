#ifndef SAVAGE_SHADER_ADAPTED_GLM_MAT4_AS_DATA_H
#define SAVAGE_SHADER_ADAPTED_GLM_MAT4_AS_DATA_H
//20140412
#include <glm/glm.hpp>
namespace savage { namespace shader{
		namespace adapted { namespace glm {
		}// namespace glm
		}// namespace adapted
		namespace datas {
			namespace traits {
				template<>
				struct pointer_type<glm::mat4> {
				private:
					typedef glm::mat4 data_type;
				public:
					typedef const float* type;
				};
			}//namespace traits
			namespace policy {
				template<>
				struct get_byte_size<glm::mat4> {
				private:
					typedef glm::mat4 data_type;
					typedef typename savage::shader::datas::traits::
						size_type<data_type>::type size_type;
				public:
					static size_type call(const data_type& data) {
						return 4*sizeof(float);
					}
				};
				template<>
				struct get_pointer<glm::mat4> {
				private:
					typedef glm::mat4 data_type;
					typedef typename savage::shader::datas::traits::
						pointer_type<data_type>::type pointer_type;
				public:
					static pointer_type call(const data_type& data) {
						return &data[0][0];
					}
				};
				template<>
				struct get_dimension_num<glm::mat4> {
				private:
					typedef glm::mat4 data_type;
					typedef typename savage::shader::datas::traits::
						dimension_num_type<data_type>::type dimension_num_type;
				public:
					static dimension_num_type call(const data_type& data) {
						return 4;
					}
				};
			}// namespace policy
		}// namespace datas
}// namespace shader
}// namespace savage

#endif //SAVAGE_SHADER_ADAPTED_GLM_MAT4_AS_DATA_H
