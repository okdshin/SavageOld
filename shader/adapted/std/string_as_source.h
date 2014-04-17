#ifndef SAVAGE_SHADER_ADAPTED_STD_STRING_AS_SOURCE_H
#define SAVAGE_SHADER_ADAPTED_STD_STRING_AS_SOURCE_H
//20140327
#include <string>
namespace savage { namespace shader {
	namespace adapted { namespace std {
		//std::string is already defined
	}// namespace adapted
	}// namespace std
	namespace sources {
		namespace traits {
			//nothing
		}// namespace traits
		namespace policy {
			template<>
			struct get_size<std::string> {
			private:
				typedef std::string source_type;
			public:
				static std::size_t call(const source_type& source) {
					return source.length();
				}
			};
			template<>
			struct get_pointer<std::string> {
			private:
				typedef std::string source_type;
			public:
				static const char* call(const source_type& source) {
					return source.c_str();
				}
			};
		}// namespace policy
	}// namespace sources
}// namespace shader
}// namespace savage
#endif //SAVAGE_SHADER_ADAPTED_STD_STRING_AS_SOURCE_H
