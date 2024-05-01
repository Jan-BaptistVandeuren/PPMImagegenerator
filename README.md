# PPMImagegenerator
Generates a PPM image

You can build the program with cmake
```plaintext
cmake --build build --config release
```

You use this executable with the following command on windows
```plaintext
build\Release\PPMImagegenerator.exe > output\image.ppm
```
You use this with the following command on mac and Linux (untested but should work)
```plaintext
build/PPMImagegenerator.exe > output\image.ppm
```


## PPM File Structure (AI Generated Explanation)

1. **Magic Number**
    - The first line of a PPM file is the magic number, which identifies the file type. For a PPM file, this is either `P3` for an ASCII (plain text) file or `P6` for a binary file.

2. **Dimensions**
    - The second line contains two integers, separated by a space. These represent the width and height of the image, respectively.

3. **Maximum Color Value**
    - The third line contains a single integer, representing the maximum color value. This is typically `255` for an 8-bit per channel image.

4. **Pixel Data**
    - The rest of the file contains the pixel data. Each pixel is represented by three integers (for red, green, and blue channels), each in the range of `0` to the maximum color value. In a `P3` (ASCII) file, these values are in plain text and separated by whitespace. In a `P6` (binary) file, these values are stored as binary data. Here we will be using P3.

Here's an example of what a small `P3` PPM file might look like:

```plaintext
P3
3 2
255
255 0 0   0 255 0   0 0 255
255 255 0 255 255 255 0 0 0
```

This represents a `3x2` pixel image. The first row of pixels is red, green, and blue. The second row is yellow, white, and black. 