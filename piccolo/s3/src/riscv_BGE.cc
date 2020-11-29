#include "riscv.h"
void riscv::decode_riscv_BGE_update() {
  uint5_t tmp_19 = 0 - 1;
  c_19 = static_cast<uint5_t> ((riscv_inst >> 15) & tmp_19);
  c_353 = c_19 == 31;
  c_348 = c_19 == 30;
  c_343 = c_19 == 29;
  c_338 = c_19 == 28;
  c_333 = c_19 == 27;
  c_328 = c_19 == 26;
  c_323 = c_19 == 25;
  c_318 = c_19 == 24;
  c_313 = c_19 == 23;
  c_308 = c_19 == 22;
  c_303 = c_19 == 21;
  c_298 = c_19 == 20;
  c_293 = c_19 == 19;
  c_288 = c_19 == 18;
  c_283 = c_19 == 17;
  c_278 = c_19 == 16;
  c_273 = c_19 == 15;
  c_268 = c_19 == 14;
  c_263 = c_19 == 13;
  c_258 = c_19 == 12;
  c_253 = c_19 == 11;
  c_248 = c_19 == 10;
  c_243 = c_19 == 9;
  c_238 = c_19 == 8;
  c_233 = c_19 == 7;
  c_228 = c_19 == 6;
  c_223 = c_19 == 5;
  c_218 = c_19 == 4;
  c_213 = c_19 == 3;
  c_208 = c_19 == 2;
  c_203 = c_19 == 1;
  c_205 = (c_203) ? riscv_x1 : 0;
  c_210 = (c_208) ? riscv_x2 : c_205;
  c_215 = (c_213) ? riscv_x3 : c_210;
  c_220 = (c_218) ? riscv_x4 : c_215;
  c_225 = (c_223) ? riscv_x5 : c_220;
  c_230 = (c_228) ? riscv_x6 : c_225;
  c_235 = (c_233) ? riscv_x7 : c_230;
  c_240 = (c_238) ? riscv_x8 : c_235;
  c_245 = (c_243) ? riscv_x9 : c_240;
  c_250 = (c_248) ? riscv_x10 : c_245;
  c_255 = (c_253) ? riscv_x11 : c_250;
  c_260 = (c_258) ? riscv_x12 : c_255;
  c_265 = (c_263) ? riscv_x13 : c_260;
  c_270 = (c_268) ? riscv_x14 : c_265;
  c_275 = (c_273) ? riscv_x15 : c_270;
  c_280 = (c_278) ? riscv_x16 : c_275;
  c_285 = (c_283) ? riscv_x17 : c_280;
  c_290 = (c_288) ? riscv_x18 : c_285;
  c_295 = (c_293) ? riscv_x19 : c_290;
  c_300 = (c_298) ? riscv_x20 : c_295;
  c_305 = (c_303) ? riscv_x21 : c_300;
  c_310 = (c_308) ? riscv_x22 : c_305;
  c_315 = (c_313) ? riscv_x23 : c_310;
  c_320 = (c_318) ? riscv_x24 : c_315;
  c_325 = (c_323) ? riscv_x25 : c_320;
  c_330 = (c_328) ? riscv_x26 : c_325;
  c_335 = (c_333) ? riscv_x27 : c_330;
  c_340 = (c_338) ? riscv_x28 : c_335;
  c_345 = (c_343) ? riscv_x29 : c_340;
  c_350 = (c_348) ? riscv_x30 : c_345;
  c_355 = (c_353) ? riscv_x31 : c_350;
  uint5_t tmp_21 = 0 - 1;
  c_21 = static_cast<uint5_t> ((riscv_inst >> 20) & tmp_21);
  c_510 = c_21 == 31;
  c_505 = c_21 == 30;
  c_500 = c_21 == 29;
  c_495 = c_21 == 28;
  c_490 = c_21 == 27;
  c_485 = c_21 == 26;
  c_480 = c_21 == 25;
  c_475 = c_21 == 24;
  c_470 = c_21 == 23;
  c_465 = c_21 == 22;
  c_460 = c_21 == 21;
  c_455 = c_21 == 20;
  c_450 = c_21 == 19;
  c_445 = c_21 == 18;
  c_440 = c_21 == 17;
  c_435 = c_21 == 16;
  c_430 = c_21 == 15;
  c_425 = c_21 == 14;
  c_420 = c_21 == 13;
  c_415 = c_21 == 12;
  c_410 = c_21 == 11;
  c_405 = c_21 == 10;
  c_400 = c_21 == 9;
  c_395 = c_21 == 8;
  c_390 = c_21 == 7;
  c_385 = c_21 == 6;
  c_380 = c_21 == 5;
  c_375 = c_21 == 4;
  c_370 = c_21 == 3;
  c_365 = c_21 == 2;
  c_360 = c_21 == 1;
  c_362 = (c_360) ? riscv_x1 : 0;
  c_367 = (c_365) ? riscv_x2 : c_362;
  c_372 = (c_370) ? riscv_x3 : c_367;
  c_377 = (c_375) ? riscv_x4 : c_372;
  c_382 = (c_380) ? riscv_x5 : c_377;
  c_387 = (c_385) ? riscv_x6 : c_382;
  c_392 = (c_390) ? riscv_x7 : c_387;
  c_397 = (c_395) ? riscv_x8 : c_392;
  c_402 = (c_400) ? riscv_x9 : c_397;
  c_407 = (c_405) ? riscv_x10 : c_402;
  c_412 = (c_410) ? riscv_x11 : c_407;
  c_417 = (c_415) ? riscv_x12 : c_412;
  c_422 = (c_420) ? riscv_x13 : c_417;
  c_427 = (c_425) ? riscv_x14 : c_422;
  c_432 = (c_430) ? riscv_x15 : c_427;
  c_437 = (c_435) ? riscv_x16 : c_432;
  c_442 = (c_440) ? riscv_x17 : c_437;
  c_447 = (c_445) ? riscv_x18 : c_442;
  c_452 = (c_450) ? riscv_x19 : c_447;
  c_457 = (c_455) ? riscv_x20 : c_452;
  c_462 = (c_460) ? riscv_x21 : c_457;
  c_467 = (c_465) ? riscv_x22 : c_462;
  c_472 = (c_470) ? riscv_x23 : c_467;
  c_477 = (c_475) ? riscv_x24 : c_472;
  c_482 = (c_480) ? riscv_x25 : c_477;
  c_487 = (c_485) ? riscv_x26 : c_482;
  c_492 = (c_490) ? riscv_x27 : c_487;
  c_497 = (c_495) ? riscv_x28 : c_492;
  c_502 = (c_500) ? riscv_x29 : c_497;
  c_507 = (c_505) ? riscv_x30 : c_502;
  c_512 = (c_510) ? riscv_x31 : c_507;
  c_580 = c_355 == c_512;
  c_582 = c_355 > c_512;
  c_584 = (c_580 | c_582);
  uint1_t tmp_45 = 0 - 1;
  c_45 = static_cast<uint1_t> ((riscv_inst >> 31) & tmp_45);
  uint1_t tmp_47 = 0 - 1;
  c_47 = static_cast<uint1_t> ((riscv_inst >> 7) & tmp_47);
  uint6_t tmp_49 = 0 - 1;
  c_49 = static_cast<uint6_t> ((riscv_inst >> 25) & tmp_49);
  uint4_t tmp_51 = 0 - 1;
  c_51 = static_cast<uint4_t> ((riscv_inst >> 8) & tmp_51);
  c_59 = (static_cast<uint5_t>(c_51) << 1) + (static_cast<uint5_t>(0));
  c_65 = (static_cast<uint11_t>(c_49) << 5) + (static_cast<uint11_t>(c_59));
  c_71 = (static_cast<uint12_t>(c_47) << 11) + (static_cast<uint12_t>(c_65));
  c_77 = (static_cast<uint13_t>(c_45) << 12) + (static_cast<uint13_t>(c_71));
  c_79 = static_cast<uint32_t>(c_77);
  c_79 = (c_77 >> 12) ? static_cast<uint32_t>(~c_77) : static_cast<uint32_t>(c_77);
  c_79 = (c_77 >> 12) ? (~c_79) : c_79;
  c_513 = (riscv_pc + c_79);
  c_516 = (riscv_pc + 4);
  c_585 = (c_584) ? c_513 : c_516;
  riscv_pc_next = c_585;
};
