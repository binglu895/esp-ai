#include <esp-ai.h>

ESP_AI esp_ai;
 

void setup() {
  Serial.begin(115200);
  // [必  填] 是否调试模式， 会输出更多信息
  bool debug = true;
  // [必  填] wifi 配置： { wifi 账号， wifi 密码 }  注意：要用双引号！
  ESP_AI_wifi_config wifi_config = { "Tenda_132368_2.4", "bC890905", "Tenda_132368_2.4"  };
  // 用开发者平台，只需要配置为空
  //ESP_AI_server_config server_config = { };
  // [必  填] 服务配置： { 服务IP， 服务端口, "请求参数，用多个参数&号分割" }
  ESP_AI_server_config server_config = { "192.168.31.136", 8088, "api-key=your_api_key&p2=test" };
  // [必  填] 离线唤醒方案：{ 方案, 识别阈值 }, "edge_impulse" | "diy"，为 "diy" 时可调用 esp_ai.wakeUp() 方法进行唤醒

  ESP_AI_wake_up_config wake_up_config = {};
  strcpy(wake_up_config.wake_up_scheme, "asrpro");  // 唤醒方案
  strcpy(wake_up_config.str, "start");              // 串口和天问asrpro 唤醒时需要配置的字符串，也就是从另一个开发版发送来的字符串
  // strcpy(wake_up_config.threshold,  0.95);  //  内置语音唤醒时需要配置 唤醒阈值 0-1
  //strcpy(wake_up_config.str, "10");  // 引脚高低电平唤醒时需要的引脚IO

  // [可留空] 麦克风引脚配置：{ bck_io_num, ws_io_num, data_in_num }
  ESP_AI_i2s_config_mic i2s_config_mic = { 4, 5, 6 };
  // [可留空] 扬声器引脚配置：{ bck_io_num, ws_io_num, data_in_num, 采样率 }
  ESP_AI_i2s_config_speaker i2s_config_speaker = { 16, 17, 15, 16000 };
  // [可留空] 音量调节配置：{ 输入引脚，输入最大值(1024|4096)，默认音量(0-1) }
  ESP_AI_volume_config volume_config = { 34, 4096, 1 };
  // 开始运行 ESP-AI 
  esp_ai.begin({debug, wifi_config, server_config, wake_up_config, volume_config, i2s_config_mic, i2s_config_speaker});
}

void loop() {
  esp_ai.loop(); 
  
}
