
_main:

;spi.c,39 :: 		void main()
;spi.c,41 :: 		SPI1_Init();
	CALL       _SPI1_Init+0
;spi.c,43 :: 		while(1)
L_main0:
;spi.c,45 :: 		SPI1_Write(0X0A);
	MOVLW      10
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;spi.c,46 :: 		Delay_ms(100);
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
;spi.c,47 :: 		SPI_Write(0X0F);
	MOVLW      15
	MOVWF      FARG_SPI_Write_data_out+0
	CALL       _SPI_Write+0
;spi.c,48 :: 		Delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
;spi.c,49 :: 		SPI_Write(0X15);
	MOVLW      21
	MOVWF      FARG_SPI_Write_data_out+0
	CALL       _SPI_Write+0
;spi.c,50 :: 		Delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
;spi.c,51 :: 		}
	GOTO       L_main0
;spi.c,52 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
