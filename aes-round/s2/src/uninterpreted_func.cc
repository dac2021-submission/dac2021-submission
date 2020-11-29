#include "AES.h"

uint128_t AES::aes128(uint128_t arg_0, uint128_t arg_1) {
  uint32_t output[4] = {0, 0, 0, 0};
  uint32_t key[4] = {0, 0, 0, 0};
  // std::cout << "arg0: " << arg_0 << std::endl;
  // std::cout << "arg1: " << arg_1 << std::endl;
  uint128_t mask = 0xff; 
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      uint32_t tmp = (uint32_t) ((arg_0 >> (i * 32 + j * 8)) & mask);
      output[3 - i] += (tmp << ((3 - j) * 8)); 
      // std::cout << "tmp[" << i << ", " << j << "] = " << tmp << std::endl; 
      tmp = (uint32_t) ((arg_1 >> (i * 32 + j * 8)) & mask);
      key[3 - i] += (tmp << ((3 - j) * 8));
    }
    // std::cout << "output[" << 3 - i << "] = " << output[3 - i] << std::endl;
  }
//   for (int i = 0; i < 4; i++) {
//     std::cout << "arg_0[" << i << "]: " << (uint32_t) ((arg_0 >> (32*i)) & (0xffffffff)) << std::endl;
//     std::cout << "arg_1[" << i << "]: " << (uint32_t) ((arg_1 >> (32*i)) & (0xffffffff)) << std::endl;
//     std::cout << "i output[" << i << "]: " << output[i] << std::endl;
//     std::cout << "i key[" << i << "]: " << key[i] << std::endl;
//   }
  encrypt_128_key_expand_inline_no_branch(output, key);
  uint128_t result;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      uint128_t tmp = output[i];
      tmp = tmp >> (j * 8);
      tmp = tmp & (0xff);
      result += tmp << ((3-i)*32 + (3-j)*8);

    }
  }
//   for (int i = 0; i < 4; i++) {
//     std::cout << "result[" << i << "]: " << (uint32_t) ((result_1 >> (32*i)) & (0xffffffff)) << std::endl;
//     std::cout << "i output[" << i << "]: " << output[i] << std::endl;
//   }  
  return result;
}