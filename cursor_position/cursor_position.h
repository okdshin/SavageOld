#ifndef SAVAGE_CURSOR_POSITION_CURSOR_POSITION_H
#define SAVAGE_CURSOR_POSITION_CURSOR_POSITION_H
//20140410
#include <savage/data_helper.h>
SAVAGE_DEFINE_DATA_TYPE_TRAITS_AND_POLICY(cursor_position, CursorPosition, x);
SAVAGE_DEFINE_DATA_TYPE_TRAITS_AND_POLICY(cursor_position, CursorPosition, y);
namespace savage { 
	namespace cursor_positions {
		namespace policy {
			template<typename CursorPosition>
			struct construct {
				static CursorPosition
				call(typename cursor_positions::x<CursorPosition>::type x,
						typename cursor_positions::x<CursorPosition>::type y) {
					return CursorPosition(x, y);
				}
			};
		}// namespace policy
		template<typename CursorPosition>
		CursorPosition 
		construct(typename cursor_positions::x<CursorPosition>::type x,
				typename cursor_positions::y<CursorPosition>::type y) {
			return cursor_positions::policy::construct<CursorPosition>::call(x, y);
		}
	}// namespace cursor_position
}// namespace savage
#endif //SAVAGE_CURSOR_POSITION_CURSOR_POSITION_H
