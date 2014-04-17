#ifndef SAVAGE_CURSOR_POSITION_ADAPTED_GLM_H
#define SAVAGE_CURSOR_POSITION_ADAPTED_GLM_H
//20140411
#include <glm/glm.hpp>
namespace savage { 
	namespace cursor_positions {
		namespace type_traits {
			template<>
			struct x<glm::vec2> {
				typedef float type;
			};
			template<>
			struct y<glm::vec2> {
				typedef float type;
			};
		}// namespace type_traits
		namespace policy {
			template<>
			struct get_x<glm::vec2> {
				static float call(const glm::vec2& cursor_position) {
					return cursor_position[0];
				}
			};
			template<>
			struct get_y<glm::vec2> {
				static float call(const glm::vec2& cursor_position) {
					return cursor_position[1];
				}
			};
		}
	}// namespace cursor_positions
}// namespace savage

#endif //SAVAGE_CURSOR_POSITION_ADAPTED_GLM_H
