
@{{BLOCK(cavebg)

@=======================================================================
@
@	cavebg, 32x96@8, 
@	Transparent color : 20,9C,00
@	+ palette 256 entries, not compressed
@	+ 48 tiles Metatiled by 2x2 not compressed
@	Total size: 512 + 3072 = 3584
@
@	Time-stamp: 2018-04-07, 14:34:09
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.14
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global cavebgTiles		@ 3072 unsigned chars
	.hidden cavebgTiles
cavebgTiles:
	.word 0x0A050500,0x00050A15,0x050A150A,0x0005150A,0x05150A15,0x00150A15,0x000A150A,0x0000150A
	.word 0x0A000000,0x00000015,0x000A150A,0x150A1500,0x00000000,0x0A150A15,0x0000150A,0x000A150A
	.word 0x0A150000,0x0A150A15,0x15000000,0x0A0A150A,0x00000A00,0x0A150A00,0x0000150A,0x00000000
	.word 0x00000000,0x0A150000,0x050A0000,0x15000005,0x0A150A00,0x00000505,0x150A1500,0x0005050A
	.word 0x00150A15,0x00000A15,0x000A150A,0x00000000,0x00000000,0x00150A15,0x0000000A,0x000A150A
	.word 0x00050515,0x00150A00,0x0505150A,0x00000000,0x05150A15,0x00000005,0x150A150A,0x150A0005
	.word 0x0A150A15,0x05050A15,0x150A150A,0x050A150A,0x0A150A15,0x0A150A15,0x050A150A,0x150A0505
	.word 0x0A150A15,0x0A050A15,0x150A150A,0x050A150A,0x0A150A15,0x0A150A15,0x150A1500,0x150A150A

	.word 0x0A150A15,0x00000515,0x150A150A,0x0000000A,0x00000015,0x00000000,0x15000000,0x0000050A
	.word 0x0A150015,0x00050A15,0x150A000A,0x050A150A,0x0A150015,0x0A150A15,0x150A0000,0x150A150A
	.word 0x0A150A15,0x0A150A15,0x150A150A,0x000A150A,0x0A150A15,0x00150A15,0x150A1500,0x000A150A
	.word 0x0A150000,0x0A150A15,0x00000005,0x150A150A,0x00050515,0x00000000,0x050A150A,0x15000000
	.word 0x0A150000,0x0A150A15,0x15000005,0x0A0A150A,0x00000505,0x0A150A15,0x0005050A,0x150A1500
	.word 0x05050A15,0x00000000,0x050A150A,0x00000005,0x0A150A05,0x00000005,0x150A1505,0x15000005
	.word 0x0A150A15,0x0A000005,0x150A150A,0x0A000005,0x0A150A15,0x00000000,0x0000150A,0x150A0000
	.word 0x00000000,0x0A150A15,0x150A1500,0x150A150A,0x05150A15,0x0A150505,0x150A150A,0x1505050A

	.word 0x0A150A15,0x0A000005,0x150A150A,0x00000005,0x0A150A15,0x05150000,0x000A150A,0x050A150A
	.word 0x0A000015,0x0A150A15,0x150A0000,0x150A150A,0x0A150015,0x0A050A15,0x150A000A,0x0505150A
	.word 0x0A150A00,0x0A150A15,0x150A0000,0x0A0A150A,0x0A000005,0x0A150A15,0x00000505,0x150A1500
	.word 0x00050505,0x00000000,0x0505050A,0x150A0000,0x05050A15,0x0A150005,0x050A150A,0x150A0005
	.word 0x0A150015,0x05150A15,0x150A0000,0x0A0A150A,0x00000000,0x0A150A15,0x0505150A,0x15000000
	.word 0x0A150A15,0x00000005,0x150A150A,0x0000050A,0x0A150A15,0x00050A15,0x150A150A,0x0005150A
	.word 0x0A150A05,0x0A000005,0x150A1505,0x0000000A,0x0A150A15,0x0A000000,0x0000150A,0x150A0000
	.word 0x00000000,0x0A150A15,0x1500000A,0x150A150A,0x0A150000,0x0A150A15,0x150A0000,0x150A150A

	.word 0x0A150A05,0x0A000005,0x150A150A,0x0A000005,0x0A150A15,0x0A000005,0x150A150A,0x00000000
	.word 0x00000000,0x05150000,0x00000505,0x150A150A,0x00050515,0x05050A15,0x0005150A,0x150A150A
	.word 0x0A150A15,0x0A050A15,0x150A150A,0x0A05150A,0x0A150A15,0x0A150A15,0x150A0000,0x150A150A
	.word 0x00000505,0x0A150A15,0x0005150A,0x00000000,0x00050A15,0x0A150A00,0x050A1505,0x150A1500
	.word 0x00050A15,0x0A150A00,0x00000000,0x0A0A0000,0x05050505,0x0A000005,0x0505150A,0x00000505
	.word 0x0A150A15,0x00000505,0x150A150A,0x00000505,0x0A150A15,0x00000515,0x150A150A,0x0000050A
	.word 0x05150A05,0x0A150A00,0x000A150A,0x0A0A1500,0x00000015,0x0A150000,0x150A1500,0x00000000
	.word 0x0A150A15,0x00000000,0x000A150A,0x150A0000,0x00000000,0x0A150A15,0x150A1500,0x150A150A

	.word 0x10141408,0x13081308,0x14141413,0x1413081B,0x14141308,0x1408131B,0x08130814,0x14130813
	.word 0x14081308,0x13081314,0x14140813,0x070C1A13,0x1408131B,0x120B0C08,0x08131B14,0x0B0B0B1A
	.word 0x13081308,0x13081308,0x0813081B,0x08131414,0x13081014,0x13141414,0x08131B14,0x08141413
	.word 0x13081308,0x13081308,0x14130807,0x0813081B,0x14081207,0x1408131B,0x14130712,0x14140814
	.word 0x13081414,0x0C0B0C19,0x08130814,0x0B0C1A1A,0x10141308,0x0C191A08,0x14140814,0x0813081B
	.word 0x14141314,0x13081314,0x08130813,0x08140813,0x13141408,0x13141408,0x14141414,0x08130813
	.word 0x1408120B,0x14141314,0x0813070B,0x14130814,0x13081319,0x13081308,0x081B0813,0x14130813
	.word 0x131B1408,0x13081414,0x08131414,0x08141414,0x14081308,0x13141414,0x14130814,0x08130814

	.word 0x10141408,0x13081308,0x14141413,0x1413081B,0x14141308,0x1408131B,0x08130814,0x14140813
	.word 0x14081308,0x14141314,0x14140813,0x08130814,0x1408131B,0x14141308,0x08131B14,0x14141413
	.word 0x14081308,0x13081314,0x08130814,0x14130813,0x13081414,0x13081014,0x14131414,0x081B1414
	.word 0x13081314,0x13141408,0x1B140813,0x08130813,0x14141408,0x1408131B,0x14141413,0x1414081B
	.word 0x13081414,0x13141408,0x14140814,0x14130813,0x14141308,0x14081308,0x08130814,0x14130813
	.word 0x13081314,0x14081414,0x08140813,0x08141414,0x13141408,0x13141408,0x14141413,0x08130813
	.word 0x14141308,0x14141314,0x14130814,0x14130814,0x13081014,0x13081308,0x081B1414,0x14130813
	.word 0x13141414,0x13081414,0x08131414,0x08141414,0x14081308,0x13141414,0x14130814,0x08131414

	.word 0x02020201,0x02020202,0x04040402,0x04040404,0x04040404,0x04040404,0x0F040404,0x0F0F0F0F
	.word 0x0F040404,0x01010101,0x01040404,0x04040404,0x010F0104,0x04040404,0x0F040404,0x04040404
	.word 0x02020202,0x01020202,0x04040104,0x02040404,0x04040404,0x04040404,0x0F0F0F0F,0x0404040F
	.word 0x01010101,0x040F0401,0x04040404,0x04010401,0x04040404,0x04040401,0x04040404,0x04040401
	.word 0x01040404,0x04040404,0x01040404,0x04040404,0x01040404,0x04040404,0x01040404,0x01010101
	.word 0x02040404,0x02020202,0x04040404,0x04040404,0x04040401,0x01040404,0x0101010F,0x0F010101
	.word 0x04040404,0x04040401,0x04040404,0x01040401,0x04040404,0x04040401,0x01010101,0x04040401
	.word 0x02020202,0x04040402,0x04040404,0x04040404,0x04040404,0x01040404,0x01010101,0x0F010101

	.word 0x08081408,0x14140808,0x18080808,0x14080814,0x14180808,0x08080814,0x14140814,0x18180808
	.word 0x14080814,0x14141808,0x08080808,0x14141408,0x14140808,0x14140808,0x14141408,0x08080814
	.word 0x14081414,0x08080808,0x08080814,0x08141408,0x08080808,0x14141414,0x08081414,0x14141414
	.word 0x08081414,0x14140808,0x18080814,0x08080814,0x14180808,0x08081414,0x14141408,0x14081414
	.word 0x1414140D,0x14140814,0x14080D0D,0x14140814,0x0D0D0D08,0x140D0808,0x08080816,0x16080816
	.word 0x08141608,0x0D081408,0x1414140D,0x0814140D,0x14160D16,0x16160D0D,0x0D0D0000,0x140D0000
	.word 0x14141408,0x0D080814,0x0D0D0D14,0x0D141408,0x0D080D14,0x08141414,0x0D080D16,0x0816160D
	.word 0x0816140D,0x0D0D0D08,0x16141416,0x14140D0D,0x160D0D0D,0x160D0D14,0x0D000D14,0x0D00000D

	.word 0x08080808,0x14140808,0x14140808,0x14080808,0x14141408,0x14140808,0x08141408,0x03031408
	.word 0x08080808,0x06060314,0x08080808,0x09090E14,0x14140808,0x17090914,0x03031408,0x08081414
	.word 0x14081414,0x08080808,0x08080814,0x08141414,0x14080814,0x08140803,0x03141403,0x14140809
	.word 0x08140809,0x14140808,0x14140817,0x08080814,0x03031408,0x08081408,0x03060314,0x14081408
	.word 0x09031408,0x03030308,0x08140808,0x03060308,0x08080808,0x17090314,0x08181808,0x08081414
	.word 0x14141418,0x08141414,0x03141414,0x08081408,0x08081414,0x18080808,0x14080808,0x14180808
	.word 0x09030314,0x08080808,0x08080809,0x08141408,0x08030608,0x08141414,0x08090314,0x08081414
	.word 0x08081408,0x14080808,0x08141408,0x14140808,0x08080814,0x14140808,0x14081414,0x14080814

	.word 0x08080808,0x14140808,0x14140808,0x08080808,0x08081408,0x03080808,0x03090808,0x08080808
	.word 0x08140808,0x06030309,0x09080808,0x0E060303,0x03080808,0x090E0603,0x17081408,0x03090909
	.word 0x14081414,0x08080808,0x08080808,0x08141414,0x14080809,0x08140803,0x03081408,0x14140809
	.word 0x08080814,0x14140808,0x14140809,0x08080808,0x03090817,0x08081408,0x03060814,0x14081414
	.word 0x08031408,0x14030917,0x08140808,0x09140808,0x08080808,0x17090814,0x08181808,0x08081414
	.word 0x14141418,0x06081414,0x03141414,0x03081408,0x08081414,0x08080808,0x14080808,0x14180808
	.word 0x09030908,0x08080808,0x08141417,0x08140814,0x08030608,0x08080809,0x08090314,0x08030608
	.word 0x08081406,0x080E0308,0x08080903,0x08090908,0x08080909,0x14080808,0x14080808,0x14080814

	.word 0x11111418,0x09111111,0x09090814,0x18141118,0x18090908,0x08080814,0x14141808,0x18090908
	.word 0x08080808,0x14141818,0x08080808,0x14141414,0x18180808,0x14141408,0x14141808,0x08080818
	.word 0x14181818,0x14111111,0x14141818,0x08180908,0x08080808,0x18090909,0x08081818,0x14141418
	.word 0x08181414,0x14141408,0x18081414,0x08080818,0x14180814,0x08081814,0x14141808,0x14081414
	.word 0x14141408,0x14140814,0x14080808,0x14140814,0x08080808,0x14080808,0x08081408,0x08081414
	.word 0x08141414,0x08141414,0x08141414,0x08081408,0x08081414,0x14080808,0x14080808,0x14140808
	.word 0x14141408,0x08080814,0x08080814,0x08141408,0x08080814,0x08141414,0x08080808,0x08081414
	.word 0x08141408,0x14080808,0x08141408,0x14140808,0x08080814,0x14140808,0x14081414,0x14080814

	.word 0x11111418,0x09111111,0x09090814,0x18141118,0x18090908,0x08080814,0x14141808,0x18090908
	.word 0x08080808,0x14141818,0x08080808,0x14141414,0x18180808,0x14141408,0x14141808,0x08080818
	.word 0x14181818,0x14111111,0x14141818,0x08180908,0x08080808,0x18090909,0x08081818,0x14141418
	.word 0x08181414,0x14141408,0x18081414,0x08080818,0x14180814,0x08081814,0x14141808,0x14081414
	.word 0x1414140D,0x14140814,0x14080D0D,0x14140814,0x0D0D0808,0x140D0808,0x08080816,0x16080816
	.word 0x08141608,0x0D08140D,0x1414140D,0x0814140D,0x14160D16,0x16160D0D,0x0D0D0000,0x140D0000
	.word 0x14141408,0x0D080814,0x0D0D0D14,0x0D14140D,0x0D080D14,0x08141414,0x0D080D16,0x0816160D
	.word 0x0816140D,0x0D0D0D08,0x16141416,0x14140D0D,0x160D0D0D,0x160D0D14,0x0D000D14,0x0D00000D

	.section .rodata
	.align	2
	.global cavebgPal		@ 512 unsigned chars
	.hidden cavebgPal
cavebgPal:
	.hword 0x0000,0x14E9,0x3675,0x37DF,0x258E,0x1062,0x7FFF,0x154F
	.hword 0x0844,0x15F9,0x0420,0x0CAA,0x0C87,0x0002,0x0E5F,0x0C84
	.hword 0x1150,0x0423,0x112D,0x0445,0x0CAC,0x0820,0x0468,0x1D6F
	.hword 0x1171,0x1083,0x0866,0x1172,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(cavebg)
