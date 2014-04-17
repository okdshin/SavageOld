#ifndef SAVAGE_SHADER_ADAPTED_STD_C_STR_AS_NAME_H
#define SAVAGE_SHADER_ADAPTED_STD_C_STR_AS_NAME_H
//20140327
#include <string>
namespace savage { namespace shader {
	namespace adapted { namespace std {
		//c_str is merely embedded type const char*
	}// namespace adapted
	}// namespace std
	namespace names {
		namespace traits {
			//nothing
		}// namespace traits
		namespace policy {
			template<>
			struct get_size<const char*> {
			private:
				typedef const char* name_type;
			public:
				static std::size_t call(name_type name) {
					return std::char_traits<char>::length(name);
				}
			};
			template<>
			struct get_pointer<const char*> {
			private:
				typedef const char* name_type;
			public:
				static const char* call(name_type name) {
					return name;
				}
			};
			template<std::size_t N>
			struct get_size<char[N]> {
			private:
				typedef const char* name_type;
			public:
				static std::size_t call(name_type name) {
					return std::char_traits<char>::length(name);
				}
			};
			template<std::size_t N>
			struct get_pointer<char[N]> {
			private:
				typedef const char* name_type;
			public:
				static const char* call(name_type name) {
					return name;
				}
			};
		}// namespace policy
	}// namespace names
}// namespace shader
}// namespace savage
#endif //SAVAGE_SHADER_ADAPTED_STD_C_STR_AS_NAME_H
