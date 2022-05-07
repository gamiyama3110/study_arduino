## whats I2C
`SDA` と `SCL` のピンで複数のモジュールと通信が可能なプロトコル。
`LCD1602` への出力をI2C通信に対応したモジュールを経由するすることで、配線が減る（大事）。

## connect the I2C module as follows
ArduinoでのI2C通信について。
https://create.arduino.cc/projecthub/abdularbi17/how-to-scan-i2c-address-in-arduino-eaadda

|i2c module|arduino nano|
|--:|--:|
|GND|GND|
|VSS|5V|
|SDA|A4|
|SCL|A5|

```
This method is used for scanning the I2C Device inside your module that connected to I2C bus in Arduino (SDA, SCL). In Arduino Uno / Nano / Pro Mini I2C bus is connected to A4 (SDA) and A5 (SCL), for Arduino Mega 2560 I2C bus is connected to D20 (SDA) and D21 (SCL)
```
`SDA` と　`SCL` の接続先はデバイスごとに変わるので要確認。

## I2C adress
チップの違いでI2Cのアドレスが変わる。
モジュール側の仕様書を要確認。
> I2C Address: 0x20-0x27(0x27 default) 