
_main:

;i2c.c,2 :: 		void main()
;i2c.c,4 :: 		I2C1_Init(100000);         // frequencia de clock do barramento I2C (CONSULTAR DATASHEET DO CHIP PARA SABER SUA FREQUENCIA M�XIMA)
	MOVLW      20
	MOVWF      SSPADD+0
	CALL       _I2C1_Init+0
;i2c.c,7 :: 		I2C1_Start();              // start no barramento i2c
	CALL       _I2C1_Start+0
;i2c.c,8 :: 		I2C1_Wr(0xA0);             // endere�o da mem�ria no barramento + comando de escrita(0)
	MOVLW      160
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;i2c.c,10 :: 		I2C1_Wr(0x88);             // endere�o da eerprom onde ser� salvo o dado
	MOVLW      136
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;i2c.c,11 :: 		I2C1_Wr(0xFF);       // grava a vari�vel A no endere�o 00 da mem�ria serial
	MOVLW      255
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;i2c.c,12 :: 		I2C1_Wr(0xF0);       // grava a vari�vel B no endere�o 01 da mem�ria serial
	MOVLW      240
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;i2c.c,13 :: 		I2C1_Wr(0xF1);       // grava a vari�vel C no endere�o 02 da mem�ria serial
	MOVLW      241
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;i2c.c,14 :: 		I2C1_Wr(0xF2);       // grava a vari�vel D no endere�o 03 da mem�ria serial
	MOVLW      242
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;i2c.c,15 :: 		I2C1_Stop();               // condi��o de stop na comunica��o i2c
	CALL       _I2C1_Stop+0
;i2c.c,16 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
