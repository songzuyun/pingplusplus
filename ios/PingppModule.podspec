
Pod::Spec.new do |s|
  s.name         = "PingppModule"
  s.version      = "0.0.1"
  s.summary      = "PingppModule"

  s.description  = <<-DESC
                  PingppModule PingppModule
                   DESC

  s.homepage     = "https://github.com/songzuyun/pingplusplus.git"
  s.license      = "MIT"
  s.author             = { "song" => "619624632@qq.com" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => 'https://github.com/songzuyun/pingplusplus.git', :tag => '0.0.1'}
  s.source_files  = "PingppModule/**/*"
  s.requires_arc = true

  s.dependency "React"
  s.ios.frameworks = 'CFNetwork','SystemConfiguration','CoreTelephony','Security','QuartzCore','CoreMotion','CoreLocation'

end
