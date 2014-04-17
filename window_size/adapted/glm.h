#ifndef SAVAGE_WINDOW_SIZE_ADAPTED_GLM_H
#define SAVAGE_WINDOW_SIZE_ADAPTED_GLM_H
//20140411
#include <glm/glm.hpp>
namespace savage { 
	namespace window_sizes {
		namespace type_traits {
			template<>
			struct width<glm::vec2> {
				typedef float type;
			};
			template<>
			struct height<glm::vec2> {
				typedef float type;
			};
		}// namespace type_traits
		namespace policy {
			template<>
			struct get_width<glm::vec2> {
				static float call(const glm::vec2& window_size) {
					return window_size[0];
				}
			};
			template<>
			struct get_height<glm::vec2> {
				static float call(const glm::vec2& window_size) {
					return window_size[1];
				}
			};
		}
	}// namespace window_sizes
}// namespace savage

#endif //SAVAGE_WINDOW_SIZE_ADAPTED_GLM_H
