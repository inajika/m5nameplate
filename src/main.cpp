#include <M5Unified.h>
#include <config.h>

/** Needs to display QR code. */
bool displayQrCOde = false;

/** Width of QR code. */
int32_t qrWidth = 0;

/**
 * To initialize settings by boards.
 */
void init() {
  switch (M5.getBoard()) {
    case m5::board_t::board_M5Paper:
      /* M5Paper */
      M5.Lcd.setRotation(1);
      M5.Lcd.setFont(&fonts::lgfxJapanGothicP_40);
      M5.Lcd.setTextSize(3);
      qrWidth = M5.Lcd.height() / 3;
      break;
    default:
      /* Other Boards */
      M5.Lcd.setRotation(0);
      M5.Lcd.setFont(&fonts::lgfxJapanGothicP_16);
      M5.Lcd.setTextSize(1);
      qrWidth = M5.Lcd.width() / 2;
      break;
  }
}

void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);
  init();

  /* My name */
  M5.Lcd.drawString(
    MY_NAME,
    M5.Lcd.width() / 20,
    (M5.Lcd.height() - M5.Lcd.fontHeight()) / 2,
    &fonts::lgfxJapanGothicP_40
  );

  /* Greeting phrase */
  M5.Lcd.drawString(
    GREETING_PHRASE,
    M5.Lcd.width() / 20,
    (M5.Lcd.height() / 2) - (M5.Lcd.fontHeight() * 1),
    &fonts::lgfxJapanGothicP_16
  );

  /* QR code of my website */
  M5.Lcd.qrcode(
    MY_WEBSITE_URL,
    (M5.Lcd.width() * 0.9) - qrWidth,
    (M5.Lcd.height() - qrWidth) / 2,
    qrWidth,
    5
  );

  /* Event name */
  M5.Lcd.drawString(
    EVENT_NAME,
    M5.Lcd.width() / 20,
    M5.Lcd.height() - M5.Lcd.fontHeight(),
    &fonts::lgfxJapanGothicP_20
  );
}

void loop() {
  // NOOP
}
