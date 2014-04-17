#ifndef SAVAGE_CURSOR_POSITION_ADAPTED_CURSOR_POSITION_H
#define SAVAGE_CURSOR_POSITION_ADAPTED_CURSOR_POSITION_H
//20140410
namespace savage { namespace cursor_positions {
	namespace adapted { namespace savage {
		class cursor_position {
		public:
			typedef double x_type;
			typedef double y_type;
			cursor_position(x_type x, y_type y) : x_(x), y_(y) {}
			x_type get_x() const {
				return x_;
			}
			y_type get_y() const {
				return y_;
			}
		private:
			x_type x_;
			y_type y_;
		};
	}// namespace savage
	}// namespace adapted
}// namespace cursor_positions
}// namespace savage
#endif //SAVAGE_CURSOR_POSITION_ADAPTED_CURSOR_POSITION_H
