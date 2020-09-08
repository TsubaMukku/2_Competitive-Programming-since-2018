/*
cited from https://www.codewars.com/kata/5efae11e2d12df00331f91a6/solutions
just for my personal studying
*/

#include <openssl/md5.h>
#include <iomanip>

std::string md5(const std::string& pin) 
{
    unsigned char ucPin[8];
    std::copy(pin.begin(), pin.end(), ucPin);
    ucPin[pin.length()] = 0;
  
    unsigned char result[MD5_DIGEST_LENGTH];
    MD5(ucPin, pin.length(), result);
  
    std::ostringstream sout;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
        sout << std::hex << std::setw(2) << std::setfill('0') << static_cast<short>(result[i]);
  
    return sout.str();
}

std::string crack(const std::string& hash) 
{
    for (int i=1; i < 100000; ++i)
    {
        std::string d = std::to_string(i);
        std::string str = std::string(5 - d.length(), '0') + d;
        if (md5(str) == hash)
            return str;
    }
    return std::string("00000");
}
