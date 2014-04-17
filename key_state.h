#ifndef SAVAGE_KEY_STATE_H
#define SAVAGE_KEY_STATE_H
//20140411
#include <GLFW/glfw3.h>
namespace savage {
	namespace key_states {
		typedef int key_id;
		const key_id escape = GLFW_KEY_ESCAPE;
		const key_id up = GLFW_KEY_UP;
		const key_id down = GLFW_KEY_DOWN;
		const key_id left = GLFW_KEY_LEFT;
		const key_id right = GLFW_KEY_RIGHT;

		typedef int state;
		const state pressed = GLFW_PRESS;
		const state released = GLFW_RELEASE;

		namespace policy {
			template<typename KeyState>
			struct construct {
				static KeyState call(savage::key_states::state state) {
					return KeyState(state);
				}
			};
		}// namespace policy
		template<typename KeyState>
		KeyState construct(savage::key_states::state state) {
			return savage::key_states::policy::
				construct<KeyState>::call(state);
		}
		namespace policy {
			template<typename KeyState>
			struct is_pressed {
				static bool call(const KeyState& key_state) {
					return key_state.is_pressed();
				}
			};
		}// namespace policy
		template<typename KeyState>
		bool is_pressed(const KeyState& key_state) {
			return savage::key_states::policy::is_pressed<KeyState>::call(key_state);
		}
		namespace adapted { namespace savage {
			class key_state {
			public:
				typedef ::savage::key_states::state state_type;
				explicit key_state(state_type state) : state_(state) {}
				bool is_pressed() const {
					return state_ == ::savage::key_states::pressed;
				}
			private:
				state_type state_;
			};
		}// namespace savage
		}// namespace adapted
	}// namespace key_states
	using savage::key_states::adapted::savage::key_state;
}// namespace savage

#endif //SAVAGE_KEY_STATE_H
