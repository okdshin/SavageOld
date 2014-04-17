#ifndef SAVAGE_DATA_HELPER_H
#define SAVAGE_DATA_HELPER_H
//20140410

#define SAVAGE_DEFINE_DATA_TYPE_TRAITS_AND_POLICY(LowerOwnerName, CapitalOwnerName, AttributeName) \
namespace savage { \
	namespace LowerOwnerName##s { \
		namespace type_traits { \
			template<typename CapitalOwnerName> \
			struct AttributeName { \
				typedef typename CapitalOwnerName::AttributeName##_type type; \
			}; \
		} \
		namespace policy { \
			template<typename CapitalOwnerName> \
			struct get_##AttributeName { \
				static typename savage::LowerOwnerName##s::type_traits:: \
					AttributeName<CapitalOwnerName>::type \
				call(const CapitalOwnerName& LowerOwnerName) { \
					return LowerOwnerName.get_##AttributeName(); \
				} \
			}; \
		} \
		template<typename CapitalOwnerName> \
		typename savage::LowerOwnerName##s::type_traits:: \
			AttributeName<CapitalOwnerName>::type \
		get_##AttributeName(const CapitalOwnerName& LowerOwnerName) { \
			return savage::LowerOwnerName##s::policy:: \
				get_##AttributeName<CapitalOwnerName>::call(LowerOwnerName); \
		} \
		using savage::LowerOwnerName##s::type_traits::AttributeName; \
		using savage::LowerOwnerName##s::get_##AttributeName; \
	} \
}

#endif //SAVAGE_DATA_HELPER_H
