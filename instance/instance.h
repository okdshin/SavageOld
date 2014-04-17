#ifndef SAVAGE_INSTANCE_INSTANCE_H
#define SAVAGE_INSTANCE_INSTANCE_H
//20140411
namespace savage {
	namespace instances {
		namespace policy {
			template<typename Instance, typename Time>
			struct update {
				static void call(Instance& instance, Time time) {
					instance.update(time);
				}
			};
		}// namespace policy
		template<typename Instance, typename Time>
		void update(Instance& instance, const Time& time) {
			savage::instances::policy::update<Instance, Time>::call(instance, time);
		}
		namespace policy {
			template<typename Instance, typename Context>
			struct main_loop {
				static void call(Instance& instance, const Context& context) {
					while(!savage::contexts::is_window_closed(context)){
						glfwPollEvents();//TODO
						glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
						savage::instances::update(instance,
								savage::time(glfwGetTime()));//TODO
						savage::contexts::swap_buffers(context);
					}
				}
			};
		}// namespace policy
		template<typename Instance, typename Context>
		void main_loop(Instance& instance, const Context& context) {
			savage::instances::policy::
				main_loop<Instance, Context>::call(instance, context);
		}
	}// namespace instances
}// namespace savage

#endif //SAVAGE_INSTANCE_INSTANCE_H
