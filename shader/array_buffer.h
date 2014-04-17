#ifndef SAVAGE_SHADER_ARRAY_BUFFER_H
#define SAVAGE_SHADER_ARRAY_BUFFER_H
//20140405
namespace savage { namespace shader {
	namespace array_buffers {
		namespace traits {
			//nothing
		}// namespace traits
		namespace policy {
			template<typename ArrayBuffer, typename Program, 
				typename Index, typename Name, typename Hint, typename Data>
			struct initialize {
			private:
				typedef ArrayBuffer array_buffer_type;
				typedef Program program_type;
				typedef Index index_type;
				typedef Name name_type;
				typedef Hint hint_type;
				typedef Data data_type;
			public:
				static void call(array_buffer_type& array_buffer, program_type& program, 
						index_type index, const name_type& name, hint_type hint,
						const data_type& data) {
					array_buffer.initialize(program, index, name, hint, data);
				}
			};
		}// namespace policy
		template<typename ArrayBuffer, typename Program, 
			typename Index, typename Name, typename Hint, typename Data>
		void initialize(ArrayBuffer& array_buffer, Program& program,
				Index index, const Name& name, Hint hint, const Data& data) {
			savage::shader::array_buffers::policy::
				initialize<ArrayBuffer, Program, Index, Name, Hint, Data>::call(
						array_buffer, program, index, name, hint, data);
		}
	}// namespace array_buffers
	using savage::shader::array_buffers::initialize;
}// namespace savage
}// namespace shader
#endif //SAVAGE_SHADER_ARRAY_BUFFER_H
