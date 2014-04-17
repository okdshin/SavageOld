#ifndef SAVAGE_SHADER_ADAPTED_GLSL_INSTANCE_H
#define SAVAGE_SHADER_ADAPTED_GLSL_INSTANCE_H
//20140327
#include <GL/glew.h>
namespace savage { namespace shader { namespace adapted { namespace glsl {
	namespace instances {
		namespace traits {
			template<typename Instance>
			struct handle_type {
				//default implementation
				typedef GLuint type;
			};
		}// namespace traits
		namespace policy {
			template<typename Instance>
			struct get_handle {
			private:
				typedef Instance instance_type;
				typedef typename savage::shader::adapted::glsl::instances::traits::
					handle_type<instance_type>::type handle_type;
			public:
				static handle_type
				call(const instance_type& instance) {
					//default implementation
					return instance.get_handle();
				}
			};
		}// namespace policy
		//helper function
		template<typename Instance>
		typename savage::shader::adapted::glsl::instances::
			traits::handle_type<Instance>::type
		get_handle(const Instance& instance) {
			return savage::shader::adapted::glsl::instances::policy::
				get_handle<Instance>::call(instance);
		}
	}// namespace instances
	//avoid ADL
	using savage::shader::adapted::glsl::instances::get_handle;
}// namespace glsl
}// namespace adapted
}// namespace shader
}// namespace savage
#endif //SAVAGE_SHADER_ADAPTED_GLSL_INSTANCE_H
