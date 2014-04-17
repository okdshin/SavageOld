#ifndef SAVAGE_SHADER_ADAPTED_STD_C_STR_AS_SOURCE_H
#define SAVAGE_SHADER_ADAPTED_STD_C_STR_AS_SOURCE_H
//20140327
#include <string>
namespace savage { namespace shader {
	namespace adapted { namespace std {
		//c_str is merely embedded type const char*
	}// namespace adapted
	}// namespace std
	namespace sources {
		namespace traits {
			//nothing
		}// namespace traits
		namespace policy {
			template<>
			struct get_size<const char*> {
			private:
				typedef const char* source_type;
			public:
				static std::size_t call(source_type source) {
					return std::char_traits<char>::length(source);
				}
			};
			template<>
			struct get_pointer<const char*> {
			private:
				typedef const char* source_type;
			public:
				static const char* call(source_type source) {
					return source;
				}
			};
			template<std::size_t N>
			struct get_size<char[N]> {
			private:
				typedef const char* source_type;
			public:
				static std::size_t call(source_type source) {
					return std::char_traits<char>::length(source);
				}
			};
			template<std::size_t N>
			struct get_pointer<char[N]> {
			private:
				typedef const char* source_type;
			public:
				static const char* call(source_type source) {
					return source;
				}
			};
		}// namespace policy
	}// namespace sources
}// namespace shader
}// namespace savage
#endif //SAVAGE_SHADER_ADAPTED_STD_C_STR_AS_SOURCE_H
