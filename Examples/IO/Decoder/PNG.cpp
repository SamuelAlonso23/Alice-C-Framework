#include <iostream>
#include <IO/Decoder/PNG.hpp>

void PNGDecoderTest()
{
    Alice::IO::Decoder::PNG i("insert your windows png file path, like C:\\image01.png   ");
    std::cout << std::boolalpha;
    std::cout << "Overflow? " << i.PixelOverflow() << std::endl;
    std::cout << "Magic number? " << i.IsMagic() << std::endl;
    std::cout << "IHDR section? " << i.HasIHDR() << std::endl;
    std::cout << "Correct header size? " << i.CorrectHeaderSize() << std::endl;
    std::cout << "Correct color bit? " << i.ColorBit() << std::endl;
    std::cout << "Checksum correct? " << i.CheckChecksum() << std::endl;
    std::cout << "Width: " << i.Width() << std::endl;
    std::cout << "Height: " << i.Height() << std::endl;
    std::cout << "Bytes: " << i.TotalOfBytes() << std::endl;
    std::cout << "Number of pixels: " << i.NumberOfPixels() << std::endl;
    std::cout << "Bit depth: " << static_cast<u16>(i.BitDepth()) << std::endl;
    std::cout << "Bits per pixel: " << i.BitsPerPixel() << std::endl;
    std::cout << "Checksum: " << i.Checksum() << std::endl;
    std::cout << "Crc32: " << i.Crc32() << std::endl;
    std::cout << "Color type: " << static_cast<u16>(i.ColorType()) << std::endl;
    std::cout << "Compression method: " << static_cast<u16>(i.Compression()) << std::endl;
    std::cout << "Filter method: " << static_cast<u16>(i.Filter()) << std::endl;
    std::cout << "Interlace method: " << static_cast<u16>(i.Interlace()) << std::endl;
    char c;
    std::cin >> c;
}
