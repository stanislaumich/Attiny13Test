//#include <Arduino.h>
// https://mysku.ru/blog/aliexpress/34220.html хорошая статья
#define F_CPU 1200000UL // Указываем тактовую частоту МК
#define LED PB3         // Используем светодиод, подключенный к PB2 (7 пин)
#include <avr/io.h>     // Подключаем определения ввода/вывода
#include <util/delay.h> // Подключаем библиотеку функций задержки

int main(void)
{
  // Светодиод
  DDRB |= (1<<LED);     // конфигурируем пин как выход
  PORTB &= ~(1<<LED);   // по умолчанию светодиод выключен
  // Основной цикл
  while (1) 
  {
    _delay_ms (500);    // задержка 500 мс
    PORTB ^= (1<<LED);  // инвертируем состояние пина
    _delay_ms (1500);    // задержка 1500 мс
    PORTB ^= (1<<LED);  // инвертируем состояние пина
    _delay_ms (500);    // задержка 1500 мс
    PORTB ^= (1<<LED);  // инвертируем состояние пина
    _delay_ms (500);    // задержка 1500 мс
    PORTB ^= (1<<LED);  // инвертируем состояние пина
    _delay_ms (500);    // задержка 1500 мс
    PORTB ^= (1<<LED);  // инвертируем состояние пина
  }
}

/* sleep
#include <avr/interrupt.h>
#include <avr/sleep.h>
// Pin 4 for LED
int led = 4;
ISR(WDT_vect) {
	digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(1000);               // wait for a second
	digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
	sleep_mode();
}

void setup() {
	// initialize the digital pin as an output.
	pinMode(led, OUTPUT);
	// prescale timer to 8s so we can measure current
	WDTCR |= (1<<WDP3 )|(0<<WDP2 )|(0<<WDP1)|(1<<WDP0); // 8s
	// Enable watchdog timer interrupts
	WDTCR |= (1<<WDTIE);
	sei(); // Enable global interrupts
	// Use the Power Down sleep mode
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	for (;;) {
		sleep_mode();   // go to sleep and wait for interrupt...
	}
}
// the loop routine runs over and over again forever:
void loop() {
}




*/