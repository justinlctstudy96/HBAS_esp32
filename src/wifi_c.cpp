#include "wifi_c.h"

char wifi_ssid[1000] = "trash";                          // "REPLACE_WITH_YOUR_SSID";
char wifi_password[100] = "12345678";                   // "REPLACE_WITH_YOUR_PASSWORD";

// these are for NTPClient connection
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "0.hk.pool.ntp.org", 3600 * 8);


void wifi_init()
{
    WiFi.begin(wifi_ssid, wifi_password);
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);
    int start_time = millis();
    int time_interval = 10000;

    // these are for NTPClient time recalibration
    while ( WiFi.status() != WL_CONNECTED && millis() - start_time <= time_interval) {
        delay ( 500 );
        Serial.print ( "." );
    }
    delay (500);

    if (wifi_stat()){
        Serial.println("Have wifi connection");
        struct timeval tv;
        timeClient.update();
        unsigned long epochTime = timeClient.getEpochTime();        // obtain time information from internet
        tv.tv_sec = epochTime;
        settimeofday(&tv, NULL);
    }

}

bool wifi_stat() // connected will return true
{
    bool state = false;
    if (WiFi.status() == WL_CONNECTED)
    {
        state = true;
    }
    return state;
}

void wifi_reconnect() //please give this function sometime to run before rerun
{
    WiFi.disconnect();
    WiFi.begin(wifi_ssid, wifi_password);
}

int wifi_strength()
{
    int rssi = WiFi.RSSI();
    return rssi;
}