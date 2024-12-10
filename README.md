# m5namepalate
M5Stackを名札にするプログラム

## 書き込む前に
`include/config.sapmle.h`をコピーして同じ階層に`config.h`を作成します。
```bash
cp -i include/config.sapmle.h include/config.h
```

以下の表を参考にして、定数を設定してください。
|#|定数物理名|定数論理名|設定例|
|:---:|---|---|---|
|1|MY_NAME|自分の名前|`やまだたろう`|
|2|GREETING_PHRASE|一言あいさつ文|`仲良くしてください!!`|
|3|MY_WEBSITE_URL|QRコードで表示したいURL|`https://example.com`|
|4|EVENT_NAME|参加するイベント名|`コミックマーケット105`|
