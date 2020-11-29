#include "GBHigh.h"
void GBHigh::decode_Propagate_prop1_update() {
  c_970 = GBHigh_ram_x == 1;
  c_966 = GBHigh_ram_y == 648;
  c_972 = (c_970 & c_966);
  c_1673 = GBHigh_ram_x > 8;
  c_1666 = GBHigh_ram_y == 8;
  c_1668 = GBHigh_ram_y > 8;
  c_1670 = (c_1666 | c_1668);
  c_1675 = (c_1673 & c_1670);
  c_1661 = GBHigh_ram_x == 1;
  c_1657 = GBHigh_ram_y > 8;
  c_1663 = (c_1661 & c_1657);
  c_1676 = (c_1675 | c_1663);
  uint8_t tmp_1599 = 0 - 1;
  c_1599 = static_cast<uint8_t> ((GBHigh_stencil8 >> 0) & tmp_1599);
  c_1010 = GBHigh_ram_y < 8;
  c_1012 = (c_1010) ? GBHigh_stencil7 : GBHigh_stencil8;
  uint8_t tmp_1591 = 0 - 1;
  c_1591 = static_cast<uint8_t> ((c_1012 >> 0) & tmp_1591);
  c_1005 = GBHigh_ram_y < 8;
  c_1007 = (c_1005) ? GBHigh_stencil6 : GBHigh_stencil7;
  uint8_t tmp_1583 = 0 - 1;
  c_1583 = static_cast<uint8_t> ((c_1007 >> 0) & tmp_1583);
  c_1000 = GBHigh_ram_y < 8;
  c_1002 = (c_1000) ? GBHigh_stencil5 : GBHigh_stencil6;
  uint8_t tmp_1575 = 0 - 1;
  c_1575 = static_cast<uint8_t> ((c_1002 >> 0) & tmp_1575);
  c_995 = GBHigh_ram_y < 8;
  c_997 = (c_995) ? GBHigh_stencil4 : GBHigh_stencil5;
  uint8_t tmp_1567 = 0 - 1;
  c_1567 = static_cast<uint8_t> ((c_997 >> 0) & tmp_1567);
  c_990 = GBHigh_ram_y < 8;
  c_992 = (c_990) ? GBHigh_stencil3 : GBHigh_stencil4;
  uint8_t tmp_1559 = 0 - 1;
  c_1559 = static_cast<uint8_t> ((c_992 >> 0) & tmp_1559);
  c_985 = GBHigh_ram_y < 8;
  c_987 = (c_985) ? GBHigh_stencil2 : GBHigh_stencil3;
  uint8_t tmp_1551 = 0 - 1;
  c_1551 = static_cast<uint8_t> ((c_987 >> 0) & tmp_1551);
  c_980 = GBHigh_ram_y < 8;
  c_982 = (c_980) ? GBHigh_stencil1 : GBHigh_stencil2;
  uint8_t tmp_1543 = 0 - 1;
  c_1543 = static_cast<uint8_t> ((c_982 >> 0) & tmp_1543);
  c_975 = GBHigh_ram_y < 8;
  c_977 = (c_975) ? GBHigh_stencil0 : GBHigh_stencil1;
  uint8_t tmp_1541 = 0 - 1;
  c_1541 = static_cast<uint8_t> ((c_977 >> 0) & tmp_1541);
  c_1549 = (static_cast<uint16_t>(c_1543) << 8) + (static_cast<uint16_t>(c_1541));
  c_1557 = (static_cast<uint24_t>(c_1551) << 16) + (static_cast<uint24_t>(c_1549));
  c_1565 = (static_cast<uint32_t>(c_1559) << 24) + (static_cast<uint32_t>(c_1557));
  c_1573 = (static_cast<uint40_t>(c_1567) << 32) + (static_cast<uint40_t>(c_1565));
  c_1581 = (static_cast<uint48_t>(c_1575) << 40) + (static_cast<uint48_t>(c_1573));
  c_1589 = (static_cast<uint56_t>(c_1583) << 48) + (static_cast<uint56_t>(c_1581));
  c_1597 = (static_cast<uint64_t>(c_1591) << 56) + (static_cast<uint64_t>(c_1589));
  c_1605 = (static_cast<uint72_t>(c_1599) << 64) + (static_cast<uint72_t>(c_1597));
  uint8_t tmp_1533 = 0 - 1;
  c_1533 = static_cast<uint8_t> ((GBHigh_stencil8 >> 8) & tmp_1533);
  uint8_t tmp_1525 = 0 - 1;
  c_1525 = static_cast<uint8_t> ((c_1012 >> 8) & tmp_1525);
  uint8_t tmp_1517 = 0 - 1;
  c_1517 = static_cast<uint8_t> ((c_1007 >> 8) & tmp_1517);
  uint8_t tmp_1509 = 0 - 1;
  c_1509 = static_cast<uint8_t> ((c_1002 >> 8) & tmp_1509);
  uint8_t tmp_1501 = 0 - 1;
  c_1501 = static_cast<uint8_t> ((c_997 >> 8) & tmp_1501);
  uint8_t tmp_1493 = 0 - 1;
  c_1493 = static_cast<uint8_t> ((c_992 >> 8) & tmp_1493);
  uint8_t tmp_1485 = 0 - 1;
  c_1485 = static_cast<uint8_t> ((c_987 >> 8) & tmp_1485);
  uint8_t tmp_1477 = 0 - 1;
  c_1477 = static_cast<uint8_t> ((c_982 >> 8) & tmp_1477);
  uint8_t tmp_1475 = 0 - 1;
  c_1475 = static_cast<uint8_t> ((c_977 >> 8) & tmp_1475);
  c_1483 = (static_cast<uint16_t>(c_1477) << 8) + (static_cast<uint16_t>(c_1475));
  c_1491 = (static_cast<uint24_t>(c_1485) << 16) + (static_cast<uint24_t>(c_1483));
  c_1499 = (static_cast<uint32_t>(c_1493) << 24) + (static_cast<uint32_t>(c_1491));
  c_1507 = (static_cast<uint40_t>(c_1501) << 32) + (static_cast<uint40_t>(c_1499));
  c_1515 = (static_cast<uint48_t>(c_1509) << 40) + (static_cast<uint48_t>(c_1507));
  c_1523 = (static_cast<uint56_t>(c_1517) << 48) + (static_cast<uint56_t>(c_1515));
  c_1531 = (static_cast<uint64_t>(c_1525) << 56) + (static_cast<uint64_t>(c_1523));
  c_1539 = (static_cast<uint72_t>(c_1533) << 64) + (static_cast<uint72_t>(c_1531));
  uint8_t tmp_1467 = 0 - 1;
  c_1467 = static_cast<uint8_t> ((GBHigh_stencil8 >> 16) & tmp_1467);
  uint8_t tmp_1459 = 0 - 1;
  c_1459 = static_cast<uint8_t> ((c_1012 >> 16) & tmp_1459);
  uint8_t tmp_1451 = 0 - 1;
  c_1451 = static_cast<uint8_t> ((c_1007 >> 16) & tmp_1451);
  uint8_t tmp_1443 = 0 - 1;
  c_1443 = static_cast<uint8_t> ((c_1002 >> 16) & tmp_1443);
  uint8_t tmp_1435 = 0 - 1;
  c_1435 = static_cast<uint8_t> ((c_997 >> 16) & tmp_1435);
  uint8_t tmp_1427 = 0 - 1;
  c_1427 = static_cast<uint8_t> ((c_992 >> 16) & tmp_1427);
  uint8_t tmp_1419 = 0 - 1;
  c_1419 = static_cast<uint8_t> ((c_987 >> 16) & tmp_1419);
  uint8_t tmp_1411 = 0 - 1;
  c_1411 = static_cast<uint8_t> ((c_982 >> 16) & tmp_1411);
  uint8_t tmp_1409 = 0 - 1;
  c_1409 = static_cast<uint8_t> ((c_977 >> 16) & tmp_1409);
  c_1417 = (static_cast<uint16_t>(c_1411) << 8) + (static_cast<uint16_t>(c_1409));
  c_1425 = (static_cast<uint24_t>(c_1419) << 16) + (static_cast<uint24_t>(c_1417));
  c_1433 = (static_cast<uint32_t>(c_1427) << 24) + (static_cast<uint32_t>(c_1425));
  c_1441 = (static_cast<uint40_t>(c_1435) << 32) + (static_cast<uint40_t>(c_1433));
  c_1449 = (static_cast<uint48_t>(c_1443) << 40) + (static_cast<uint48_t>(c_1441));
  c_1457 = (static_cast<uint56_t>(c_1451) << 48) + (static_cast<uint56_t>(c_1449));
  c_1465 = (static_cast<uint64_t>(c_1459) << 56) + (static_cast<uint64_t>(c_1457));
  c_1473 = (static_cast<uint72_t>(c_1467) << 64) + (static_cast<uint72_t>(c_1465));
  uint8_t tmp_1401 = 0 - 1;
  c_1401 = static_cast<uint8_t> ((GBHigh_stencil8 >> 24) & tmp_1401);
  uint8_t tmp_1393 = 0 - 1;
  c_1393 = static_cast<uint8_t> ((c_1012 >> 24) & tmp_1393);
  uint8_t tmp_1385 = 0 - 1;
  c_1385 = static_cast<uint8_t> ((c_1007 >> 24) & tmp_1385);
  uint8_t tmp_1377 = 0 - 1;
  c_1377 = static_cast<uint8_t> ((c_1002 >> 24) & tmp_1377);
  uint8_t tmp_1369 = 0 - 1;
  c_1369 = static_cast<uint8_t> ((c_997 >> 24) & tmp_1369);
  uint8_t tmp_1361 = 0 - 1;
  c_1361 = static_cast<uint8_t> ((c_992 >> 24) & tmp_1361);
  uint8_t tmp_1353 = 0 - 1;
  c_1353 = static_cast<uint8_t> ((c_987 >> 24) & tmp_1353);
  uint8_t tmp_1345 = 0 - 1;
  c_1345 = static_cast<uint8_t> ((c_982 >> 24) & tmp_1345);
  uint8_t tmp_1343 = 0 - 1;
  c_1343 = static_cast<uint8_t> ((c_977 >> 24) & tmp_1343);
  c_1351 = (static_cast<uint16_t>(c_1345) << 8) + (static_cast<uint16_t>(c_1343));
  c_1359 = (static_cast<uint24_t>(c_1353) << 16) + (static_cast<uint24_t>(c_1351));
  c_1367 = (static_cast<uint32_t>(c_1361) << 24) + (static_cast<uint32_t>(c_1359));
  c_1375 = (static_cast<uint40_t>(c_1369) << 32) + (static_cast<uint40_t>(c_1367));
  c_1383 = (static_cast<uint48_t>(c_1377) << 40) + (static_cast<uint48_t>(c_1375));
  c_1391 = (static_cast<uint56_t>(c_1385) << 48) + (static_cast<uint56_t>(c_1383));
  c_1399 = (static_cast<uint64_t>(c_1393) << 56) + (static_cast<uint64_t>(c_1391));
  c_1407 = (static_cast<uint72_t>(c_1401) << 64) + (static_cast<uint72_t>(c_1399));
  uint8_t tmp_1335 = 0 - 1;
  c_1335 = static_cast<uint8_t> ((GBHigh_stencil8 >> 32) & tmp_1335);
  uint8_t tmp_1327 = 0 - 1;
  c_1327 = static_cast<uint8_t> ((c_1012 >> 32) & tmp_1327);
  uint8_t tmp_1319 = 0 - 1;
  c_1319 = static_cast<uint8_t> ((c_1007 >> 32) & tmp_1319);
  uint8_t tmp_1311 = 0 - 1;
  c_1311 = static_cast<uint8_t> ((c_1002 >> 32) & tmp_1311);
  uint8_t tmp_1303 = 0 - 1;
  c_1303 = static_cast<uint8_t> ((c_997 >> 32) & tmp_1303);
  uint8_t tmp_1295 = 0 - 1;
  c_1295 = static_cast<uint8_t> ((c_992 >> 32) & tmp_1295);
  uint8_t tmp_1287 = 0 - 1;
  c_1287 = static_cast<uint8_t> ((c_987 >> 32) & tmp_1287);
  uint8_t tmp_1279 = 0 - 1;
  c_1279 = static_cast<uint8_t> ((c_982 >> 32) & tmp_1279);
  uint8_t tmp_1277 = 0 - 1;
  c_1277 = static_cast<uint8_t> ((c_977 >> 32) & tmp_1277);
  c_1285 = (static_cast<uint16_t>(c_1279) << 8) + (static_cast<uint16_t>(c_1277));
  c_1293 = (static_cast<uint24_t>(c_1287) << 16) + (static_cast<uint24_t>(c_1285));
  c_1301 = (static_cast<uint32_t>(c_1295) << 24) + (static_cast<uint32_t>(c_1293));
  c_1309 = (static_cast<uint40_t>(c_1303) << 32) + (static_cast<uint40_t>(c_1301));
  c_1317 = (static_cast<uint48_t>(c_1311) << 40) + (static_cast<uint48_t>(c_1309));
  c_1325 = (static_cast<uint56_t>(c_1319) << 48) + (static_cast<uint56_t>(c_1317));
  c_1333 = (static_cast<uint64_t>(c_1327) << 56) + (static_cast<uint64_t>(c_1325));
  c_1341 = (static_cast<uint72_t>(c_1335) << 64) + (static_cast<uint72_t>(c_1333));
  uint8_t tmp_1269 = 0 - 1;
  c_1269 = static_cast<uint8_t> ((GBHigh_stencil8 >> 40) & tmp_1269);
  uint8_t tmp_1261 = 0 - 1;
  c_1261 = static_cast<uint8_t> ((c_1012 >> 40) & tmp_1261);
  uint8_t tmp_1253 = 0 - 1;
  c_1253 = static_cast<uint8_t> ((c_1007 >> 40) & tmp_1253);
  uint8_t tmp_1245 = 0 - 1;
  c_1245 = static_cast<uint8_t> ((c_1002 >> 40) & tmp_1245);
  uint8_t tmp_1237 = 0 - 1;
  c_1237 = static_cast<uint8_t> ((c_997 >> 40) & tmp_1237);
  uint8_t tmp_1229 = 0 - 1;
  c_1229 = static_cast<uint8_t> ((c_992 >> 40) & tmp_1229);
  uint8_t tmp_1221 = 0 - 1;
  c_1221 = static_cast<uint8_t> ((c_987 >> 40) & tmp_1221);
  uint8_t tmp_1213 = 0 - 1;
  c_1213 = static_cast<uint8_t> ((c_982 >> 40) & tmp_1213);
  uint8_t tmp_1211 = 0 - 1;
  c_1211 = static_cast<uint8_t> ((c_977 >> 40) & tmp_1211);
  c_1219 = (static_cast<uint16_t>(c_1213) << 8) + (static_cast<uint16_t>(c_1211));
  c_1227 = (static_cast<uint24_t>(c_1221) << 16) + (static_cast<uint24_t>(c_1219));
  c_1235 = (static_cast<uint32_t>(c_1229) << 24) + (static_cast<uint32_t>(c_1227));
  c_1243 = (static_cast<uint40_t>(c_1237) << 32) + (static_cast<uint40_t>(c_1235));
  c_1251 = (static_cast<uint48_t>(c_1245) << 40) + (static_cast<uint48_t>(c_1243));
  c_1259 = (static_cast<uint56_t>(c_1253) << 48) + (static_cast<uint56_t>(c_1251));
  c_1267 = (static_cast<uint64_t>(c_1261) << 56) + (static_cast<uint64_t>(c_1259));
  c_1275 = (static_cast<uint72_t>(c_1269) << 64) + (static_cast<uint72_t>(c_1267));
  uint8_t tmp_1203 = 0 - 1;
  c_1203 = static_cast<uint8_t> ((GBHigh_stencil8 >> 48) & tmp_1203);
  uint8_t tmp_1195 = 0 - 1;
  c_1195 = static_cast<uint8_t> ((c_1012 >> 48) & tmp_1195);
  uint8_t tmp_1187 = 0 - 1;
  c_1187 = static_cast<uint8_t> ((c_1007 >> 48) & tmp_1187);
  uint8_t tmp_1179 = 0 - 1;
  c_1179 = static_cast<uint8_t> ((c_1002 >> 48) & tmp_1179);
  uint8_t tmp_1171 = 0 - 1;
  c_1171 = static_cast<uint8_t> ((c_997 >> 48) & tmp_1171);
  uint8_t tmp_1163 = 0 - 1;
  c_1163 = static_cast<uint8_t> ((c_992 >> 48) & tmp_1163);
  uint8_t tmp_1155 = 0 - 1;
  c_1155 = static_cast<uint8_t> ((c_987 >> 48) & tmp_1155);
  uint8_t tmp_1147 = 0 - 1;
  c_1147 = static_cast<uint8_t> ((c_982 >> 48) & tmp_1147);
  uint8_t tmp_1145 = 0 - 1;
  c_1145 = static_cast<uint8_t> ((c_977 >> 48) & tmp_1145);
  c_1153 = (static_cast<uint16_t>(c_1147) << 8) + (static_cast<uint16_t>(c_1145));
  c_1161 = (static_cast<uint24_t>(c_1155) << 16) + (static_cast<uint24_t>(c_1153));
  c_1169 = (static_cast<uint32_t>(c_1163) << 24) + (static_cast<uint32_t>(c_1161));
  c_1177 = (static_cast<uint40_t>(c_1171) << 32) + (static_cast<uint40_t>(c_1169));
  c_1185 = (static_cast<uint48_t>(c_1179) << 40) + (static_cast<uint48_t>(c_1177));
  c_1193 = (static_cast<uint56_t>(c_1187) << 48) + (static_cast<uint56_t>(c_1185));
  c_1201 = (static_cast<uint64_t>(c_1195) << 56) + (static_cast<uint64_t>(c_1193));
  c_1209 = (static_cast<uint72_t>(c_1203) << 64) + (static_cast<uint72_t>(c_1201));
  uint8_t tmp_1137 = 0 - 1;
  c_1137 = static_cast<uint8_t> ((GBHigh_stencil8 >> 56) & tmp_1137);
  uint8_t tmp_1129 = 0 - 1;
  c_1129 = static_cast<uint8_t> ((c_1012 >> 56) & tmp_1129);
  uint8_t tmp_1121 = 0 - 1;
  c_1121 = static_cast<uint8_t> ((c_1007 >> 56) & tmp_1121);
  uint8_t tmp_1113 = 0 - 1;
  c_1113 = static_cast<uint8_t> ((c_1002 >> 56) & tmp_1113);
  uint8_t tmp_1105 = 0 - 1;
  c_1105 = static_cast<uint8_t> ((c_997 >> 56) & tmp_1105);
  uint8_t tmp_1097 = 0 - 1;
  c_1097 = static_cast<uint8_t> ((c_992 >> 56) & tmp_1097);
  uint8_t tmp_1089 = 0 - 1;
  c_1089 = static_cast<uint8_t> ((c_987 >> 56) & tmp_1089);
  uint8_t tmp_1081 = 0 - 1;
  c_1081 = static_cast<uint8_t> ((c_982 >> 56) & tmp_1081);
  uint8_t tmp_1079 = 0 - 1;
  c_1079 = static_cast<uint8_t> ((c_977 >> 56) & tmp_1079);
  c_1087 = (static_cast<uint16_t>(c_1081) << 8) + (static_cast<uint16_t>(c_1079));
  c_1095 = (static_cast<uint24_t>(c_1089) << 16) + (static_cast<uint24_t>(c_1087));
  c_1103 = (static_cast<uint32_t>(c_1097) << 24) + (static_cast<uint32_t>(c_1095));
  c_1111 = (static_cast<uint40_t>(c_1105) << 32) + (static_cast<uint40_t>(c_1103));
  c_1119 = (static_cast<uint48_t>(c_1113) << 40) + (static_cast<uint48_t>(c_1111));
  c_1127 = (static_cast<uint56_t>(c_1121) << 48) + (static_cast<uint56_t>(c_1119));
  c_1135 = (static_cast<uint64_t>(c_1129) << 56) + (static_cast<uint64_t>(c_1127));
  c_1143 = (static_cast<uint72_t>(c_1137) << 64) + (static_cast<uint72_t>(c_1135));
  uint8_t tmp_1071 = 0 - 1;
  c_1071 = static_cast<uint8_t> ((GBHigh_stencil8 >> 64) & tmp_1071);
  uint8_t tmp_1063 = 0 - 1;
  c_1063 = static_cast<uint8_t> ((c_1012 >> 64) & tmp_1063);
  uint8_t tmp_1055 = 0 - 1;
  c_1055 = static_cast<uint8_t> ((c_1007 >> 64) & tmp_1055);
  uint8_t tmp_1047 = 0 - 1;
  c_1047 = static_cast<uint8_t> ((c_1002 >> 64) & tmp_1047);
  uint8_t tmp_1039 = 0 - 1;
  c_1039 = static_cast<uint8_t> ((c_997 >> 64) & tmp_1039);
  uint8_t tmp_1031 = 0 - 1;
  c_1031 = static_cast<uint8_t> ((c_992 >> 64) & tmp_1031);
  uint8_t tmp_1023 = 0 - 1;
  c_1023 = static_cast<uint8_t> ((c_987 >> 64) & tmp_1023);
  uint8_t tmp_1015 = 0 - 1;
  c_1015 = static_cast<uint8_t> ((c_982 >> 64) & tmp_1015);
  uint8_t tmp_1013 = 0 - 1;
  c_1013 = static_cast<uint8_t> ((c_977 >> 64) & tmp_1013);
  c_1021 = (static_cast<uint16_t>(c_1015) << 8) + (static_cast<uint16_t>(c_1013));
  c_1029 = (static_cast<uint24_t>(c_1023) << 16) + (static_cast<uint24_t>(c_1021));
  c_1037 = (static_cast<uint32_t>(c_1031) << 24) + (static_cast<uint32_t>(c_1029));
  c_1045 = (static_cast<uint40_t>(c_1039) << 32) + (static_cast<uint40_t>(c_1037));
  c_1053 = (static_cast<uint48_t>(c_1047) << 40) + (static_cast<uint48_t>(c_1045));
  c_1061 = (static_cast<uint56_t>(c_1055) << 48) + (static_cast<uint56_t>(c_1053));
  c_1069 = (static_cast<uint64_t>(c_1063) << 56) + (static_cast<uint64_t>(c_1061));
  c_1077 = (static_cast<uint72_t>(c_1071) << 64) + (static_cast<uint72_t>(c_1069));
  c_1611 = (static_cast<uint144_t>(c_1143) << 72) + (static_cast<uint144_t>(c_1077));
  c_1617 = (static_cast<uint216_t>(c_1209) << 144) + (static_cast<uint216_t>(c_1611));
  c_1623 = (static_cast<uint288_t>(c_1275) << 216) + (static_cast<uint288_t>(c_1617));
  c_1629 = (static_cast<uint360_t>(c_1341) << 288) + (static_cast<uint360_t>(c_1623));
  c_1635 = (static_cast<uint432_t>(c_1407) << 360) + (static_cast<uint432_t>(c_1629));
  c_1641 = (static_cast<uint504_t>(c_1473) << 432) + (static_cast<uint504_t>(c_1635));
  c_1647 = (static_cast<uint576_t>(c_1539) << 504) + (static_cast<uint576_t>(c_1641));
  c_1653 = (static_cast<uint648_t>(c_1605) << 576) + (static_cast<uint648_t>(c_1647));
  c_1677 = (c_1676) ? c_1653 : Propagate_proc_in;
  c_1678 = (c_972) ? Propagate_proc_in : c_1677;
  c_1704 = kernel(c_1678);
  c_1705 = (c_972) ? GBHigh_arg_0_TDATA : c_1704;
  GBHigh_arg_0_TDATA_next = c_1705;
  c_1698 = GBHigh_ram_x > 8;
  c_1691 = GBHigh_ram_y == 8;
  c_1693 = GBHigh_ram_y > 8;
  c_1695 = (c_1691 | c_1693);
  c_1700 = (c_1698 & c_1695);
  c_1686 = GBHigh_ram_x == 1;
  c_1682 = GBHigh_ram_y > 8;
  c_1688 = (c_1686 & c_1682);
  c_1701 = (c_1700 | c_1688);
  c_1702 = (c_1701) ? 1 : 0;
  c_1703 = (c_972) ? GBHigh_arg_0_TVALID : c_1702;
  GBHigh_arg_0_TVALID_next = c_1703;
  c_962 = (488 - 1);
  c_963 = GBHigh_ram_x == c_962;
  c_957 = (648 - 1);
  c_958 = GBHigh_ram_y == c_957;
  c_965 = (c_963 & c_958);
  c_1679 = (c_965) ? 0 : 1;
  GBHigh_arg_1_TREADY_next = c_1679;
  Propagate_proc_in_next = c_1678;
  GBHigh_st_ready_next = 1;
  GBHigh_stencil0_next = c_977;
  GBHigh_stencil1_next = c_982;
  GBHigh_stencil2_next = c_987;
  GBHigh_stencil3_next = c_992;
  GBHigh_stencil4_next = c_997;
  GBHigh_stencil5_next = c_1002;
  GBHigh_stencil6_next = c_1007;
  GBHigh_stencil7_next = c_1012;
};