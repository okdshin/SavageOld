#ifndef SAVAGE_CONTEXT_H
#define SAVAGE_CONTEXT_H
//20140410
#include <boost/scoped_ptr.hpp>
#include <GLFW/glfw3.h>
#include <savage/window_size.h>
#include <savage/cursor_position.h>
#include <savage/key_state.h>
#include <savage/time.h>
#include <savage/debug.h>
namespace savage {
	namespace contexts {
		namespace type_traits {
			template<typename Context>
			struct window_size {
				typedef typename Context::window_size_type type;
			};
		}// namespace type_traits
		using savage::contexts::type_traits::window_size;
		namespace policy {
			template<typename Context>
			struct get_window_size {
			private:
				typedef typename savage::contexts::
					window_size<Context>::type window_size_type;
			public:
				static window_size_type
				call(const Context& context) {
					using namespace savage::window_sizes;
					int width, height;
					glfwGetWindowSize(context.get_window_handle(),
							&width, &height);
					return savage::window_sizes::
						construct<window_size_type>(width, height);
				}
			};
		}// namespace policy
		template<typename Context>
		typename savage::contexts::window_size<Context>::type
		get_window_size(const Context& context) {
			return savage::contexts::policy::
				get_window_size<Context>::call(context);
		}

		namespace type_traits {
			template<typename Context>
			struct cursor_position {
				typedef typename Context::cursor_position_type type;
			};
		}// namespace type_traits
		using savage::contexts::type_traits::cursor_position;
		namespace policy {
			template<typename Context>
			struct get_cursor_position {
			private:
				typedef typename savage::contexts::
					cursor_position<Context>::type cursor_position_type;
			public:
				static cursor_position_type
				call(const Context& context) {
					using namespace savage::cursor_positions;
					double x, y;
					glfwGetCursorPos(context.get_window_handle(), &x, &y);
					return savage::cursor_positions::
						construct<cursor_position_type>(x, y);
				}
			};
		}// namespace policy
		template<typename Context>
		typename savage::contexts::cursor_position<Context>::type
		get_cursor_position(const Context& context) {
			return savage::contexts::policy::
				get_cursor_position<Context>::call(context);
		}
		
		namespace policy {
			template<typename Context, typename CursorPosition>
			struct set_cursor_position {
				static void call(const Context& context, 
						const CursorPosition& cursor_position) {
					glfwSetCursorPos(context.get_window_handle(),
							savage::cursor_positions::get_x(cursor_position),
							savage::cursor_positions::get_y(cursor_position));
				}
			};
		}// namespace policy
		template<typename Context, typename CursorPosition>
		void 
		set_cursor_position(const Context& context, 
				const CursorPosition& cursor_position) {
			savage::contexts::policy::
				set_cursor_position<Context, CursorPosition>::call(
						context, cursor_position);
		}

		namespace type_traits {
			template<typename Context>
			struct key_state {
				typedef typename Context::key_state_type type;
			};
		}// namespace type_traits
		using savage::contexts::type_traits::key_state;
		namespace policy {
			template<typename Context>
			struct get_key_state {
			private:
				typedef typename savage::contexts::
					key_state<Context>::type key_state_type;
			public:
				static key_state_type
				call(const Context& context, savage::key_states::key_id key_id) {
					return savage::key_states::construct<key_state_type>(
							glfwGetKey(context.get_window_handle(), key_id));
				}
			};
		}// policy
		template<typename Context>
		typename savage::contexts::key_state<Context>::type
		get_key_state(const Context& context, savage::key_states::key_id key_id) {
			return savage::contexts::policy::
				get_key_state<Context>::call(context, key_id);
		}

#define SAVAGE_DEFINE_CONTEXT_UNARY_POLICY(ReturnType, LowerName, Statement) \
		namespace policy { \
			template<typename Context> \
			struct LowerName { \
				static ReturnType call(const Context& context) \
				Statement \
			}; \
		} \
		template<typename Context> \
		ReturnType LowerName(const Context& context) { \
			return savage::contexts::policy::LowerName<Context>::call(context); \
		} 
		SAVAGE_DEFINE_CONTEXT_UNARY_POLICY(
			bool, is_window_closed, {
				return glfwWindowShouldClose(context.get_window_handle());
			}
		)
		SAVAGE_DEFINE_CONTEXT_UNARY_POLICY(
			void, swap_buffers, {
				glfwSwapBuffers(context.get_window_handle());
			}
		)
#undef SAVAGE_DEFINE_CONTEXT_UNARY_POLICY
	}// namespace contexts
	template<typename WindowSize, typename CursorPosition, 
		typename KeyState = savage::key_state>
	class basic_context {
	public:
		typedef WindowSize window_size_type;
		typedef CursorPosition cursor_position_type;
		typedef KeyState key_state_type;

		template<typename OtherWindowSize>
		basic_context(const OtherWindowSize& window_size) {
			initializer::initialize();
			window_ = glfwCreateWindow(
					savage::window_sizes::get_width(window_size),
					savage::window_sizes::get_height(window_size),
					"title", 0, 0);
			if(!window_){
				throw std::runtime_error("window init error");
			}
			glfwMakeContextCurrent(window_);
		}

		GLFWwindow* get_window_handle() const {
			return window_;
		}
	private:
		class initializer {
		public:
			static initializer& get_ref() {
				return *self_;
			}
			static void initialize() {
				self_.reset(new initializer);
			}
			~initializer() {
				glfwTerminate();
				SAVAGE_DEBUG_PRINT("glfwTerminate()");
			}
		private:
			initializer() {
				if(!glfwInit()){
					throw std::runtime_error("glfw init error");
				}
				SAVAGE_DEBUG_PRINT("glfwInit()");
			}
			static boost::scoped_ptr<initializer> self_;
		};
		GLFWwindow* window_;
	};
	template<typename WindowSize, typename CursorPosition, typename KeyState>
	boost::scoped_ptr<typename basic_context<WindowSize, CursorPosition, KeyState>::initializer> 
		basic_context<WindowSize, CursorPosition, KeyState>::initializer::self_;
	typedef basic_context<savage::window_size, savage::cursor_position> context;
}// namespace savage

#endif //SAVAGE_CONTEXT_H
