#include "rgb_hsv_converter.h"
#include <gtest/gtest.h>
#include <utility>

namespace constant
{
	const std::pair<RGB, HSV> black = { {0, 0, 0}, {0, 0, 0} };
	const std::pair<RGB, HSV> white = { {255, 255, 255}, {0, 0, 100} };
	const std::pair<RGB, HSV> red = { {255, 0, 0}, {0, 100, 100} };
	const std::pair<RGB, HSV> green = { {0, 255, 0}, {120, 100, 100} };
	const std::pair<RGB, HSV> blue = { {0, 0, 255}, {240, 100, 100} };
	const std::vector<std::pair<RGB, HSV>> correctInputs { black, white, red, green, blue };
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
