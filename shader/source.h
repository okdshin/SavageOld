#ifndef SAVAGE_SHADER_SOURCE_H
#define SAVAGE_SHADER_SOURCE_H
//20140327
#include <savage/static_assert.h>
#include <savage/null.h>
namespace savage { namespace shader {
	namespace sources {
		namespace traits {
			//nothing
		}// namespace traits
		namespace policy {
			template<typename Source>
			struct get_size {
			private:
				typedef Source source_type;
			public:
				static std::size_t call(const source_type& source) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
					return 0;
				}
			};
			template<typename Source>
			struct get_pointer {
			private:
				typedef Source source_type;
			public:
				static const char* call(const source_type& source) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
					return SAVAGE_NULL;
				}
			};
		}// namespace policy
		template<typename Source>
		std::size_t get_size(const Source& source) {
			return savage::shader::sources::policy::
				get_size<Source>::call(source);
		}
		template<typename Source>
		const char* get_pointer(const Source& source) {
			return savage::shader::sources::policy::
				get_pointer<Source>::call(source);
		}
	}// namespace sources
}// namespace shader
}// namespace savage

#endif //SAVAGE_SHADER_SOURCE_H
