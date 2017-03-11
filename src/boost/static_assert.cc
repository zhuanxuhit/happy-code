#include <boost/static_assert.hpp>
#include <cstdint>


class Timestamp
{
private:
	int64_t microSecondsSinceEpoch_;
};
// 编译时就可以检查
// assert则是运行时检查
BOOST_STATIC_ASSERT(sizeof(Timestamp) == sizeof(int64_t));
//BOOST_STATIC_ASSERT(sizeof(int) == sizeof(short));

int main(void)
{
	return 0;
}
