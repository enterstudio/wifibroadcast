tinkering with befinitiv's wifibroadcast project
* (send video thru 802.11 STA via packet injection, for RC FPV)
* https://bitbucket.org/befi/wifibroadcast
* https://befinitiv.wordpress.com/

##Added Features
* careful backoff and retry when adapter falls behind pcap_inject()
* enhanced timing stats (instantaneous and average kbps, mbit/s)
* a driver that runtime patches ath9k_htc driver, the ath fw (work in progress)
  * fw patch at fw load to insert new rate
  * driver patch to up tx power to 30db
  * change internal chipset register values for max throughput

##How Does WifiBroadcast Work?
* raspbian comes with a utility that reads video: raspivid
* raspivid's output gets piped into the tx portion of this project

##Steps
* install libpcap `sudo apt-get install libpcap-dev`
* install iw `sudo apt-get install iw`
* patch firmware `sudo cp ./patches/AR9271/firmware/htc_9271.fw over /lib/firmware/htc_9271.fw`
* compile lib ilclient `cd /opt/vc/src/libs/ilclient && make`
* compile hello_video `cd /opt/vc/src/hello_video && make`
* compile wifibroadcast `cd <wifibroadcast_dir> && make`
* remove avahi-daemon `sudo apt-get remove avahi-daemon`
* kill other interface meddling processes `pkill dhcpcd` `pkill ntpd`
* run it `./tx` or `./rx` (see ./scripts/tx.sh for example)
  * ifconfig wlan0 down
  * iw dev wlan0 set monitor otherbss fcsfail
  * ifconfig wlan0 up
  * iwconfig wlan0 channel 11
* setup auto start (see ./scripts/systemd)

##Other Notes
###testing in linux
mplayer can play h264 from stdin: `mplayer - -fps 48` (or whatever $FPS is defined in the scripts)

###getting .config from running raspi board
```
sudo modprobe configs
zcat /proc/config.gz
```

###testing the TL-WN722N (AR9271 Rev:1) in Ubuntu
```
ifconfig wlan0 down
iw dev wlan0 set monitor otherbss fcsfail
ifconfig wlan0 up
iwconfig wlan0 channel 11
```
and now verify packets using `tcpdump` or `wireshark`

###mounting partitions within raspi images
* fdisk -l TX_2015-09-24-raspbian-jessie.img (should show FAT boot and Linux/ext4 system)
* example:
```
                                              Device Boot      Start         End      Blocks   Id  System
/home/a/Downloads/TX_2015-09-24-raspbian-jessie.img1            8192      122879       57344    c  W95 FAT32 (LBA)
/home/a/Downloads/TX_2015-09-24-raspbian-jessie.img2          122880     8447999     4162560   83  Linux
```
* Start/End/Blocks are in 512-byte units, so multiply to get file offset (8192*512 and 122880*512)
* mount -v -o offset=4194304 -t vfat whatever.img /mnt/raspi_boot
* mount -v -o offset=62914560 -t ext4 whatever.img /mnt/raspi_system
