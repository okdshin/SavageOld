#ifndef SAVAGE_WINDOW_SIZE_ADAPTED_SAVAGE_H
#define SAVAGE_WINDOW_SIZE_ADAPTED_SAVAGE_H
//20140410
namespace savage { namespace window_sizes {
	namespace adapted { namespace savage {
		class window_size {
		public:
			typedef int width_type;
			typedef int height_type;
			window_size(width_type width, height_type height) :
				width_(width), height_(height){}
			width_type get_width() const {
				return width_;
			}
			height_type get_height() const {
				return height_;
			}
		private:
			width_type width_;
			height_type height_;
		};
	}// namespace savage
	}// namespace adapted
}// namespace window_sizes
}// namespace savage

#endif //SAVAGE_WINDOW_SIZE_ADAPTED_SAVAGE_H
