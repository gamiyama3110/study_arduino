## components required
* Arduino Nano
* MQ135-4P
* 22kΩ Resistor
  * 
* LCD1602

### software
* [GeorgK/MQ135](https://github.com/GeorgK/MQ135)
  * ライブラリを改変して感度の調整を行う

## reference
* [ガスセンサー MQ-135を使ったCO2濃度測定(M5StickC Plus編)](https://qiita.com/tomorrow56/items/127b06a6ba8bede56dff)

## preparing
### MQ135-4P
[MQ135 dataheet](https://components101.com/sites/default/files/component_datasheet/MQ135%20Datasheet.pdf)

|MQ135-4P|Arduino Nano|
|--:|--:|
|VCC|5V|
|GND|GND|
|DO|NC|
|AO|A0|

`DO` はOPampの出力らしいがよくわからん。

#### センサー抵抗値
センサーごとに抵抗値にばらつきがあるので、利用するモジュールの抵抗値を計測する。
`measure_sensor_resistor` 関数の呼び出しを有効にすると実測値と平均値をLCDに出力してくれる。

#### CO2濃度
CO2濃度系を別途持っていれば計測、または[気象庁の月平均値](https://ds.data.jma.go.jp/ghg/kanshi/obs/co2_monthave_ryo.html)を参考にする。

## setup
`MQ135.h` にモジュールに対応した設定値を反映する。

|name|param|description|
|--:|:--|--:|
|RLOAD|22.0|モジュールのRL抵抗値。交換してるなら交換後の抵抗値。|
|RZERO|80.0|センサー抵抗値。|
|ATMOCO2|420|CO2濃度。|
