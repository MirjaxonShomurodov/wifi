#include <ESP8266WiFi.h>

// WiFi tarmoq ma'lumotlari
const char* wifi_name = "Wifi_5G"; // Tarmoq nomi
const char* wifi_password = "123456789"; // Tarmoq paroli

void setup() {
  // Serial monitorni ishga tushirish
  Serial.begin(115200);
  Serial.println();
  Serial.println("WiFi'ga ulanish jarayoni boshlanmoqda...");

  // WiFi ulanish
  WiFi.begin(wifi_name, wifi_password);

  // Ulanishni kuzatish
  int retryCount = 0;
  while (WiFi.status()!= WL_CONNECTED && retryCount < 10) {
    delay(1000); // Har 1 sekundda tekshirish
    Serial.print(".");
    retryCount++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.println("WiFi'ga muvaffaqiyatli ulandi!");
    Serial.print("IP manzilingiz: ");
    Serial.println(WiFi.localIP()); // IP manzilni chiqarish
  } else {
    Serial.println();
    Serial.println("WiFi ulanishni amalga oshirib bo'lmadi.");
  }
}

void loop() {
  // WiFi ulanish holatini tekshirish
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi ulanish yo'q! Qayta ulanmoqda...");
    WiFi.disconnect();        // Avvalgi ulanishni uzish
    WiFi.begin(wifi_name, wifi_password); // Yangi ulanishni boshlash

    // Ulanishni qayta tekshirish uchun vaqt
    int retryCount = 0;
    while (WiFi.status() != WL_CONNECTED && retryCount < 10) {
      delay(1000); // Har 1 sekundda tekshirish
      Serial.print(".");
      retryCount++;
    }

    // Ulanish holatini ko‘rsatish
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println();
      Serial.println("WiFi'ga qayta ulandi!");
      Serial.print("IP manzilingiz: ");
      Serial.println(WiFi.localIP());
    } else {
      Serial.println();
      Serial.println("WiFi ulanishni amalga oshirib bo'lmadi. Keyinroq qayta urinib ko‘ramiz.");
    }
  }

  // Bu yerda boshqa doimiy funksiyalarni ishlatishingiz mumkin
  delay(5000); // Tizimni ortiqcha yuklamaslik uchun 5 sekund kutish
}
