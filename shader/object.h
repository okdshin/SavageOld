#ifndef SAVAGE_SHADER_OBJECT_H
#define SAVAGE_SHADER_OBJECT_H
//20140325
#include <iostream>
#include <savage/static_assert.h>
namespace savage { namespace shader {
	namespace objects {
		namespace traits {
			//nothing
		}
		namespace policy {
			template<typename Object, typename Source>
			struct compile {
			private:
				typedef Object object_type;
				typedef Source source_type;
			public:
				static void 
				call(const object_type& object, const source_type& source) {
					SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT;
					return object;
				}
			};
		}
		template<typename Object, typename Source>
		void compile(const Object& object, const Source& source) {
			savage::shader::objects::policy::
				compile<Object, Source>::call(object, source);
		}
	}// namespace objects
	using savage::shader::objects::compile;
}// namespace shader
}// namespace savage

#endif //SAVAGE_SHADER_OBJECT_H
