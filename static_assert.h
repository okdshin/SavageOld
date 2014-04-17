#ifndef SAVAGE_STATIC_ASSERT_H
#define SAVAGE_STATIC_ASSERT_H
#include <boost/mpl/assert.hpp>
#include <boost/type_traits.hpp>
//20140326

#define SAVAGE_STATIC_ASSERT_MSG(Expr, Message) \
	BOOST_MPL_ASSERT_MSG(Expr, Message, (void))
#define SAVAGE_NOT_IMPLEMENTED_ERROR_STATIC_ASSERT \
	SAVAGE_STATIC_ASSERT_MSG(false, NOT_IMPLEMENTED)

#endif //SAVAGE_STATIC_ASSERT_H
