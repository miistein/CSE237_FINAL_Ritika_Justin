#include "conv1.h"
short * conv1( const short in[CONV1_IN], short out[CONV1_OUT] ) {
short in_6 = in[3] - in[4];
short in_7 = in[1] + in[5];
short in_8 = in[0] - in[5];
short in_9 = in[1] - in[2];
short in_10 = in_6 - in_8;
short in_11 = in[1] - in[4];
short in_12 = in[0] + in[2];
short in_13 = in[4] + in[5];
short in_14 = in[3] + in[5];
short in_15 = in_7;
short in_16 = in[2];
short in_17 = in_16 + in_7;
short in_18 = in[3] + in[4];
short in_19 = in[0];
short in_20 = in_19 - in_7;
short in_21 = in[2];
short in_22 = in_21 + in_6;
short in_23 = -in_22 + in_20;
short in_24 = in_6 + in_12;
short in_25 = in[2] + in[4];
short in_26 = in[1];
short in_27 = in_6 + in_9;
short in_28 = in_12 + in_13;
short in_29 = in[3];
short in_30 = in_29;
short in_31 = in_30 + in_20;
short in_32 = in[5];
short in_33 = in[3];
short in_34 = in_33 - in_8;
short in_35 = in_6;
short in_36 = -in_35 + in_20;
short in_37 = -in[1] + in[5];
short in_38 = in_8 + in_11;
short in_39 = in[1];
short in_40 = in_39 + in_8;
short in_41 = in_8;
short in_42 = in[2];
short in_43 = in_42 - in_18;
short in_44 = in[4];
short in_45 = in_44 + in_7;
short in_46 = in[5];
short in_47 = in_46 + in_6;
short in_48 = in_12;
short in_49 = in_48 + in_47;
short in_50 = in[0] + in[3];
short in_51 = in[2];
short in_52 = in_51;
short in_53 = in_52 + in_10;
short in_54 = in[1] + in[2];
short in_55 = in_54;
short in_56 = -in_55 + in_34;
short in_57 = in_8;
short in_58 = -in_57 + in_43;
short in_59 = in[2];
short in_60 = in_59;
short in_61 = in_60 - in_34;
short in_62 = in_25;
short in_63 = in_62 + in_20;
short in_64 = in_27;
short in_65 = in[3];
short in_66 = in_65 + in_7;
short in_67 = in_7;
short in_68 = in_67 + in_43;
short in_69 = in_17;
short in_70 = in_9;
short in_71 = in_70 - in_10;
short in_72 = in[2];
short in_73 = in_72 + in_18;
short in_74 = in[5];
short in_75 = in_74 - in_6;
short in_76 = in[2];
short in_77 = in_76;
short in_78 = in_77 + in_47;
short in_79 = in_43;
short in_80 = in_66;
short in_81 = in_7 + in_6;
short in_82 = -in[0] + in[1];
short in_83 = in_82 - in_18;
short in_84 = in_8;
short in_85 = in_84 - in_73;
short in_86 = -in_9 + in_18;
short in_87 = in[5];
short in_88 = -in_87 + in_11;
short in_89 = in[2];
short in_90 = in_89 - in_6;
short in_91 = in[0];
short in_92 = in_91 + in_7;
short in_93 = in[2];
short in_94 = in_93 + in_8;
short in_95 = in[0];
short in_96 = in_95 - in_9;
short in_97 = in_10;
short in_98 = in_11 + in_12;
short in_99 = in[4];
short in_100 = in_99;
short in_101 = in_100 - in_92;
short in_102 = in_9 - in_13;
short in_103 = in[4];
short in_104 = in_103;
short in_105 = -in_104 + in_17;
short in_106 = in_8;
short in_107 = in_106 + in_90;
short in_108 = in_18;
short in_109 = -in_108 + in_20;
short in_110 = in_20 + in_90;
short in_111 = in_13;
short in_112 = in_111 + in_96;
short in_113 = in[5];
short in_114 = -in_113 + in_25;
short in_115 = in_8;
short in_116 = in_115 + in_27;
short in_117 = in_25;
short in_118 = in_117 + in_92;
short in_119 = in[0];
short in_120 = in_119;
short in_121 = -in_120 + in_90;
short in_122 = in_34;
short in_123 = in_18;
short in_124 = in_123 + in_96;
short in_125 = -in_43 + in_92;
short in_126 = in[0] - in[1];
short in_127 = in_126;
short in_128 = in_127 + in_47;
short in_129 = in_9 + in_50;
short in_130 = in_66;
short in_131 = in_129;
short in_132 = in_43 + in_92;
short in_133 = in_92 - in_73;
short in_134 = in[1];
short in_135 = in_134;
short in_136 = in_135 + in_94;
short in_137 = in[3];
short in_138 = in_137;
short in_139 = in_138;
short in_140 = in_139 + in_136;
short in_141 = in_11;
short in_142 = in_141 + in_94;
short in_143 = in[1];
short in_144 = in_143;
short in_145 = in_144 + in_90;
short in_146 = in_92 + in_73;
short in_147 = in_90 + in_92;
short in_148 = in_94;
short in_149 = -in[4] + in[5];
short in_150 = in_149;
short in_151 = in_150 + in_96;
short in_152 = in_129;
short in_153 = in_18;
short in_154 = in_153;
short in_155 = in_154 + in_136;
short in_156 = -in_14;
short in_157 = -in_15;
short in_158 = -in_24;
short in_159 = -in_31;
short in_160 = -in_32;
short in_161 = -in_45;
short in_162 = -in_49;
short in_163 = -in_63;
short in_164 = -in_79;
short in_165 = -in_80;
short in_166 = -in_81;
short in_167 = -in_97;
short in_168 = -in_98;
short in_169 = -in_107;
short in_170 = -in_110;
short in_171 = -in_116;
short in_172 = -in_122;
short in_173 = -in_124;
short in_174 = -in_130;
short in_175 = -in_132;
short in_176 = -in_140;
short in_177 = -in_155;
out[0] = in_147;
out[1] = in_148;
out[2] = in_151;
out[3] = in_167;
out[4] = in_168;
out[5] = in_101;
out[6] = in_102;
out[7] = in_156;
out[8] = in_157;
out[9] = in_105;
out[10] = in_169;
out[11] = in_109;
out[12] = in_170;
out[13] = in_112;
out[14] = in_23;
out[15] = in_158;
out[16] = in_114;
out[17] = in_26;
out[18] = in_171;
out[19] = in_28;
out[20] = in_159;
out[21] = in_160;
out[22] = in_118;
out[23] = in_121;
out[24] = in_172;
out[25] = in_36;
out[26] = in_37;
out[27] = in_38;
out[28] = in_40;
out[29] = in_173;
out[30] = in_41;
out[31] = in_125;
out[32] = in_161;
out[33] = in_128;
out[34] = in_162;
out[35] = in_152;
out[36] = in_53;
out[37] = in_56;
out[38] = in_58;
out[39] = in_61;
out[40] = in_163;
out[41] = in_64;
out[42] = in_174;
out[43] = in_68;
out[44] = in_131;
out[45] = in_69;
out[46] = in_175;
out[47] = in_71;
out[48] = in_133;
out[49] = in_177;
out[50] = 0;
out[51] = in_75;
out[52] = in_176;
out[53] = in_78;
out[54] = in_142;
out[55] = in_164;
out[56] = in_165;
out[57] = in_145;
out[58] = in_166;
out[59] = in_146;
out[60] = in_83;
out[61] = in_85;
out[62] = in_86;
out[63] = in_88;
return out;
}
