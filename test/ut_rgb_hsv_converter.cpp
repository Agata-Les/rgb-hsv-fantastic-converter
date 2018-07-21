#include "rgb_hsv_converter.h"
#include <gtest/gtest.h>
#include <utility>
#include <vector>

namespace constant
{
	const std::pair<RGB, HSV> black = { {0, 0, 0}, {0, 0, 0} };
	const std::pair<RGB, HSV> white = { {255, 255, 255}, {0, 0, 100} };
	const std::pair<RGB, HSV> red = { {255, 0, 0}, {0, 100, 100} };
	const std::pair<RGB, HSV> green = { {0, 255, 0}, {120, 100, 100} };
	const std::pair<RGB, HSV> blue = { {0, 0, 255}, {240, 100, 100} };
	const std::pair<RGB, HSV> dummy_colour = { {138, 16, 212}, {277, 92.5, 83.1} };
	const std::pair<RGB, HSV> wrongConvertion = { {255, 255, 255}, {0, 0, 0} };
	const std::vector<std::pair<RGB, HSV>> correctInputs { black, white, red, green, blue, dummy_colour };
}

class ut_rgb_hsv_converter : public ::testing::TestWithParam<std::pair<RGB, HSV>>
{
};

TEST_P(ut_rgb_hsv_converter, convert_RGB_to_HSV_correct_values)
{
	HSV temp = convert_RGB_to_HSV(GetParam().first);
	EXPECT_EQ(convert_RGB_to_HSV(GetParam().first), GetParam().second);
}

TEST(ut_rgb_hsv_converter, convert_RGB_to_HSV_incorrect_values)
{
	EXPECT_NE(convert_RGB_to_HSV(constant::wrongConvertion.first), constant::wrongConvertion.second);
}

INSTANTIATE_TEST_CASE_P(RGB_HSV_colours,
                        ut_rgb_hsv_converter,
                        ::testing::ValuesIn(constant::correctInputs));
