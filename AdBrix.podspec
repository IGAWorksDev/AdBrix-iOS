Pod::Spec.new do |s|
s.name         = "AdBrix"
s.version      = "2.3.1"
s.summary      = "AdBrix.framework"
s.homepage     = "https://github.com/IGAWorksDev/AdBrix-iOS"

s.license      = {
:type => 'Commercial',
:text => <<-LICENSE
All text and design is copyright 2006-2020 igaworks, Inc.

All rights reserved.

https://github.com/IGAWorksDev/AdBrix-iOS
LICENSE
}

s.platform = :ios, '8.0'
s.author       = { "mike-igaw" => "mike@igaworks.com" }
s.source       = { :git => "https://github.com/IGAWorksDev/AdBrix-iOS.git", :tag => "#{s.version}" }
s.ios.vendored_frameworks = 'AdBrix.framework'
s.libraries = 'xml2'
s.xcconfig     = { 'HEADER_SEARCH_PATHS' => '"$(SDKROOT)/usr/include/libxml2"' }
end
