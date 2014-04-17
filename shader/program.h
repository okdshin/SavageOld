#ifndef SAVAGE_SHADERS_PROGRAMS_H
#define SAVAGE_SHADERS_PROGRAMS_H
//20140325
#include <savage/static_assert.h>

namespace savage { namespace shader {
	namespace programs {
		namespace traits {
			//nothing
		}// namespace traits
		namespace policy {
			template<typename Program, typename Object>
			struct attach_object {
			private:
				typedef Program program_type;
				typedef Object object_type;
			public:
				static void call(const program_type& program, 
						const object_type& object) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
				}
			};
			template<typename Program>
			struct link {
			private:
				typedef Program program_type;
			public:
				static void call(const program_type& program) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
				}
			};
			template<typename Program>
			struct use {
			private:
				typedef Program program_type;
			public:
				static void call(const program_type& program) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
				}
			};
			template<typename Program, typename Name, typename Data>
			struct set_uniform {
			private:
				typedef Program program_type;
				typedef Name name_type;
				typedef Data data_type;
			public:
				static void call(const program_type& program, 
						const name_type& name, const data_type& data) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
				}
			};
		}// namespace policy
		template<typename Program, typename Object>
		void attach_object(const Program& program, const Object& object) {
			savage::shader::programs::policy::
				attach_object<Program, Object>::call(program, object);
		}
		template<typename Program>
		void link(const Program& program) {
			savage::shader::programs::policy::link<Program>::call(program);
		}
		template<typename Program>
		void use(const Program& program) {
			savage::shader::programs::policy::use<Program>::call(program);
		}
		template<typename Program, typename Name, typename Data>
		void set_uniform(const Program& program, const Name& name, const Data& data) {
			savage::shader::programs::policy::
				set_uniform<Program, Name, Data>::call(program, name, data);
		}
	}// namespace programs
}// namespace shader
}// namespace savage

#endif// SAVAGE_SHADERS_PROGRAMS_H
