#ifndef SAVAGE_WINDOW_SIZE_WINDOW_SIZE_H
#define SAVAGE_WINDOW_SIZE_WINDOW_SIZE_H
//20140410
#include <savage/data_helper.h>
SAVAGE_DEFINE_DATA_TYPE_TRAITS_AND_POLICY(window_size, WindowSize, width);
SAVAGE_DEFINE_DATA_TYPE_TRAITS_AND_POLICY(window_size, WindowSize, height);
namespace savage { 
	namespace window_sizes {
		namespace policy {
			template<typename WindowSize>
			struct construct {
				static WindowSize
				call(typename window_sizes::width<WindowSize>::type width,
						typename window_sizes::height<WindowSize>::type height) {
					return WindowSize(width, height);
				}
			};
		}// namespace policy
		template<typename WindowSize>
		WindowSize 
		construct(typename window_sizes::width<WindowSize>::type width,
				typename window_sizes::height<WindowSize>::type height) {
			return window_sizes::policy::construct<WindowSize>::call(width, height);
		}
	}// namespace cursor_position
}// namespace savage
#endif //SAVAGE_WINDOW_SIZE_WINDOW_SIZE_H
