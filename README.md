# RGB - HSV Fantastic Converter

The library contains structures and functions dedicated to calculate RGB values of colours to HSV values of colours and vice versa.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to use the library in your project.

### Prerequisites

* cmake
* google test [Install Guide](https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu)
* compiler supporting C++11

### Installing

```
$ git clone https://github.com/Agata-Les/rgb-hsv-fantastic-converter
$ cd rgb-hsv-fantastic-converter
$ cmake .
$ make
$ ./example
```

## Running the tests

```
$ make
$ ./runTests
```

## Deployment

If you are willing to use the library you need to:
* if you use Cmake add `target_link_libraries(example rgb-hsv-fantastic-converter)`
* if you use pure g++ commands add flag `-l rgb-hsv-fantastic-converter`

Ensure that include file `rgb_hsv_converter.h` is present in your project include path.

## Authors

* **Agata Les** - [Agata-Les](https://github.com/Agata-Les)

Special thanks to [Kamil Mowinski](https://github.com/Mowinski) who reviewed this project.

## License

This project is licensed under the Apache License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* Insights worth checking: [HSV - RGB Conversion Algorithms](http://dystopiancode.blogspot.com/2012/06/hsv-rgb-conversion-algorithms-in-c.html)
