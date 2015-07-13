apt-get install wget
apt-get install unzip

http_sdk_dir='http://developer.nordicsemi.com/nRF51_SDK/nRF51_SDK_v8.x.x/'
sdk_version=''
version=$1
case $version in
        8.0.0)
            sdk_version="nRF51_SDK_8.0.0_5fc2c3a.zip"
            ;;
        8.1.0)
            sdk_version="nRF51_SDK_8.1.0_b6ed55f.zip"
            ;;
        8.1.1)
            sdk_version="nRF51_SDK_8.1.1_ef6048c.zip"
            ;;
        *)
            echo $"Version not tracked"
            exit 1
            ;;
esac

echo $"Downloading sdk from $http_sdk_dir$sdk_version"

wget -O tmp.zip $http_sdk_dir$sdk_version && unzip tmp.zip  && rm tmp.zip
