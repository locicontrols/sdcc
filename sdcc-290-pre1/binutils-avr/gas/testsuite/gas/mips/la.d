#objdump: -dr --prefix-addresses -mmips:3000
#name: MIPS la
#as: -mips1

# Test the la macro.

.*: +file format .*mips.*

Disassembly of section .text:
0+0000 <[^>]*> li	\$a0,0
0+0004 <[^>]*> li	\$a0,1
0+0008 <[^>]*> li	\$a0,0x8000
0+000c <[^>]*> li	\$a0,-32768
0+0010 <[^>]*> lui	\$a0,0x1
0+0014 <[^>]*> lui	\$a0,0x1
0+0018 <[^>]*> ori	\$a0,\$a0,0xa5a5
0+001c <[^>]*> li	\$a0,0
0+0020 <[^>]*> addu	\$a0,\$a0,\$a1
0+0024 <[^>]*> li	\$a0,1
0+0028 <[^>]*> addu	\$a0,\$a0,\$a1
0+002c <[^>]*> li	\$a0,0x8000
0+0030 <[^>]*> addu	\$a0,\$a0,\$a1
0+0034 <[^>]*> li	\$a0,-32768
0+0038 <[^>]*> addu	\$a0,\$a0,\$a1
0+003c <[^>]*> lui	\$a0,0x1
0+0040 <[^>]*> addu	\$a0,\$a0,\$a1
0+0044 <[^>]*> lui	\$a0,0x1
0+0048 <[^>]*> ori	\$a0,\$a0,0xa5a5
0+004c <[^>]*> addu	\$a0,\$a0,\$a1
0+0050 <[^>]*> lui	\$a0,0x0
[ 	]*50: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+0054 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*54: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+0058 <[^>]*> lui	\$a0,0x0
[ 	]*58: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+005c <[^>]*> addiu	\$a0,\$a0,0
[ 	]*5c: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+0060 <[^>]*> addiu	\$a0,\$gp,0
[ 	]*60: [A-Z0-9_]*GPREL[A-Z0-9_]*	small_external_data_label
0+0064 <[^>]*> lui	\$a0,0x0
[ 	]*64: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+0068 <[^>]*> addiu	\$a0,\$a0,0
[ 	]*68: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+006c <[^>]*> addiu	\$a0,\$gp,0
[ 	]*6c: [A-Z0-9_]*GPREL[A-Z0-9_]*	small_external_common
0+0070 <[^>]*> lui	\$a0,0x0
[ 	]*70: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+0074 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*74: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+0078 <[^>]*> addiu	\$a0,\$gp,[-0-9]+
[ 	]*78: [A-Z0-9_]*GPREL[A-Z0-9_]*	.sbss.*
0+007c <[^>]*> lui	\$a0,0x0
[ 	]*7c: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+0080 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*80: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+0084 <[^>]*> lui	\$a0,0x0
[ 	]*84: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+0088 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*88: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+008c <[^>]*> addiu	\$a0,\$gp,[-0-9]+
[ 	]*8c: [A-Z0-9_]*GPREL[A-Z0-9_]*	small_external_data_label
0+0090 <[^>]*> lui	\$a0,0x0
[ 	]*90: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+0094 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*94: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+0098 <[^>]*> addiu	\$a0,\$gp,[-0-9]+
[ 	]*98: [A-Z0-9_]*GPREL[A-Z0-9_]*	small_external_common
0+009c <[^>]*> lui	\$a0,0x0
[ 	]*9c: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+00a0 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*a0: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+00a4 <[^>]*> addiu	\$a0,\$gp,[-0-9]+
[ 	]*a4: [A-Z0-9_]*GPREL[A-Z0-9_]*	.sbss.*
0+00a8 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*a8: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+00ac <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*ac: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+00b0 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*b0: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+00b4 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*b4: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+00b8 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*b8: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_data_label
0+00bc <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*bc: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_data_label
0+00c0 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*c0: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+00c4 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*c4: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+00c8 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*c8: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_common
0+00cc <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*cc: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_common
0+00d0 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*d0: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+00d4 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*d4: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+00d8 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*d8: [A-Z0-9_]*HI[A-Z0-9_]*	.sbss.*
0+00dc <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*dc: [A-Z0-9_]*LO[A-Z0-9_]*	.sbss.*
0+00e0 <[^>]*> lui	\$a0,0x0
[ 	]*e0: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+00e4 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*e4: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+00e8 <[^>]*> lui	\$a0,0x0
[ 	]*e8: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+00ec <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*ec: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+00f0 <[^>]*> lui	\$a0,0x0
[ 	]*f0: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_data_label
0+00f4 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*f4: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_data_label
0+00f8 <[^>]*> lui	\$a0,0x0
[ 	]*f8: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+00fc <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*fc: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+0100 <[^>]*> lui	\$a0,0x0
[ 	]*100: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_common
0+0104 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*104: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_common
0+0108 <[^>]*> lui	\$a0,0x0
[ 	]*108: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+010c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*10c: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+0110 <[^>]*> lui	\$a0,0x0
[ 	]*110: [A-Z0-9_]*HI[A-Z0-9_]*	.sbss.*
0+0114 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*114: [A-Z0-9_]*LO[A-Z0-9_]*	.sbss.*
0+0118 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*118: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+011c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*11c: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+0120 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*120: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+0124 <[^>]*> addiu	\$a0,\$a0,0
[ 	]*124: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+0128 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*128: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_data_label
0+012c <[^>]*> addiu	\$a0,\$a0,0
[ 	]*12c: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_data_label
0+0130 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*130: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+0134 <[^>]*> addiu	\$a0,\$a0,0
[ 	]*134: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+0138 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*138: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_common
0+013c <[^>]*> addiu	\$a0,\$a0,0
[ 	]*13c: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_common
0+0140 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*140: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+0144 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*144: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+0148 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*148: [A-Z0-9_]*HI[A-Z0-9_]*	.sbss.*
0+014c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*14c: [A-Z0-9_]*LO[A-Z0-9_]*	.sbss.*
0+0150 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*150: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+0154 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*154: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+0158 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*158: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+015c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*15c: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+0160 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*160: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_data_label
0+0164 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*164: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_data_label
0+0168 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*168: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+016c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*16c: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+0170 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*170: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_common
0+0174 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*174: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_common
0+0178 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*178: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+017c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*17c: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+0180 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*180: [A-Z0-9_]*HI[A-Z0-9_]*	.sbss.*
0+0184 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*184: [A-Z0-9_]*LO[A-Z0-9_]*	.sbss.*
0+0188 <[^>]*> lui	\$a0,0x0
[ 	]*188: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+018c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*18c: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+0190 <[^>]*> addu	\$a0,\$a0,\$a1
0+0194 <[^>]*> lui	\$a0,0x0
[ 	]*194: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+0198 <[^>]*> addiu	\$a0,\$a0,0
[ 	]*198: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+019c <[^>]*> addu	\$a0,\$a0,\$a1
0+01a0 <[^>]*> addiu	\$a0,\$gp,0
[ 	]*1a0: [A-Z0-9_]*GPREL[A-Z0-9_]*	small_external_data_label
0+01a4 <[^>]*> addu	\$a0,\$a0,\$a1
0+01a8 <[^>]*> lui	\$a0,0x0
[ 	]*1a8: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+01ac <[^>]*> addiu	\$a0,\$a0,0
[ 	]*1ac: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+01b0 <[^>]*> addu	\$a0,\$a0,\$a1
0+01b4 <[^>]*> addiu	\$a0,\$gp,0
[ 	]*1b4: [A-Z0-9_]*GPREL[A-Z0-9_]*	small_external_common
0+01b8 <[^>]*> addu	\$a0,\$a0,\$a1
0+01bc <[^>]*> lui	\$a0,0x0
[ 	]*1bc: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+01c0 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*1c0: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+01c4 <[^>]*> addu	\$a0,\$a0,\$a1
0+01c8 <[^>]*> addiu	\$a0,\$gp,[-0-9]+
[ 	]*1c8: [A-Z0-9_]*GPREL[A-Z0-9_]*	.sbss.*
0+01cc <[^>]*> addu	\$a0,\$a0,\$a1
0+01d0 <[^>]*> lui	\$a0,0x0
[ 	]*1d0: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+01d4 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*1d4: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+01d8 <[^>]*> addu	\$a0,\$a0,\$a1
0+01dc <[^>]*> lui	\$a0,0x0
[ 	]*1dc: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+01e0 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*1e0: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+01e4 <[^>]*> addu	\$a0,\$a0,\$a1
0+01e8 <[^>]*> addiu	\$a0,\$gp,[-0-9]+
[ 	]*1e8: [A-Z0-9_]*GPREL[A-Z0-9_]*	small_external_data_label
0+01ec <[^>]*> addu	\$a0,\$a0,\$a1
0+01f0 <[^>]*> lui	\$a0,0x0
[ 	]*1f0: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+01f4 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*1f4: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+01f8 <[^>]*> addu	\$a0,\$a0,\$a1
0+01fc <[^>]*> addiu	\$a0,\$gp,[-0-9]+
[ 	]*1fc: [A-Z0-9_]*GPREL[A-Z0-9_]*	small_external_common
0+0200 <[^>]*> addu	\$a0,\$a0,\$a1
0+0204 <[^>]*> lui	\$a0,0x0
[ 	]*204: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+0208 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*208: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+020c <[^>]*> addu	\$a0,\$a0,\$a1
0+0210 <[^>]*> addiu	\$a0,\$gp,[-0-9]+
[ 	]*210: [A-Z0-9_]*GPREL[A-Z0-9_]*	.sbss.*
0+0214 <[^>]*> addu	\$a0,\$a0,\$a1
0+0218 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*218: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+021c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*21c: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+0220 <[^>]*> addu	\$a0,\$a0,\$a1
0+0224 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*224: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+0228 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*228: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+022c <[^>]*> addu	\$a0,\$a0,\$a1
0+0230 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*230: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_data_label
0+0234 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*234: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_data_label
0+0238 <[^>]*> addu	\$a0,\$a0,\$a1
0+023c <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*23c: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+0240 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*240: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+0244 <[^>]*> addu	\$a0,\$a0,\$a1
0+0248 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*248: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_common
0+024c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*24c: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_common
0+0250 <[^>]*> addu	\$a0,\$a0,\$a1
0+0254 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*254: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+0258 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*258: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+025c <[^>]*> addu	\$a0,\$a0,\$a1
0+0260 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*260: [A-Z0-9_]*HI[A-Z0-9_]*	.sbss.*
0+0264 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*264: [A-Z0-9_]*LO[A-Z0-9_]*	.sbss.*
0+0268 <[^>]*> addu	\$a0,\$a0,\$a1
0+026c <[^>]*> lui	\$a0,0x0
[ 	]*26c: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+0270 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*270: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+0274 <[^>]*> addu	\$a0,\$a0,\$a1
0+0278 <[^>]*> lui	\$a0,0x0
[ 	]*278: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+027c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*27c: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+0280 <[^>]*> addu	\$a0,\$a0,\$a1
0+0284 <[^>]*> lui	\$a0,0x0
[ 	]*284: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_data_label
0+0288 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*288: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_data_label
0+028c <[^>]*> addu	\$a0,\$a0,\$a1
0+0290 <[^>]*> lui	\$a0,0x0
[ 	]*290: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+0294 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*294: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+0298 <[^>]*> addu	\$a0,\$a0,\$a1
0+029c <[^>]*> lui	\$a0,0x0
[ 	]*29c: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_common
0+02a0 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*2a0: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_common
0+02a4 <[^>]*> addu	\$a0,\$a0,\$a1
0+02a8 <[^>]*> lui	\$a0,0x0
[ 	]*2a8: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+02ac <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*2ac: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+02b0 <[^>]*> addu	\$a0,\$a0,\$a1
0+02b4 <[^>]*> lui	\$a0,0x0
[ 	]*2b4: [A-Z0-9_]*HI[A-Z0-9_]*	.sbss.*
0+02b8 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*2b8: [A-Z0-9_]*LO[A-Z0-9_]*	.sbss.*
0+02bc <[^>]*> addu	\$a0,\$a0,\$a1
0+02c0 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*2c0: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+02c4 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*2c4: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+02c8 <[^>]*> addu	\$a0,\$a0,\$a1
0+02cc <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*2cc: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+02d0 <[^>]*> addiu	\$a0,\$a0,0
[ 	]*2d0: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+02d4 <[^>]*> addu	\$a0,\$a0,\$a1
0+02d8 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*2d8: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_data_label
0+02dc <[^>]*> addiu	\$a0,\$a0,0
[ 	]*2dc: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_data_label
0+02e0 <[^>]*> addu	\$a0,\$a0,\$a1
0+02e4 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*2e4: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+02e8 <[^>]*> addiu	\$a0,\$a0,0
[ 	]*2e8: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+02ec <[^>]*> addu	\$a0,\$a0,\$a1
0+02f0 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*2f0: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_common
0+02f4 <[^>]*> addiu	\$a0,\$a0,0
[ 	]*2f4: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_common
0+02f8 <[^>]*> addu	\$a0,\$a0,\$a1
0+02fc <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*2fc: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+0300 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*300: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+0304 <[^>]*> addu	\$a0,\$a0,\$a1
0+0308 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*308: [A-Z0-9_]*HI[A-Z0-9_]*	.sbss.*
0+030c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*30c: [A-Z0-9_]*LO[A-Z0-9_]*	.sbss.*
0+0310 <[^>]*> addu	\$a0,\$a0,\$a1
0+0314 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*314: [A-Z0-9_]*HI[A-Z0-9_]*	.data.*
0+0318 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*318: [A-Z0-9_]*LO[A-Z0-9_]*	.data.*
0+031c <[^>]*> addu	\$a0,\$a0,\$a1
0+0320 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*320: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_data_label
0+0324 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*324: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_data_label
0+0328 <[^>]*> addu	\$a0,\$a0,\$a1
0+032c <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*32c: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_data_label
0+0330 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*330: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_data_label
0+0334 <[^>]*> addu	\$a0,\$a0,\$a1
0+0338 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*338: [A-Z0-9_]*HI[A-Z0-9_]*	big_external_common
0+033c <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*33c: [A-Z0-9_]*LO[A-Z0-9_]*	big_external_common
0+0340 <[^>]*> addu	\$a0,\$a0,\$a1
0+0344 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*344: [A-Z0-9_]*HI[A-Z0-9_]*	small_external_common
0+0348 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*348: [A-Z0-9_]*LO[A-Z0-9_]*	small_external_common
0+034c <[^>]*> addu	\$a0,\$a0,\$a1
0+0350 <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*350: [A-Z0-9_]*HI[A-Z0-9_]*	.bss.*
0+0354 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*354: [A-Z0-9_]*LO[A-Z0-9_]*	.bss.*
0+0358 <[^>]*> addu	\$a0,\$a0,\$a1
0+035c <[^>]*> lui	\$a0,[-0-9x]+
[ 	]*35c: [A-Z0-9_]*HI[A-Z0-9_]*	.sbss.*
0+0360 <[^>]*> addiu	\$a0,\$a0,[-0-9]+
[ 	]*360: [A-Z0-9_]*LO[A-Z0-9_]*	.sbss.*
0+0364 <[^>]*> addu	\$a0,\$a0,\$a1
	...
