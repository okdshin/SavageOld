#ifndef SAVAGE_SHADER_DATA_H
#define SAVAGE_SHADER_DATA_H
//20140407

namespace savage { namespace shader { 
	namespace datas {
		namespace traits {
			template<typename Data>
			struct size_type {
			private:
				typedef Data data_type;
			public:
				typedef std::size_t type;
			};
			template<typename Data>
			struct pointer_type {
			private:
				typedef Data data_type;
			public:
				typedef typename data_type::pointer_type type;
			};
			template<typename Data>
			struct dimension_num_type {
			private:
				typedef Data data_type;
			public:
				typedef std::size_t type;
			};
		}//namespace traits
		namespace policy {
			template<typename Data>
			struct get_byte_size {
			private:
				typedef Data data_type;
				typedef typename savage::shader::datas::traits::
					size_type<data_type>::type size_type;
			public:
				static size_type call(const data_type& data) {
					return data.get_byte_size();
				}
			};
			template<typename Data>
			struct get_pointer {
			private:
				typedef Data data_type;
				typedef typename savage::shader::datas::traits::
					pointer_type<data_type>::type pointer_type;
			public:
				static pointer_type call(const data_type& data) {
					return data.get_pointer();
				}
			};
			template<typename Data>
			struct get_dimension_num {
			private:
				typedef Data data_type;
				typedef typename savage::shader::datas::traits::
					dimension_num_type<data_type>::type dimension_num_type;
			public:
				static dimension_num_type call(const data_type& data) {
					return data.get_dimension_num();
				}
			};
		}// namespace policy
		template<typename Data>
		typename savage::shader::datas::traits::size_type<Data>::type
		get_byte_size(const Data& data) {
			return savage::shader::datas::policy::get_byte_size<Data>::call(data);
		}
		template<typename Data>
		typename savage::shader::datas::traits::pointer_type<Data>::type
		get_pointer(const Data& data) {
			return savage::shader::datas::policy::get_pointer<Data>::call(data);
		}
		template<typename Data>
		typename savage::shader::datas::traits::dimension_num_type<Data>::type
		get_dimension_num(const Data& data) {
			return savage::shader::datas::policy::get_dimension_num<Data>::call(data);
		}
	}// namespace datas
}// namespace shader
}// namespace savage

#endif //SAVAGE_SHADER_DATA_H
