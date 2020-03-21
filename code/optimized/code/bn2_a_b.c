#include "bn2_a_b.h"
short * bn2_a_b( short in[BN2_A_B_FILT] ) {
in[0] = (short)(((27*((int)in[0]))+10985) >> 8);
in[0] = in[0] * ( in[0] > 0 );
in[1] = (short)(((38*((int)in[1]))+-2924) >> 8);
in[1] = in[1] * ( in[1] > 0 );
in[2] = (short)(((57*((int)in[2]))+-25687) >> 8);
in[2] = in[2] * ( in[2] > 0 );
in[3] = (short)(((41*((int)in[3]))+-9150) >> 8);
in[3] = in[3] * ( in[3] > 0 );
in[4] = (short)(((34*((int)in[4]))+7078) >> 8);
in[4] = in[4] * ( in[4] > 0 );
in[5] = (short)(((52*((int)in[5]))+12415) >> 8);
in[5] = in[5] * ( in[5] > 0 );
in[6] = (short)(((54*((int)in[6]))+12110) >> 8);
in[6] = in[6] * ( in[6] > 0 );
in[7] = (short)(((35*((int)in[7]))+-18735) >> 8);
in[7] = in[7] * ( in[7] > 0 );
in[8] = (short)(((29*((int)in[8]))+5394) >> 8);
in[8] = in[8] * ( in[8] > 0 );
in[9] = (short)(((37*((int)in[9]))+2271) >> 8);
in[9] = in[9] * ( in[9] > 0 );
in[10] = (short)(((29*((int)in[10]))+-7236) >> 8);
in[10] = in[10] * ( in[10] > 0 );
in[11] = (short)(((50*((int)in[11]))+-16199) >> 8);
in[11] = in[11] * ( in[11] > 0 );
in[12] = (short)(((33*((int)in[12]))+5186) >> 8);
in[12] = in[12] * ( in[12] > 0 );
in[13] = (short)(((38*((int)in[13]))+11379) >> 8);
in[13] = in[13] * ( in[13] > 0 );
in[14] = (short)(((26*((int)in[14]))+7040) >> 8);
in[14] = in[14] * ( in[14] > 0 );
in[15] = (short)(((36*((int)in[15]))+13993) >> 8);
in[15] = in[15] * ( in[15] > 0 );
in[16] = (short)(((28*((int)in[16]))+7193) >> 8);
in[16] = in[16] * ( in[16] > 0 );
in[17] = (short)(((75*((int)in[17]))+18545) >> 8);
in[17] = in[17] * ( in[17] > 0 );
in[18] = (short)(((36*((int)in[18]))+-8657) >> 8);
in[18] = in[18] * ( in[18] > 0 );
in[19] = (short)(((50*((int)in[19]))+559) >> 8);
in[19] = in[19] * ( in[19] > 0 );
in[20] = (short)(((35*((int)in[20]))+-5789) >> 8);
in[20] = in[20] * ( in[20] > 0 );
in[21] = (short)(((41*((int)in[21]))+12477) >> 8);
in[21] = in[21] * ( in[21] > 0 );
in[22] = (short)(((37*((int)in[22]))+-11905) >> 8);
in[22] = in[22] * ( in[22] > 0 );
in[23] = (short)(((58*((int)in[23]))+11958) >> 8);
in[23] = in[23] * ( in[23] > 0 );
in[24] = (short)(((25*((int)in[24]))+4513) >> 8);
in[24] = in[24] * ( in[24] > 0 );
in[25] = (short)(((30*((int)in[25]))+2678) >> 8);
in[25] = in[25] * ( in[25] > 0 );
in[26] = (short)(((27*((int)in[26]))+5746) >> 8);
in[26] = in[26] * ( in[26] > 0 );
in[27] = (short)(((62*((int)in[27]))+7164) >> 8);
in[27] = in[27] * ( in[27] > 0 );
in[28] = (short)(((31*((int)in[28]))+-9978) >> 8);
in[28] = in[28] * ( in[28] > 0 );
in[29] = (short)(((36*((int)in[29]))+9377) >> 8);
in[29] = in[29] * ( in[29] > 0 );
in[30] = (short)(((43*((int)in[30]))+-7514) >> 8);
in[30] = in[30] * ( in[30] > 0 );
in[31] = (short)(((39*((int)in[31]))+11533) >> 8);
in[31] = in[31] * ( in[31] > 0 );
in[32] = (short)(((29*((int)in[32]))+9874) >> 8);
in[32] = in[32] * ( in[32] > 0 );
in[33] = (short)(((27*((int)in[33]))+8526) >> 8);
in[33] = in[33] * ( in[33] > 0 );
in[34] = (short)(((39*((int)in[34]))+-13691) >> 8);
in[34] = in[34] * ( in[34] > 0 );
in[35] = (short)(((43*((int)in[35]))+6915) >> 8);
in[35] = in[35] * ( in[35] > 0 );
in[36] = (short)(((31*((int)in[36]))+8988) >> 8);
in[36] = in[36] * ( in[36] > 0 );
in[37] = (short)(((23*((int)in[37]))+9726) >> 8);
in[37] = in[37] * ( in[37] > 0 );
in[38] = (short)(((34*((int)in[38]))+11364) >> 8);
in[38] = in[38] * ( in[38] > 0 );
in[39] = (short)(((29*((int)in[39]))+7480) >> 8);
in[39] = in[39] * ( in[39] > 0 );
in[40] = (short)(((46*((int)in[40]))+10491) >> 8);
in[40] = in[40] * ( in[40] > 0 );
in[41] = (short)(((57*((int)in[41]))+5925) >> 8);
in[41] = in[41] * ( in[41] > 0 );
in[42] = (short)(((28*((int)in[42]))+5694) >> 8);
in[42] = in[42] * ( in[42] > 0 );
in[43] = (short)(((41*((int)in[43]))+-22820) >> 8);
in[43] = in[43] * ( in[43] > 0 );
in[44] = (short)(((29*((int)in[44]))+-5505) >> 8);
in[44] = in[44] * ( in[44] > 0 );
in[45] = (short)(((26*((int)in[45]))+8854) >> 8);
in[45] = in[45] * ( in[45] > 0 );
in[46] = (short)(((25*((int)in[46]))+10871) >> 8);
in[46] = in[46] * ( in[46] > 0 );
in[47] = (short)(((60*((int)in[47]))+2665) >> 8);
in[47] = in[47] * ( in[47] > 0 );
in[48] = (short)(((31*((int)in[48]))+1908) >> 8);
in[48] = in[48] * ( in[48] > 0 );
in[49] = (short)(((23*((int)in[49]))+10412) >> 8);
in[49] = in[49] * ( in[49] > 0 );
in[50] = (short)(((27*((int)in[50]))+10889) >> 8);
in[50] = in[50] * ( in[50] > 0 );
in[51] = (short)(((43*((int)in[51]))+9706) >> 8);
in[51] = in[51] * ( in[51] > 0 );
in[52] = (short)(((31*((int)in[52]))+4169) >> 8);
in[52] = in[52] * ( in[52] > 0 );
in[53] = (short)(((42*((int)in[53]))+7745) >> 8);
in[53] = in[53] * ( in[53] > 0 );
in[54] = (short)(((41*((int)in[54]))+8535) >> 8);
in[54] = in[54] * ( in[54] > 0 );
in[55] = (short)(((26*((int)in[55]))+4183) >> 8);
in[55] = in[55] * ( in[55] > 0 );
in[56] = (short)(((42*((int)in[56]))+-10264) >> 8);
in[56] = in[56] * ( in[56] > 0 );
in[57] = (short)(((38*((int)in[57]))+6244) >> 8);
in[57] = in[57] * ( in[57] > 0 );
in[58] = (short)(((39*((int)in[58]))+2934) >> 8);
in[58] = in[58] * ( in[58] > 0 );
in[59] = (short)(((33*((int)in[59]))+-1514) >> 8);
in[59] = in[59] * ( in[59] > 0 );
in[60] = (short)(((38*((int)in[60]))+-5604) >> 8);
in[60] = in[60] * ( in[60] > 0 );
in[61] = (short)(((34*((int)in[61]))+-10261) >> 8);
in[61] = in[61] * ( in[61] > 0 );
in[62] = (short)(((32*((int)in[62]))+-10291) >> 8);
in[62] = in[62] * ( in[62] > 0 );
in[63] = (short)(((32*((int)in[63]))+11429) >> 8);
in[63] = in[63] * ( in[63] > 0 );
return in;
}