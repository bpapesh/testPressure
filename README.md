# Over-The-Air firmware upgrades for Internet of Things devices with JFrog Bintray


* [Example of Bintray OTA Repository](https://bintray.com/ivankravets/platformio-ota/bintray-secure-ota)
* [swampUp 2018: Presentation](https://www.slideshare.net/ivankravets/swampup-overtheair-ota-firmware-upgrades-for-internet-of-things-devices-with-platformio-and-jfrog-bintray)

#Usage
Use debug env in platformio.ini to initially write to board connected to usb(setting appropriate login details and keys)

Once board is looking for firmware versions from bitray, switch to release env in platformio.ini and modify esp code to send updates
