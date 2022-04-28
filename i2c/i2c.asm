
_main:

;i2c.c,2 :: 		int main()
;i2c.c,4 :: 		I2C1_Init(100000); //Inicializa I2C Master com clock de 100KHz
	MOVLW      20
	MOVWF      SSPADD+0
	CALL       _I2C1_Init+0
;i2c.c,5 :: 		while(1)
L_main0:
;i2c.c,7 :: 		I2C1_Start();
	CALL       _I2C1_Start+0
;i2c.c,8 :: 		I2C1_Wr(0xFF);
	MOVLW      255
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;i2c.c,9 :: 		I2C1_Wr(0xD0);
	MOVLW      208
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;i2c.c,10 :: 		I2C1_Wr(0x88);
	MOVLW      136
	MOVWF      FARG_I2C1_Wr_data_+0
	CALL       _I2C1_Wr+0
;i2c.c,11 :: 		I2C1_Stop();
	CALL       _I2C1_Stop+0
;i2c.c,12 :: 		Delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
;i2c.c,13 :: 		}
	GOTO       L_main0
;i2c.c,14 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
