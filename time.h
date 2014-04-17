#ifndef SAVAGE_TIME_H
#define SAVAGE_TIME_H
//20140411

namespace savage {
	namespace times {
		namespace type_traits {
			template<typename Time>
			struct second {
				typedef typename Time::second_type type;
			};
		}// namespace type_traits
		using savage::times::type_traits::second;
		namespace policy {
			template<typename Time>
			struct get_seconds {
				static typename savage::times::second<Time>::type
				call(const Time& time) {
					return time.get_seconds();
				}
			};
		}// namespace policy
		template<typename Time>
		typename savage::times::second<Time>::type
		get_seconds(const Time& time) {
			return savage::times::policy::get_seconds<Time>::call(time);
		}
		namespace adapted { namespace savage {
			class time {
			public:
				typedef double second_type;
				time(double seconds) : seconds_(seconds) {}
				second_type get_seconds() const {
					return seconds_;
				}
			private:
				second_type seconds_;
			};
		}// namesapce savage
		}// namespace adapted
	}// namespace times
	using savage::times::adapted::savage::time;
}// namespace savage

#endif //SAVAGE_TIME_H
