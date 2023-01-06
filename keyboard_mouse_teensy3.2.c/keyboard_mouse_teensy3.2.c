
String Incoming = "";
String headIncoming = "";
String dataIncoming = "";

void setup() {
  Serial1.setTimeout(30);
  Serial1.begin(9600);

    delay(1000);
Mouse.screenSize(1280 , 720);
}

void loop() {
   if (Serial1.available() > 0) {
   Incoming = Serial1.readString();
   
  headIncoming = Incoming.substring( 0 , 3 );
  dataIncoming = Incoming.substring(3);

  if (headIncoming == "k00" || headIncoming == "k0:" || headIncoming == "kp:") { 
    Keyboard.print(dataIncoming); 
  }
  else if (headIncoming == "k11" || headIncoming == "k1:" || headIncoming == "kb:"){
    multi_buttons(dataIncoming);
  }
  else if (headIncoming == "k22" || headIncoming == "k2:" || headIncoming == "kh:"){
    holding_buttons(dataIncoming);
  }
  else if (headIncoming == "m00" || headIncoming == "m0:"){
       mousecontrol(dataIncoming);
    }
  else if (headIncoming == "m11" || headIncoming == "m1:"|| headIncoming == "mm:"){
        mousemove(dataIncoming);
  }
  else if (headIncoming == "m22" || headIncoming == "m2:"|| headIncoming == "mc:"){
        mouseclick(dataIncoming);
        }
  else if (headIncoming == "m33" || headIncoming == "m3:"|| headIncoming == "mp:"){
        mousepositionX(dataIncoming); 
        mousepositionY(dataIncoming);  
  }
  else if (headIncoming == "m44" || headIncoming == "m4:"|| headIncoming == "mt:"){
        mouse_moveto(dataIncoming); 
  }
  else if (headIncoming == "m55" || headIncoming == "m5:"|| headIncoming == "ms:"){
        mouse_screensize(dataIncoming); 
  }
  else if (headIncoming == "Hi0" ){
        Keyboard.print("hi eissa");
  }
  else if (Incoming.substring( 0 , 4 ) == "test"){
    Serial1.print(Incoming);}
  }
  
}


void multi_buttons(String c) {

String button1[10];
int count = 0;
  while (count <= 6) {
    button1[count] = c.substring(0, c.indexOf("+:") );
    c.remove(0,  button1[count].length()+2); 
    count=count+1;
  }

int count2 = 0;

while (count2 != count){
  press_button(button1[count2]);
  count2=count2+1;
}

delay(10);
Keyboard.releaseAll();
  
}

void holding_buttons(String c) {
 

String  button_state , button0 ;

if (c.substring( c.indexOf(",s") , c.indexOf(",s")+2 ) == ",s"){
      button_state = c.substring( c.indexOf(",s")+2);
      button0 = c.substring(0 , c.indexOf(",s"));

          if (button_state == "1"){
            press_button(button0);}
          else if (button_state == "0"){
            release_button(button0);
            }
} 
}


void release_button(String a) {

if ( a == "MODIFIERKEY_CTRL" || a == "modifierkey_ctrl" || a == "ctrl"){
    Keyboard.release(MODIFIERKEY_CTRL);
   }
else if ( a == "MODIFIERKEY_RIGHT_CTRL" || a == "modifierkey_right_ctrl"){
    Keyboard.release(MODIFIERKEY_RIGHT_CTRL);
   }
else if ( a == "MODIFIERKEY_SHIFT" || a == "modifierkey_shift" || a == "shift"){
    Keyboard.release(MODIFIERKEY_SHIFT);
   }
else if ( a == "MODIFIERKEY_RIGHT_SHIFT" || a == "modifierkey_right_shift"){
    Keyboard.release(MODIFIERKEY_RIGHT_SHIFT);
   }
else if ( a == "MODIFIERKEY_ALT" || a == "modifierkey_alt" || a == "alt"){
    Keyboard.release(MODIFIERKEY_ALT);
   }
else if ( a == "MODIFIERKEY_RIGHT_ALT" || a == "modifierkey_right_alt"){
    Keyboard.release(MODIFIERKEY_RIGHT_ALT);
   }
else if ( a == "MODIFIERKEY_GUI" || a == "modifierkey_gui" || a == "gui"){
    Keyboard.release(MODIFIERKEY_GUI);
   }
else if ( a == "MODIFIERKEY_RIGHT_GUI" || a == "modifierkey_right_gui"){
    Keyboard.release(MODIFIERKEY_RIGHT_GUI);
   }
else if ( a == "KEY_ENTER" || a == "key_enter" || a == "enter"){
    Keyboard.release(KEY_ENTER);
   }
else if ( a == "KEY_ESC" || a == "key_esc" || a == "esc"){
    Keyboard.release(KEY_ESC);
   }
else if ( a == "KEY_BACKSPACE" || a == "key_backspace" || a == "backspace"){
    Keyboard.release(KEY_BACKSPACE);
   }
else if ( a == "KEY_TAB" || a == "key_tab" || a == "tab"){
    Keyboard.release(KEY_TAB);
   }
else if ( a == "KEY_SPACE" || a == "key_space" || a == "space"){
    Keyboard.release(KEY_SPACE);
   }
else if ( a == "KEY_MINUS" || a == "key_minus"){
    Keyboard.release(KEY_MINUS);
   }
else if ( a == "KEY_EQUAL" || a == "key_equal"){
    Keyboard.release(KEY_EQUAL);
   }
else if ( a == "KEY_LEFT_BRACE" || a == "key_left_brace"){
    Keyboard.release(KEY_LEFT_BRACE);
   }
else if ( a == "KEY_RIGHT_BRACE" || a == "key_right_brace"){
    Keyboard.release(KEY_RIGHT_BRACE);
   }
else if ( a == "KEY_BACKSLASH" || a == "key_backslash"){
    Keyboard.release(KEY_BACKSLASH);
   }
else if ( a == "KEY_SEMICOLON" || a == "key_semicolon"){
    Keyboard.release(KEY_SEMICOLON);
   }
else if ( a == "KEY_QUOTE" || a == "key_quote"){
    Keyboard.release(KEY_QUOTE);
   }
else if ( a == "KEY_TILDE" || a == "key_tilde"){
    Keyboard.release(KEY_TILDE);
   }
else if ( a == "KEY_COMMA" || a == "key_comma"){
    Keyboard.release(KEY_COMMA);
   }
else if ( a == "KEY_PERIOD" || a == "key_period"){
    Keyboard.release(KEY_PERIOD);
   }
else if ( a == "KEY_SLASH" || a == "key_slash" || a == "slash"){
    Keyboard.release(KEY_SLASH);
   }
else if ( a == "KEY_CAPS_LOCK" || a == "key_caps_lock" || a == "capslock"){
    Keyboard.release(KEY_CAPS_LOCK);
   }
else if ( a == "KEY_F1" || a == "key_f1" || a == "f1"){
    Keyboard.release(KEY_F1);
   }
else if ( a == "KEY_F2" || a == "key_f2" || a == "f2"){
    Keyboard.release(KEY_F2);
   }
else if ( a == "KEY_F3" || a == "key_f3" || a == "f3"){
    Keyboard.release(KEY_F3);
   }
else if ( a == "KEY_F4" || a == "key_f4"  || a == "f4"){
    Keyboard.release(KEY_F4);
   }
else if ( a == "KEY_F5" || a == "key_f5"  || a == "f5"){
    Keyboard.release(KEY_F5);
   }
else if ( a == "KEY_F6" || a == "key_f6" || a == "f6"){
    Keyboard.release(KEY_F6);
   }
else if ( a == "KEY_F7" || a == "key_f7" || a == "f7"){
    Keyboard.release(KEY_F7);
   }
else if ( a == "KEY_F8" || a == "key_f8" || a == "f8"){
    Keyboard.release(KEY_F8);
   }
else if ( a == "KEY_F9" || a == "key_f9" || a == "f9"){
    Keyboard.release(KEY_F9);
   }
else if ( a == "KEY_F10" || a == "key_f10" || a == "f10"){
    Keyboard.release(KEY_F10);
   }
else if ( a == "KEY_F11" || a == "key_f11" || a == "f11"){
    Keyboard.release(KEY_F11);
   }
else if ( a == "KEY_F12" || a == "key_f12" || a == "f12"){
    Keyboard.release(KEY_F12);
   }
else if ( a == "KEY_PRINTSCREEN" || a == "key_printscreen"){
    Keyboard.release(KEY_PRINTSCREEN);
   }
else if ( a == "KEY_SCROLL_LOCK" || a == "key_scroll_lock"){
    Keyboard.release(KEY_SCROLL_LOCK);
   }
else if ( a == "KEY_PAUSE" || a == "key_pause" || a == "pause"){
    Keyboard.release(KEY_PAUSE);
   }
else if ( a == "KEY_INSERT" || a == "key_insert" || a == "insert"){
    Keyboard.release(KEY_INSERT);
   }
else if ( a == "KEY_HOME" || a == "key_home" || a == "home"){
    Keyboard.release(KEY_HOME);
   }
else if ( a == "KEY_PAGE_UP" || a == "key_page_up" || a == "pageup"){
    Keyboard.release(KEY_PAGE_UP);
   }
else if ( a == "KEY_DELETE" || a == "key_delete" || a == "delete"){
    Keyboard.release(KEY_DELETE);
   }
else if ( a == "KEY_END" || a == "key_end" || a == "end"){
    Keyboard.release(KEY_END);
   }
else if ( a == "KEY_PAGE_DOWN" || a == "key_page_down" || a == "pagedown"){
    Keyboard.release(KEY_PAGE_DOWN);
   }
else if ( a == "KEY_RIGHT" || a == "key_right" || a == "right"){
    Keyboard.release(KEY_RIGHT);
   }
else if ( a == "KEY_LEFT" || a == "key_left" || a == "left"){
    Keyboard.release(KEY_LEFT);
   }
else if ( a == "KEY_DOWN" || a == "key_down" || a == "down"){
    Keyboard.release(KEY_DOWN);
   }
else if ( a == "KEY_UP" || a == "key_up" || a == "up"){
    Keyboard.release(KEY_UP);
   }
else if ( a == "KEY_NUM_LOCK" || a == "key_num_lock"){
    Keyboard.release(KEY_NUM_LOCK);
   }
else if ( a == "KEYPAD_SLASH" || a == "keypad_slash"){
    Keyboard.release(KEYPAD_SLASH);
   }
else if ( a == "KEYPAD_ASTERIX" || a == "keypad_asterix"){
    Keyboard.release(KEYPAD_ASTERIX);
   }
else if ( a == "KEYPAD_MINUS" || a == "keypad_minus"){
    Keyboard.release(KEYPAD_MINUS);
   }
else if ( a == "KEYPAD_PLUS" || a == "keypad_plus"){
    Keyboard.release(KEYPAD_PLUS);
   }
else if ( a == "KEYPAD_ENTER" || a == "keypad_enter"){
    Keyboard.release(KEYPAD_ENTER);
   }
else if ( a == "KEYPAD_1" || a == "keypad_1"){
    Keyboard.release(KEYPAD_1);
   }
else if ( a == "KEYPAD_2" || a == "keypad_2"){
    Keyboard.release(KEYPAD_2);
   }
else if ( a == "KEYPAD_3" || a == "keypad_3"){
    Keyboard.release(KEYPAD_3);
   }
else if ( a == "KEYPAD_4" || a == "keypad_4"){
    Keyboard.release(KEYPAD_4);
   }
else if ( a == "KEYPAD_5" || a == "keypad_5"){
    Keyboard.release(KEYPAD_5);
   }
else if ( a == "KEYPAD_6" || a == "keypad_6"){
    Keyboard.release(KEYPAD_6);
   }
else if ( a == "KEYPAD_7" || a == "keypad_7"){
    Keyboard.release(KEYPAD_7);
   }
else if ( a == "KEYPAD_8" || a == "keypad_8"){
    Keyboard.release(KEYPAD_8);
   }
else if ( a == "KEYPAD_9" || a == "keypad_9"){
    Keyboard.release(KEYPAD_9);
   }
else if ( a == "KEYPAD_0" || a == "keypad_0"){
    Keyboard.release(KEYPAD_0);
   }
else if ( a == "KEYPAD_PERIOD" || a == "keypad_period"){
    Keyboard.release(KEYPAD_PERIOD);
   }
else if ( a == "KEY_MEDIA_PLAY" || a == "key_media_play"){
    Keyboard.release(KEY_MEDIA_PLAY);
   }
else if ( a == "KEY_MEDIA_PAUSE" || a == "key_media_pause"){
    Keyboard.release(KEY_MEDIA_PAUSE);
   }
else if ( a == "KEY_MEDIA_RECORD" || a == "key_media_record"){
    Keyboard.release(KEY_MEDIA_RECORD);
   }
else if ( a == "KEY_MEDIA_STOP" || a == "key_media_stop"){
    Keyboard.release(KEY_MEDIA_STOP);
   }
else if ( a == "KEY_MEDIA_REWIND" || a == "key_media_rewind"){
    Keyboard.release(KEY_MEDIA_REWIND);
   }
else if ( a == "KEY_MEDIA_FAST_FORWARD" || a == "key_media_fast_forward"){
    Keyboard.release(KEY_MEDIA_FAST_FORWARD);
   }
else if ( a == "KEY_MEDIA_PREV_TRACK" || a == "key_media_prev_track"){
    Keyboard.release(KEY_MEDIA_PREV_TRACK);
   }
else if ( a == "KEY_MEDIA_NEXT_TRACK" || a == "key_media_next_track"){
    Keyboard.release(KEY_MEDIA_NEXT_TRACK);
   }
else if ( a == "KEY_MEDIA_VOLUME_DEC" || a == "key_media_volume_dec"){
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
   }
else if ( a == "KEY_MEDIA_VOLUME_INC" || a == "key_media_volume_inc"){
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
   }
else if ( a == "KEY_MEDIA_PLAY_PAUSE" || a == "key_media_play_pause"){
    Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
   }
else if ( a == "KEY_MEDIA_PLAY_SKIP" || a == "key_media_play_skip"){
    Keyboard.release(KEY_MEDIA_PLAY_SKIP);
   }
else if ( a == "KEY_MEDIA_MUTE" || a == "key_media_mute"){
    Keyboard.release(KEY_MEDIA_MUTE);
   }
else if ( a == "KEY_MEDIA_EJECT" || a == "key_media_eject"){
    Keyboard.release(KEY_MEDIA_EJECT);
   }
else if ( a == "KEY_SYSTEM_POWER_DOWN" || a == "key_system_power_down" || a == "powerdown"){
    Keyboard.release(KEY_SYSTEM_POWER_DOWN);
   }
else if ( a == "KEY_SYSTEM_WAKE_UP" || a == "key_system_wake_up" || a == "wakeup"){
    Keyboard.release(KEY_SYSTEM_WAKE_UP);
   }
else if ( a == "KEY_SYSTEM_SLEEP" || a == "key_system_sleep" || a == "sleep"){
    Keyboard.release(KEY_SYSTEM_SLEEP);
   }
if ( a.length() == 1){
     char l = a[0];
      Keyboard.release(l);
    }
if ( a == "all"){
    Keyboard.releaseAll();
   }
}


void press_button(String a) {




if ( a == "MODIFIERKEY_CTRL" || a == "modifierkey_ctrl" || a == "ctrl"){
    Keyboard.press(MODIFIERKEY_CTRL);
   }
else if ( a == "MODIFIERKEY_RIGHT_CTRL" || a == "modifierkey_right_ctrl"){
    Keyboard.press(MODIFIERKEY_RIGHT_CTRL);
   }
else if ( a == "MODIFIERKEY_SHIFT" || a == "modifierkey_shift" || a == "shift"){
    Keyboard.press(MODIFIERKEY_SHIFT);
   }
else if ( a == "MODIFIERKEY_RIGHT_SHIFT" || a == "modifierkey_right_shift"){
    Keyboard.press(MODIFIERKEY_RIGHT_SHIFT);
   }
else if ( a == "MODIFIERKEY_ALT" || a == "modifierkey_alt" || a == "alt"){
    Keyboard.press(MODIFIERKEY_ALT);
   }
else if ( a == "MODIFIERKEY_RIGHT_ALT" || a == "modifierkey_right_alt"){
    Keyboard.press(MODIFIERKEY_RIGHT_ALT);
   }
else if ( a == "MODIFIERKEY_GUI" || a == "modifierkey_gui" || a == "gui"){
    Keyboard.press(MODIFIERKEY_GUI);
   }
else if ( a == "MODIFIERKEY_RIGHT_GUI" || a == "modifierkey_right_gui"){
    Keyboard.press(MODIFIERKEY_RIGHT_GUI);
   }
else if ( a == "KEY_ENTER" || a == "key_enter" || a == "enter"){
    Keyboard.press(KEY_ENTER);
   }
else if ( a == "KEY_ESC" || a == "key_esc" || a == "esc"){
    Keyboard.press(KEY_ESC);
   }
else if ( a == "KEY_BACKSPACE" || a == "key_backspace" || a == "backspace"){
    Keyboard.press(KEY_BACKSPACE);
   }
else if ( a == "KEY_TAB" || a == "key_tab" || a == "tab"){
    Keyboard.press(KEY_TAB);
   }
else if ( a == "KEY_SPACE" || a == "key_space" || a == "space"){
    Keyboard.press(KEY_SPACE);
   }
else if ( a == "KEY_MINUS" || a == "key_minus"){
    Keyboard.press(KEY_MINUS);
   }
else if ( a == "KEY_EQUAL" || a == "key_equal"){
    Keyboard.press(KEY_EQUAL);
   }
else if ( a == "KEY_LEFT_BRACE" || a == "key_left_brace"){
    Keyboard.press(KEY_LEFT_BRACE);
   }
else if ( a == "KEY_RIGHT_BRACE" || a == "key_right_brace"){
    Keyboard.press(KEY_RIGHT_BRACE);
   }
else if ( a == "KEY_BACKSLASH" || a == "key_backslash"){
    Keyboard.press(KEY_BACKSLASH);
   }
else if ( a == "KEY_SEMICOLON" || a == "key_semicolon"){
    Keyboard.press(KEY_SEMICOLON);
   }
else if ( a == "KEY_QUOTE" || a == "key_quote"){
    Keyboard.press(KEY_QUOTE);
   }
else if ( a == "KEY_TILDE" || a == "key_tilde"){
    Keyboard.press(KEY_TILDE);
   }
else if ( a == "KEY_COMMA" || a == "key_comma"){
    Keyboard.press(KEY_COMMA);
   }
else if ( a == "KEY_PERIOD" || a == "key_period"){
    Keyboard.press(KEY_PERIOD);
   }
else if ( a == "KEY_SLASH" || a == "key_slash" || a == "slash"){
    Keyboard.press(KEY_SLASH);
   }
else if ( a == "KEY_CAPS_LOCK" || a == "key_caps_lock" || a == "capslock"){
    Keyboard.press(KEY_CAPS_LOCK);
   }
else if ( a == "KEY_F1" || a == "key_f1" || a == "f1"){
    Keyboard.press(KEY_F1);
   }
else if ( a == "KEY_F2" || a == "key_f2" || a == "f2"){
    Keyboard.press(KEY_F2);
   }
else if ( a == "KEY_F3" || a == "key_f3" || a == "f3"){
    Keyboard.press(KEY_F3);
   }
else if ( a == "KEY_F4" || a == "key_f4"  || a == "f4"){
    Keyboard.press(KEY_F4);
   }
else if ( a == "KEY_F5" || a == "key_f5"  || a == "f5"){
    Keyboard.press(KEY_F5);
   }
else if ( a == "KEY_F6" || a == "key_f6" || a == "f6"){
    Keyboard.press(KEY_F6);
   }
else if ( a == "KEY_F7" || a == "key_f7" || a == "f7"){
    Keyboard.press(KEY_F7);
   }
else if ( a == "KEY_F8" || a == "key_f8" || a == "f8"){
    Keyboard.press(KEY_F8);
   }
else if ( a == "KEY_F9" || a == "key_f9" || a == "f9"){
    Keyboard.press(KEY_F9);
   }
else if ( a == "KEY_F10" || a == "key_f10" || a == "f10"){
    Keyboard.press(KEY_F10);
   }
else if ( a == "KEY_F11" || a == "key_f11" || a == "f11"){
    Keyboard.press(KEY_F11);
   }
else if ( a == "KEY_F12" || a == "key_f12" || a == "f12"){
    Keyboard.press(KEY_F12);
   }
else if ( a == "KEY_PRINTSCREEN" || a == "key_printscreen"){
    Keyboard.press(KEY_PRINTSCREEN);
   }
else if ( a == "KEY_SCROLL_LOCK" || a == "key_scroll_lock"){
    Keyboard.press(KEY_SCROLL_LOCK);
   }
else if ( a == "KEY_PAUSE" || a == "key_pause" || a == "pause"){
    Keyboard.press(KEY_PAUSE);
   }
else if ( a == "KEY_INSERT" || a == "key_insert" || a == "insert"){
    Keyboard.press(KEY_INSERT);
   }
else if ( a == "KEY_HOME" || a == "key_home" || a == "home"){
    Keyboard.press(KEY_HOME);
   }
else if ( a == "KEY_PAGE_UP" || a == "key_page_up" || a == "pageup"){
    Keyboard.press(KEY_PAGE_UP);
   }
else if ( a == "KEY_DELETE" || a == "key_delete" || a == "delete"){
    Keyboard.press(KEY_DELETE);
   }
else if ( a == "KEY_END" || a == "key_end" || a == "end"){
    Keyboard.press(KEY_END);
   }
else if ( a == "KEY_PAGE_DOWN" || a == "key_page_down" || a == "pagedown"){
    Keyboard.press(KEY_PAGE_DOWN);
   }
else if ( a == "KEY_RIGHT" || a == "key_right" || a == "right"){
    Keyboard.press(KEY_RIGHT);
   }
else if ( a == "KEY_LEFT" || a == "key_left" || a == "left"){
    Keyboard.press(KEY_LEFT);
   }
else if ( a == "KEY_DOWN" || a == "key_down" || a == "down"){
    Keyboard.press(KEY_DOWN);
   }
else if ( a == "KEY_UP" || a == "key_up" || a == "up"){
    Keyboard.press(KEY_UP);
   }
else if ( a == "KEY_NUM_LOCK" || a == "key_num_lock"){
    Keyboard.press(KEY_NUM_LOCK);
   }
else if ( a == "KEYPAD_SLASH" || a == "keypad_slash"){
    Keyboard.press(KEYPAD_SLASH);
   }
else if ( a == "KEYPAD_ASTERIX" || a == "keypad_asterix"){
    Keyboard.press(KEYPAD_ASTERIX);
   }
else if ( a == "KEYPAD_MINUS" || a == "keypad_minus"){
    Keyboard.press(KEYPAD_MINUS);
   }
else if ( a == "KEYPAD_PLUS" || a == "keypad_plus"){
    Keyboard.press(KEYPAD_PLUS);
   }
else if ( a == "KEYPAD_ENTER" || a == "keypad_enter"){
    Keyboard.press(KEYPAD_ENTER);
   }
else if ( a == "KEYPAD_1" || a == "keypad_1"){
    Keyboard.press(KEYPAD_1);
   }
else if ( a == "KEYPAD_2" || a == "keypad_2"){
    Keyboard.press(KEYPAD_2);
   }
else if ( a == "KEYPAD_3" || a == "keypad_3"){
    Keyboard.press(KEYPAD_3);
   }
else if ( a == "KEYPAD_4" || a == "keypad_4"){
    Keyboard.press(KEYPAD_4);
   }
else if ( a == "KEYPAD_5" || a == "keypad_5"){
    Keyboard.press(KEYPAD_5);
   }
else if ( a == "KEYPAD_6" || a == "keypad_6"){
    Keyboard.press(KEYPAD_6);
   }
else if ( a == "KEYPAD_7" || a == "keypad_7"){
    Keyboard.press(KEYPAD_7);
   }
else if ( a == "KEYPAD_8" || a == "keypad_8"){
    Keyboard.press(KEYPAD_8);
   }
else if ( a == "KEYPAD_9" || a == "keypad_9"){
    Keyboard.press(KEYPAD_9);
   }
else if ( a == "KEYPAD_0" || a == "keypad_0"){
    Keyboard.press(KEYPAD_0);
   }
else if ( a == "KEYPAD_PERIOD" || a == "keypad_period"){
    Keyboard.press(KEYPAD_PERIOD);
   }
else if ( a == "KEY_MEDIA_PLAY" || a == "key_media_play"){
    Keyboard.press(KEY_MEDIA_PLAY);
   }
else if ( a == "KEY_MEDIA_PAUSE" || a == "key_media_pause"){
    Keyboard.press(KEY_MEDIA_PAUSE);
   }
else if ( a == "KEY_MEDIA_RECORD" || a == "key_media_record"){
    Keyboard.press(KEY_MEDIA_RECORD);
   }
else if ( a == "KEY_MEDIA_STOP" || a == "key_media_stop"){
    Keyboard.press(KEY_MEDIA_STOP);
   }
else if ( a == "KEY_MEDIA_REWIND" || a == "key_media_rewind"){
    Keyboard.press(KEY_MEDIA_REWIND);
   }
else if ( a == "KEY_MEDIA_FAST_FORWARD" || a == "key_media_fast_forward"){
    Keyboard.press(KEY_MEDIA_FAST_FORWARD);
   }
else if ( a == "KEY_MEDIA_PREV_TRACK" || a == "key_media_prev_track"){
    Keyboard.press(KEY_MEDIA_PREV_TRACK);
   }
else if ( a == "KEY_MEDIA_NEXT_TRACK" || a == "key_media_next_track"){
    Keyboard.press(KEY_MEDIA_NEXT_TRACK);
   }
else if ( a == "KEY_MEDIA_VOLUME_DEC" || a == "key_media_volume_dec"){
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
   }
else if ( a == "KEY_MEDIA_VOLUME_INC" || a == "key_media_volume_inc"){
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
   }
else if ( a == "KEY_MEDIA_PLAY_PAUSE" || a == "key_media_play_pause"){
    Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
   }
else if ( a == "KEY_MEDIA_PLAY_SKIP" || a == "key_media_play_skip"){
    Keyboard.press(KEY_MEDIA_PLAY_SKIP);
   }
else if ( a == "KEY_MEDIA_MUTE" || a == "key_media_mute"){
    Keyboard.press(KEY_MEDIA_MUTE);
   }
else if ( a == "KEY_MEDIA_EJECT" || a == "key_media_eject"){
    Keyboard.press(KEY_MEDIA_EJECT);
   }
else if ( a == "KEY_SYSTEM_POWER_DOWN" || a == "key_system_power_down" || a == "powerdown"){
    Keyboard.press(KEY_SYSTEM_POWER_DOWN);
   }
else if ( a == "KEY_SYSTEM_WAKE_UP" || a == "key_system_wake_up" || a == "wakeup"){
    Keyboard.press(KEY_SYSTEM_WAKE_UP);
   }
else if ( a == "KEY_SYSTEM_SLEEP" || a == "key_system_sleep" || a == "sleep"){
    Keyboard.press(KEY_SYSTEM_SLEEP);
   }
   
if ( a.length() == 1){
     char l = a[0];
      Keyboard.press(l);
    }

}

void mousemove(String c) {
int x=1;
String q = c.substring( 0 , c.indexOf(',') );
String e = c.substring( c.indexOf(',')+1);

    if( q== "up"){
       for (int i = 1; i <= e.toInt(); i++) {
       Mouse.move(0, -8);
       delay(10);
    } }
    else if( q== "down"){
       for (int i = 1; i <= e.toInt(); i++) {
       Mouse.move(0, 8);
       delay(10);
    } }
    else if( q== "left"){
       for (int i = 1; i <= e.toInt(); i++) {
       Mouse.move(-8, 0);
       delay(10);
    } }  
    else if( q== "right"){
       for (int i = 1; i <= e.toInt(); i++) {
       Mouse.move(8, 0);
       delay(10);
    } }
    else if( q== "s.up"){
       for (int i = 1; i <= e.toInt(); i++) {
       Mouse.scroll(3);
       delay(10);
    } }
    else if( q== "s.down"){
       for (int i = 1; i <= e.toInt(); i++) {
       Mouse.scroll(-3);
       delay(10);
    } }
}


void mousecontrol(String c) {
String x; String y; String s; String l; String m; String r;
  if (c.substring( c.indexOf('x') , c.indexOf('x')+1 ) == "x"){
        x = c.substring( c.indexOf('x')+1 , c.indexOf(',' ));}
  else  {
          x = "0";}
          
  if (c.substring( c.indexOf('y') , c.indexOf('y')+1 ) == "y"){
        y = c.substring( c.indexOf('y')+1 , c.indexOf(',') );}
  else  {
          y= "0";}
          
  if (c.substring( c.indexOf('s') , c.indexOf('s')+1 ) == "s"){
        s = c.substring( c.indexOf('s')+1 , c.indexOf(',') );}
  else  {
          s= "0";}
          
    if (c.substring( c.indexOf('l') , c.indexOf('l')+1 ) == "l"){
        l = c.substring( c.indexOf('l')+1 , c.indexOf(',') );}
  else  {
          l= "0";}
          
  if (c.substring( c.indexOf('m') , c.indexOf('m')+1 ) == "m"){
        m = c.substring( c.indexOf('m')+1 , c.indexOf(',') );}
  else  {
          m= "0";}
   if (c.substring( c.indexOf('r') , c.indexOf('r')+1 ) == "r"){
        r = c.substring( c.indexOf('r')+1 , c.indexOf(',') );}
  else  {
          r= "0";}
  Mouse.set_buttons(l.toInt(), m.toInt(), r.toInt());
  Mouse.move(x.toInt() , y.toInt() );
  Mouse.scroll(s.toInt());
}

void mouseclick(String c) {

if ( c == "r"){
 Mouse.set_buttons(0, 0, 1);
 delay(50);
 Mouse.set_buttons(0, 0, 0);}
 
 if ( c == "l2"){
 Mouse.set_buttons(1, 0, 0);
 delay(20);
 Mouse.set_buttons(0, 0, 0);
 delay(20);
 Mouse.set_buttons(1, 0, 0);
 delay(20);
 Mouse.set_buttons(0, 0, 0);}

 if ( c == "l"){
 Mouse.set_buttons(1, 0, 0);
 delay(50);
 Mouse.set_buttons(0, 0, 0);}

 if ( c == "m"){
 Mouse.set_buttons(0, 1, 0);
 delay(50);
 Mouse.set_buttons(0, 0, 0);}

 String  button_pr, button0;

if (c.substring( c.indexOf(",s") , c.indexOf(",s")+2 ) == ",s"){
      button_pr = c.substring( c.indexOf(",s")+2);
      button0 = c.substring(0 , c.indexOf(",s"));
        }
  else  {
          button_pr= "none";
          button0= "none";}

if (button0 == "l"){
    Mouse.set_buttons(button_pr.toInt(),0, 0);}
else if (button0 == "r"){
    Mouse.set_buttons(0),0, button_pr.toInt();}

}


void mouse_moveto(String c) {

String x = c.substring( 0 , c.indexOf(',') );
String y = c.substring( c.indexOf(',')+1);
Mouse.moveTo(x.toInt(), y.toInt());
}



void mouse_screensize(String c) {


String x = c.substring( 0 , c.indexOf(',') );
String y = c.substring( c.indexOf(',')+1);

Mouse.screenSize(x.toInt(), y.toInt());


}




void mousepositionX(String c) {
String a ;
int s;
if (c.substring( c.indexOf('x') , c.indexOf('x')+1 ) == "x"){
        a = c.substring( c.indexOf('x')+1 , c.indexOf(',' ));
  
  if (c.substring( c.indexOf('s') , c.indexOf('s')+1 ) == "s"){
    s = c.substring( c.indexOf('s')+1 , c.indexOf(',') ).toInt();}
   else{s=2000;}
  
  while (s > 0 ) {
    if(s > 127){
      Mouse.move(-127 , 0 );
      s =s-127;
    }
    else {
      Mouse.move(-s , 0 );
      s =0;
    }
  }
   int x =a.toInt(); 
while (x > 0 ) {
  if(x > 127){
    Mouse.move( 127 , 0 );
    x =x-127;}
  else {
    Mouse.move( x , 0 );
    x =0;}
}

}
}

void mousepositionY(String c) {
String b ;
int s;
if (c.substring( c.indexOf('y') , c.indexOf('y')+1 ) == "y"){
        b = c.substring( c.indexOf('y')+1 , c.indexOf(',' ));
  
  if (c.substring( c.indexOf('s') , c.indexOf('s')+1 ) == "s"){
    s = c.substring( c.indexOf('s')+1 , c.indexOf(',') ).toInt();}
   else{s=2000;}
  
  while (s > 0 ) {
    if(s > 127){
      Mouse.move(0 , -127 );
      s =s-127;
    }
    else {
      Mouse.move(0 , -s );
      s =0;
    }
  }
  int y =b.toInt();
while (y > 0 ) {
  if(y > 127){
    Mouse.move( 0 , 127 );
    y =y-127;}
  else {
    Mouse.move( 0 , y );
    y =0;}
}

}
}
