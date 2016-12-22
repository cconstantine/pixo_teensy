#include "WProgram.h"

extern "C" int main(void)
{
	pinMode(13, OUTPUT);
	while (1) {
    static unsigned long lastTick = millis();
    unsigned long now = millis();
    if (lastTick + 1000 < now) {
      Serial.write("Ping\n");
      lastTick += 1000;
      static bool high;
      digitalWriteFast(13, (high = !high )? HIGH : LOW);
    }

		yield();
	}


}

