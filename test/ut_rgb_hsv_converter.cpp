#include "rgb_hsv_converter.h"
#include <gtest/gtest.h>
#include <utility>

namespace constant
{
	const std::pair<RGB, HSV> black = { {0, 0, 0}, {0, 0, 0} };
	const std::vector<std::pair<RGB, HSV>> correctInputs { black };
}

class ut_rgb_hsv_converter : public ::testing::TestWithParam<std::pair<RGB, HSV>>
{
};

TEST_P(ut_rgb_hsv_converter, convert_RGB_to_HSV_correct_values)
{
	EXPECT_EQ(convert_RGB_to_HSV(GetParam().first), GetParam().second);
}

INSTANTIATE_TEST_CASE_P(RGB_HSV_colours,
                        ut_rgb_hsv_converter,
                        ::testing::ValuesIn(constant::correctInputs));
