// ILA@SYN_BACKGROUND

#include "stdio.h"
#include "stdlib.h"
#include "AES_impl.h"

void encrypt_128_key_expand_inline_no_branch(word state[], word key[]) {
    int nr = 10;
    int i;
    word k0 = key[0], k1 = key[1], k2 = key[2], k3 = key[3];
    state[0] ^= k0;
    state[1] ^= k1;
    state[2] ^= k2;
    state[3] ^= k3;
    word *t0 = (word *)table_0;
    word p0, p1, p2, p3;
    byte *b;
    byte rcon = 1;

    for(i=1; i<nr; i++) {
        word temp = k3;
        rot_down_8(temp);
        sub_byte(temp);
        temp ^= rcon;
        int j = (char)rcon;
        j <<= 1;
        j ^= (j >> 8) & 0x1B; // if (rcon&0x80 != 0) then (j ^= 0x1B)
        rcon = (byte)j;
        k0 ^= temp;
        k1 ^= k0;
        k2 ^= k1;
        k3 ^= k2;
        word z0 = k0, z1 = k1, z2 = k2, z3 = k3;
        b = (byte *)state; table_lookup; rot;
        z0 ^= p0, z3 ^= p1, z2 ^= p2, z1 ^= p3;
        b += 4; table_lookup; rot;
        z1 ^= p0, z0 ^= p1, z3 ^= p2, z2 ^= p3;
        b += 4; table_lookup; rot;
        z2 ^= p0, z1 ^= p1, z0 ^= p2, z3 ^= p3;
        b += 4; table_lookup; rot;
        state[0] = z0 ^ p3;
        state[1] = z1 ^ p2;
        state[2] = z2 ^ p1;
        state[3] = z3 ^ p0;
    }
    word temp = k3;
    rot_down_8(temp);
    sub_byte(temp);
    temp ^= rcon;
    k0 ^= temp;
    k1 ^= k0;
    k2 ^= k1;
    k3 ^= k2;
    byte *a = (byte *)state, *t = table_0;
    b = (byte *)&k0;
    b[0] ^= t[a[0]*4], b[1] ^= t[a[5]*4], b[2] ^= t[a[10]*4], b[3] ^= t[a[15]*4];
    b = (byte *)&k1;
    b[0] ^= t[a[4]*4], b[1] ^= t[a[9]*4], b[2] ^= t[a[14]*4], b[3] ^= t[a[3]*4];
    b = (byte *)&k2;
    b[0] ^= t[a[8]*4], b[1] ^= t[a[13]*4], b[2] ^= t[a[2]*4], b[3] ^= t[a[7]*4];
    b = (byte *)&k3;
    b[0] ^= t[a[12]*4], b[1] ^= t[a[1]*4], b[2] ^= t[a[6]*4], b[3] ^= t[a[11]*4];
    state[0] = k0;
    state[1] = k1;
    state[2] = k2;
    state[3] = k3;
}

void AES_block_encrypt(uint32_t key[4], uint32_t plaintext[4], uint32_t output[4])
{
    memory_move(plaintext,output,4);
    encrypt_128_key_expand_inline_no_branch(output,key);    
}

void inc(uint32_t cnt[],int len, int value)
{
    uint32_t carry = value;     // add one
    int i;
    for(i=0; i<len; i++)  // LITTLE-Endian
    {
    	if(carry==0)
    		break;
        if (cnt[i] >= (uint32_t)(-value) )
        {
            cnt[i] = 0;
            carry = 1;
        }
        else
        {
            cnt[i] = cnt[i] + carry;
            carry = 0;
        }
    }
}

void c_xor(uint32_t in1[],uint32_t in2[],uint32_t out[],int len)
{
    int i;
    for(i=0;i<len;i++)
        out[i] = in1[i] ^ in2[i];
}


//##LABEL##@_global##//

void AES_CTR_start(struct AES_parameter param)
{
    uint32_t key[4];
    uint32_t plaintext[4];
    uint32_t tmp_result[4];
    uint32_t final_result[4];
    uint32_t AES_ctr[4];
    int byteCount;
    
    memory_move(param.EncryptKey,key,4);
    memory_move(param.EncryptCtr,AES_ctr,4);

    for( byteCount = 0; byteCount <= param.EncryptLength;  byteCount += 16)
    {
		//##LABEL##@_ILA_aes_step_1##//
        loadFromMem(param.PlainTextPointer + byteCount/4, plaintext ); // PlainTextPointer is a word pointer !!
		//##LABEL##@_ILA_aes_step_2##//
        AES_block_encrypt(key,AES_ctr,tmp_result);
        c_xor(tmp_result,plaintext,final_result,4);
		//##LABEL##@_ILA_aes_step_3##//
        storeToMem(param.PlainTextPointer + byteCount/4, final_result );
        inc(AES_ctr,4,16); // Increase a micro-arch state, in Verilog, no such states
    }
    
    byteCount -= 16;
    //##LABEL##@_ILA_aes_end##//
}

// dummy main for running the code
// also to make the interface as a memory-mapping interface


void c_model::c_run(uint8_t cmd, uint16_t cmdaddr, uint8_t cmddata)
{
	    //##LABEL##@_ILA_aes_top_0##//
    pc += 1;
	uint8_t * p = (uint8_t *) & mmport;

	if(cmdaddr >= 0xff00 && cmdaddr < 0xff40)
	{
		if(cmd == 2)
			p[(cmdaddr-0xff00)] = cmddata;
	// here we convert mmio -> function parameter
		ToFunctionArg(&mmport, &param, buffer);
		if(cmd == 2 && cmdaddr == 0xff00 && cmddata == 1)
		    AES_CTR_start(param); // let's start
		ToMemoryMap(&param, &mmport);
	}
	    //##LABEL##@_ILA_aes_end##//	
	return;
}

