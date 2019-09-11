
Pod::Spec.new do |s|
  s.name         = "PingppModule"
  s.version      = "1.0.3"
  s.summary      = "PingppModule"

  s.description  = <<-DESC
                  PingppModule PingppModule
                   DESC

  s.homepage     = "https://coding.net/u/pingplusplus/p/pingpp-react-native/git"
  s.license      = "MIT"
  s.author             = { "song" => "619624632@qq.com" }
  s.platform     = :ios, "7.0"
  s.source       = { :coding => 'https://coding.net/u/pingplusplus/p/pingpp-react-native/git', :tag => 'v1.0.3'}
  s.source_files  = "PingppModule/*.{h,m}"
  s.requires_arc = true

  s.dependency "React"
  s.ios.frameworks = 'CFNetwork','SystemConfiguration','CoreTelephony','Security','QuartzCore','CoreMotion','CoreLocation'

end
