#ifndef SAVAGE_SHADER_ADAPTED_STD_VECTOR_AS_DATA_H
#define SAVAGE_SHADER_ADAPTED_STD_VECTOR_AS_DATA_H
//20140407
#include <vector>
namespace savage { namespace shader { 
	namespace adapted { namespace std {
		//std::vector is already defined
	}// namespace std
	}// namespace adapted
	namespace datas {
		namespace traits {
			template<typename T>
			struct size_type<std::vector<T> > {
			private:
				typedef std::vector<T> data_type;
			public:
				typedef typename data_type::size_type type;
			};
			template<typename T>
			struct pointer_type<std::vector<T> > {
			private:
				typedef std::vector<T> data_type;
			public:
				typedef const T* type;
			};
			template<typename T>
			struct dimension_num_type<std::vector<T> > {
			private:
				typedef std::vector<T> data_type;
			public:
				typedef std::size_t type;
			};
		}//namespace traits
		namespace policy {
			template<typename T>
			struct get_byte_size<std::vector<T> > {
			private:
				typedef std::vector<T> data_type;
				typedef typename savage::shader::datas::traits::
					size_type<data_type>::type size_type;
			public:
				static size_type call(const data_type& data) {
					return sizeof(T)*data.size();
				}
			};
			template<typename T>
			struct get_pointer<std::vector<T> > {
			private:
				typedef std::vector<T> data_type;
				typedef typename savage::shader::datas::traits::
					pointer_type<data_type>::type pointer_type;
			public:
				static pointer_type call(const data_type& data) {
					return data.data();
				}
			};
			template<typename T>
			struct get_dimension_num<std::vector<T> > {
			private:
				typedef std::vector<T> data_type;
				typedef typename savage::shader::datas::traits::
					dimension_num_type<data_type>::type dimension_num_type;
			public:
				static dimension_num_type call(const data_type& data) {
					return 2;//TODO
				}
			};
		}// namespace policy
	}//namespace datas
}// namespace shader
}// namespace savage
#endif //SAVAGE_SHADER_ADAPTED_STD_VECTOR_AS_DATA_H
