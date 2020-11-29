#include "riscv.h"
void riscv::decode_riscv_LBU_update() {
  c_1095 = (riscv_pc + 4);
  riscv_pc_next = c_1095;
  riscv_x0_next = 0;
  uint5_t tmp_17 = 0 - 1;
  c_17 = static_cast<uint5_t> ((riscv_inst >> 7) & tmp_17);
  c_1901 = c_17 == 1;
  uint5_t tmp_19 = 0 - 1;
  c_19 = static_cast<uint5_t> ((riscv_inst >> 15) & tmp_19);
  c_1085 = c_19 == 31;
  c_1080 = c_19 == 30;
  c_1075 = c_19 == 29;
  c_1070 = c_19 == 28;
  c_1065 = c_19 == 27;
  c_1060 = c_19 == 26;
  c_1055 = c_19 == 25;
  c_1050 = c_19 == 24;
  c_1045 = c_19 == 23;
  c_1040 = c_19 == 22;
  c_1035 = c_19 == 21;
  c_1030 = c_19 == 20;
  c_1025 = c_19 == 19;
  c_1020 = c_19 == 18;
  c_1015 = c_19 == 17;
  c_1010 = c_19 == 16;
  c_1005 = c_19 == 15;
  c_1000 = c_19 == 14;
  c_995 = c_19 == 13;
  c_990 = c_19 == 12;
  c_985 = c_19 == 11;
  c_980 = c_19 == 10;
  c_975 = c_19 == 9;
  c_970 = c_19 == 8;
  c_965 = c_19 == 7;
  c_960 = c_19 == 6;
  c_955 = c_19 == 5;
  c_950 = c_19 == 4;
  c_945 = c_19 == 3;
  c_940 = c_19 == 2;
  c_935 = c_19 == 1;
  c_937 = (c_935) ? riscv_x1 : 0;
  c_942 = (c_940) ? riscv_x2 : c_937;
  c_947 = (c_945) ? riscv_x3 : c_942;
  c_952 = (c_950) ? riscv_x4 : c_947;
  c_957 = (c_955) ? riscv_x5 : c_952;
  c_962 = (c_960) ? riscv_x6 : c_957;
  c_967 = (c_965) ? riscv_x7 : c_962;
  c_972 = (c_970) ? riscv_x8 : c_967;
  c_977 = (c_975) ? riscv_x9 : c_972;
  c_982 = (c_980) ? riscv_x10 : c_977;
  c_987 = (c_985) ? riscv_x11 : c_982;
  c_992 = (c_990) ? riscv_x12 : c_987;
  c_997 = (c_995) ? riscv_x13 : c_992;
  c_1002 = (c_1000) ? riscv_x14 : c_997;
  c_1007 = (c_1005) ? riscv_x15 : c_1002;
  c_1012 = (c_1010) ? riscv_x16 : c_1007;
  c_1017 = (c_1015) ? riscv_x17 : c_1012;
  c_1022 = (c_1020) ? riscv_x18 : c_1017;
  c_1027 = (c_1025) ? riscv_x19 : c_1022;
  c_1032 = (c_1030) ? riscv_x20 : c_1027;
  c_1037 = (c_1035) ? riscv_x21 : c_1032;
  c_1042 = (c_1040) ? riscv_x22 : c_1037;
  c_1047 = (c_1045) ? riscv_x23 : c_1042;
  c_1052 = (c_1050) ? riscv_x24 : c_1047;
  c_1057 = (c_1055) ? riscv_x25 : c_1052;
  c_1062 = (c_1060) ? riscv_x26 : c_1057;
  c_1067 = (c_1065) ? riscv_x27 : c_1062;
  c_1072 = (c_1070) ? riscv_x28 : c_1067;
  c_1077 = (c_1075) ? riscv_x29 : c_1072;
  c_1082 = (c_1080) ? riscv_x30 : c_1077;
  c_1087 = (c_1085) ? riscv_x31 : c_1082;
  uint12_t tmp_29 = 0 - 1;
  c_29 = static_cast<uint12_t> ((riscv_inst >> 20) & tmp_29);
  c_31 = static_cast<uint32_t>(c_29);
  c_31 = (c_29 >> 11) ? static_cast<uint32_t>(~c_29) : static_cast<uint32_t>(c_29);
  c_31 = (c_29 >> 11) ? (~c_31) : c_31;
  c_1088 = (c_1087 + c_31);
  uint2_t tmp_1862 = 0 - 1;
  c_1862 = static_cast<uint2_t> ((c_1088 >> 0) & tmp_1862);
  c_1894 = c_1862 == 0;
  uint14_t tmp_1089 = 0 - 1;
  c_1089 = static_cast<uint14_t> ((c_1088 >> 2) & tmp_1089);
  c_1091 = riscv_mem[static_cast<uint32_t> (c_1089)];
  uint8_t tmp_1888 = 0 - 1;
  c_1888 = static_cast<uint8_t> ((c_1091 >> 0) & tmp_1888);
  c_1890 = 0;
  c_1890 = static_cast<uint32_t>(c_1888);
  c_1885 = c_1862 == 1;
  uint8_t tmp_1879 = 0 - 1;
  c_1879 = static_cast<uint8_t> ((c_1091 >> 8) & tmp_1879);
  c_1881 = 0;
  c_1881 = static_cast<uint32_t>(c_1879);
  c_1876 = c_1862 == 2;
  uint8_t tmp_1870 = 0 - 1;
  c_1870 = static_cast<uint8_t> ((c_1091 >> 16) & tmp_1870);
  c_1872 = 0;
  c_1872 = static_cast<uint32_t>(c_1870);
  uint8_t tmp_1866 = 0 - 1;
  c_1866 = static_cast<uint8_t> ((c_1091 >> 24) & tmp_1866);
  c_1868 = 0;
  c_1868 = static_cast<uint32_t>(c_1866);
  c_1878 = (c_1876) ? c_1872 : c_1868;
  c_1887 = (c_1885) ? c_1881 : c_1878;
  c_1896 = (c_1894) ? c_1890 : c_1887;
  c_1903 = (c_1901) ? c_1896 : riscv_x1;
  riscv_x1_next = c_1903;
  c_1946 = c_17 == 10;
  c_1948 = (c_1946) ? c_1896 : riscv_x10;
  riscv_x10_next = c_1948;
  c_1951 = c_17 == 11;
  c_1953 = (c_1951) ? c_1896 : riscv_x11;
  riscv_x11_next = c_1953;
  c_1956 = c_17 == 12;
  c_1958 = (c_1956) ? c_1896 : riscv_x12;
  riscv_x12_next = c_1958;
  c_1961 = c_17 == 13;
  c_1963 = (c_1961) ? c_1896 : riscv_x13;
  riscv_x13_next = c_1963;
  c_1966 = c_17 == 14;
  c_1968 = (c_1966) ? c_1896 : riscv_x14;
  riscv_x14_next = c_1968;
  c_1971 = c_17 == 15;
  c_1973 = (c_1971) ? c_1896 : riscv_x15;
  riscv_x15_next = c_1973;
  c_1976 = c_17 == 16;
  c_1978 = (c_1976) ? c_1896 : riscv_x16;
  riscv_x16_next = c_1978;
  c_1981 = c_17 == 17;
  c_1983 = (c_1981) ? c_1896 : riscv_x17;
  riscv_x17_next = c_1983;
  c_1986 = c_17 == 18;
  c_1988 = (c_1986) ? c_1896 : riscv_x18;
  riscv_x18_next = c_1988;
  c_1991 = c_17 == 19;
  c_1993 = (c_1991) ? c_1896 : riscv_x19;
  riscv_x19_next = c_1993;
  c_1906 = c_17 == 2;
  c_1908 = (c_1906) ? c_1896 : riscv_x2;
  riscv_x2_next = c_1908;
  c_1996 = c_17 == 20;
  c_1998 = (c_1996) ? c_1896 : riscv_x20;
  riscv_x20_next = c_1998;
  c_2001 = c_17 == 21;
  c_2003 = (c_2001) ? c_1896 : riscv_x21;
  riscv_x21_next = c_2003;
  c_2006 = c_17 == 22;
  c_2008 = (c_2006) ? c_1896 : riscv_x22;
  riscv_x22_next = c_2008;
  c_2011 = c_17 == 23;
  c_2013 = (c_2011) ? c_1896 : riscv_x23;
  riscv_x23_next = c_2013;
  c_2016 = c_17 == 24;
  c_2018 = (c_2016) ? c_1896 : riscv_x24;
  riscv_x24_next = c_2018;
  c_2021 = c_17 == 25;
  c_2023 = (c_2021) ? c_1896 : riscv_x25;
  riscv_x25_next = c_2023;
  c_2026 = c_17 == 26;
  c_2028 = (c_2026) ? c_1896 : riscv_x26;
  riscv_x26_next = c_2028;
  c_2031 = c_17 == 27;
  c_2033 = (c_2031) ? c_1896 : riscv_x27;
  riscv_x27_next = c_2033;
  c_2036 = c_17 == 28;
  c_2038 = (c_2036) ? c_1896 : riscv_x28;
  riscv_x28_next = c_2038;
  c_2041 = c_17 == 29;
  c_2043 = (c_2041) ? c_1896 : riscv_x29;
  riscv_x29_next = c_2043;
  c_1911 = c_17 == 3;
  c_1913 = (c_1911) ? c_1896 : riscv_x3;
  riscv_x3_next = c_1913;
  c_2046 = c_17 == 30;
  c_2048 = (c_2046) ? c_1896 : riscv_x30;
  riscv_x30_next = c_2048;
  c_2051 = c_17 == 31;
  c_2053 = (c_2051) ? c_1896 : riscv_x31;
  riscv_x31_next = c_2053;
  c_1916 = c_17 == 4;
  c_1918 = (c_1916) ? c_1896 : riscv_x4;
  riscv_x4_next = c_1918;
  c_1921 = c_17 == 5;
  c_1923 = (c_1921) ? c_1896 : riscv_x5;
  riscv_x5_next = c_1923;
  c_1926 = c_17 == 6;
  c_1928 = (c_1926) ? c_1896 : riscv_x6;
  riscv_x6_next = c_1928;
  c_1931 = c_17 == 7;
  c_1933 = (c_1931) ? c_1896 : riscv_x7;
  riscv_x7_next = c_1933;
  c_1936 = c_17 == 8;
  c_1938 = (c_1936) ? c_1896 : riscv_x8;
  riscv_x8_next = c_1938;
  c_1941 = c_17 == 9;
  c_1943 = (c_1941) ? c_1896 : riscv_x9;
  riscv_x9_next = c_1943;
};