/* 
 * File:   main.c
 * Author: Ramazan Subasi (subram)
 *
 * Created on 05 Kasim 2013 Sali, 15:42
 */



#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <time.h>




// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// CONFIG2
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

#define _XTAL_FREQ 4000000      // Calisma Frekansi
int i,j;                        //  i ve j ad?nda 8 bitlik kaydediciler tan?mlan?yor


void main()
{
    TRISB=0;                    // PORTB Komple Cikis Olarak Ayarlans?
    PORTB=0;                    // PORTB Cikislari Sifirlandi
    while(1)                    // Program Sonsuz Donguye Sokuluyor
    {
        j=1;                    // j'ye '1'(00000001) Degeri Ataniyor
        for(i=0;i<7;i=i+1)      // i, 0'dan 7'ya Kadar Sayiyor
        {
            PORTB=j;            // j Degerini PORTB'ye Yukle
            __delay_ms(200);    // 200 Milisaniye Bekle
            j=j<<1;             // j Degerini Sola Kaydir
        }                       // 1. For Dongusu Sonu
        for(i=0;i<7;i++)        // i, 0'dan 7'ya Kadar Sayiyor
        {
            PORTB=j;            // j Degerini PORTB'ye Yukle
            __delay_ms(200);    // 200 Milisaniye Bekle
            j=j>>1;             // j Degerini Saga Kaydir
            
        }                       // 2. For Dongusu Sonu
    }                           // While Dongusunun Sonu
}                               // Program?n Sonu
