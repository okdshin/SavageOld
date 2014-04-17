#ifndef SAVAGE_SHADER_NAME_H
#define SAVAGE_SHADER_NAME_H
//20140327
#include <savage/static_assert.h>
#include <savage/null.h>
namespace savage { namespace shader {
	namespace names {
		namespace traits {
			//nothing
		}// namespace traits
		namespace policy {
			template<typename Name>
			struct get_size {
			private:
				typedef Name name_type;
			public:
				static std::size_t call(const name_type& name) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
					return 0;
				}
			};
			template<typename Name>
			struct get_pointer {
			private:
				typedef Name name_type;
			public:
				static const char* call(const name_type& name) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
					return SAVAGE_NULL;
				}
			};
		}// namespace policy
		template<typename Name>
		std::size_t get_size(const Name& name) {
			return savage::shader::names::policy::
				get_size<Name>::call(name);
		}
		template<typename Name>
		const char* get_pointer(const Name& name) {
			return savage::shader::names::policy::
				get_pointer<Name>::call(name);
		}
	}// namespace names
}// namespace shader
}// namespace savage

#endif //SAVAGE_SHADER_NAME_H
