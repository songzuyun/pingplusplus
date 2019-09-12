
Pod::Spec.new do |s|
  s.name         = "pingpp-react-native"
  s.version      = "0.0.1"
  s.summary      = "pingpp-react-native"
  s.homepage     = "https://github.com/songzuyun/pingplusplus.git"
  s.license      = "MIT"
  s.author       = { "song" => "619624632@qq.com" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => 'https://github.com/songzuyun/pingplusplus.git', :tag => '0.0.1'}
  s.source_files  = "ios/PingppModule/**/*.{h,m}"

  s.dependency "React"
  s.ios.frameworks = 'CFNetwork','SystemConfiguration','CoreTelephony','Security','QuartzCore','CoreMotion','CoreLocation'

end
