#include <stdint.h>


#define PLACEHOLDER(n,name)  uint8_t name[(n)]

struct mmio
{
    PLACEHOLDER(1,start); 
    PLACEHOLDER(1,state); 
    uint16_t PlainTextPointer;
    uint16_t EncryptLength;
    PLACEHOLDER(10,empty);
    uint32_t  EncryptKey[4];
    uint32_t  EncryptCtr[4];
};

struct AES_parameter
{
    uint32_t * PlainTextPointer;
    uint16_t EncryptLength;
    uint32_t  EncryptKey[4];
    uint32_t  EncryptCtr[4];
};


void ToFunctionArg(struct mmio *m, struct AES_parameter *p, uint8_t * buffer);
void ToMemoryMap(struct AES_parameter *p, struct mmio *m);
void loadFromMem(uint32_t *memAddr, uint32_t dest[]);
void storeToMem(uint32_t *memAddr, uint32_t src[]);
void memory_move(uint32_t src[], uint32_t dest[], int len);

